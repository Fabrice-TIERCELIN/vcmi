# 1.0.0 -> 1.1.0

### GENERAL:
* iOS is supported
* Mods and their versions and serialized into save files. Game checks mod compatibility before loading
* Logs are stored in system default logs directory
* LUA/ERM libs are not compiled by default
* FFMpeg dependency is optional now
* Conan package manager is supported for MacOS and iOS

### MULTIPLAYER:
* Map is passed over network, so different platforms are compatible with each other
* Server self-killing is more robust
* Unlock in-game console while opponent's turn
* Host can control game session by using console commands
* Control over player is transferred to AI if client escaped the game
* Reconnection mode for crashed client processes
* Playing online is available using proxy server

### ADVENTURE MAP:
* Fix for digging while opponent's turn
* Supported right click for quick recruit window
* Fixed problem with quests are requiring identical artefacts
* Bulk move and swap artifacts
* Pause & resume for towns and terrains music themes
* Feature to assemble/disassemble artefacts in backpack
* Clickable status bar to send messages
* Heroes no longer have chance to receive forbidden skill on leveling up
* Fixed visibility of newly recruited heroes near town 
* Fixed missing artifact slot in Artifact Merchant window

### BATTLES:
* Fix healing/regeneration behaviour and effect
* Fix crashes related to auto battle
* Implemented ray projectiles for shooters
* Introduced default tower shooter icons
* Towers destroyed during battle will no longer be listed as casualties

### AI:
* BattleAI: Target prioritizing is now based on damage difference instead of health difference
* Nullkiller AI can retreat and surrender
* Nullkiller AI doesn't visit allied dwellings anymore
* Fixed a few freezes in Nullkiller AI

### RANDOM MAP GENERATOR:
* Speedup generation of random maps
* Necromancy cannot be learned in Witch Hut on random maps

### MODS:
* Supported rewardable objects customization
* Battleground obstacles are extendable now with VLC mechanism
* Introduced "compatibility" section into mods settings
* Fixed bonus system for custom advmap spells
* Supported customisable town entrance placement
* Fixed validation of mods with new adventure map objects

### LAUNCHER:
* Fixed problem with duplicated mods in the list
* Launcher shows compatible mods only
* Uninstall button was moved to the left of layout
* Unsupported resolutions are not shown
* Lobby for online gameplay is implemented

### MAP EDITOR:
* Basic version of Qt-based map editor

# 0.99 -> 1.0.0

### GENERAL:
* Spectator mode was implemented through command-line options
* Some main menu settings get saved after returning to main menu - last selected map, save etc.
* Restart scenario button should work correctly now
* Skyship Grail works now immediately after capturing without battle
* Lodestar Grail implemented
* Fixed Gargoyles immunity
* New bonuses:
** SOUL_STEAL - "WoG ghost" ability, should work somewhat same as in H3
** TRANSMUTATION - "WoG werewolf"-like ability
** SUMMON_GUARDIANS - "WoG santa gremlin"-like ability + two-hex unit extension
** CATAPULT_EXTRA_SHOTS - defines number of extra wall attacks for units that can do so
** RANGED_RETALIATION - allows ranged counterattack
** BLOCKS_RANGED_RETALIATION - disallow enemy ranged counterattack
** SECONDARY_SKILL_VAL2 - set additional parameter for certain secondary skills
** MANUAL_CONTROL - grant manual control over war machine
** WIDE_BREATH - melee creature attacks affect many nearby hexes
** FIRST_STRIKE - creature counterattacks before attack if possible
** SYNERGY_TARGET - placeholder bonus for Mod Design Team (subject to removal in future)
** SHOOTS_ALL_ADJACENT - makes creature shots affect all neighbouring hexes
** BLOCK_MAGIC_BELOW - allows blocking spells below particular spell level. HotA cape artifact can be implemented with this
** DESTRUCTION - creature ability for killing extra units after hit, configurable

### MULTIPLAYER:
* Loading support. Save from single client could be used to load all clients.
* Restart support. All clients will restart together on same server.
* Hotseat mixed with network game. Multiple colors can be controlled by each client.

### SPELLS:
* Implemented cumulative effects for spells

### MODS:
* Improve support for WoG commander artifacts and skill descriptions
* Added support for modding of original secondary skills and creation of new ones.
* Map object sounds can now be configured via json
* Added bonus updaters for hero specialties
* Added allOf, anyOf and noneOf qualifiers for bonus limiters
* Added bonus limiters: alignment, faction and terrain
* Supported new terrains, new battlefields, custom water and rock terrains
* Following special buildings becomes available in the fan towns:
** attackVisitingBonus
** defenceVisitingBonus
** spellPowerVisitingBonus
** knowledgeVisitingBonus
** experienceVisitingBonus
** lighthouse
** treasury

### SOUND:
* Fixed many mising or wrong pickup and visit sounds for map objects
* All map objects now have ambient sounds identical to OH3

### RANDOM MAP GENERATOR:
* Random map generator supports water modes (normal, islands)
* Added config randomMap.json with settings for map generator
* Added parameter for template allowedWaterContent
* Extra resource packs appear nearby mines
* Underground can be player starting place for factions allowed to be placed underground
* Improved obstacles placement aesthetics
* Rivers are generated on the random maps
* RMG works more stable, various crashes have been fixed
* Treasures requiring guards are guaranteed to be protected

### VCAI:
* Reworked goal decomposition engine, fixing many loopholes. AI will now pick correct goals faster.
* AI will now use universal pathfinding globally
* AI can use Summon  Boat and Town Portal
* AI can gather and save resources on purpose
* AI will only buy army on demand instead of every turn
* AI can distinguish the value of all map objects
* General speed optimizations

### BATTLES:
* Towers should block ranged retaliation
* AI can bypass broken wall with moat instead of standing and waiting until gate is destroyed
* Towers do not attack war machines automatically
* Draw is possible now as battle outcome in case the battle ends with only summoned creatures (both sides loose)

### ADVENTURE MAP:
* Added buttons and keyboard shortcuts to quickly exchange army and artifacts between heroes
* Fix: Captured town should not be duplicated on the UI

### LAUNCHER:
* Implemented notifications about updates
* Supported redirection links for downloading mods

# 0.98 -> 0.99

### GENERAL:
* New Bonus NO_TERRAIN_PENALTY
* Nomads will remove Sand movement penalty from army
* Flying and water walking is now supported in pathfinder
* New artifacts supported
** Angel Wings
** Boots of Levitation
* Implemented rumors in tavern window
* New cheat codes:
** vcmiglaurung - gives 5000 crystal dragons into each slot
** vcmiungoliant - conceal fog of war for current player
* New console commands:
** gosolo - AI take control over human players and vice versa
** controlai - give control of one or all AIs to player
** set hideSystemMessages on/off - supress server messages in chat

### BATTLES:
* Drawbridge mechanics implemented (animation still missing)
* Merging of town and visiting hero armies on siege implemented
* Hero info tooltip for skills and mana implemented

