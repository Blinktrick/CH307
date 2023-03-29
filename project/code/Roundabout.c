/*
 * Roundabout.c
 *
 *  Created on: 2022��2��24��
 *      Author: kare
 */

#include "Roundabout.h"

uint16 RightRoundabout_Right_Line_Lost_Count = 0;
                                                  // 环岛右线丢失点数
uint16 RightRoundabout_Right_Line_Refind_Count = 0; // 环岛右线重找到点数
uint16 RightRoundabout_Left_Line_Find_Count    = 0; // 环岛左线找到点数

uint16 LeftRoundabout_Left_Line_Lost_Count = 0;
                                                 // 环岛左线丢失点数
uint16 LeftRoundabout_Left_Line_Refind_Count = 0; // 环岛左线重找到点数
uint16 LeftRoundabout_Right_Line_Find_Count  = 0; // 环岛右线找到点数

int64 RightRoundabout_Encoder = 0;
int64 LeftRoundabout_Encoder  = 0;

// #pragma section all "cpu1_psram"

void Check_RightRoundabout(TRACK_BORDER_INFO *p_Border, TRACK_TYPE_INFO *p_Type) // 寻找右环岛
{
    int64 Current_Encoder;
    Current_Encoder = GetEncoder(); // 编码器获得速度

    // 左边直线,右边直角拐点在一定范围内,判定为环岛一阶段
    if (p_Type->m_u8RightRoundaboutFlag == ROUNDABOUT_NONE && p_Border->RL_CornerPos != -1 && p_Border->RL_CornerPos <= 15 /*右L角点找到且小于15*/ /*&& p_Border ->RL_CornerPos >= 5*/ && p_Type->m_u8LeftLineStraightFlag == 1 /*逆透视后左边界数组大于50*/ && p_Border->LL_CornerPos == -1 /*没有左L角点*/) {
        p_Type->m_u8RightRoundaboutFlag = ROUNDABOUT_BEGIN; // 准备进入环岛
        RightRoundabout_Encoder         = Current_Encoder;
    }

    // 搜索远端拐点,用于区分环岛和P字
    //  if(g_TrackType.m_u8RightRoundaboutFlag == ROUNDABOUT_BEGIN && g_Border.m_i16RPointCnt < 60)/*用于区分P字和环岛，暂定 将代码注释*/
    //  {
    //  FindRightRemoteCorner(mt9v03x_image, &g_Border);
    // }

    // 右边线先丢再有进入二阶段
    if (p_Type->m_u8RightRoundaboutFlag == ROUNDABOUT_BEGIN && p_Border->m_i16RPointCntRS < 5 /*右数组几乎丢线*/) {
        RightRoundabout_Right_Line_Lost_Count++; // 右边线丢线点数
    }
    if (p_Type->m_u8RightRoundaboutFlag == ROUNDABOUT_BEGIN && RightRoundabout_Right_Line_Lost_Count > 2 && p_Border->m_i16RPointCntRS > 20 && p_Border->RL_CornerPos == -1 /*右L角点没找到*/) {
        RightRoundabout_Right_Line_Refind_Count++;       // 右边线重新找到的点数
        if (RightRoundabout_Right_Line_Refind_Count > 2) // 右边重新找到点数大于2
        {
            RightRoundabout_Right_Line_Lost_Count   = 0;
            RightRoundabout_Right_Line_Refind_Count = 0;

            // if(Find_Right_Remote_Corner_Count > 4)/*P字判断 暂定将代码注释*/
            //             {
            //                 p_Type ->m_u8RightPRoadFlag = PROAD_MID;
            //                 p_Type ->m_u8RightRoundaboutFlag = ROUNDABOUT_NONE;
            // //                p_Type ->m_u8PRoadDir = RIGHTPROAD;
            //             }
            //             else
            //             {
            p_Type->m_u8RightRoundaboutFlag = ROUNDABOUT_IN; // 判定进环岛
            yaw_angle                       = 0;             // 陀螺仪角度赋为0
            //             }

            // Find_Right_Remote_Corner_Count = 0;
        }
    }

    // 左边线先丢再有并且陀螺仪转过一定角度进入环岛三阶段
    if (p_Type->m_u8RightRoundaboutFlag == ROUNDABOUT_IN && p_Type->m_u8LeftLineStraightFlag == 0 && p_Border->m_i16LPointCntRS > 20 /*左边界数组大于20*/) {
        RightRoundabout_Left_Line_Find_Count++; // 左边线找到点数
    }
    if (p_Type->m_u8RightRoundaboutFlag == ROUNDABOUT_IN && RightRoundabout_Left_Line_Find_Count > 2 && yaw_angle /*陀螺仪相关变量*/ < -70) // 左边线找到点数大于2且陀螺仪角度小于-70
    {
        p_Type->m_u8RightRoundaboutFlag      = ROUNDABOUT_MID; // 判定为环岛中
        RightRoundabout_Left_Line_Find_Count = 0;

        if (Current_Encoder > 1.4 * EncoderPerMeter)
            p_Type->m_u8RoundaboutSize = BIG_ROUNDABOUT; // encoder大于1.4米则为大环岛
        else
            p_Type->m_u8RoundaboutSize = SMALL_ROUNDABOUT; // 否则小环岛
    }

    // 看到左侧直角拐点并且在一定范围内进入环岛四阶段
    if (p_Type->m_u8RightRoundaboutFlag == ROUNDABOUT_MID && p_Border->LL_CornerPos != -1 && p_Border->LL_CornerPos < 20) p_Type->m_u8RightRoundaboutFlag = ROUNDABOUT_OUT;

    // 左边线长直道进入环岛五阶段
    if (p_Type->m_u8RightRoundaboutFlag == ROUNDABOUT_OUT && p_Type->m_u8LeftLineStraightFlag == 1 && p_Border->m_i16LPointCntRS > 65) p_Type->m_u8RightRoundaboutFlag = ROUNDABOUT_END;

    // 右边线先丢再有后刷掉环岛状态
    if (p_Type->m_u8RightRoundaboutFlag == ROUNDABOUT_END && p_Border->m_i16RPointCntRS < 5) RightRoundabout_Right_Line_Lost_Count++;

    if (p_Type->m_u8RightRoundaboutFlag == ROUNDABOUT_END && p_Border->m_i16RPointCntRS > 25 && RightRoundabout_Right_Line_Lost_Count > 2) {
        p_Type->m_u8RightRoundaboutFlag       = ROUNDABOUT_NONE;
        RightRoundabout_Right_Line_Lost_Count = 0;

        Protect_Frame = 8;

        pitch_angle = 0;
    }
}

