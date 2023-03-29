//#include "adc_dc.h"
//
//float32 LL;
//float32 LC;
//float32 CC;
//float32 CR;
//float32 RR;
//float32 L1;
//float32 R1;
//
//int8 Normalization_H;
//int8 Normalization_X;
//int8 Normalization_S;
//
//void DG_ADC_Init()
//{
//    adc_init(ADC1_CH0_A0, ADC_12BIT);
//    adc_init(ADC1_CH1_A1, ADC_12BIT);
//    adc_init(ADC1_CH2_A2, ADC_12BIT);
//    adc_init(ADC1_CH3_A3, ADC_12BIT);
//    adc_init(ADC1_CH4_A4, ADC_12BIT);
//    adc_init(ADC1_CH5_A5, ADC_12BIT);
//    adc_init(ADC1_CH6_A6, ADC_12BIT);
//    adc_init(ADC1_CH7_A7, ADC_12BIT);
//    adc_init(ADC1_CH8_B0, ADC_12BIT);
//}
//
//unsigned int Acquisition_Once(int DG) // 均值滤波，输出平均的adc值
//{
//    unsigned int value = 0;
//    switch (DG)
//    {
//    case 7:
//        value = adc_mean_filter_convert(ADC1_CH7_A7, 10);
//        break;
//    case 1:
//        value = adc_mean_filter_convert(ADC1_CH0_A0, 10);
//        break;
//    case 2:
//        value = adc_mean_filter_convert(ADC1_CH2_A2, 10);
//        break;
//    case 3:
//        value = adc_mean_filter_convert(ADC1_CH3_A3, 10);
//        break;
//    case 4:
//        value = adc_mean_filter_convert(ADC1_CH4_A4, 10);
//        break;
//    case 5:
//        value = adc_mean_filter_convert(ADC1_CH5_A5, 10);
//        break;
//    case 6:
//        value = adc_mean_filter_convert(ADC1_CH6_A6, 10);
//        break;
//    default:
//        return 0;
//    }
//    return value;
//}
//
//void Get_ADC()
//{
//    uint8 AD_LL = 0;
//    uint8 AD_LC = 0;
//    uint8 AD_CC = 0;
//    uint8 AD_CR = 0;
//    uint8 AD_RR = 0;
//    uint8 AD_L1 = 0;
//    uint8 AD_R1 = 0;
//
//    int max_dg = 30;
//
//    float32 AD_0 = 0;
//    float32 AD_1 = 0;
//    float32 AD_2 = 0;
//    float32 AD_3 = 0;
//    float32 AD_4 = 0;
//    float32 AD_5 = 0;
//    float32 AD_6 = 0;
//    float32 AD_7 = 0;
//
//    /*for(i=0;i<12;i++)
//      {
//       AD_LL  +=Acquisition_Once(0);
//       AD_LR  +=Acquisition_Once(1);
//       AD_RL  +=Acquisition_Once(2);
//       AD_RR  +=Acquisition_Once(3);
//       AD_B_R +=Acquisition_Once(4);
//       AD_F   +=Acquisition_Once(5);
//       AD_B_L +=Acquisition_Once(6);
//       }*/
//
//    // DB.LL = Acquisition_Once(4) * 1.0;
//    // DB.LC = Acquisition_Once(2) * 1.0;
//    // DB.CC = Acquisition_Once(6) * 1.0;
//    // DB.CR = Acquisition_Once(1) * 1.0;
//    // DB.RR = Acquisition_Once(3) * 1.0;
//    // DB.L1 = Acquisition_Once(7) * 1.0;
//    // DB.R1 = Acquisition_Once(5) * 1.0;
//
//    AD_LL = Acquisition_Once(4); // 获得adc值
//    AD_LC = Acquisition_Once(2);
//    AD_CC = Acquisition_Once(6);
//    AD_CR = Acquisition_Once(1);
//    AD_RR = Acquisition_Once(3);
//    AD_L1 = Acquisition_Once(7);
//    AD_R1 = Acquisition_Once(5);
//
//    AD_0 = AD_L1 * 1.0f;
//    AD_7 = AD_CC * 1.0f;
//    AD_2 = AD_LC * 1.0f;
//    AD_3 = AD_LL * 1.0f;
//    AD_4 = AD_CR * 1.0f;
//    AD_5 = AD_RR * 1.0f;
//    AD_6 = AD_R1 * 1.0f;
//
//    /*
//        AD_3=((AD_LL / 12.0f) / 4095.0f) * 24.0f;
//        AD_6=((AD_LC / 12.0f) / 4095.0f) * 24.0f;
//        AD_7=((AD_CC / 12.0f) / 4095.0f) * 27.0f;
//        AD_2=((AD_CR / 12.0f) / 4095.0f) * 24.0f;
//        AD_5=((AD_RR / 12.0f) / 4095.0f) * 12.0f;
//        AD_0=((AD_L1 / 12.0f) / 4095.0f) * 12.0f;
//        AD_4=((AD_R1 / 12.0f) / 4095.0f) * 12.0f;
//    */
//    // 归一化
//    // LL_f = ((LL_f - TL_Min)  / TL_Max) * 100.0f;
//    AD_0 = (AD_0 / max_dg) * 1.0f;
//    AD_1 = (AD_1 / max_dg) * 1.0f;
//    AD_2 = (AD_2 / max_dg) * 1.0f;
//    AD_3 = (AD_3 / max_dg) * 1.0f;
//    AD_4 = (AD_4 / max_dg) * 1.0f;
//    AD_5 = (AD_5 / max_dg) * 1.0f;
//    AD_6 = (AD_6 / max_dg) * 1.0f;
//
//    // RR_f = ((RR_f - TR_Min） / TR_Max) *100.0f;
//    // 归一化限幅
//    AD_0 = AD_0 > 100.0f ? 100.0f : AD_0;
//    AD_1 = AD_1 > 100.0f ? 100.0f : AD_1;
//    AD_2 = AD_2 > 100.0f ? 100.0f : AD_2;
//    AD_3 = AD_3 > 100.0f ? 100.0f : AD_3;
//    AD_4 = AD_4 > 100.0f ? 100.0f : AD_4;
//    AD_5 = AD_5 > 100.0f ? 100.0f : AD_5;
//    AD_6 = AD_6 > 100.0f ? 100.0f : AD_6;
//
//    AD_0 = AD_0 < 5.0f ? 5.0f : AD_0;
//    AD_1 = AD_1 < 5.0f ? 5.0f : AD_1;
//    AD_2 = AD_2 < 5.0f ? 5.0f : AD_2;
//    AD_3 = AD_3 < 5.0f ? 5.0f : AD_3;
//    AD_4 = AD_4 < 5.0f ? 5.0f : AD_4;
//    AD_5 = AD_5 < 5.0f ? 5.0f : AD_5;
//    AD_6 = AD_6 < 5.0f ? 5.0f : AD_6;
//
//    // Normalization_H = myabs(AD_LL - AD_RR);
//    // Normalization_X = myabs(AD_LC - AD_CR);
//    // Normalization_S = myabs(AD_L1 - AD_R1);
//    /*
//                DB.LL  = AD_3;
//                DB.CR  = AD_4;
//                DB.CC  = AD_7;
//                DB.R1  = AD_6;
//                DB.RR  = AD_5;
//                DB.L1  = AD_0;
//                DB.LC  = AD_2;
//    */
//    // 差比荷
//    // Normalization_S=( (LL - RR) / (LL + RR) )*100;// 竖 0~100
//    // Normalization_H=( (LR - RL) / (LR + RL) )*100;// 横 0~100
//    // Normalization_M=( (L - R)  / (L + R) )*100;//  中 0~100
//    // Normalization_L=( (LR - L) / (LR + L) )*100;// 左 0~100
//    // Normalization_R=( (RL - R) / (RL + R) )*100;// 右 0~100
//    // Normalization_ZD=( ((LL + LR) - (RR + RL)) / ((LL+LR)+(RR+RL)) );
//}
//
//void err_get(float adc_L, float adc_LM, float adc_RM, float adc_R, float A, float B)
//{
//    float temp_add1 = 0, temp_add2 = 0, temp_sub1 = 0, temp_sub2 = 0, err_back; // bais=开根号的adc值相减，此函数还未更改。仅更改最外侧的
//    temp_sub1 = adc_L - adc_R;
//    temp_sub2 = adc_LM - adc_RM;
//    temp_add1 = adc_L + adc_R;
//    temp_add2 = adc_LM + adc_RM;
//
//    err_back = (A * temp_sub1 + B * temp_sub2) / (A * temp_add1 + B * temp_add2);
//    // return err_back;
//}
