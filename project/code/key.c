#include "key.h"

uint8 key1_status    = 1;
uint8 key2_status    = 1;
uint8 key3_status    = 1;
uint8 key4_status    = 1;
uint8 switch1_status = 1;
uint8 switch2_status = 1;

uint8 key1_last_status, key2_last_status, key3_last_status, key4_last_status;
uint8 switch1_last_status, switch2_last_status;

uint8 key1_flag, key2_flag, key3_flag, key4_flag;
uint8 switch1_flag, switch2_flag;

uint8 Menu_row = 0;

bool key_switch(void)
{

    key1_last_status    = key1_status;
    key2_last_status    = key2_status;
    key3_last_status    = key3_status;
    key4_last_status    = key4_status;


    key1_status = gpio_get_level(KEY1);
    key2_status = gpio_get_level(KEY2);
    key3_status = gpio_get_level(KEY3);
    key4_status = gpio_get_level(KEY4);



    if (key1_status && !key1_last_status)
        key1_flag = 1;
    if (key2_status && !key2_last_status)
        key2_flag = 1;
    if (key3_status && !key3_last_status)
        key3_flag = 1;
    if (key4_status && !key4_last_status)
        key4_flag = 1;

    return key1_flag | key2_flag | key3_flag | key4_flag ;
}

void key_flag_clear(void)
{
    key1_flag = 0;
    key2_flag = 0;
    key3_flag = 0;
    key4_flag = 0;
}