void Check_MIDRightRoundabout(uint8 (*InImg)[IMGW], TRACK_BORDER_INFO *p_Border, TRACK_TYPE_INFO *p_Type, LINE_ERROR_INFO *p_Error)
{
    if (p_Type->m_u8RightRoundaboutFlag == ROUNDABOUT_NONE) {
        /*  中入环岛条件
         *  单边直道
         *  内环点数在一定范围内并且没有拐点
         *  有局部极值
         */
        if (p_Type->m_u8LeftLineStraightFlag == 1 && p_Border->m_i16RPointCntRS > 6 && p_Border->m_i16RPointCntRS < 25 && p_Border->RL_CornerPos == -1) //原m_i16RPointCntRSm_i16RPointCntRS < 50 > 12 左边线为长直道且右边线数组大于12小于50并且没有右L角点
        {
            int16 Pos = 0;
            if (/*p_Error ->m_f32RightBorderKappa > 0.45 && Fabs(p_Error->m_f32LeftBorderKappa) < 0.2*/ CheckLocalMinimum(p_Border->m_RPnt, p_Border->m_RPntGrowDirection, p_Border->m_i16RPointCnt, 9, &Pos)) {
                FindRightRemoteCornerRD(InImg, p_Border);

                if (p_Border->RL_CornerPosRemote != -1) {
                    p_Type->m_u8RightRoundaboutFlag = ROUNDABOUT_IN;
                    yaw_angle                       = 0;
                }
            }
        }
    }
}

