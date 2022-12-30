#ifndef GUARD_VS_SEEKER_H
#define GUARD_VS_SEEKER_H

#include "global.h"

void Task_VsSeeker_0(u8 taskId);
void ClearRematchStateByTrainerId(void);
void ClearRematchStateOfLastTalked(void);
int GetRematchTrainerId(u16 trainerId);
bool8 UpdateVsSeekerStepCounter(void);
void MapResetTrainerRematches(u8 mapGroup, u8 mapNum);

#endif //GUARD_VS_SEEKER_H
