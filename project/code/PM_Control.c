#include "PM_Control.h"

int16 normal_speed;
float32 Avg_speed;

int16 V_Bia; // 差速

float SetLeft;
float SetRight;

// 位置环
Positon_Para Position;

__attribute__((optimize(2)))void Angle_Control(void)
{
    float32 Img_Error;
    static float32 Img_LastError=0;

    if (g_LineError.m_u8LeftCenterValid == 1 && g_LineError.m_u8RightCenterValid == 1) {
        if ((g_Border.m_i16RCnterCntRS < 3 && g_Border.m_i16LCnterCntRS > 3) || (g_Border.m_i16RCnterCntRSRemote < 3 && g_Border.m_i16LCnterCntRSRemote > 3)) {
            Img_Error = g_LineError.error_Leftangle / SMOTOR_RATE;
        }
        if ((g_Border.m_i16LCnterCntRS < 3 && g_Border.m_i16RCnterCntRS > 3) || (g_Border.m_i16LCnterCntRSRemote < 3 && g_Border.m_i16RCnterCntRSRemote > 3)) {
            Img_Error = g_LineError.error_Rightangle / SMOTOR_RATE;
        }
        if ((g_Border.m_i16LCnterCntRS < 3 && g_Border.m_i16RCnterCntRS < 3) || (g_Border.m_i16LCnterCntRSRemote < 3 && g_Border.m_i16RCnterCntRSRemote < 3)) {
            Img_Error = Img_LastError;
        }
        if ((g_Border.m_i16LCnterCntRS>3 && g_Border.m_i16RCnterCntRS > 3) || (g_Border.m_i16LCnterCntRSRemote > 3 && g_Border.m_i16RCnterCntRSRemote > 3)){
            Img_Error = ((g_LineError.error_Leftangle + g_LineError.error_Rightangle) / 2.0) / SMOTOR_RATE;
        }
//        Img_Error = ((g_LineError.error_Leftangle + g_LineError.error_Rightangle) / 2.0) / SMOTOR_RATE;
    } else if (g_LineError.m_u8LeftCenterValid == 1 && g_LineError.m_u8RightCenterValid == 0) {
        if (g_Border.m_i16LCnterCntRS < 3 || g_Border.m_i16LCnterCntRSRemote < 3) {
            Img_Error = Img_LastError;
        }
        if (g_Border.m_i16LCnterCntRS > 3 || g_Border.m_i16LCnterCntRSRemote > 3){
            Img_Error = g_LineError.error_Leftangle / SMOTOR_RATE;
        }
//        Img_Error = g_LineError.error_Leftangle / SMOTOR_RATE;
    } else if (g_LineError.m_u8LeftCenterValid == 0 && g_LineError.m_u8RightCenterValid == 1) {//右边
               if (g_Border.m_i16RCnterCntRS < 3 || g_Border.m_i16RCnterCntRSRemote < 3) {
                    Img_Error = Img_LastError;
                }
               if(g_Border.m_i16RCnterCntRS > 3 || g_Border.m_i16RCnterCntRSRemote > 3){
                    Img_Error = g_LineError.error_Rightangle / SMOTOR_RATE;
                }
//        Img_Error = g_LineError.error_Rightangle / SMOTOR_RATE;
    } else if (g_LineError.m_u8LeftCenterValid == 0 && g_LineError.m_u8RightCenterValid == 0) {
        Img_Error = Img_LastError;
    }
    Img_LastError = Img_Error;
//    Img_Error = ((g_LineError.error_Leftangle + g_LineError.error_Rightangle) / 2.0) / SMOTOR_RATE;
    ips200_show_float(50, 90, Img_Error, 6, 6);

    // 需要处理的元素:环岛、P字、S路、坡道、车库
    // 需要固定速度的元素：坡道上、P字出阶段、入库阶段
    // 直道弯道区分 无元素

    if (g_TrackType.m_u8ShortLeftLineStraightFlag == 1 || g_TrackType.m_u8ShortRightLineStraightFlag == 1 /*|| g_TrackType.m_u8CrossFlag != CROSS_NONE || g_TrackType.m_u8RightSideCrossFlag != CROSS_NONE || g_TrackType.m_u8LeftSideCrossFlag != CROSS_NONE*/) {
        // 十字
        if (g_TrackType.m_u8CrossFlag != CROSS_NONE || g_TrackType.m_u8RightSideCrossFlag != CROSS_NONE || g_TrackType.m_u8LeftSideCrossFlag != CROSS_NONE) {
            Serve.Kp_Gain = 0;
            Serve.Base    = 2;
            Serve.Kd_Gain = 1;
        } else // 直道
        {
            Serve.Kp_Gain = 0;
            Serve.Base    = 5;
            Serve.Kd_Gain = 1;
        }
    } else { // 弯道

        Serve.Kp_Gain = 5;
        Serve.Base    = 5;
        Serve.Kd_Gain = 5;
    }
//    // 环岛进
//    if (g_TrackType.m_u8LeftRoundaboutFlag == ROUNDABOUT_IN || g_TrackType.m_u8RightRoundaboutFlag == ROUNDABOUT_IN) {
//        Serve.Kp_Gain = 0.35;
//        Serve.Base    = 2;
//        Serve.Kd_Gain = 5;
//    }
//    // 环岛中
//    else if (g_TrackType.m_u8LeftRoundaboutFlag == ROUNDABOUT_MID || g_TrackType.m_u8RightRoundaboutFlag == ROUNDABOUT_MID) {
//        Serve.Kp_Gain = 0.35;
//        Serve.Base    = 2;
//        Serve.Kd_Gain = 5;
//    }
//    // 环岛出
//    else if (g_TrackType.m_u8LeftRoundaboutFlag == ROUNDABOUT_OUT || g_TrackType.m_u8RightRoundaboutFlag == ROUNDABOUT_OUT) {
//        Serve.Kp_Gain = 0.35;
//        Serve.Base    = 2;
//        Serve.Kd_Gain = 5;
//    }
//
//    // 环岛结束阶段
//    else if (g_TrackType.m_u8LeftRoundaboutFlag == ROUNDABOUT_END || g_TrackType.m_u8RightRoundaboutFlag == ROUNDABOUT_END) {
//        Serve.Kp_Gain = 0.35;
//        Serve.Base    = 2;
//        Serve.Kd_Gain = 5;
//    }

    // // S路  S弯的计算放最后
    // else if (g_TrackType.m_u8BendSFlag == BENDS_YES)
    // {
    // }

    Duoji_Control(&Serve, Img_Error);
//    pwm_set_duty(DUOJI_CHANY, Duoji_Duty_Maximum);
}