### ADVENTURE AI:
* Fixed AI trying to go through underground rock
* Fixed several cases causing AI wandering aimlessly
* AI can again pick best artifacts and exchange artifacts between heroes
* AI heroes with patrol enabled won't leave patrol area anymore

### RANDOM MAP GENERATOR:
* Changed fractalization algorithm so it can create cycles
* Zones will not have straight paths anymore, they are totally random
* Generated zones will have different size depending on template setting
* Added Thieves Guild random object (1 per zone)
* Added Seer Huts with quests that match OH3
* RMG will guarantee at least 100 pairs of Monoliths are available even if there are not enough different defs

# 0.97 -> 0.98

### GENERAL:
* Pathfinder can now find way using Monoliths and Whirlpools (only used if hero has protection)

### ADVENTURE AI:
* AI will try to use Monolith entrances for exploration
* AI will now always revisit each exit of two way monolith if exit no longer visible
* AI will eagerly pick guarded and blocked treasures

### ADVENTURE MAP:
* Implemented world view
* Added graphical fading effects

### SPELLS:
* New spells handled:
** Earthquake
** View Air
** View Earth
** Visions
** Disguise
* Implemented CURE spell negative dispell effect
* Added LOCATION target for spells castable on any hex with new target modifiers

### BATTLES:
* Implemented OH3 stack split / upgrade formulas according to AlexSpl

### RANDOM MAP GENERATOR:
* Underground tunnels are working now
* Implemented "junction" zone type
* Improved zone placing algorithm
* More balanced distribution of treasure piles
* More obstacles within zones

# 0.96 -> 0.97 (Nov 01 2014)

### GENERAL:
* (windows) Moved VCMI data directory from '%userprofile%\vcmi' to '%userprofile%\Documents\My Games\vcmi'
* (windows) (OSX) Moved VCMI save directory from 'VCMI_DATA\Games' to 'VCMI_DATA\Saves'
* (linux)
* Changes in used librries:
** VCMI can now be compiled with SDL2
** Movies will use ffmpeg library
** change boost::bind to std::bind 
** removed boost::asign 
** Updated FuzzyLite to 5.0 
* Multiplayer load support was implemented through command-line options

### ADVENTURE AI:
* Significantly optimized execution time, AI should be much faster now.

### ADVENTURE MAP:
* Non-latin characters can now be entered in chat window or used for save names.
* Implemented separate speed for owned heroes and heroes owned by other players

### GRAPHICS:
* Better upscaling when running in fullscreen mode.
* New creature/commader window
* New resolutions and bonus icons are now part of a separate mod
* Added graphics for GENERAL_DAMAGE_REDUCTION bonus (Kuririn)

### RANDOM MAP GENERATOR:
* Random map generator now creates complete and playable maps, should match original RMG
* All important features from original map templates are implemented
* Fixed major crash on removing objects
* Undeground zones will look just like surface zones

### LAUNCHER:
* Implemented switch to disable intro movies in game

# 0.95 -> 0.96 (Jul 01 2014)

### GENERAL:
* (linux) now VCMI follows XDG specifications. See http://forum.vcmi.eu/viewtopic.php?t=858

### ADVENTURE AI:
* Optimized speed and removed various bottlenecks.

### ADVENTURE MAP:
* Heroes auto-level primary and secondary skill levels according to experience

### BATTLES:
* Wall hit/miss sound will be played when using catapult during siege

### SPELLS:
* New configuration format: http://wiki.vcmi.eu/index.php?title=Spell_Format

### RANDOM MAP GENERATOR:
* Towns from mods can be used
* Reading connections, terrains, towns and mines from template
* Zone placement
* Zone borders and connections, fractalized paths inside zones
* Guard generation
* Treasue piles generation (so far only few removable objects)

### MODS:
* Support for submods - mod may have their own "submods" located in <modname>/Mods directory
* Mods may provide their own changelogs and screenshots that will be visible in Launcher
* Mods can now add new (offensive, buffs, debuffs) spells and change existing
* Mods can use custom mage guild background pictures and videos for taverns, setting of resources daily income for buildings

### GENERAL:
* Added configuring of heroes quantity per player allowed in game

# 0.94 -> 0.95 (Mar 01 2014)

### GENERAL:
* Components of combined artifacts will now display info about entire set.
* Implements level limit
* Added WoG creature abilities by Kuririn
* Implemented a confirmation dialog when pressing Alt + F4 to quit the game 
* Added precompiled header compilation for CMake (can be enabled per flag)
* VCMI will detect changes in text files using crc-32 checksum
* Basic support for unicode. Internally vcmi always uses utf-8
* (linux) Launcher will be available as "VCMI" menu entry from system menu/launcher
* (linux) Added a SIGSEV violation handler to vcmiserver executable for logging stacktrace (for convenience)

### ADVENTURE AI:
More info at http://wiki.vcmi.eu/index.php?title=Adventure_AI
* AI will use fuzzy logic to compare and choose multiple possible subgoals.
* AI will now use SectorMap to find a way to guarded / covered objects. 
* Significantly improved exploration algorithm.
* Locked heroes now try to decompose their goals exhaustively.
* Fixed (common) issue when AI found neutral stacks infinitely strong.
* Improvements for army exchange criteria.
* GatherArmy may include building dwellings in town (experimental).
* AI should now conquer map more aggressively and much faster
* Fuzzy rules will be printed out at map launch (if AI log is enabled)

### CAMPAIGNS:
* Implemented move heroes to next scenario
* Support for non-standard victory conditions for H3 campaigns
* Campaigns use window with bonus & scenario selection than scenario information window from normal maps
* Implemented hero recreate handling (e.g. Xeron will be recreated on AB campaign)
* Moved place bonus hero before normal random hero and starting hero placement -> same behaviour as in OH3
* Moved placing campaign heroes before random object generation -> same behaviour as in OH3 

### TOWNS:
* Extended building dependencies support

### MODS:
* See http://wiki.vcmi.eu/index.php?title=Modding_changelog#0.94_-.3E_0.95 for format changes
* Custom victory/loss conditions for maps or campaigns
* 7 days without towns loss condition is no longer hardcoded
* Only changed mods will be validated

# 0.93 -> 0.94 (Oct 01 2013)

### GENERAL:
* New Launcher application, see 
* Filesystem now supports zip archives. They can be loaded similarly to other archives in filesystem.json. Mods can use Content.zip instead of Content/ directory.
* fixed "get txt" console command
* command "extract" to extract file by name
* command "def2bmp" to convert def into set of frames.
* fixed crash related to cammander's SPELL_AFTER_ATTACK spell id not initialized properly (text id was resolved on copy of bonus)
* fixed duels, added no-GUI mode for automatic AI testing
* Sir Mullich is available at the start of the game
* Upgrade cost will never be negative.
* support for Chinese fonts (GBK 2-byte encoding)

### ADVENTURE MAP:
* if Quick Combat option is turned on, battles will be resolved by AI
* first hero is awakened on new turn
* fixed 3000 gems reward in shipwreck

