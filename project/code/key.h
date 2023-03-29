#ifndef _KEY_H_
#define _KEY_H_

#include "zf_common_headfile.h"
#include "headfile.h"

#define KEY1 (A8)
#define KEY2 (D8)
#define KEY3 (B12)
#define KEY4 (B0)

extern uint16 i;
extern uint8 key1_status, key2_status, key3_status, key4_status;
extern uint8 key1_last_status, key2_last_status, key3_last_status, key4_last_status;
extern uint8 key1_flag, key2_flag, key3_flag, key4_flag;

bool key_switch(void);
void key_flag_clear(void);

#endif
