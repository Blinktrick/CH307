#ifndef __INITALL_H__
#define __INITALL_H__

#include "zf_common_headfile.h"
#include "headfile.h"
#include "imgStruct.h"

#define LED1           (H2)

#define PIT            (TIM6_PIT)
#define PIT_PRIORITY   (TIM6_IRQn)
#define PIT_2          (TIM7_PIT)
#define PIT_PRIORITY_2 (TIM7_IRQn)

#define S_MOTOR_PIN    ATOM1_CH1_P33_9

extern int8 start_flag;

void INITALL(void);

#endif