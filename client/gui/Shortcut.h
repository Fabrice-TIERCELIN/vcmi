/*
 * Shortcut.h, part of VCMI engine
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 *
 */
#pragma once

enum class EShortcut
{
	NONE,

	GLOBAL_CONFIRM,    // Enter
	GLOBAL_CANCEL,     // Escape
	GLOBAL_RETURN,     // Enter, Escape
	GLOBAL_FULLSCREEN, // F4
	GLOBAL_OPTIONS,
	GLOBAL_BACKSPACE,
	GLOBAL_MOVE_FOCUS,

	SELECT_LEFT,
	SELECT_RIGHT,
	SELECT_UP,
	SELECT_DOWN,
	SELECT_FIRST,
	SELECT_LAST,
	SELECT_PAGE_UP,
	SELECT_PAGE_DOWN,

	SELECT_INDEX_1,
	SELECT_INDEX_2,
	SELECT_INDEX_3,
	SELECT_INDEX_4,
	SELECT_INDEX_5,
	SELECT_INDEX_6,
	SELECT_INDEX_7,
	SELECT_INDEX_8,

	MAIN_MENU_NEW,
	MAIN_MENU_LOAD,
	MAIN_MENU_SCORES,
	MAIN_MENU_CREDITS,
	MAIN_MENU_BACK,
	MAIN_MENU_QUIT,
	MAIN_MENU_SINGLEPLAYER,
	MAIN_MENU_MULTIPLAYER,
	MAIN_MENU_CAMPAIGN,
	MAIN_MENU_TUTORIAL,
	MAIN_MENU_CAMPAIGN_SOD,
	MAIN_MENU_CAMPAIGN_ROE,
	MAIN_MENU_CAMPAIGN_AB,
	MAIN_MENU_CAMPAIGN_CUSTOM,

	LOBBY_BEGIN_GAME, // b, Return
	LOBBY_LOAD_GAME,  // l, Return
	LOBBY_SAVE_GAME,  // s, Return
	LOBBY_RANDOM_MAP,
	LOBBY_HIDE_CHAT,
	LOBBY_ADDITIONAL_OPTIONS,
	LOBBY_SELECT,

	GAME_END_TURN,
	GAME_LOAD_GAME,
	GAME_SAVE_GAME,
	GAME_RESTART_GAME,
	GAME_TO_MAIN_MENU,
	GAME_QUIT_GAME,
	GAME_MARKETPLACE,
	GAME_THIEVES_GUILD,
	GAME_ACTIVATE_CONSOLE,

	ADVENTURE_OPTIONS,
	ADVENTURE_TOGGLE_GRID,
	ADVENTURE_TOGGLE_SLEEP,
	ADVENTURE_MOVE_HERO,
	ADVENTURE_VISIT_OBJECT,
	ADVENTURE_MOVE_HERO_SW,
	ADVENTURE_MOVE_HERO_SS,
	ADVENTURE_MOVE_HERO_SE,
	ADVENTURE_MOVE_HERO_WW,
	ADVENTURE_MOVE_HERO_EE,
	ADVENTURE_MOVE_HERO_NW,
	ADVENTURE_MOVE_HERO_NN,
	ADVENTURE_MOVE_HERO_NE,
	ADVENTURE_VIEW_SELECTED,
	ADVENTURE_NEXT_OBJECT,
	ADVENTURE_NEXT_TOWN,
	ADVENTURE_NEXT_HERO,
	ADVENTURE_FIRST_TOWN,
	ADVENTURE_FIRST_HERO,
	ADVENTURE_VIEW_SCENARIO,
	ADVENTURE_DIG_GRAIL,
	ADVENTURE_VIEW_PUZZLE,
	ADVENTURE_VIEW_WORLD,
	ADVENTURE_TOGGLE_MAP_LEVEL,
	ADVENTURE_KINGDOM_OVERVIEW,
	ADVENTURE_QUEST_LOG,
	ADVENTURE_CAST_SPELL,
	ADVENTURE_END_TURN,
	ADVENTURE_THIEVES_GUILD,

	BATTLE_TOGGLE_QUEUE,
	BATTLE_USE_CREATURE_SPELL,
	BATTLE_SURRENDER,
	BATTLE_RETREAT,
	BATTLE_AUTOCOMBAT,
	BATTLE_CAST_SPELL,
	BATTLE_WAIT,
	BATTLE_DEFEND,
	BATTLE_CONSOLE_UP,
	BATTLE_CONSOLE_DOWN,
	BATTLE_TACTICS_NEXT,
	BATTLE_TACTICS_END,

	TOWN_OPEN_TAVERN,
	TOWN_SWAP_ARMIES,

	RECRUITMENT_MAX,
	RECRUITMENT_MIN,
	RECRUITMENT_UPGRADE, // U
	RECRUITMENT_UPGRADE_ALL, // A, U

	KINGDOM_HEROES,
	KINGDOM_TOWNS,

	HERO_DISMISS,
	HERO_COMMANDER,
	HERO_LOOSE_FORMATION,
	HERO_TIGHT_FORMATION,
	HERO_TOGGLE_TACTICS, // b

	SPELLBOOK_TAB_ADVENTURE,
	SPELLBOOK_TAB_COMBAT,

	AFTER_LAST
};

