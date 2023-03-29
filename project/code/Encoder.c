#include "Encoder.h"

int16 encoder_1 = 0;
int16 encoder_2 = 0;

/*测距离*/
const int64 EncoderPerMeter   = 11500; // 速度控制变量 原：tc264 speed.c
int64 LeftMotor_TotalEncoder  = 0;
int64 RightMotor_TotalEncoder = 0;

float dt_Position = 0.02; // 位置环周期

void Get_Speed(void)
{

    encoder_1 = encoder_get_count(TIM1_ENCOEDER); // 获取编码器计数

    encoder_2 = -encoder_get_count(TIM9_ENCOEDER); // 获取编码器计数

    if (encoder_1 < 0)
        encoder_1 = -encoder_1;
    if (encoder_2 < 0)
        encoder_2 = -encoder_2;

    encoder_1 = (uint8)encoder_1;
    encoder_2 = (uint8)encoder_2;

    encoder_clear_count(TIM1_ENCOEDER); // 定时器清空        左轮
    encoder_clear_count(TIM9_ENCOEDER); // 定时器清空        右轮
}

// 用编码器计算里程
void EncoderCount(void)
{
    LeftMotor_TotalEncoder += encoder_1;
    RightMotor_TotalEncoder += encoder_2;
}

// 获取测里程(米)
int64 GetEncoder(void)
{
    return (LeftMotor_TotalEncoder + RightMotor_TotalEncoder) / 2 / EncoderPerMeter;
}