void FindRightRemoteCornerRD(uint8 (*InImg)[IMGW], TRACK_BORDER_INFO *p_Border)
{
    int16 thresholdclip          = 5;
    int16 int16_half             = BinaryBlock / 2;
    INT_POINT_INFO t_SeedRRemote = {-1, -1};
    int16 y1, x1;
    int16 int16_dy, int16_dx;

    if (p_Border->m_i16RPointCnt > 5)/*原10*/ {
        y1 = p_Border->m_RPnt[p_Border->m_i16RPointCnt - 5].m_i16y - 6; // 右边线数组倒数第6个的y值再剪掉6
        x1 = p_Border->m_RPnt[p_Border->m_i16RPointCnt - 5].m_i16x;     // 右边线数组倒数第6个的x值
        if (x1 > 85) x1 = 85;//原85
    } else {
        y1 = 25;//原50
        x1 = 85;//原176
    }
    while (--y1 >= 15)/*原30*/ {
        int int16_localthre = 0;
        int16_dy            = -int16_half - 1;
        while (++int16_dy <= int16_half) {
            int16_dx = -int16_half - 1;
            while (++int16_dx <= int16_half) {
                int16_localthre += InImg[y1 + int16_dy][x1 + int16_dx];
            }
        }
        int16_localthre /= (BinaryBlock * BinaryBlock);
        int16_localthre -= thresholdclip;

        if (InImg[y1 - 1][x1] < int16_localthre) // 二值化起点
        {
            t_SeedRRemote.m_i16x = x1;
            t_SeedRRemote.m_i16y = y1;
            break;
        }
    }

    RightLine_SeedGrow_Adaptive(InImg, t_SeedRRemote, p_Border->m_RRemotePnt, p_Border->m_RRemotePntGrowDirection, BinaryBlock, Threclip, &p_Border->m_i16RRemotePointCnt);
    Inverse_Perspective(p_Border->m_RRemotePnt, p_Border->m_RPntInvpRemote, p_Border->m_i16RRemotePointCnt);
    Points_Blur(p_Border->m_RPntInvpRemote, p_Border->m_RPntoutRemote, p_Border->m_i16RRemotePointCnt, PointsBlurKernel);

    p_Border->m_i16RPointCntRSRemote = IMGH;
    Points_Resample(p_Border->m_RPntoutRemote, p_Border->m_RPntRSRemote, p_Border->m_i16RRemotePointCnt, &p_Border->m_i16RPointCntRSRemote, SampleDist * PixelperMeter);

    Border_Local_Angle(p_Border->m_RPntRSRemote, p_Border->RdAngleRemote, p_Border->m_i16RPointCntRSRemote, InterPoint);
    Angle_NMS(p_Border->RdAngleRemote, p_Border->RdAngleNMSRemote, p_Border->m_i16RPointCntRSRemote, NMSKernel);

    p_Border->RL_CornerPosRemote = -1;

    if (p_Border->m_i16RPointCntRSRemote >20)/*原40*/ {
        int16 int16_Loopi;

        int16_Loopi = -1;
        while (++int16_Loopi < p_Border->m_i16RPointCntRSRemote - 1) {
            if (p_Border->RdAngleNMSRemote[int16_Loopi] == 0) continue;

            int16 upper = clip(int16_Loopi + InterPoint, 0, p_Border->m_i16RPointCntRSRemote - 1);
            int16 lower = clip(int16_Loopi - InterPoint, 0, p_Border->m_i16RPointCntRSRemote - 1);

            float32 f32_Corn = Fabs(p_Border->RdAngleRemote[int16_Loopi]) - (Fabs(p_Border->RdAngleRemote[upper]) + Fabs(p_Border->RdAngleRemote[lower])) / 2;

            if (f32_Corn > L_CORNER_LOWERBOUND && f32_Corn < L_CORNER_UPPERBOUND && int16_Loopi < 1.2 / SampleDist) {
                p_Border->RL_CornerPosRemote = int16_Loopi;
            }
            if (p_Border->RL_CornerPosRemote != -1) break;
        }

        if (p_Border->RL_CornerPosRemote != -1) {
            if (!(p_Border->m_RPntRSRemote[clip(p_Border->RL_CornerPosRemote - 25, 0, p_Border->m_i16RPointCntRSRemote - 1)].m_i16x > p_Border->m_RPntRSRemote[p_Border->RL_CornerPosRemote].m_i16x + 5)) p_Border->RL_CornerPosRemote = -1;//原50
        }
    }
}

