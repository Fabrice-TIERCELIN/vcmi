/*
* ResourceManager.cpp, part of VCMI engine
*
* Authors: listed in file AUTHORS in main folder
*
* License: GNU General Public License v2.0 or later
* Full text of license available in license.txt file, in main folder
*
*/
#include "StdInc.h"
#include "ResourceManager.h"

#include "../../CCallback.h"
#include "../../lib/mapObjects/MapObjects.h"

#define GOLD_RESERVE (10000); //at least we'll be able to reach capitol

ResourceObjective::ResourceObjective(TResources & Res, Goals::TSubgoal Goal)
	: resources(Res), goal(Goal)
{
}

bool ResourceObjective::operator<(const ResourceObjective & ro) const
{
	return goal->priority < ro.goal->priority;
}

ResourceManager::ResourceManager(CPlayerSpecificInfoCallback * CB, VCAI * AI)
	: ai(AI), cb(CB)
{
}

void ResourceManager::setCB(CPlayerSpecificInfoCallback * CB)
{
	cb = CB;
}

void ResourceManager::setAI(VCAI * AI)
{
	ai = AI;
}

bool ResourceManager::canAfford(const TResources & cost) const
{
	return freeResources().canAfford(cost);
}

TResources ResourceManager::estimateIncome() const
{
	TResources ret;
	for (const CGTownInstance * t : cb->getTownsInfo())
	{
		ret += t->dailyIncome();
	}

	for (const CGObjectInstance * obj : ai->getFlaggedObjects())
	{
		if (obj->ID == Obj::MINE)
		{
			switch (obj->subID)
			{
			case Res::WOOD:
			case Res::ORE:
				ret[obj->subID] += WOOD_ORE_MINE_PRODUCTION;
				break;
			case Res::GOLD:
			case 7: //abandoned mine -> also gold
				ret[Res::GOLD] += GOLD_MINE_PRODUCTION;
				break;
			default:
				ret[obj->subID] += RESOURCE_MINE_PRODUCTION;
				break;
			}
		}
	}

	return ret;
}

void ResourceManager::reserveResoures(TResources & res, Goals::TSubgoal goal)
{
	if (!goal->invalid())
		tryPush(ResourceObjective(res, goal));
	else
		logAi->warn("Attempt to reserve resources for Invalid goal");
}

Goals::TSubgoal ResourceManager::collectResourcesForOurGoal(ResourceObjective &o) const
{
	auto allResources = cb->getResourceAmount();
	auto income = estimateIncome();
	Res::ERes resourceType = Res::INVALID;
	TResource amountToCollect = 0;

	typedef std::pair<Res::ERes, TResource> resPair;
	std::map<Res::ERes, TResource> missingResources;

	//TODO: unit test for complex resource sets

	//sum missing resources of given type for ALL reserved objectives
	for (auto it = queue.ordered_begin(); it != queue.ordered_end(); it++)
	{
		//choose specific resources we need for this goal (not 0)
		for (auto r = Res::ResourceSet::nziterator(o.resources); r.valid(); r++)
			missingResources[r->resType] += it->resources[r->resType]; //goal it costs r units of resType
	}
	for (auto it = Res::ResourceSet::nziterator(o.resources); it.valid(); it++)
	{
		missingResources[it->resType] -= allResources[it->resType]; //missing = (what we need) - (what we have)
		vstd::amax(missingResources[it->resType], 0); // if we have more resources than reserved, we don't need them
	}
	vstd::erase_if(missingResources, [=](const resPair & p) -> bool
	{
		return !(p.second); //in case evaluated to 0 or less
	});
	if (missingResources.empty()) //FIXME: should be unit-tested out
	{
		logAi->error("We don't need to collect resources %s for goal %s", o.resources.toString(), o.goal->name());
		return o.goal;
	}

	float goalPriority = 10; //arbitrary, will be divided
	for (const resPair & p : missingResources)
	{
		if (!income[p.first]) //prioritize resources with 0 income
		{
			resourceType = p.first;
			amountToCollect = p.second;
			goalPriority /= amountToCollect; //need more resources -> lower priority
			break;
		}
	}
	if (resourceType == Res::INVALID) //no needed resources has 0 income, 
	{
		//find the one which takes longest to collect
		typedef std::pair<Res::ERes, float> timePair;
		std::map<Res::ERes, float> daysToEarn;
		for (auto it : missingResources)
			daysToEarn[it.first] = (float)missingResources[it.first] / income[it.first];
		auto incomeComparer = [&income](const timePair & lhs, const timePair & rhs) -> bool
		{
			//theoretically income can be negative, but that falls into this comparison
			return lhs.second < rhs.second;
		};

		resourceType = boost::max_element(daysToEarn, incomeComparer)->first;
		amountToCollect = missingResources[resourceType];
		goalPriority /= daysToEarn[resourceType]; //more days - lower priority
	}
	if (resourceType == Res::GOLD)
		goalPriority *= 1000;

	//this is abstract goal and might take soem time to complete
	return Goals::sptr(Goals::CollectRes(resourceType, amountToCollect).setisAbstract(true));
}

