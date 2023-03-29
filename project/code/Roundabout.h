/*
 * Roundabout.h
 *
 *  Created on: 2022��2��24��
 *      Author: kare
 */

#ifndef _ROUNDABOUT_H_
#define _ROUNDABOUT_H_
#include "zf_common_headfile.h"
#include "headfile.h"
#include "imgStruct.h"

//#define ROUNDABOUT_NONE 0
//#define ROUNDABOUT_BEGIN 1
//#define ROUNDABOUT_IN 2
//#define ROUNDABOUT_MID 3
//#define ROUNDABOUT_OUT 4
//#define ROUNDABOUT_END 5

typedef enum
{
    ROUNDABOUT_NONE,
    ROUNDABOUT_BEGIN,
    ROUNDABOUT_IN,
    ROUNDABOUT_MID,
    ROUNDABOUT_OUT,
    ROUNDABOUT_END
}RoundaboutStatus;

typedef enum
{
    SMALL_ROUNDABOUT,
    BIG_ROUNDABOUT
}RoundaboutSize;


void Check_RightRoundabout(TRACK_BORDER_INFO *p_Border, TRACK_TYPE_INFO *p_Type);

void Check_MIDRightRoundabout(uint8 (*InImg)[IMGW], TRACK_BORDER_INFO *p_Border, TRACK_TYPE_INFO *p_Type, LINE_ERROR_INFO *p_Error);

void FindRightRemoteCornerRD(uint8 (*InImg)[IMGW], TRACK_BORDER_INFO *p_Border);

void Check_LeftRoundabout(TRACK_BORDER_INFO *p_Border, TRACK_TYPE_INFO *p_Type);

//无环岛的情况下，判断是否满足条件，用于未进入环岛一阶段直接入环
//1. 右边直线
//2. 左边远端L型拐点
//3. 左边近端有线但没有拐点
//4. 左线曲率偏差 < -0.55 ?
void Check_MIDLeftRoundabout(uint8 (*InImg)[IMGW], TRACK_BORDER_INFO *p_Border, TRACK_TYPE_INFO *p_Type, LINE_ERROR_INFO *p_Error);

void FindLeftRemoteCornerRD(uint8 (*InImg)[IMGW], TRACK_BORDER_INFO *p_Border);


uint8 CheckLocalMaximum(INT_POINT_INFO PointIN[], uint8 pointDirection[], int16 PointNum, int16 kernelSize, int16 *LocalMaximumPos);
uint8 CheckLocalMinimum(INT_POINT_INFO PointIN[], uint8 pointDirection[], int16 PointNum, int16 kernelSize, int16 *LocalMinimumPos);

#endif /* CODE_ROUNDABOUT_H_ */
