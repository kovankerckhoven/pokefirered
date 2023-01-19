#ifndef GUARD_OVERWORLD_H
#define GUARD_OVERWORLD_H

#include "global.h"
#include "main.h"

#define LINK_KEY_CODE_NULL 0x00
#define LINK_KEY_CODE_EMPTY 0x11
#define LINK_KEY_CODE_DPAD_DOWN 0x12
#define LINK_KEY_CODE_DPAD_UP 0x13
#define LINK_KEY_CODE_DPAD_LEFT 0x14
#define LINK_KEY_CODE_DPAD_RIGHT 0x15
#define LINK_KEY_CODE_READY 0x16
#define LINK_KEY_CODE_EXIT_ROOM 0x17
#define LINK_KEY_CODE_START_BUTTON 0x18
#define LINK_KEY_CODE_A_BUTTON 0x19
#define LINK_KEY_CODE_IDLE 0x1A

// These two are a hack to stop user input until link stuff can be
// resolved.
#define LINK_KEY_CODE_HANDLE_RECV_QUEUE 0x1B
#define LINK_KEY_CODE_HANDLE_SEND_QUEUE 0x1C

#define LINK_KEY_CODE_EXIT_SEAT 0x1D

#define MOVEMENT_MODE_FREE 0
#define MOVEMENT_MODE_FROZEN 1
#define MOVEMENT_MODE_SCRIPTED 2

struct LinkPlayerObjectEvent
{
    u8 active;
    u8 linkPlayerId;
    u8 objEventId;
    u8 movementMode;
};

struct CreditsOverworldCmd
{
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
};

/* gDisableMapMusicChangeOnMapLoad */
#define MUSIC_DISABLE_OFF 0
#define MUSIC_DISABLE_STOP 1
#define MUSIC_DISABLE_KEEP 2

#define MAPGROUPS_SPECIAL_START     0 // Link & SpecialArea
#define MAPGROUPS_KANTO_START       2 // https://pokemon.fandom.com/wiki/Kanto
#define MAPGROUPS_SEVII_START       5 // Sevii Islands (https://pokemon.fandom.com/wiki/Sevii_Islands)
#define MAPGROUPS_JOHTO_START       8 // https://pokemon.fandom.com/wiki/Johto
#define MAPGROUPS_HOENN_START       11 // https://pokemon.fandom.com/wiki/Hoenn
#define MAPGROUPS_SINNOH_START      14 // https://pokemon.fandom.com/wiki/Sinnoh (old name "Hisui": https://pokemon.fandom.com/wiki/Hisui)
#define MAPGROUPS_UNOVA_START       17 // https://pokemon.fandom.com/wiki/Unova "New York/New Jersey"
#define MAPGROUPS_KALOS_START       20 // https://pokemon.fandom.com/wiki/Kalos "France"
#define MAPGROUPS_ALOLA_START       23 // https://pokemon.fandom.com/wiki/Alola "Hawaii?"
#define MAPGROUPS_GALAR_START       26 // https://pokemon.fandom.com/wiki/Galar "United Kingdom"
#define MAPGROUPS_PALDEA_START      29 // https://pokemon.fandom.com/wiki/Paldea "Iberia"
#define MAPGROUPS_ORANGE_START      32 // Orange Islands (https://pokemon.fandom.com/wiki/Orange_Islands)
#define MAPGROUPS_BLUE_START        35 // Blue Islands near Hoehn?
#define MAPGROUPS_ORRE_START        38 // https://pokemon.fandom.com/wiki/Orre "Arizona desert"
#define MAPGROUPS_FIORE_START       41 // https://pokemon.fandom.com/wiki/Fiore "Italy?"
#define MAPGROUPS_ALMIA_START       44 // https://pokemon.fandom.com/wiki/Almia
#define MAPGROUPS_OBLIVIA_START     47 // https://pokemon.fandom.com/wiki/Oblivia
#define MAPGROUPS_RANSEI_START      50 // https://pokemon.fandom.com/wiki/Ransei
#define MAPGROUPS_PASIO_START       53 // https://pokemon.fandom.com/wiki/Pasio
#define MAPGROUPS_LENTAL_START      56 // https://pokemon.fandom.com/wiki/Lental
#define MAPGROUPS_AEOS_START        59 // Aeos Island (https://pokemon.fandom.com/wiki/Aeos_Island)
#define MAPGROUPS_DECOLORE_START    62 // Decolore Islands (https://pokemon.fandom.com/wiki/Decolore_Islands)

