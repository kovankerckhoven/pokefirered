#ifndef GUARD_HEAL_LOCATION_H
#define GUARD_HEAL_LOCATION_H

#include "global.h"

struct HealLocation
{
    u8 group;
    u8 map;
    s16 x;
    s16 y;
};

const struct HealLocation *GetHealLocation(u32 loc); // TODO: Can this become u8 loc?
void SetWhiteoutRespawnWarpAndHealerNpc(struct WarpData * warp);

#endif // GUARD_HEAL_LOCATION_H
