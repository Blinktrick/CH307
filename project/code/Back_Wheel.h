#ifndef __BACK_WHEEL_H__
#define __BACK_WHEEL_H__

#include "zf_common_headfile.h"

#include "headfile.h"

#define MOTOR1_DIR                (D12)
#define MOTOR1_PWM                (TIM4_PWM_MAP1_CH2_D13)
#define MOTOR2_DIR                (D15)
#define MOTOR2_PWM                (TIM4_PWM_MAP1_CH3_D14)

#define Distance_Col              0.200 // 车身的前后轮中心距

#define Distance_Row              0.155 // 两后轮中心距

#define MIN(a, b)                 (((a) < (b)) ? (a) : (b))
#define MAX(a, b)                 (((a) > (b)) ? (a) : (b))
#define MINMAX(input, low, upper) MIN(MAX(input, low), upper)

/*定义PID对象类型*/
typedef struct // 位置型普通PID
{
    float maximum;   /*输出值上限*/
    float minimum;   /*输出值下限*/
    float setpoint;  // 设定值
    float result;    // 输出值
    float integral;  // 积分值

} PID_1;

typedef struct // 增量型普通PID
{
    float maximum;     /*输出值上限*/
    float minimum;     /*输出值下限*/
    float setpoint;    // 设定值

    float result;     // 输出值
    float integral;   // 积分值
    float derivative; // 微分值

} PID_2;

typedef struct // 后轮结构体参数
{
    // 变积分参数
    float L_Max_I;
    float L_Ci;

    float R_Max_I;
    float R_Ci;

    // 变比例参数
    float L_Bas_KP;
    float L_Gain_KP;
    float L_Cp;

    float R_Bas_KP;
    float R_Gain_KP;
    float R_Cp;

    enum {  //枚举
        MODE_NORMAL,
        MODE_BANGBANG,
        MODE_SOFT,
    } motor_mode;

} Motor_Para;

typedef struct // 差速结构体参数
{
    float K;       // 补偿系数
    float maximun; // 差速最大值
    float minimum; // 差速最小值

} Chasu_Para;

extern PID_2 Motor_Left;  // 左轮变量
extern PID_2 Motor_Right; // 右轮变量
extern Motor_Para MOTOR;  // PID参数结构体

extern Chasu_Para CHASU; // 差速参数结构体

extern uint8 Speed_Bia;


void Back_Wheel_Out(int32 R_outPWM, int32 L_outPWM);
void Motor_L_Control(PID_2 *vPID, Motor_Para *Motor, int16 processValue);
void Motor_R_Control(PID_2 *vPID, Motor_Para *Motor, int16 processValue);
void Motor_L_Control_Position(PID_2 *vPID, Motor_Para *Motor, int16 processValue);
void Motor_R_Control_Position(PID_2 *vPID, Motor_Para *Motor, int16 processValue);
void Motor_L_Control_Position_Advance_differential(PID_2 *vPID, Motor_Para *Motor, int16 processValue);

uint16 BetaGeneration(float error, float epsilon);
float errorfilter(float inData, float a);
float data_filtering(float *filter, const float filter_data, const uint8 filter_depth);
float Filter_ave_DuojiData(float value, uint8 time);

__attribute__((optimize(2)))void Motor_L_Control_Change_Integral(float32 setpoint, PID_2 *vPID, Motor_Para *Motor, int16 processValue);
__attribute__((optimize(2)))void Motor_R_Control_Change_Integral(float32 setpoint, PID_2 *vPID, Motor_Para *Motor, int16 processValue);

int16 Differrntial(Chasu_Para *Diff);

//----------------------------------------------------------我是分割线-------------------------------------------------------------//
//----------------------------------------------------------我是分割线-------------------------------------------------------------//
//----------------------------------------------------------我是分割线-------------------------------------------------------------//
//----------------------------------------------------------我是分割线-------------------------------------------------------------//
// PIDģ模板

////普通位置型PID(梯形积分)
// void PIDRegulation_1(PID_1 *vPID, float processValue)
//{
//
//     float thisError;
//     float result;
//     thisError = vPID->setpoint - processValue;
//     if (fabs(thisError) > vPID->deadband) {
//         vPID->integral += (thisError + vPID->lasterror) / 2;
//         result = vPID->proportiongain * thisError + vPID->integralgain * vPID->integral + vPID->derivativegain * (thisError - vPID->lasterror);
//
//     } else {
//         if ((abs(vPID->setpoint - vPID->minimum) < vPID->deadband) && (abs(processValue - vPID->minimum) < vPID->deadband)) {
//             result = vPID->minimum;
//         }
//     }
//     /*对输出限幅，避免超调和积分饱和问题*/
//     if (result >= vPID->maximum) {
//         result = vPID->maximum;
//     }
//     if (result <= vPID->minimum) {
//         result = vPID->minimum;
//     }
//     vPID->lasterror = thisError;
//     vPID->result = result;
//     vPID->output = ((result - vPID->minimum) / (vPID->maximum - vPID->minimum)) * 100.0;
// }

// 普通增量型PID(梯形积分)
// void PIDRegulation_2 (PID_2 *vPID, float processValue)
//{
//     float thisError;
//     float result;
//     float increment;
//     float pError, dError, iError;
//
//     thisError = vPID->setpoint - processValue; //得到偏差值
//     result = vPID->result;
//
//     if (fabs(thisError) > vPID->deadband)
//     {
//         pError = thisError - vPID->lasterror;
//         iError = (thisError + vPID->lasterror) / 2.0;
//         dError = thisError - 2 * (vPID->lasterror) + vPID->preerror;
//
//         increment = vPID->proportiongain * pError + vPID->integralgain * iError + vPID->derivativegain * dError;
//     }
//     else
//     {
//         if ((fabs(vPID->setpoint - vPID->minimum) < vPID->deadband)
//                 && (fabs(processValue - vPID->minimum) < vPID->deadband))
//         {
//             result = vPID->minimum;
//         }
//         increment = 0.0;
//     }
//     result = result + increment;
//
//     /*对输出限值，避免超调和积分饱和问题*/
//     if (result >= vPID->maximum)
//     {
//         result = vPID->maximum;
//     }
//     if (result <= vPID->minimum)
//     {
//         result = vPID->minimum;
//     }
//
//     vPID->preerror = vPID->lasterror; //存放偏差用于下次运算
//     vPID->lasterror = thisError;
//     vPID->result = result;
//     vPID->output = ((result - vPID->minimum) / (vPID->maximum - vPID->minimum)) * 100.0;
// }

#endif
