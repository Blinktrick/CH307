#ifndef __STEERING_H__
#define __STEERING_H__

#include "zf_common_headfile.h"
#include "headfile.h"

#define DUOJI_CHANY        TIM2_PWM_MAP3_CH1_A15

#define Duoji_Duty_Maximum (805)
#define Duoji_Duty_Midmum  (732)
#define Duoji_Duty_Minimum (665)

#define SMOTOR_RATE        (2.4) // 每度所占pwm  26°=60pwm

extern uint16 Duoji_Duty;

typedef struct // 舵机结构体参数
{

    float KP;
    float KD;

    /*变比例*/
    float Kp_Gain;
    float Base;

    /*变微分*/
    float Kd_Gain;

} Duoji_Para;


extern Duoji_Para Serve;


__attribute__((optimize(2)))void Duoji_Control(Duoji_Para *Duoji, float processValue);
//__attribute__((optimize(2)))void Duoji_Control_Advance_differential( Duoji_Para *Duoji, float processValue);

#endif