### BATTLES:
* autofight implemented
* most of the animations is time-based
* simplified postioning of units in battle, should fix remaining issues with unit positioning
* synchronized attack/defence animation
* spell animation speed uses game settings
* fixed disrupting ray duration
* added logging domain for battle animations
* Fixed crashes on Land Mines / Fire Wall casting.
* UI will be correctly greyed-out during opponent turn
* fixed remaining issues with blit order
* Catapult attacks should be identical to H3. Catapult may miss and attack another part of wall instead (this is how it works in H3)
* Fixed Remove Obstacle.
* defeating hero will yield 500 XP
* Added lots of missing spell immunities from Strategija
* Added stone gaze immunity for Troglodytes (did you know about it?)
* damage done by turrets is properly increased by built buldings
* Wyverns will cast Poison instead of Stone Gaze.

### TOWN:
* Fixed issue that allowed to build multiple boats in town.
* fix for lookout tower

# 0.92 -> 0.93 (Jun 01 2013)

### GENERAL:
* Support for SoD-only installations, WoG becomes optional addition
* New logging framework
* Negative luck support, disabled by default
* Several new icons for creature abilities (Fire Shield, Non-living, Magic Mirror, Spell-like Attack)
* Fixed stack artifact (and related buttons) not displaying in creature window.
* Fixed crash at month of double population.

### MODS:
* See http://wiki.vcmi.eu/index.php?title=Modding_changelog#0.92_-.3E_0.93 for compatibility info.
* Improved json validation. Now it support most of features from latest json schema draft.
* Icons use path to icon instead of image indexes.
* It is possible to edit data of another mod or H3 data via mods.
* Mods can access only ID's from dependenies, virtual "core" mod and itself (optional for some mods compatibility)
* Removed no longer needed field "projectile spins"
* Heroes: split heroes.json in manner similar to creatures\factions; string ID's for H3 heroes; h3 hero classes and artifacts can be modified via json.

### BATTLES:
* Fixed Death Stare of Commanders
* Projectile blitting should be closer to original H3. But still not perfect.
* Fixed missing Mirth effects
* Stack affected by Berserk should not try to attack itself
* Fixed several cases of incorrect positioning of creatures in battles
* Fixed abilities of Efreet.
* Fixed broken again palette in some battle backgrounds

### TOWN:
* VCMI will not crash if building selection area is smaller than def
* Detection of transparency on selection area is closer to H3
* Improved handling buildings with mode "auto":
** they will be properly processed (new creatures will be added if dwelling, spells learned if mage guild, and so on)
** transitive dependencies are handled (A makes B build, and B makes C and D)

### SOUND:
* Added missing WoG creature sounds (from Kuririn).
* The Windows package comes with DLLs needed to play .ogg files
* (linux) convertMP3 option for vcmibuilder for systems where SDL_Mixer can't play mp3's
* some missing sounds for battle effects

### ARTIFACTS:
* Several fixes to combined artifacts added via mods.
* Fixed Spellbinder's Hat giving level 1 spells instead of 5.
* Fixed incorrect components of Cornucopia.
* Cheat code with grant all artifacts, including the ones added by mods

# 0.91 -> 0.92 (Mar 01 2013)

### GENERAL:
* hero crossover between missions in campaigns
* introduction before missions in campaigns

### MODS:
* Added CREATURE_SPELL_POWER for commanders
* Added spell modifiers to various spells: Hypnotize (Astral), Firewall (Luna), Landmine 
* Fixed ENEMY_DEFENCE_REDUCTION, GENERAL_ATTACK_REDUCTION
* Extended usefulness of ONLY_DISTANCE_FIGHT, ONLY_MELEE_FIGHT ranges
* Double growth creatures are configurable now
* Drain Life now has % effect depending on bonus value
* Stack can use more than 2 attacks. Additional attacks can now be separated as "ONLY_MELEE_FIGHT and "ONLY_DISTANCE_FIGHT".
* Moat damage configurable
* More config options for spells:
** mind immunity handled by config
** direct damage immunity handled by config
** immunity icon configurable
** removed mind_spell flag 
* creature config use string ids now. 
* support for string subtype id in short bonus format
* primary skill identifiers for bonuses

# 0.9 -> 0.91 (Feb 01 2013)

### GENERAL:
* VCMI build on OS X is now supported
* Completely removed autotools
* Added RMG interace and ability to generate simplest working maps
* Added loading screen

### MODS:
* Simplified mod structure. Mods from 0.9 will not be compatible.
* Mods can be turned on and off in config/modSettings.json file
* Support for new factions, including:
** New towns
** New hero classes
** New heroes
** New town-related external dwellings
* Support for new artifact, including combined, commander and stack artifacts
* Extended configuration options
** All game objects are referenced by string identifiers
** Subtype resolution for bonuses

### BATTLES:
* Support for "enchanted" WoG ability

### ADVENTURE AI:
* AI will try to use Subterranean Gate, Redwood Observatory and Cartographer for exploration
* Improved exploration algorithm
* AI will prioritize dwellings and mines when there are no opponents visible

# 0.89 -> 0.9 (Oct 01 2012)

### GENERAL:
* Provisional support creature-adding mods
* New filesystem allowing easier resource adding/replacing
* Reorganized package for better compatibility with HotA and not affecting the original game
* Moved many hard-coded settings into text config files
* Commander level-up dialog
* New Quest Log window
* Fixed a number of bugs in campaigns, support for starting hero selection bonus. 

### BATTLES:
* New graphics for Stack Queue
* Death Stare works identically to H3
* No explosion when catapult fails to damage the wall
* Fixed crash when attacking stack dies before counterattack
* Fixed crash when attacking stack dies in the Moat just before the attack
* Fixed Orb of Inhibition and Recanter's Cloak (they were incorrectly implemented)
* Fleeing hero won't lose artifacts.
* Spellbook won't be captured. 

### ADVENTURE AI:
* support for quests (Seer Huts, Quest Guardians, and so)
* AI will now wander with all the heroes that have spare movement points. It should prevent stalling.
* AI will now understand threat of Abandoned Mine.
* AI can now exchange armies between heroes. By default, it will pass army to main hero.
* Fixed strange case when AI found allied town extremely dangerous
* Fixed crash when AI tried to "revisit" a Boat
* Fixed crash when hero assigned to goal was lost when attempting realizing it
* Fixed a possible freeze when exchanging resources at marketplace

### BATTLE AI:
* It is possible to select a battle AI module used by VCMI by typing into the console "setBattleAI <name>". The names of avaialble modules are "StupidAI" and "BattleAI". BattleAI may be a little smarter but less stable. By the default, StupidAI will be used, as in previous releases.
* New battle AI module: "BattleAI" that is smarter and capable of casting some offensive and enchantment spells

# 0.88 -> 0.89 (Jun 01 2012)

### GENERAL:
* Mostly implemented Commanders feature (missing level-up dialog)
* Support for stack artifacts
* New creature window graphics contributed by fishkebab
* Config file may have multiple upgrades for creatures
* CTRL+T will open marketplace window
* G will open thieves guild window if player owns at least one town with tavern
* Implemented restart functionality. CTRL+R will trigger a quick restart
* Save game screen and returning to main menu will work if game was started with --start option
* Simple mechanism for detecting game desynchronization after init
* 1280x800 resolution graphics, contributed by Topas