void Check_LeftRoundabout(TRACK_BORDER_INFO *p_Border, TRACK_TYPE_INFO *p_Type)
{
    int64 Current_Encoder;
    Current_Encoder = GetEncoder();

    if (p_Type->m_u8LeftRoundaboutFlag == ROUNDABOUT_NONE && p_Border->LL_CornerPos != -1 && p_Border->LL_CornerPos <= 15 /*&& p_Border ->LL_CornerPos >= 5*/ && p_Type->m_u8RightLineStraightFlag == 1 && p_Border->RL_CornerPos == -1) {
        p_Type->m_u8LeftRoundaboutFlag = ROUNDABOUT_BEGIN;
        LeftRoundabout_Encoder         = Current_Encoder;
    }

    // if(g_TrackType.m_u8LeftRoundaboutFlag == ROUNDABOUT_BEGIN && g_Border.m_i16LPointCnt < 60)
    // {
    //     FindLeftRemoteCorner(mt9v03x_image, &g_Border);
    // }

    if (p_Type->m_u8LeftRoundaboutFlag == ROUNDABOUT_BEGIN && p_Border->m_i16LPointCntRS < 5) {
        LeftRoundabout_Left_Line_Lost_Count++;
    }
    if (p_Type->m_u8LeftRoundaboutFlag == ROUNDABOUT_BEGIN && LeftRoundabout_Left_Line_Lost_Count > 2 && p_Border->m_i16LPointCntRS > 10/*原20*/ && p_Border->LL_CornerPos == -1) {
        LeftRoundabout_Left_Line_Refind_Count++;
        if (LeftRoundabout_Left_Line_Refind_Count > 2) {
            LeftRoundabout_Left_Line_Lost_Count   = 0;
            LeftRoundabout_Left_Line_Refind_Count = 0;

            //             if(Find_Left_Remote_Corner_Count > 4)
            //             {
            //                 p_Type ->m_u8LeftPRoadFlag = PROAD_MID;
            //                 p_Type ->m_u8LeftRoundaboutFlag = ROUNDABOUT_NONE;
            // //                p_Type ->m_u8PRoadDir = LEFTPROAD;
            //             }
            //             else
            //             {
            p_Type->m_u8LeftRoundaboutFlag = ROUNDABOUT_IN;
            //                 yaw_angle = 0;
            //             }

            //             Find_Left_Remote_Corner_Count = 0;
        }
    }

    if (p_Type->m_u8LeftRoundaboutFlag == ROUNDABOUT_IN && p_Type->m_u8RightLineStraightFlag == 0 && p_Border->m_i16RPointCntRS > 10/*原20*/ && yaw_angle > 70) {
        LeftRoundabout_Right_Line_Find_Count++;
    }
    if (p_Type->m_u8LeftRoundaboutFlag == ROUNDABOUT_IN && LeftRoundabout_Right_Line_Find_Count > 2) {
        p_Type->m_u8LeftRoundaboutFlag       = ROUNDABOUT_MID;
        LeftRoundabout_Right_Line_Find_Count = 0;

        if (Current_Encoder > 1.4 * EncoderPerMeter /*测距离的变量*/)
            p_Type->m_u8RoundaboutSize = BIG_ROUNDABOUT;
        else
            p_Type->m_u8RoundaboutSize = SMALL_ROUNDABOUT;
    }

    if (p_Type->m_u8LeftRoundaboutFlag == ROUNDABOUT_MID && p_Border->RL_CornerPos != -1 && p_Border->RL_CornerPos < 20) p_Type->m_u8LeftRoundaboutFlag = ROUNDABOUT_OUT;

    if (p_Type->m_u8LeftRoundaboutFlag == ROUNDABOUT_OUT && p_Type->m_u8RightLineStraightFlag == 1 && p_Border->m_i16RPointCntRS > 30)/*原65*/ p_Type->m_u8LeftRoundaboutFlag = ROUNDABOUT_END;

    if (p_Type->m_u8LeftRoundaboutFlag == ROUNDABOUT_END && p_Border->m_i16LPointCntRS < 5) LeftRoundabout_Left_Line_Lost_Count++;

    if (p_Type->m_u8LeftRoundaboutFlag == ROUNDABOUT_END && p_Border->m_i16LPointCntRS > 25 && LeftRoundabout_Left_Line_Lost_Count > 2) {
        p_Type->m_u8LeftRoundaboutFlag      = ROUNDABOUT_NONE;
        LeftRoundabout_Left_Line_Lost_Count = 0;

        Protect_Frame = 8; /*未知变量*/

        pitch_angle = 0; /*未知变量*/
    }
}

void Check_MIDLeftRoundabout(uint8 (*InImg)[IMGW], TRACK_BORDER_INFO *p_Border, TRACK_TYPE_INFO *p_Type, LINE_ERROR_INFO *p_Error)
{
    // 这里还需要加一点条件
    if (p_Type->m_u8LeftRoundaboutFlag == ROUNDABOUT_NONE) {
        if (p_Type->m_u8RightLineStraightFlag == 1 && p_Border->m_i16LPointCntRS > 6/*原12*/ && p_Border->m_i16LPointCntRS < 25 /*原50*/&& p_Border->LL_CornerPos == -1) {
            int16 Pos = 0;
            if (/*p_Error ->m_f32LeftBorderKappa < -0.45 && Fabs(p_Error->m_f32RightBorderKappa) < 0.2*/ CheckLocalMaximum(p_Border->m_LPnt, p_Border->m_LPntGrowDirection, p_Border->m_i16LPointCnt, 9, &Pos)) {
                FindLeftRemoteCornerRD(InImg, p_Border);

                if (p_Border->LL_CornerPosRemote != -1) {
                    p_Type->m_u8LeftRoundaboutFlag = ROUNDABOUT_IN;
                    yaw_angle                      = 0;
                }
            }
        }
    }
}