Goals::TSubgoal ResourceManager::whatToDo() const //suggest any goal
{
	if (queue.size())
	{
		auto o = queue.top();
		
		auto allResources = cb->getResourceAmount(); //we don't consider savings, it's out top-priority goal
		if (allResources.canAfford(o.resources))
			return o.goal;
		else //we can't afford even top-priority goal, need to collect resources
			return collectResourcesForOurGoal(o);
	}
	else
		return Goals::sptr(Goals::Invalid()); //nothing else to do
}

Goals::TSubgoal ResourceManager::whatToDo(TResources &res, Goals::TSubgoal goal)
{
	TResources accumulatedResources;
	auto allResources = cb->getResourceAmount();

	ResourceObjective ro(res, goal);
	tryPush(ro);
	//check if we can afford all the objectives with higher priority first
	for (auto it = queue.ordered_begin(); it != queue.ordered_end(); it++)
	{
		accumulatedResources += it->resources;
		if (!accumulatedResources.canBeAfforded(allResources)) //can't afford
			return collectResourcesForOurGoal(ro);
		else //can afford all goals up to this point
		{
			if (it->goal == goal)
				return goal; //can afford immediately
		}
	}
	return collectResourcesForOurGoal(ro); //fallback, ever needed?
}

bool ResourceManager::containsObjective(Goals::TSubgoal goal) const
{
	//TODO: unit tests for once
	for (auto objective : queue)
	{
		if (objective.goal == goal)
			return true;
	}
	return false;
}

bool ResourceManager::notifyGoalCompleted(Goals::TSubgoal goal)
{
	if (goal->invalid())
		logAi->warn("Attempt to complete Invalid goal");

	bool removedGoal = false;
	while (true)
	{ //unfortunatelly we can't use remove_if on heap
		auto it = boost::find_if(queue, [goal](const ResourceObjective & ro) -> bool
		{
			return ro.goal == goal || ro.goal->fulfillsMe (goal);
		});
		if (it != queue.end()) //removed at least one
		{
			queue.erase(queue.s_handle_from_iterator(it));
			logAi->debug("Removed goal %s from ResourceManager.", it->goal->name());
			removedGoal = true;
		}
		else //found nothing more to remove
			return removedGoal;
	}
	return removedGoal;
}

bool ResourceManager::updateGoal(Goals::TSubgoal goal)
{
	//we update priority of goal if it is easier or more difficult to complete
	if (goal->invalid())
		logAi->warn("Attempt to update Invalid goal");

	auto it = boost::find_if(queue, [goal](const ResourceObjective & ro) -> bool
	{
		return ro.goal == goal;
	});
	if (it != queue.end())
	{
		it->goal->setpriority(goal->priority);
		auto handle = queue.s_handle_from_iterator(it);
		queue.update(handle); //restore order
		return true;
	}
	else
		return false;
}

bool ResourceManager::tryPush(ResourceObjective & o)
{
	auto goal = o.goal;

	auto it = boost::find_if(queue, [goal](const ResourceObjective & ro) -> bool
	{
		return ro.goal == goal;
	});
	if (it != queue.end())
	{
		auto handle = queue.s_handle_from_iterator(it);
		vstd::amax(goal->priority, it->goal->priority); //increase priority if case
		//update resources with new value
		queue.update(handle, ResourceObjective(o.resources, goal)); //restore order
		return false;
	}
	else
	{
		queue.push(o); //add new objective
		logAi->debug("Reserved resources (%s) for %s", o.resources.toString(), goal->name());
		return true;
	}
}

bool ResourceManager::hasTasksLeft() const
{
	return !queue.empty();
}

TResources ResourceManager::reservedResources() const
{
	TResources res;
	for (auto it : queue) //substract the value of reserved goals
		res += it.resources;
	return res;
}

TResources ResourceManager::freeResources() const
{
	TResources myRes = cb->getResourceAmount();
	auto towns = cb->getTownsInfo();
	if (towns.size()) //we don't save for Capitol if there are no towns
	{
		if (std::none_of(towns.begin(), towns.end(), [](const CGTownInstance * x) -> bool
		{
			return x->builtBuildings.find(BuildingID::CAPITOL) != x->builtBuildings.end();
		}))
		{
			myRes[Res::GOLD] -= GOLD_RESERVE;
			//what if capitol is blocked from building in all possessed towns (set in map editor)?
		}
	}
	myRes -= reservedResources(); //substract the value of reserved goals

	for (auto & val : myRes)
		vstd::amax(val, 0); //never negative

	return myRes;
}

TResource ResourceManager::freeGold() const
{
	return freeResources()[Res::GOLD];
}

TResources ResourceManager::allResources() const
{
	return cb->getResourceAmount();
}

TResource ResourceManager::allGold() const
{
	return cb->getResourceAmount()[Res::GOLD];
}