### ADVENTURE MAP:
* Fixed monsters regenerating casualties from battle at the start of new week.
* T in adventure map will switch to next town

### BATTLES:
* It's possible to switch active creature during tacts phase by clicking on stack
* After battle artifacts of the defeated hero (and his army) will be taken by winner
* Rewritten handling of battle obstacles. They will be now placed following H3 algorithm.
* Fixed crash when death stare or acid breath activated on stack that was just killed
* First aid tent can heal only creatures that suffered damage
* War machines can't be healed by tent
* Creatures casting spells won't try to cast them during tactic phase
* Console tooltips for first aid tent
* Console tooltips for teleport spell
* Cursor is reset to pointer when action is requested
* Fixed a few other missing or wrong tooltips/cursors
* Implemented opening creature window by l-clicking on stack
* Fixed crash on attacking walls with Cyclop Kings
* Fixed and simplified Teleport casting
* Fixed Remove Obstacle spell
* New spells supported:
** Chain Lightning
** Fire Wall
** Force Field
** Land Mine
** Quicksands
** Sacrifice

### TOWNS:
* T in castle window will open a tavern window (if available)

### PREGAME:
* Pregame will use same resolution as main game
* Support for scaling background image
* Customization of graphics with config file.

### ADVENTURE AI:
* basic rule system for threat evaluation
* new town development logic
* AI can now use external dwellings
* AI will weekly revisit dwellings & mills
* AI will now always pick best stacks from towns
* AI will recruit multiple heroes for exploration
* AI won't try attacking its own heroes

# 0.87 -> 0.88 (Mar 01 2012)

* added an initial version of new adventure AI: VCAI
* system settings window allows to change default resolution
* introduced unified JSON-based settings system
* fixed all known localization issues
* Creature Window can handle descriptions of spellcasting abilities
* Support for the clone spell

# 0.86 -> 0.87 (Dec 01 2011)

### GENERAL:
* Pathfinder can find way using ships and subterranean gates
* Hero reminder & sleep button

### PREGAME:
* Credits are implemented

### BATTLES:
* All attacked hexes will be highlighted
* New combat abilities supported:
** Spell Resistance aura
** Random spellcaster (Genies)
** Mana channeling
** Daemon summoning
** Spellcaster (Archangel Ogre Mage, Elementals, Faerie Dragon)
** Fear
** Fearless
** No wall penalty
** Enchanter
** Bind
** Dispell helpful spells

# 0.85 -> 0.86 (Sep 01 2011)

### GENERAL:
* Reinstated music support
* Bonus system optimizations (caching)
* converted many config files to JSON
* .tga file support
* New artifacts supported
** Admiral's Hat
** Statue of Legion
** Titan's Thunder

### BATTLES:
* Correct handling of siege obstacles
* Catapult animation
* New combat abilities supported
** Dragon Breath
** Three-headed Attack
** Attack all around
** Death Cloud / Fireball area attack
** Death Blow
** Lightning Strike
** Rebirth
* New WoG abilities supported
** Defense Bonus
** Cast before attack
** Immunity to direct damage spells
* New spells supported
** Magic Mirror
** Titan's Lightning Bolt

# 0.84 -> 0.85 (Jun 01 2011)

### GENERAL:
* Support for stack experience
* Implemented original campaign selection screens
* New artifacts supported:
** Statesman's Medal
** Diplomat's Ring
** Ambassador's Sash

### TOWNS:
* Implemented animation for new town buildings
* It's possible to sell artifacts at Artifact Merchants

### BATTLES:
* Neutral monsters will be split into multiple stacks
* Hero can surrender battle to keep army
* Support for Death Stare, Support for Poison, Age, Disease, Acid Breath, Fire / Water / Earth / Air immunities and Receptiveness
* Partial support for Stone Gaze, Paralyze, Mana drain

# 0.83 -> 0.84 (Mar 01 2011)

### GENERAL:
* Bonus system has been rewritten
* Partial support for running VCMI in duel mode (no adventure map, only one battle, ATM only AI-AI battles)
* New artifacts supported:
** Angellic Alliance
** Bird of Perception
** Emblem of Cognizance
** Spell Scroll
** Stoic Watchman

### BATTLES:
* Better animations handling
* Defensive stance is supported

### HERO:
* New secondary skills supported:
** Artillery
** Eagle Eye
** Tactics

### AI PLAYER:
* new AI leading neutral creatures in combat, slightly better then previous

# 0.82 -> 0.83 (Nov 01 2010)

### GENERAL:
* Alliances support
* Week of / Month of events
* Mostly done pregame for MP games (temporarily only for local clients)
* Support for 16bpp displays
* Campaigns:
** support for building bonus
** moving to next map after victory
* Town Portal supported
* Vial of Dragon Blood and Statue of Legion supported

### HERO:
* remaining specialities have been implemented

### TOWNS:
* town events supported
* Support for new town structures: Deiety of Fire and Escape Tunnel 

### BATTLES:
* blocked retreating from castle

# 0.81 -> 0.82 (Aug 01 2010)

### GENERAL:
* Some of the starting bonuses in campaigns are supported
* It's possible to select difficulty level of mission in campaign
* new cheat codes:
** vcmisilmaril - player wins
** vcmimelkor - player loses

### ADVENTURE MAP:
* Neutral armies growth implemented (10% weekly)
* Power rating of neutral stacks
* Favourable Winds reduce sailing cost

### HERO:
* Learning secondary skill supported.
* Most of hero specialities are supported, including:
** Creature specialities (progressive, fixed, Sir Mullich)
** Spell damage specialities (Deemer), fixed bonus (Ciele)
** Secondary skill bonuses
** Creature Upgrades (Gelu)
** Resorce generation
** Starting Skill (Adrienne)

### TOWNS:
* Support for new town structures:
** Artifact Merchant
** Aurora Borealis
** Castle Gates
** Magic University
** Portal of Summoning 
** Skeleton transformer
** Veil of Darkness

### OBJECTS:
* Stables will now upgrade Cavaliers to Champions.
* New object supported:
** Abandoned Mine
** Altar of Sacrifice
** Black Market
** Cover of Darkness
** Hill Fort
** Refugee Camp
** Sanctuary
** Tavern
** University
** Whirlpool

# 0.8 -> 0.81 (Jun 01 2010)

### GENERAL:
* It's possible to start campaign
* Support for build grail victory condition
* New artifacts supported:
** Angel's Wings
** Boots of levitation
** Orb of Vulnerability
** Ammo cart
** Golden Bow
** Hourglass of Evil Hour
** Bow of Sharpshooter
** Armor of the Damned

### ADVENTURE MAP:
* Creatures now guard surrounding tiles
* New adventura map spells supported:
** Summon Boat
** Scuttle Boat 
** Dimension Door
** Fly
** Water walk

### BATTLES:
* A number of new creature abilities supported
* First Aid Tent is functional
* Support for distance/wall/melee penalties & no * penalty abilities
* Reworked damage calculation to fit OH3 formula better
* Luck support
* Teleportation spell

