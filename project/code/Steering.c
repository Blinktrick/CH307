#include "Steering.h"

uint16 Duoji_Duty;
Duoji_Para Serve;


//--------------------------------------------------------------
//  @brief     位置式PD舵机控制
//  @param     PID_2 *vPID                       PID结构体
//             processValue                      图像误差
//  @return    void        没有欸
//  @note      位置式PD
//--------------------------------------------------------------
__attribute__((optimize(2)))void Duoji_Control( Duoji_Para *Duoji, float processValue)
{

    float thisError;
    float result         = 0;
    static float lasterror = 0;

    thisError = 0 - processValue;

    Duoji->KP = Fabs(thisError) * Duoji->Kp_Gain + Duoji->Base;
    Duoji->KD = Duoji->Kd_Gain * Duoji->KP;

    // KP_kx_b     = ((Fabs(((FExp(-Fabs(thisError / 8)) - 1)) / ((FExp(-Fabs(thisError / 8)) + 1)))) / 2 + 0.5) * Duoji->Bias;
    // Duoji->KP_V = (1 - powf((1 + 1 / Duoji->b), (-error_ave / 6))) * Duoji->bas_kp + Duoji->KP_fix;

    result = Duoji->KP * thisError + Duoji->KD * (thisError - lasterror);
    lasterror  = thisError;
    Duoji_Duty = Duoji_Duty_Midmum + result;
    Duoji_Duty = MINMAX(Duoji_Duty, Duoji_Duty_Minimum, Duoji_Duty_Maximum);
    pwm_set_duty(DUOJI_CHANY, Duoji_Duty);
}

// 陀螺仪补偿方法
//      steer_drive->pid_CamOut = (int32)(steer_Kp * steer_drive->steer_pid.mt9v03x_Error_Cam[0]
//                               + steer_Kd * (steer_drive->steer_pid.mt9v03x_Error_Cam[0] - steer_drive->steer_pid.mt9v03x_Error_Cam[1])
//                               + (icm_gyro_y - Gyro_VAL) * steer_drive->steer_pid.straight_Imu_p);//★★★★★

//   //  if(steer_drive->pid_CamOut > -5  && steer_drive->pid_CamOut < 5)     steer_drive->pid_CamOut = 0;

//     steer_drive->pid_PwmOut = steer_drive->steer_center - steer_drive->pid_CamOut;//舵机反转则改+-
