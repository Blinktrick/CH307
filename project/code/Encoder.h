#ifndef __ENCODER_H__
#define __ENCODER_H__

#include "zf_common_headfile.h"
#include "headfile.h"

extern int16 encoder_1;
extern int16 encoder_2;

extern float dt_Position;

extern int64 LeftMotor_TotalEncoder;
extern int64 RightMotor_TotalEncoder;
extern const int64 EncoderPerMeter;

void Get_Speed(void);
void EncoderCount(void);
int64 GetEncoder(void);

#endif