void FindLeftRemoteCornerRD(uint8 (*InImg)[IMGW], TRACK_BORDER_INFO *p_Border)
{
    int16 thresholdclip          = 5;
    int16 int16_half             = BinaryBlock / 2;
    INT_POINT_INFO t_SeedLRemote = {-1, -1};
    int16 y1, x1;
    int16 int16_dy, int16_dx;

    if (p_Border->m_i16LPointCnt > 10) {
        y1 = p_Border->m_LPnt[p_Border->m_i16LPointCnt - 5].m_i16y - 6;
        x1 = p_Border->m_LPnt[p_Border->m_i16LPointCnt - 5].m_i16x;
        if (x1 < 10) x1 = 10;
    } else {
        y1 = 35;
        x1 = 10;
    }

    while (--y1 >= 15) {
        int int16_localthre = 0;
        int16_dy            = -int16_half - 1;
        while (++int16_dy <= int16_half) {
            int16_dx = -int16_half - 1;
            while (++int16_dx <= int16_half) {
                int16_localthre += InImg[y1 + int16_dy][x1 + int16_dx];
            }
        }
        int16_localthre /= (BinaryBlock * BinaryBlock);
        int16_localthre -= thresholdclip;

        if (InImg[y1 - 1][x1] < int16_localthre) {
            t_SeedLRemote.m_i16x = x1;
            t_SeedLRemote.m_i16y = y1;
            break;
        }
    }

    p_Border->m_i16LRemotePointCnt = IMGH;
    LeftLine_SeedGrow_Adaptive(InImg, t_SeedLRemote, p_Border->m_LRemotePnt, p_Border->m_LRemotePntGrowDirection, BinaryBlock, Threclip, &p_Border->m_i16LRemotePointCnt);
    Inverse_Perspective(p_Border->m_LRemotePnt, p_Border->m_LPntInvpRemote, p_Border->m_i16LRemotePointCnt);
    Points_Blur(p_Border->m_LPntInvpRemote, p_Border->m_LPntoutRemote, p_Border->m_i16LRemotePointCnt, PointsBlurKernel);

    p_Border->m_i16LPointCntRSRemote = IMGH;
    Points_Resample(p_Border->m_LPntoutRemote, p_Border->m_LPntRSRemote, p_Border->m_i16LRemotePointCnt, &p_Border->m_i16LPointCntRSRemote, SampleDist * PixelperMeter);

    Border_Local_Angle(p_Border->m_LPntRSRemote, p_Border->LdAngleRemote, p_Border->m_i16LPointCntRSRemote, InterPoint);
    Angle_NMS(p_Border->LdAngleRemote, p_Border->LdAngleNMSRemote, p_Border->m_i16LPointCntRSRemote, NMSKernel);

    p_Border->LL_CornerPosRemote = -1;

    if (p_Border->m_i16LPointCntRSRemote > 20)/*40*/ {
        int16 int16_Loopi;

        int16_Loopi = -1;
        while (++int16_Loopi < p_Border->m_i16LPointCntRSRemote - 1) {
            if (p_Border->LdAngleNMSRemote[int16_Loopi] == 0) continue;

            int16 upper = clip(int16_Loopi + InterPoint, 0, p_Border->m_i16LPointCntRSRemote - 1);
            int16 lower = clip(int16_Loopi - InterPoint, 0, p_Border->m_i16LPointCntRSRemote - 1);

            float32 f32_Corn = Fabs(p_Border->LdAngleRemote[int16_Loopi]) - (Fabs(p_Border->LdAngleRemote[upper]) + Fabs(p_Border->LdAngleRemote[lower])) / 2;

            if (f32_Corn > L_CORNER_LOWERBOUND && f32_Corn < L_CORNER_UPPERBOUND && int16_Loopi < 1.2 / SampleDist) {
                p_Border->LL_CornerPosRemote = int16_Loopi;
            }

            if (p_Border->LL_CornerPosRemote != -1) break;
        }

        if (p_Border->LL_CornerPosRemote != -1) {
            if (!(p_Border->m_LPntRSRemote[clip(p_Border->LL_CornerPosRemote - 25/*50*/, 0, p_Border->m_i16LPointCntRSRemote - 1)].m_i16x < p_Border->m_LPntRSRemote[p_Border->LL_CornerPosRemote].m_i16x - 5)) p_Border->LL_CornerPosRemote = -1;
        }
    }
}