### HERO:
* First Aid secondary skill
* Improved formula for necromancy to match better OH3

### TOWNS:
* Sending resources to other players by marketplace
* Support for new town structures:
** Lighthouse
** Colossus
** Freelancer's Guild
** Guardian Spirit
** Necromancy Amplifier
** Soul Prison

### OBJECTS:
* New object supported:
** Freelancer's Guild
** Trading Post
** War Machine Factory

# 0.75 -> 0.8 (Mar 01 2010)

### GENERAL:
* Victory and loss conditions are supported. It's now possible to win or lose the game.
* Implemented assembling and disassembling of combination artifacts.
* Kingdom Overview screen is now available.
* Implemented Grail (puzzle map, digging, constructing ultimate building)
* Replaced TTF fonts with original ones.

### ADVENTURE MAP:
* Implemented rivers animations (thx to GrayFace).

### BATTLES:
* Fire Shield spell (and creature ability) supported
* affecting morale/luck and casting spell after attack creature abilities supported

### HERO:
* Implementation of Scholar secondary skill

### TOWN:
* New left-bottom info panel functionalities.

### TOWNS:
* new town structures supported:
** Ballista Yard
** Blood Obelisk
** Brimstone Clouds
** Dwarven Treasury
** Fountain of Fortune
** Glyphs of Fear
** Mystic Pond
** Thieves Guild
** Special Grail functionalities for Dungeon, Stronghold and Fortress

### OBJECTS:
* New objects supported:
** Border gate
** Den of Thieves
** Lighthouse
** Obelisk
** Quest Guard
** Seer hut

A lot of of various bugfixes and improvements:
http://bugs.vcmi.eu/changelog_page.php?version_id=14

# 0.74 -> 0.75 (Dec 01 2009)

### GENERAL:
* Implemented "main menu" in-game option.
* Hide the mouse cursor while displaying a popup window.
* Better handling of huge and empty message boxes (still needs more changes)
* Fixed several crashes when exiting.

### ADVENTURE INTERFACE:
* Movement cursor shown for unguarded enemy towns.
* Battle cursor shown for guarded enemy garrisons.
* Clicking on the border no longer opens an empty info windows

### HERO WINDOW:
* Improved artifact moving. Available slots are higlighted. Moved artifact is bound to mouse cursor. 

### TOWNS:
* new special town structures supported:
** Academy of Battle Scholars
** Cage of Warlords
** Mana Vortex
** Stables
** Skyship (revealing entire map only)

### OBJECTS:
* External dwellings increase town growth
* Right-click info window for castles and garrisons you do not own shows a rough amount of creatures instead of none
* Scholar won't give unavaliable spells anymore.

A lot of of various bugfixes and improvements:
http://bugs.vcmi.eu/changelog_page.php?version_id=2

# 0.73 -> 0.74 (Oct 01 2009)

### GENERAL:
* Scenario Information window
* Save Game window
* VCMI window should start centered
* support for Necromancy and Ballistics secondary skills
* new artifacts supported, including those improving Necromancy, Legion Statue parts, Shackles of War and most of combination artifacts (but not combining)
* VCMI client has its own icon (thx for graphic to Dikamilo)
* Ellipsis won't be split when breaking text on several lines
* split button will be grayed out when no creature is selected
* fixed issue when splitting stack to the hero with only one creatures
* a few fixes for shipyard window

### ADVENTURE INTERFACE:
* Cursor shows if tile is accesible and how many turns away
* moving hero with arrow keys / numpad
* fixed Next Hero button behaviour
* fixed Surface/Underground switch button in higher resolutions

### BATTLES:
* partial siege support
* new stack queue for higher resolutions (graphics made by Dru, thx!)
* 'Q' pressing toggles the stack queue displaying (so it can be enabled/disabled it with single key press)
* more creatures special abilities supported
* battle settings will be stored
* fixed crashes occurring on attacking two hex creatures from back
* fixed crash when clicking on enemy stack without moving mouse just after receiving action
* even large stack numbers will fit the boxes
* when active stack is killed by spell, game behaves properly
* shooters attacking twice (like Grand Elves) won't attack twice in melee 
* ballista can shoot even if there's an enemy creature next to it 
* improved obstacles placement, so they'll better fit hexes (thx to Ivan!)
* selecting attack directions works as in H3
* estimating damage that will be dealt while choosing stack to be attacked
* modified the positioning of battle effects, they should look about right now.
* after selecting a spell during combat, l-click is locked for any action other than casting. 
* flying creatures will be blitted over all other creatures, obstacles and wall
* obstacles and units should be printed in better order (not tested)
* fixed armageddon animation
* new spells supported:
** Anti-Magic
** Cure
** Resurrection 
** Animate Dead 
** Counterstrike 
** Berserk 
** Hypnotize 
** Blind 
** Fire Elemental 
** Earth Elemental 
** Water Elemental 
** Air Elemental 
** Remove obstacle

### TOWNS:
* enemy castle can be taken over
* only one capitol per player allowed (additional ones will be lost)
* garrisoned hero can buy a spellbook
* heroes available in tavern should be always different
* ship bought in town will be correctly placed
* new special town structures supported:
** Lookout Tower
** Temple of Valhalla
** Wall of Knowledge
** Order of Fire

### HERO WINDOW:
* war machines cannot be unequiped

### PREGAME:
* sorting: a second click on the column header sorts in descending order.
* advanced options tab: r-click popups for selected town, hero and bonus
* starting scenario / game by double click
* arrows in options tab are hidden when not available 
* subtitles for chosen hero/town/bonus in pregame

### OBJECTS:
* fixed pairing Subterranean Gates
* New objects supported:
** Borderguard & Keymaster Tent
** Cartographer
** Creature banks
** Eye of the Magi & Hut of the Magi
** Garrison
** Stables
** Pandora Box
** Pyramid

# 0.72 -> 0.73 (Aug 01 2009)

### GENERAL:
* infowindow popup will be completely on screen
* fixed possible crash with in game console
* fixed crash when gaining artifact after r-click on hero in tavern
* Estates / hero bonuses won't give resources on first day. 
* video handling (intro, main menu animation, tavern animation, spellbook animation, battle result window)
* hero meeting window allowing exchanging armies and artifacts between heroes on adventure map
* 'T' hotkey opens marketplace window
* giving starting spells for heroes
* pressing enter or escape close spellbook
* removed redundant quotation marks from skills description and artifact events texts
* disabled autosaving on first turn
* bonuses from bonus artifacts
* increased char per line limit for subtitles under components
* corrected some exp/level values
* primary skills cannot be negative
* support for new artifacts: Ring of Vitality, Ring of Life, Vial of Lifeblood, Garniture of Interference, Surcoat of Counterpoise, Boots of Polarity
* fixed timed events reappearing
* saving system options
* saving hero direction
* r-click popups on enemy heroes and towns
* hero leveling formula matches the H3

### ADVENTURE INTERFACE:
* Garrisoning, then removing hero from garrison move him at the end of the heroes list
* The size of the frame around the map depends on the screen size.
* spellbook shows adventure spells when opened on adventure map
* erasing path after picking objects with last movement point

