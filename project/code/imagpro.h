#ifndef _IMAGPRO_H_
#define _IMAGPRO_H_

#include "zf_common_headfile.h"
#include "headfile.h"
#include "imgStruct.h"

// #define IMGW MT9V03X_W / 2
// #define IMGH MT9V03X_H / 2
#define IMGW_Y  MT9V03X_W
#define IMGH_Y  MT9V03X_H

#define B_WHITE 254
#define B_BLACK 1

#define MINMIN(a, b, c, d)       MIN(MIN(MIN(a, b), c), d)

/*-----------------------变量定义------------------------------------*/

// extern uint8 outimage[MT9V03X_H / 2][MT9V03X_W / 2];
// extern uint8 outimage1[MT9V03X_H][MT9V03X_W];

extern float32 CenterX;
extern float32 CenterY;

extern float32 SpeedThres;
extern float32 SpeedDistance;

extern const float32 RoadWith;   // 赛道宽度
extern const float32 SampleDist; // 采样间距
extern const int16 InterPoint;   // 间隔点数
extern const int16 BinaryBlock;
extern const int16 Threclip;
extern const int16 PointsBlurKernel;
extern const int16 NMSKernel;
extern const int8 arr_frontdir[4][2];
extern const int8 arr_frontleftdir[4][2];
extern const int8 arr_frontrightdir[4][2];
extern int16 clp;

// 未找到边线标志
#define FIND_NO 0

// 找到边线标志
#define FIND_YES 1

// 无需补线标志位
#define LINE_NO 0

// 未找到需要补线标志
#define LINE_LOSTADD 1

// 违反单调性需要补线标志
#define LINE_VIOLATEADD 2

/*选择搜线方法,0为八邻域,1为最优列行遍历*/
#define SeachBorderMethod 0

#define TYPE_FALSE        0
#define TYPE_TRUE         1

/* 65/180*pi */
#define L_CORNER_LOWERBOUND 1.1344640137963142250003989995175982637378 // 1.2217304763960307038465835379420288994100（65度）
/* 110/180*pi */
#define L_CORNER_UPPERBOUND 1.9198621771937625346160598453374739847871 // （110度）
/* (45)   40/180*pi */
#define Y_CORNER_LOWERBOUND 0.6981317007977318307694763073954450853771f // 0.7853981633974483096156608458198757210492（45度）
/* 60/180*pi */
#define Y_CORNER_UPPERBOUND 1.0471975511965977461542144610931676280657 // 1.1344640137963142250003989995175982637378（60度）
/* 5/180*pi*/
#define STRAIGHTBOUND         0.0872664625997164788461845384244306356721 // （5度）

#define STRAIGHTNUMBOUND      1. / SampleDist // 50

#define SHORTSTRAIGHTNUMBOUND 0.8 / SampleDist // 40

#define MIDSTRAIGHTNUMBOUND   1.2 / SampleDist // 60

/****临时定义***/

extern uint8 inv_image[60][94];        // 逆透视全图数组
extern uint8 Pooling_image[60][94]; // 池化数组




void DrawCenter(TRACK_BORDER_INFO *p_Border);
void DrawBoarder(TRACK_BORDER_INFO *p_Border);
void DrawBoarderInvp(TRACK_BORDER_INFO *p_Border);
void pooling(void);
void adaptiveThreshold_1(uint8 (*InImg)[MT9V03X_W], uint8 (*OutImg)[MT9V03X_W], int width, int height, int block, uint8_t clip_value);
__attribute__((optimize(2)))void wusuowei(uint8 (*InImg)[IMGW], TRACK_BORDER_INFO *p_Border, TRACK_TYPE_INFO *p_Type);
__attribute__((optimize(2)))void LeftLine_SeedGrow_Adaptive(uint8 (*InImg)[IMGW], INT_POINT_INFO t_Seed, INT_POINT_INFO point[], uint8 pointDirection[], int16 blocksize, int16 threclip, int16 *num);
__attribute__((optimize(2)))void RightLine_SeedGrow_Adaptive(uint8 (*InImg)[IMGW], INT_POINT_INFO t_Seed, INT_POINT_INFO point[], uint8 pointDirection[], int16 blocksize, int16 threclip, int16 *num);
__attribute__((optimize(2)))void BorderLineReCoor(INT_POINT_INFO PointIN[], int16 PointNum, int16 PointOUT[]);
__attribute__((optimize(2)))void BorderWidth_Calc(TRACK_BORDER_INFO *p_Border, int16 PointLeft[], int16 PointRight[]);
__attribute__((optimize(2)))void Inverse_Perspective(INT_POINT_INFO PointIN[], INT_POINT_INFO PointOUT[], int16 PointNum);
__attribute__((optimize(2)))void Points_Blur(INT_POINT_INFO PointIN[], FLOAT_POINT_INFO PointOUT[], int16 PointNum, int16 kernelSize);
__attribute__((optimize(2)))void Points_Resample(FLOAT_POINT_INFO PointIN[], FLOAT_POINT_INFO PointOUT[], int16 PointINNum, int16 *PointOUTNum, float32 dist); // Dist = pixel per meter * 0.02m
__attribute__((optimize(2)))void Border_Local_Angle(FLOAT_POINT_INFO PointIN[], float32 AngleOUT[], int16 PointNum, int16 len);
__attribute__((optimize(2)))void Angle_NMS(float32 AngleIN[], float32 AngleOUT[], int16 AngleNum, int16 kernelSize);
__attribute__((optimize(2)))void LeftBorderTrackingCenter(FLOAT_POINT_INFO LeftPoint[], FLOAT_POINT_INFO CenterPoint[], int16 PointNum, int16 InterPoint, float32 dist);
__attribute__((optimize(2)))void RightBorderTrackingCenter(FLOAT_POINT_INFO LeftPoint[], FLOAT_POINT_INFO CenterPoint[], int16 PointNum, int16 InterPoint, float32 dist);
unsigned char *out_float(double value, unsigned char decimal_digit, unsigned char *output_length);
__attribute__((optimize(2)))void FindCorner(TRACK_BORDER_INFO *p_Border, TRACK_TYPE_INFO *p_Type);
__attribute__((optimize(2)))void GetAimingDist(TRACK_BORDER_INFO *p_Border, LINE_ERROR_INFO *p_Error, TRACK_TYPE_INFO *p_Type);
__attribute__((optimize(2)))void PurePursuit(TRACK_BORDER_INFO *p_Border, LINE_ERROR_INFO *p_Error, TRACK_TYPE_INFO *p_Type);
void PurePursuit_ZX(TRACK_BORDER_INFO *p_Border, LINE_ERROR_INFO *p_Error, TRACK_TYPE_INFO *p_Type);
__attribute__((optimize(2)))void Full_Inverse_Perspective(void);
void Out_Protect(uint8 (*image)[IMGW]);
__attribute__((optimize(2)))void All_image(void);

#endif /* CODE_IMAGEPRO_H_ */
