#ifndef _CAMERAPARAMS_H_
#define _CAMERAPARAMS_H_

#include "zf_common_headfile.h"
#include "headfile.h"
#include "imgStruct.h"

/*每米的像素点*/
extern const float32 PixelperMeter;

/*逆透视转换矩阵*/
// extern const float32 INV_PERS[3][3];

/*逆透视打表数组*/
extern uint8 Inv_x[5640];
extern uint8 Inv_y[5640];
extern uint8 Inv_x_imge[5640];
extern uint8 Inv_y_imge[5640];

#endif /* CODE_CAMERAPARAMS_H_ */