uint8 CheckLocalMaximum(INT_POINT_INFO PointIN[], uint8 pointDirection[], int16 PointNum, int16 kernelSize, int16 *LocalMaximumPos)
{
    int16 int16_half = kernelSize / 2;
    int16 int16_loopi, int16_loopj;
    uint8 IsLocalMaximum;

    int16_loopi = int16_half;

    while (++int16_loopi < PointNum - int16_half) {
        IsLocalMaximum = 1;
        int16_loopj    = -int16_half - 1;

        // 遍历搜索该点是否为极值
        while (++int16_loopj <= int16_half) {
            if (PointIN[clip(int16_loopi + int16_loopj, 0, PointNum - 1)].m_i16x > PointIN[int16_loopi].m_i16x && IsLocalMaximum) {
                IsLocalMaximum = 0;
                break;
            }
        }

        if (IsLocalMaximum) {

            // 根据极值点前后两点的差值和生长方向二次判断
            if (Kabs(PointIN[clip(int16_loopi + int16_half, 0, PointNum - 1)].m_i16x - PointIN[clip(int16_loopi - int16_half, 0, PointNum - 1)].m_i16x) < 6) {

                int16 int16_k             = int16_loopi;
                int16 GrowTowardLeft      = 0;
                int16 GrowTowardFrontLeft = 0;
                while (++int16_k < PointNum - 1) {
                    if (pointDirection[int16_k] == LEFTLINE_LEFT)
                        GrowTowardLeft++;
                    else if (pointDirection[int16_k] == LEFTLINE_FRONT_LEFT)
                        GrowTowardFrontLeft++;
                }

                //                GrowCount = GrowTowardLeft;
                //                GrowCount2 = GrowTowardFrontLeft;

                if (GrowTowardLeft < 13 && GrowTowardFrontLeft > 5)/*26 10*/ {
                    *LocalMaximumPos = int16_loopi;
                    return 1;
                }
            }
        }
    }

    return 0;
}

uint8 CheckLocalMinimum(INT_POINT_INFO PointIN[], uint8 pointDirection[], int16 PointNum, int16 kernelSize, int16 *LocalMinimumPos)
{
    int16 int16_half = kernelSize / 2;
    int16 int16_loopi, int16_loopj;
    uint8 IsLocalMinimum;

    int16_loopi = int16_half;
    while (++int16_loopi < PointNum - int16_half) {
        IsLocalMinimum = 1;
        int16_loopj    = -int16_half - 1;

        while (++int16_loopj <= int16_half) // 寻找一定区间内的最小值
        {
            if (PointIN[clip(int16_loopi + int16_loopj, 0, PointNum - 1)].m_i16x < PointIN[int16_loopi].m_i16x && IsLocalMinimum) {
                IsLocalMinimum = 0;
                break;
            }
        }

        if (IsLocalMinimum) {
            if (Kabs(PointIN[clip(int16_loopi + int16_half, 0, PointNum - 1)].m_i16x - PointIN[clip(int16_loopi - int16_half, 0, PointNum - 1)].m_i16x) < 6) // 最小值所处的区间内开始与结束的x值相差小于6
            {
                int16 int16_k              = int16_loopi;
                int16 GrowTowardRight      = 0;
                int16 GrowTowardFrontRight = 0;
                while (++int16_k < PointNum - 1) {
                    if (pointDirection[int16_k] == RIGHTLINE_RIGHT)
                        GrowTowardRight++; // 右转
                    else if (pointDirection[int16_k] == RIGHTLINE_FRONT_RIGHT)
                        GrowTowardFrontRight++; // 右前
                }

                GrowCount  = GrowTowardRight;
                GrowCount2 = GrowTowardFrontRight;

                if (GrowTowardRight < 13 && GrowTowardFrontRight > 5)/*26 10*/ {
                    *LocalMinimumPos = int16_loopi;
                    return 1;
                }
            }
        }
    }

    return 0;
}
// #pragma section all restore
