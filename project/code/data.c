#include "data.h"

/*---------------------------------��������-----------------------------*/

TRACK_BORDER_INFO g_Border;
TRACK_TYPE_INFO g_TrackType; /*��������*/
/***�������߰汾������***/
LINE_ERROR_INFO g_LineError; /*���ͼ���������ص�ƫ����Ϣ*/

uint16 Protect_Frame;

uint32 tim1;
uint32 tim2;

int16 BlackBlock_Monitor = 0;

float32 Dist_Monitor = 0;

int16 Pnt = 0;

int16 GrowCount  = 0;
int16 GrowCount2 = 0;
int16 GrowCount3 = 0;
int16 GrowCount4 = 0;

uint8 BinaryImg[90][188];

void OSG_Memcpy(OSG_OUT uint8* dst, OSG_IN uint8* src, OSG_IN uint32 length)
{
#if 1
	uint32 i;
	uint64* uxSrc;
	uint64* uxDst;

	while (((uint32)dst & 0x03U) && (length > 0U)) {
		dst[0] = src[0];
		dst++;
		src++;
		length--;
	}

	uxSrc = (uint64*)src;
	uxDst = (uint64*)dst;
	for (i = 0; i < (length >> 3U); i++) {
		uxDst[i] = uxSrc[i];
	}

  src += (i << 3U);
  dst += (i << 3U);

  for (i = 0; i < (length & 0x07U); i++) {
    dst[i] = src[i];
  }
#else
	  memcpy(dst, src, length);
#endif

}
/*---------------------------------��������-----------------------------*/
void Img_data_init(void)
{
    CenterX       = 47;
    CenterY       = 56;
    Protect_Frame = 0;

    g_TrackType.Outframe             = 0;
    g_TrackType.error_type_flag      = 0;
    g_LineError.m_u8LeftCenterValid  = 0;
    g_LineError.m_u8RightCenterValid = 0;

    g_LineError.m_f32RightBorderKappa = 0;
    g_LineError.m_f32LeftBorderKappa  = 0;
    g_LineError.m_f32RampError        = 0;
    g_LineError.m_u8RampErrorValid    = 0;
    g_LineError.Last_m_f32LeftBorderKappa=5;
    g_LineError.Last_m_f32RightBorderKappa=5;

    //     //��ʼ������Ȧ��

    //     g_TrackType.m_u8Garage_Mode = 0;

    //     g_TrackType.m_u8Round_Count = 0;
    //     g_TrackType.m_u8GarageFlag = GARAGE_NONE;  //������
    //     g_TrackType.m_u8GarageDirection = Garage_Out_LEFT;
    //     g_TrackType.m_u8GarageTracking = Garage_Tracking_Near;
    //     g_TrackType.m_u8YjunctionDirection = YJUNCTION_LEFT;

    //     /*��������Ԫ�س�ʼ��*/

    g_TrackType.m_u8CrossFlag          = CROSS_NONE;
    g_TrackType.m_u8LeftSideCrossFlag  = CROSS_NONE;
    g_TrackType.m_u8RightSideCrossFlag = CROSS_NONE;

    g_TrackType.m_u8RightRoundaboutFlag = ROUNDABOUT_NONE;
    g_TrackType.m_u8LeftRoundaboutFlag  = ROUNDABOUT_NONE;

    //     g_TrackType.m_u8BendSFlag = BENDS_NONE;
    //     g_TrackType.m_u8RampFlag = RAMP_NONE;
    //     g_TrackType.m_int16BendSCount = 0;
    // CornerLossCount = 0;
    //     StopCharging = 0;
    //     Beep.flag = 0;
    //     Beep.time = 0;
    //     Beep.num = 0;
    memset(g_Border.m_LRemotePnt, 0, sizeof(g_Border.m_LRemotePnt[0]) * IMGH);
    memset(g_Border.m_RRemotePnt, 0, sizeof(g_Border.m_RRemotePnt[0]) * IMGH);
}