### BATTLES:
* spell resistance supported (secondary skill, artifacts, creature skill)
* corrected damage inflicted by spells and ballista
* added some missing projectile infos
* added native terrain bonuses in battles
* number of units in stack in battle should better fit the box
* non-living and undead creatures have now always 0 morale
* displaying luck effect animation
* support for battleground overlays:
** cursed ground
** magic plains
** fiery fields
** rock lands
** magic clouds
** lucid pools
** holy ground
** clover field
** evil fog

### TOWNS:
* fixes for horde buildings
* garrisoned hero can buy a spellbook if he is selected or if there is no visiting hero
* capitol bar in town hall is grey (not red) if already one exists
* fixed crash on entering hall when town was near map edge

### HERO WINDOW:
* garrisoned heroes won't be shown on the list
* artifacts will be present on morale/luck bonuses list

### PREGAME:
* saves are sorted primary by map format, secondary by name
* fixed displaying date of saved game (uses local time, removed square character)

### OBJECTS:
* Fixed primary/secondary skill levels given by a scholar.
* fixed problems with 3-tiles monoliths
* fixed crash with flaggable building next to map edge
* fixed some descriptions for events
* New objects supported:
** Buoy
** Creature Generators
** Flotsam
** Mermaid
** Ocean bottle
** Sea Chest 
** Shipwreck Survivor
** Shipyard
** Sirens 

# 0.71 -> 0.72 (Jun 1 2009)

### GENERAL:
* many sound effects and music
* autosave (to 5 subsequent files)
* artifacts support (most of them)
* added internal game console (activated on TAB)
* fixed 8 hero limit to check only for wandering heroes (not garrisoned)
* improved randomization
* fixed crash on closing application
* VCMI won't always give all three stacks in the starting armies
* fix for drawing starting army creatures count
* Diplomacy secondary skill support
* timed events won't cause resources amount to be negative
* support for sorcery secondary skill
* reduntant quotation marks from artifact descriptions are removed
* no income at the first day

### ADVENTURE INTERFACE:
* fixed crasbug occurring on revisiting objects (by pressing space)
* always restoring default cursor when movng mouse out of the terrain
* fixed map scrolling with ctrl+arrows when some windows are opened
* clicking scrolling arrows in town/hero list won't open town/hero window
* pathfinder will now look for a path going via printed positions of roads when it's possible
* enter can be used to open window with selected hero/town

### BATTLES:
* many creatures special skills implemented
* battle will end when one side has only war machines
* fixed some problems with handling obstacles info
* fixed bug with defending / waiting while no stack is active
* spellbook button is inactive when hero cannot cast any spell
* obstacles will be placed more properly when resolution is different than 800x600
* canceling of casting a spell by pressing Escape or R-click (R-click on a creatures does not cancel a spell)
* spellbook cannot be opened by L-click on hero in battle when it shouldn't be possible
* new spells:
** frost ring
** fireball
** inferno
** meteor shower
** death ripple
** destroy undead
** dispel
** armageddon
** disrupting ray
** protection from air
** protection from fire
** protection from water
** protection from earth
** precision
** slayer

### TOWNS:
* resting in town with mage guild will replenih all the mana points
* fixed Blacksmith
* the number of creatures at the beginning of game is their base growth
* it's possible to enter Tavern via Brotherhood of Sword

### HERO WINDOW:
* fixed mana limit info in the hero window
* war machines can't be removed
* fixed problems with removing artifacts when all visible slots in backpack are full

### PREGAME:
* clicking on "advanced options" a second time now closes the tab instead of refreshing it.
* Fix position of maps names. 
* Made the slider cursor much more responsive. Speedup the map select screen.
* Try to behave when no maps/saves are present.
* Page Up / Page Down / Home / End hotkeys for scrolling through scenarios / games list

### OBJECTS:
* Neutral creatures can join or escape depending on hero strength (escape formula needs to be improved)
* leaving guardians in flagged mines.
* support for Scholar object
* support for School of Magic
* support for School of War
* support for Pillar of Fire
* support for Corpse
* support for Lean To
* support for Wagon
* support for Warrior's Tomb
* support for Event
* Corpse (Skeleton) will be accessible from all directions

# 0.7 -> 0.71 (Apr 01 2009)