enum {
    REGION_NONE, // Link & SpecialArea + fallthrough
    REGION_KANTO, // https://pokemon.fandom.com/wiki/Kanto
    REGION_SEVII, // Sevii Islands (https://pokemon.fandom.com/wiki/Sevii_Islands)
    REGION_JOHTO, // https://pokemon.fandom.com/wiki/Johto
    REGION_HOENN, // https://pokemon.fandom.com/wiki/Hoenn
    REGION_SINNOH, // https://pokemon.fandom.com/wiki/Sinnoh (old name "Hisui": https://pokemon.fandom.com/wiki/Hisui)
    REGION_UNOVA, // https://pokemon.fandom.com/wiki/Unova "New York/New Jersey"
    REGION_KALOS, // https://pokemon.fandom.com/wiki/Kalos "France"
    REGION_ALOLA, // https://pokemon.fandom.com/wiki/Alola "Hawaii?"
    REGION_GALAR, // https://pokemon.fandom.com/wiki/Galar "United Kingdom"
    REGION_PALDEA, // https://pokemon.fandom.com/wiki/Paldea "Iberia"
    REGION_ORANGE, // Orange Islands (https://pokemon.fandom.com/wiki/Orange_Islands)
    REGION_BLUE, // Blue Islands near Hoehn?
    REGION_ORRE, // https://pokemon.fandom.com/wiki/Orre "Arizona desert"
    REGION_FIORE, // https://pokemon.fandom.com/wiki/Fiore "Italy?"
    REGION_ALMIA, // https://pokemon.fandom.com/wiki/Almia
    REGION_OBLIVIA, // https://pokemon.fandom.com/wiki/Oblivia
    REGION_RANSEI, // https://pokemon.fandom.com/wiki/Ransei
    REGION_PASIO, // https://pokemon.fandom.com/wiki/Pasio
    REGION_LENTAL, // https://pokemon.fandom.com/wiki/Lental
    REGION_AEOS, // Aeos Island (https://pokemon.fandom.com/wiki/Aeos_Island)
    REGION_DECOLORE, // Decolore Islands (https://pokemon.fandom.com/wiki/Decolore_Islands)
    // TODO: Other regions still possible?
};

extern const struct Coords32 gDirectionToVectors[];

extern struct LinkPlayerObjectEvent gLinkPlayerObjectEvents[4];
extern MainCallback gFieldCallback;

extern struct WarpData gLastUsedWarp;

extern u8 gExitStairsMovementDisabled;
extern u8 gFieldLinkPlayerCount;
extern u8 gLocalLinkPlayerId;

void IncrementGameStat(u8 index);

void SetObjEventTemplateCoords(u8, s16, s16);
void SetObjEventTemplateMovementType(u8, u8);

void SetWarpDestination(u8 mapGroup, u8 mapNum, s8 warpId, s16 x, s16 y);

void SetDynamicWarp(s32 unused, u8 mapGroup, u8 mapNum, s8 warpId);
void SetDynamicWarpWithCoords(s32 unused, u8 mapGroup, u8 mapNum, s8 warpId, s16 x, s16 y);
void SetFixedDiveWarp(u8 mapGroup, u8 mapNum, s8 warpId, s16 x, s16 y);
void SetFixedHoleWarp(u8 mapGroup, u8 mapNum, s8 warpId, s16 x, s16 y);
void SetEscapeWarp(u8 mapGroup, u8 mapNum, s8 warpId, s16 x, s16 y);
void Overworld_SetHealLocationWarp(u8);
void SetWarpDestinationToEscapeWarp(void);
void SetWarpDestinationToLastHealLocation(void);
u8 IsMapTypeOutdoors(u8 mapType);
void Overworld_ClearSavedMusic(void);
bool32 Overworld_MusicCanOverrideMapMusic(u16 song);

void SetFlashLevel(s32 a1);
u8 Overworld_GetFlashLevel(void);

void Overworld_SetSavedMusic(u16);
void Overworld_ChangeMusicToDefault(void);
void Overworld_ChangeMusicTo(u16);

bool32 IsUpdateLinkStateCBActive(void);

void ClearLinkPlayerObjectEvents(void);
const struct MapHeader *const Overworld_GetMapHeaderByGroupAndId(u8, u8);
const struct MapHeader *const GetDestinationWarpMapHeader(void);
const u8 Overworld_GetRegionByGroup(u8 mapGroup);
void ObjectEventMoveDestCoords(struct ObjectEvent *, u32, s16 *, s16 *);
void CB2_ReturnToField(void);
void CB2_ReturnToFieldContinueScriptPlayMapMusic(void);
void WarpIntoMap(void);
u8 GetMapTypeByGroupAndId(u8 mapGroup, u8 mapNum);
void SetWarpDestinationToMapWarp(u8 mapGroup, u8 mapNum, s8 warpNum);
void SetWarpDestinationToDynamicWarp(u8 unused);

