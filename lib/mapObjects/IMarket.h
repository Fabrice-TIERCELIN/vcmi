/*
 * IMarket.h, part of VCMI engine
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 *
 */
#pragma once

#include "../networkPacks/TradeItem.h"
#include "../constants/Enumerations.h"
#include "../CArtHandler.h"

VCMI_LIB_NAMESPACE_BEGIN

class DLL_LINKAGE IMarket : public virtual Serializeable
{
public:
	class CArtifactSetAltar : public CArtifactSet
	{
	public:
		ArtBearer::ArtBearer bearerType() const override {return ArtBearer::ALTAR;};
	};

	virtual ObjectInstanceID getObjInstanceID() const = 0;	// The market is always an object on the map
	virtual int getMarketEfficiency() const = 0;
	virtual bool allowsTrade(const EMarketMode mode) const;
	virtual int availableUnits(const EMarketMode mode, const int marketItemSerial) const; //-1 if unlimited
	virtual std::vector<TradeItemBuy> availableItemsIds(const EMarketMode mode) const;
	void addMarketMode(const EMarketMode mode);
	void addMarketMode(const std::set<EMarketMode> & modes);
	void removeMarketMode(const EMarketMode mode);
	void removeMarketMode(const std::set<EMarketMode> & modes);
	void removeAllMarketModes();
	std::set<EMarketMode> availableModes() const;
	std::shared_ptr<CArtifactSet> getArtifactsStorage() const;
	bool getOffer(int id1, int id2, int &val1, int &val2, EMarketMode mode) const; //val1 - how many units of id1 player has to give to receive val2 units

	template <typename Handler> void serialize(Handler & h)
	{
		h & marketModes;

		if(vstd::contains(marketModes, EMarketMode::ARTIFACT_EXP))
		{
			if (!h.saving)
				altarArtifactsStorage = std::make_shared<CArtifactSetAltar>();

			h & *altarArtifactsStorage;
		}
	}

	template <typename Handler> void serializeArtifactsAltar(Handler & h)
	{
		h & *altarArtifactsStorage;
	}

private:
	std::shared_ptr<CArtifactSetAltar> altarArtifactsStorage;
	std::set<EMarketMode> marketModes;
};

VCMI_LIB_NAMESPACE_END