### GENERAL:
* fixed scrolling behind window problem (now it's possible to scroll with CTRL + arrows) 
* morale/luck system and corresponding sec. skills supported 
* fixed crash when hero get level and has less than two sec. skills to choose between 
* added keybindings for components in selection window (eg. for treasure chest dialog): 1, 2, and so on. Selection dialog can be closed with Enter key
* proper handling of custom portraits of heroes
* fixed problems with non-hero/town defs not present in def list but present on map (occurring probably only in case of def substitution in map editor)
* fixed crash when there was no hero available to hire for some player 
* fixed problems with 1024x600 screen resolution
* updating blockmap/visitmap of randomized objects 
* fixed crashes on loading maps with flag all mines/dwelling victory condition
* further fixes for leveling-up (stability and identical offered skills bug)
* splitting window allows to rebalance two stack with the same creatures
* support for numpad keyboard
* support for timed events

### ADVENTURE INTERFACE:
* added "Next hero" button functionality
* added missing path arrows
* corrected centering on hero's position 
* recalculating hero path after reselecting hero
* further changes in pathfinder making it more like original one
* orientation of hero can't be change if movement points are exhausted 
* campfire, borderguard, bordergate, questguard will be accessible from the top
* new movement cost calculation algorithm
* fixed sight radious calculation
* it's possible to stop hero movement
* faster minimap refreshing 
* provisional support for "Save" button in System Options Window
* it's possible to revisit object under hero by pressing Space

### BATTLES:
* partial support for battle obstacles
* only one spell can be casted per turn
* blocked opening sepllbook if hero doesn't have a one
* spells not known by hero can't be casted 
* spell books won't be placed in War Machine slots after battle
* attack is now possible when hex under cursor is not displayed 
* glowing effect of yellow border around creatures
* blue glowing border around hovered creature
* made animation on battlefield more smooth
* standing stacks have more static animation
* probably fixed problem with displaying corpses on battlefield
* fixes for two-hex creatures actions
* fixed hero casting spell animation
* corrected stack death animation
* battle settings will be remembered between battles
* improved damage calculation formula
* correct handling of flying creatures in battles
* a few tweaks in battle path/available hexes calculation (more of them is needed)
* amounts of units taking actions / being an object of actions won't be shown until action ends
* fixed positions of stack queue and battle result window when resolution is != 800x600 
* corrected duration of frenzy spell which was incorrect in certain cases 
* corrected hero spell casting animation
* better support for battle backgrounds 
* blocked "save" command during battle 
* spellbook displays only spells known by Hero
* New spells supported:
** Mirth
** Sorrow
** Fortune
** Misfortune

### TOWN INTERFACE:
* cannot build more than one capitol
* cannot build shipyard if town is not near water
* Rampart's Treasury requires Miner's Guild 
* minor improvements in Recruitment Window
* fixed crash occurring when clicking on hero portrait in Tavern Window, minor improvements for Tavern Window
* proper updating resdatabar after building structure in town or buying creatures (non 800x600 res)
* fixed blinking resdatabar in town screen when buying (800x600) 
* fixed horde buildings displaying in town hall
* forbidden buildings will be shown as forbidden, even if there are no res / other conditions are not fulfilled

### PREGAME:
* added scrolling scenario list with mouse wheel
* fixed mouse slow downs
* cannot select heroes for computer player (pregame) 
* no crash if uses gives wrong resolution ID number
* minor fixes

### OBJECTS:
* windmill gives 500 gold only during first week ever (not every month)
* After the first visit to the Witch Hut, right-click/hover tip mentions the skill available. 
* New objects supported:
** Prison
** Magic Well
** Faerie Ring
** Swan Pond
** Idol of Fortune
** Fountain of Fortune
** Rally Flag
** Oasis
** Temple
** Watering Hole
** Fountain of Youth
** support for Redwood Observatory
** support for Shrine of Magic Incantation / Gesture / Thought
** support for Sign / Ocean Bottle

### AI PLAYER:
* Minor improvements and fixes.

# 0.64 -> 0.7 (Feb 01 2009)

### GENERAL:
* move some settings to the config/settings.txt file
* partial support for new screen resolutions
* it's possible to set game resolution in pregame (type 'resolution' in the console) 
* /Data and /Sprites subfolders can be used for adding files not present in .lod archives
* fixed crashbug occurring when hero levelled above 15 level
* support for non-standard screen resolutions
* F4 toggles between full-screen and windowed mode
* minor improvements in creature card window
* splitting stacks with the shift+click 
* creature card window contains info about modified speed 

### ADVENTURE INTERFACE:
* added water animation
* speed of scrolling map and hero movement can be adjusted in the System Options Window
* partial handling r-clicks on adventure map

### TOWN INTERFACE:
* the scroll tab won't remain hanged to our mouse position if we move the mouse is away from the scroll bar
* fixed cloning creatures bug in garrisons (and related issues)

### BATTLES:
* support for the Wait command
* magic arrow *really* works
* war machines support partially added
* queue of stacks narrowed
* spell effect animation displaying improvements
* positive/negative spells cannot be cast on hostile/our stacks
* showing spell effects affecting stack in creature info window
* more appropriate coloring of stack amount box when stack is affected by a spell
* battle console displays notifications about wait/defend commands 
* several reported bugs fixed
* new spells supported:
** Haste
** lightning bolt
** ice bolt
** slow
** implosion
** forgetfulness
** shield
** air shield
** bless
** curse
** bloodlust
** weakness
** stone skin
** prayer
** frenzy

### AI PLAYER:
* Genius AI (first VCMI AI) will control computer creatures during the combat.

### OBJECTS:
* Guardians property for resources is handled
* support for Witch Hut
* support for Arena
* support for Library of Enlightenment 

And a lot of minor fixes

# 0.63 -> 0.64 (Nov 01 2008)

### GENERAL:
* sprites from /Sprites folder are handled correctly
* several fixes for pathfinder and path arrows
* better handling disposed/predefined heroes
* heroes regain 1 mana point each turn
* support for mistycisim and intelligence skills
* hero hiring possible
* added support for a number of hotkeys
* it's not possible anymore to leave hero level-up window without selecting secondary skill
* many minor improvements

* Added some kind of simple chatting functionality through console. Implemented several WoG cheats equivalents:
** woggaladriel -> vcmiainur
** wogoliphaunt -> vcminoldor
** wogshadowfax -> vcminahar
** wogeyeofsauron -> vcmieagles
** wogisengard -> vcmiformenos
** wogsaruman -> vcmiistari
** wogpathofthedead -> vcmiangband 
** woggandalfwhite -> vcmiglorfindel

### ADVENTURE INTERFACE:
* clicking on a tile in advmap view when a path is shown will not only hide it but also calculate a new one 
* slowed map scrolling 
* blocked scrolling adventure map with mouse when left ctrl is pressed
* blocked map scrolling when dialog window is opened
* scholar will be accessible from the top

### TOWN INTERFACE:
* partially done tavern window (only hero hiring functionality)

### BATTLES:
* water elemental will really be treated as 2 hex creature
* potential infinite loop in reverseCreature removed
* better handling of battle cursor 
* fixed blocked shooter behavior
* it's possible in battles to check remeaining HP of neutral stacks
* partial support for Magic Arrow spell
* fixed bug with dying unit
* stack queue hotkey is now 'Q'
* added shots limit 

# 0.62 -> 0.63 (Oct 01 2008)

### GENERAL:
* coloured console output, logging all info to txt files
* it's possible to use other port than 3030 by passing it as an additional argument
* removed some redundant warnings
* partially done spellbook
* Alt+F4 quits the game
* some crashbugs was fixed
* added handling of navigation, logistics, pathfinding, scouting end estates secondary skill
* magical hero are given spellbook at the beginning
* added initial secondary skills for heroes 

### BATTLES:
* very significant optimization of battles 
* battle summary window
* fixed crashbug occurring sometimes on exiting battle 
* confirm window is shown before retreat 
* graphic stack queue in battle (shows when 'c' key is pressed)
* it's possible to attack enemy hero
* neutral monster army disappears when defeated
* casualties among hero army and neutral creatures are saved
* better animation handling in battles
* directional attack in battles 
* mostly done battle options (although they're not saved)
* added receiving exp (and leveling-up) after a won battle 
* added support for archery, offence and armourer secondary abilities 
* hero's primary skills accounted for damage dealt by creatures in battle

### TOWNS:
* mostly done marketplace 
* fixed crashbug with battles on swamps and rough terrain
* counterattacks 
* heroes can learn new spells in towns
* working resource silo
* fixed bug with the mage guild when no spells available
* it's possible to build lighthouse

### HERO WINDOW:
* setting army formation
* tooltips for artifacts in backpack

### ADVENTURE INTERFACE:
* fixed bug with disappearing head of a hero in adventure map
* some objects are no longer accessible from the top 
* no tooltips for objects under FoW
* events won't be shown
* working Subterranean Gates, Monoliths
* minimap shows all flaggable objects (towns, mines, etc.) 
* artifacts we pick up go to the appropriate slot (if free)

# 0.61 -> 0.62 (Sep 01 2008)

### GENERAL:
* restructured to the server-client model
* support for heroes placed in towns
* upgrading creatures
* working gaining levels for heroes (including dialog with skill selection)
* added graphical cursor
* showing creature amount in the creature info window
* giving starting bonus

### CASTLES:
* icon in infobox showing that there is hero in town garrison
* fort/citadel/castle screen
* taking last stack from the heroes army should be impossible (or at least harder)
* fixed reading forbidden structures
* randomizing spells in towns
* viewing hero window in the town screen
* possibility of moving hero into the garrison
* mage guild screen 
* support for blacksmith
* if hero doesn't have a spell book, he can buy one in a mage guild
* it's possible to build glyph of fear in fortress
* creatures placeholders work properly

### ADVENTURE INTERFACE:
* hopefully fixed problems with wrong town defs (village/fort/capitol)

### HERO WINDOW:
* bugfix: splitting stacks works in hero window
* removed bug causing significant increase of CPU consumption

### BATTLES:
* shooting
* removed some displaying problems
* showing last group of frames in creature animation won't crash
* added start moving and end moving animations
* fixed moving two-hex creatures
* showing/hiding graphic cursor
* a part of using graphic cursor
* slightly optimized showing of battle interface
* animation of getting hit / death by shooting is displayed when it should be
* improved pathfinding in battles, removed problems with displaying movement, adventure map interface won't be called during battles.
* minor optimizations

### PREGAME:
* updates settings when selecting new map after changing sorting criteria
* if sorting not by name, name will be used as a secondary criteria
* when filter is applied a first available map is selected automatically
* slider position updated after sorting in pregame

### OBJECTS:
* support for the Tree of knowledge
* support for Campfires
* added event message when picking artifact

# 0.6 -> 0.61 (Jun 15 2008)

### IMPROVEMENTS:
* improved attacking in the battles
* it's possible to kill hostile stack
* animations won't go in the same phase
* Better pathfinder
* "%s" substitutions in Right-click information in town hall
* windmill won't give wood
* hover text for heroes
* support for ZSoft-style PCX files in /Data
* Splitting: when moving slider to the right so that 0 is left in old slot the army is moved
* in the townlist in castle selected town will by placed on the 2nd place (not 3rd)
* stack at the limit of unit's range can now be attacked
* range of unit is now properly displayed
* battle log is scrolled down when new event occurs
* console is closed when application exits

### BUGFIXES:
* stack at the limit of unit's range can now be attacked
* good background for the town hall screen in Stronghold
* fixed typo in hall.txt
* VCMI won't crash when r-click neutral stack during the battle
* water won't blink behind shipyard in the Castle
* fixed several memory leaks
* properly displaying two-hex creatures in recruit/split/info window
* corrupted map file won't cause crash on initializing main menu

# 0.59 -> 0.6 (Jun 1 2008)

* partially done attacking in battles
* screen isn't now refreshed while blitting creature info window
* r-click creature info windows in battles
* no more division by 0 in slider
* "plural" reference names for Conflux creatures (starting armies of Conflux heroes should now be working)
* fixed estate problems
* fixed blinking mana vortex
* grail increases creature growths
* new pathfinder
* several minor improvements

# 0.58 -> 0.59 (May 24 2008 - closed, test release)

* fixed memory leak in battles
* blitting creature animations to rects in the recruitment window
* fixed wrong creatures def names
* better battle pathfinder and unit reversing
* improved slider ( #58 )
* fixed problems with horde buildings (won't block original dwellings)
* giving primary skill when hero get level (but there is still no dialog)
* if an upgraded creature is available it'll be shown as the first in a recruitment window
* creature levels not messed in Fortress
* war machines are added to the hero's inventory, not to the garrison
* support for H3-style PCX graphics in Data/
* VCMI won't crash when is unable to initialize audio system
* fixed displaying wrong town defs
* improvements in recruitment window (slider won't allow to select more creatures than we can afford)
* creature info window (only r-click)
* callback for buttons/lists based on boost::function
* a lot of minor improvements

# 0.55 -> 0.58 (Apr 20 2008 - closed, test release)

### TOWNS:
* recruiting creatures
* working creature growths (including castle and horde building influences)
* towns give income
* town hall screen
* building buildings (requirements and cost are handled)
* hints for structures
* updating town infobox

### GARRISONS:
* merging stacks
* splitting stacks

### BATTLES:
* starting battles
* displaying terrain, animations of heroes, units, grid, range of units, battle menu with console, amounts of units in stacks
* leaving battle by pressing flee button
* moving units in battles and displaying their ranges
* defend command for units

### GENERAL:
* a number of minor fixes and improvements

# 0.54 -> 0.55 (Feb 29 2008)

* Sprites/ folder works for h3sprite.lod same as Data/ for h3bitmap.lod (but it's still experimental)
* randomization quantity of creatures on the map
* fix of Pandora's Box handling
* reading disposed/predefined heroes
* new command - "get txt" - VCMI will extract all .txt files from h3bitmap.lod to the Extracted_txts/ folder.
* more detailed logs
* reported problems with hero flags resolved
* heroes cannot occupy the same tile
* hints for most of creature generators
* some minor stuff

# 0.53b -> 0.54 (Feb 23 2008 - first public release)
* given hero is placed in the town entrance
* some objects such as river delta won't be blitted "on" hero
* tiles under FoW are inaccessible
* giving random hero on RoE maps
* improved protection against hero duplication
* fixed starting values of primary abilities of random heroes on RoE/AB maps
* right click popups with infoboxes for heroes/towns lists
* new interface coloring (many thanks to GrayFace ;])
* fixed bug in object flag's coloring
* added hints in town lists
* eliminated square from city hints

# 0.53 - 0.53b (Feb 20 2008)

* added giving default buildings in towns
* town infobox won't crash on empty town

# 0.52 - 0.53 (Feb 18 2008):

* hopefully the last bugfix of Pandora's Box
* fixed blockmaps of generated heroes
* disposed hero cannot be chosen in scenario settings (unless he is in prison)
* fixed town randomization
* fixed hero randomization
* fixed displaying heroes in preGame
* fixed selecting/deselecting artifact slots in hero window
* much faster pathfinder
* memory usage and load time significantly decreased
* it's impossible to select empty artifact slot in hero window
* fixed problem with FoW displaying on minimap on L-sized maps
* fixed crashbug in hero list connected with heroes dismissing
* mostly done town infobox
* town daily income is properly calculated

# 0.51 - 0.52 (Feb 7 2008):

* [feature] giving starting hero
* [feature] VCMI will try to use files from /Data folder instead of those from h3bitmap.lod
* [feature] picked artifacts are added to hero's backpack
* [feature] possibility of choosing player to play
* [bugfix] ZELP.TXT file *should* be handled correctly even it is non-english
* [bugfix] fixed crashbug in reading defs with negativ left/right margins
* [bugfix] improved randomization
* [bugfix] pathfinder can't be cheated (what caused errors)

# 0.5 - 0.51 (Feb 3 2008):

* close button properly closes (same does 'q' key)
* two players can't have selected same hero
* double click on "Show Available Scenarios" won't reset options
* fixed possible crashbug in town/hero lists
* fixed crashbug in initializing game caused by wrong prisons handling
* fixed crashbug on reading hero's custom artifacts in RoE maps
* fixed crashbug on reading custom Pandora's Box in RoE maps
* fixed crashbug on reading blank Quest Guards
* better console messages
* map reading speed up (though it's still slow, especially on bigger maps)

# 0.0 -> 0.5 (Feb 2 2008 - first closed release):

* Main menu and New game screens
* Scenario selection, part of advanced options support
* Partially done adventure map, town and hero interfaces
* Moving hero
* Interactions with several objects (mines, resources, mills, and others)