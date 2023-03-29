#include "Initall.h"

int8 start_flag = 0;

void Duoji_Init(void)
{
    pwm_init(DUOJI_CHANY, 50, Duoji_Duty);
    Duoji_Duty = Duoji_Duty_Midmum;
}

void Motor_Init(void)
{
    pwm_init(MOTOR1_PWM, 17000, 0);
    gpio_init(MOTOR1_DIR, GPO, 0, GPO_PUSH_PULL);
    pwm_init(MOTOR2_PWM, 17000, 0);
    gpio_init(MOTOR2_DIR, GPO, 0, GPO_PUSH_PULL);
}

void PIT_Init(void)
{

    pit_ms_init(TIM6_PIT, 1);
    interrupt_set_priority(TIM6_IRQn, 0); // 中断优先级越低越高

    pit_ms_init(TIM5_PIT, 5);
    interrupt_set_priority(TIM5_IRQn, 1);
}

void Encoder_Init(void)
{

    // 一个定时器只能做一件事情。例如这个编码器用作了PWM输出，就不能做其他的用了。
    // 使用定时器1做编码器解码(正交解码模式)
    encoder_quad_init(TIM1_ENCOEDER, TIM1_ENCOEDER_MAP3_CH1_E9, TIM1_ENCOEDER_MAP3_CH2_E11);

    // 使用定时器9做编码器解码(正交解码模式)
    encoder_quad_init(TIM9_ENCOEDER, TIM9_ENCOEDER_MAP3_CH1_D9, TIM9_ENCOEDER_MAP3_CH2_D11);
}

//----------------------------------------------------------参数初始化--------------------------------------------------------------//
//----------------------------------------------------------参数初始化--------------------------------------------------------------//
//----------------------------------------------------------参数初始化--------------------------------------------------------------//
//----------------------------------------------------------参数初始化--------------------------------------------------------------//

void Motor_L_Init(void) // 左轮基本参数初始化
{
    Motor_Left.result      = 0;
    Motor_Left.setpoint    = 100 - Speed_Bia; // 设定编码器的值
    Motor_Left.maximum     = 8000;            // 输出最大值
    Motor_Left.minimum     = -8000;           // 输出最小值
}

void Motor_R_Init(void) // 右轮基本参数初始化
{
    Motor_Right.result      = 0;
    Motor_Right.setpoint    = 100;
    Motor_Right.maximum     = 8000;
    Motor_Right.minimum     = -8000;
}

void MOTOR_PID_Init(void) // 后轮控制参数初始化
{
    /****************************增量式ʽ********************************/


    /*****变积分参数******/
    MOTOR.L_Max_I = 6;    // 0.15
    MOTOR.L_Ci    = 0.02; // Ci越小积分越快

    MOTOR.R_Max_I = 6; // 补偿
    MOTOR.R_Ci    = 0.02;

    /*****变比例参数*****/
    MOTOR.L_Bas_KP  = 50;
    MOTOR.L_Gain_KP = 20;
    MOTOR.L_Cp      = 0.02;

    MOTOR.R_Bas_KP  = 72;
    MOTOR.R_Gain_KP = 10;
    MOTOR.R_Cp      = 0.02;
}

void Duoji_PID_Init(void)
{

    Serve.KP = 0;
    Serve.KD = 0;

    // 变比例参数
    Serve.Kp_Gain = 1.5;
    Serve.Base    = 8;

    // 变微分参数
    Serve.Kd_Gain = 2;
}

void Chasu_Init(void) // 差速基本参数初始化
{
    CHASU.K       = 2.8; // 差速系数
    CHASU.maximun = 20;
}

void GYRO_Init(void) // 陀螺仪初始化
{
    gyro_z_0 = 0;
}

void Position_Init(void) // 位置环初始化
{

    Position.deadband = 0; /*死区*/ //! 要好好确定
    Position.maximum  = 40;         /*速度补偿上限*/
    Position.minimum  = -40;        /*速度降低下限*/
    Position.setpoint = 0;          // 设定位置

    Position.result = 0; // 输出值

    Position.KP = 0;
    Position.KD = 0;

    // 变积分参数
    // PositionMax_I = 0;
    // Position.Ci   = 0;

    // // 变比例参数
    // Bas_KP;
    // Gain_KP;
    // Cp;
}

void DATA_INIT(void)
{

    Img_data_init();
    Motor_L_Init();
    Motor_R_Init();
    MOTOR_PID_Init();
    Duoji_PID_Init();
    GYRO_Init();
}

void INITALL(void)
{
     interrupt_global_disable;      // 关闭总中断
     clock_init(SYSTEM_CLOCK_144M); // 初始化芯片时钟 工作频率为 144MHz
     debug_init();                  // 初始化默认 Debug UART

     ips200_init(IPS200_TYPE_PARALLEL8);
     ips200_set_color(RGB565_GREEN, RGB565_BLACK);
//     key_init(10);

     timer_init(TIM_3, TIMER_US);
     mt9v03x_init();
     Duoji_Init();
     Motor_Init();
     Encoder_Init();
//     wireless_uart_init();
     uart_init(UART1_MAP0_TX_A9, 115200, UART1_MAP0_TX_A9, UART1_MAP0_RX_A10);
     imu660ra_init();
     PIT_Init();
     DATA_INIT();
     interrupt_global_enable(0); // 开启总中断
}
