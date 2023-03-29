#ifndef __PM_CONTROL_H__
#define __PM_CONTROL_H__

#include "zf_common_headfile.h"
#include "headfile.h"
#include "imgStruct.h"

typedef struct // 位置环结构体参数
{

    float deadband; /*死区*/
    int16 maximum;  /*速度补偿上限*/
    int16 minimum;  /*速度降低下限*/
    float setpoint; // 设定位置

    float result;     // 输出值
    float derivative; // 微分值

    float KP;
    float KD;

    // 变比例参数
    float Bas_KP;
    float Gain_KP;
    float Cp;

    // 变积分参数
    float Max_I;
    float Ci;

} Positon_Para;

extern Positon_Para Position;

extern int16 normal_speed;
extern float32 Avg_speed;

extern int16 V_Bia;

extern float SetLeft;
extern float SetRight;

__attribute__((optimize(2)))void Angle_Control(void);
__attribute__((optimize(2)))void Position_Control(Positon_Para *Position);
__attribute__((optimize(2)))void Speed_Control(void);

#endif