//--------------------------------------------------------------
//  @brief     位置环PD控制
//  @param     Positon_Para *Position   位置环环结构体
//             processValue             里程值
//  @return    Position.result          期望平均速度补偿
//  @note      位置式PI，死区限制
//--------------------------------------------------------------
__attribute__((optimize(2)))void Position_Control(Positon_Para *Position)
{
    float thisError;
    float result;
    static float lasterror = 0; // 前一拍偏差

    thisError = Position->setpoint - (SetLeft + SetRight) / 2 * dt_Position; // （单位是编码器脉冲数）
    // 如果图像曲率小，那么预瞄点放近，在dt_Position内无法达到目标点，那么就加速补偿
    result = Position->result;
    if (Fabs(thisError) > Position->deadband) {

        result = Position->KP * thisError + Position->KD * (thisError - lasterror);
    } else {
        if (Fabs(Position->setpoint - Position->minimum) < Position->deadband) {
            result = Position->minimum;
        }
    }
    lasterror        = thisError;
    Position->result = MINMAX(result, Position->minimum, Position->maximum);
}

//--------------------------------------------------------------
//  @brief     速度环增量式PI控制
//  @param     Speed_Para *Speed       速度环结构体
//             processValue            编码器值
//  @return    Speed.result            期望平均加速度补偿
//  @note      增量式PI，死区限制，梯形积分
//--------------------------------------------------------------
__attribute__((optimize(2)))void Speed_Control(void)
{

    SetLeft   = Motor_Left.setpoint + Position.result;
    SetRight  = Motor_Right.setpoint + Position.result;
    Avg_speed = (SetLeft + SetRight) / 2; //! 平均速度要不要算上差速？
    V_Bia     = Differrntial(&CHASU);

    if (Duoji_Duty > Duoji_Duty_Midmum) // 左转
    {
        SetLeft = SetLeft - V_Bia;
    }

    if (Duoji_Duty < Duoji_Duty_Midmum) // 右转
    {

        SetRight = SetRight - V_Bia;
    }

    Motor_L_Control_Change_Integral(SetLeft, &Motor_Left, &MOTOR, encoder_1);
    Motor_R_Control_Change_Integral(SetRight, &Motor_Right, &MOTOR, encoder_2);

    // // 防止左轮堵转
    // if (encoder_1 < 15 && over_speed_left < 30 && flag_left == 1 && g_TrackType.m_u8CarRunningState == 0)
    // { // 避免左轮第一次启动就堵转
    //     if (outL >= 0.9 * Max_speed)
    //     {
    //         over_speed_left++;
    //     }
    // }
    // else if (over_speed_left < 30 && flag_left == 1)
    // {
    //     over_speed_left = 0;
    // }

    // // 防止右轮堵转
    // if (speed_right < 15 && over_speed_right < 30 && flag_right == 1 && g_TrackType.m_u8CarRunningState == 0)
    // { // 避免右轮第一次启动就堵转
    //     if (outR >= 0.9 * Max_speed)
    //     {
    //         over_speed_right++;
    //     }
    // }
    // else if (over_speed_right < 30 && flag_right == 1)
    // {
    //     over_speed_right = 0;
    // }

    // // 150ms堵转，停车
    // if (over_speed_right >= 30 || over_speed_left >= 30)
    // {
    //     pid_speed.SetSpeed = 0;
    // }

    Back_Wheel_Out(-Motor_Left.result, Motor_Right.result);
}