u32 GetGameStat(u8 statId);
void SetGameStat(u8 statId, u32 value);

void CB2_ContinueSavedGame(void);
void Overworld_SetWarpDestinationFromWarp(struct WarpData *);
void CB2_SetUpOverworldForQLPlayback(void);
void CB2_SetUpOverworldForQLPlaybackWithWarpExit(void);
void CB2_EnterFieldFromQuestLog(void);
void Overworld_PlaySpecialMapMusic(void);

u16 GetCurrentRegionMapSectionId(void);

void SetCurrentMapLayout(u16 mapLayoutId);
void SetWarpDestinationToFixedHoleWarp(s16 x, s16 y);

void ResetInitialPlayerAvatarState(void);
void CleanupOverworldWindowsAndTilemaps(void);
u32 ComputeWhiteOutMoneyLoss(void);

extern u8 gDisableMapMusicChangeOnMapLoad;
extern u8 gGlobalFieldTintMode;

extern bool8 (* gFieldCallback2)(void);

void SetLastHealLocationWarp(u8 healLocaionId);
void LoadMapFromCameraTransition(u8 mapGroup, u8 mapNum);
void CB2_ReturnToFieldFromDiploma(void);
void CB2_OverworldBasic(void);
void CB2_NewGame(void);
bool8 IsMapTypeOutdoors(u8 mapType);
bool8 Overworld_MapTypeAllowsTeleportAndFly(u8 mapType);
void Overworld_ResetStateAfterTeleport(void);

void Overworld_FadeOutMapMusic(void);
void CB2_LoadMap(void);
bool8 BGMusicStopped(void);
bool8 IsMapTypeIndoors(u8 mapType);
bool32 Overworld_IsBikingAllowed(void);
void Overworld_ResetStateAfterDigEscRope(void);
bool32 Overworld_LinkRecvQueueLengthMoreThan2(void);
u8 GetCurrentMapType(void);

u8 GetLastUsedWarpMapType(void);
void TryFadeOutOldMapMusic(void);
void CB2_ReturnToFieldCableClub(void);
void ResetGameStats(void);

void Overworld_CreditsMainCB(void);
bool32 Overworld_DoScrollSceneForCredits(u8 *, const struct CreditsOverworldCmd *, u8);

bool32 IsSendingKeysOverCable(void);

void CB2_ReturnToFieldWithOpenMenu(void);
void CB2_WhiteOut(void);
void CB2_ReturnToFieldFromMultiplayer(void);
void ApplyNewEncryptionKeyToGameStats(u32 newKey);
void SetContinueGameWarpToDynamicWarp(int);

void SetContinueGameWarpToHealLocation(u8 loc);

void UpdateAmbientCry(s16 *state, u16 *delayCounter);
void SetWarpDestinationToHealLocation(u8 a0);
bool32 Overworld_SendKeysToLinkIsRunning(void);
bool32 Overworld_RecvKeysFromLinkIsRunning(void);
void OverworldWhiteOutGetMoneyLoss(void);
u8 GetCurrentMapBattleScene(void);
void Overworld_ResetStateAfterFly(void);
bool8 MetatileBehavior_IsSurfableInSeafoamIslands(u16 metatileBehavior);
void Overworld_ResetMapMusic(void);
u16 QueueExitLinkRoomKey(void);
u16 SetInCableClubSeat(void);
u32 GetCableClubPartnersReady(void);
u16 SetStartedCableClubActivity(void);
u16 SetLinkWaitingForScript(void);
void SetMainCallback1(MainCallback cb);
void CB1_Overworld(void);
void CB2_ReturnToFieldContinueScript(void);
u16 GetLastUsedWarpMapSectionId(void);
void StoreInitialPlayerAvatarState(void);
void UpdateEscapeWarp(s16 x, s16 y);
bool8 SetDiveWarpEmerge(s16 x, s16 y);
bool8 SetDiveWarpDive(s16 x, s16 y);

extern u16 *gBGTilemapBuffers1;
extern u16 *gBGTilemapBuffers2;
extern u16 *gBGTilemapBuffers3;
extern u16 gHeldKeyCodeToSend;

#endif //GUARD_OVERWORLD_H
