################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/Back_Wheel.c \
F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/CameraParams.c \
F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/Cross.c \
F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/Encoder.c \
F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/Initall.c \
F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/Menu.c \
F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/PM_Control.c \
F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/QMath.c \
F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/Roundabout.c \
F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/Steering.c \
F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/adc_dc.c \
F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/data.c \
F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/imagpro.c \
F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/imu.c \
F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/key.c 

OBJS += \
./code/Back_Wheel.o \
./code/CameraParams.o \
./code/Cross.o \
./code/Encoder.o \
./code/Initall.o \
./code/Menu.o \
./code/PM_Control.o \
./code/QMath.o \
./code/Roundabout.o \
./code/Steering.o \
./code/adc_dc.o \
./code/data.o \
./code/imagpro.o \
./code/imu.o \
./code/key.o 

C_DEPS += \
./code/Back_Wheel.d \
./code/CameraParams.d \
./code/Cross.d \
./code/Encoder.d \
./code/Initall.d \
./code/Menu.d \
./code/PM_Control.d \
./code/QMath.d \
./code/Roundabout.d \
./code/Steering.d \
./code/adc_dc.d \
./code/data.d \
./code/imagpro.d \
./code/imu.d \
./code/key.d 


# Each subdirectory must supply rules for building sources it contributes
code/Back_Wheel.o: F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/Back_Wheel.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\Libraries\doc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Core" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Ld" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Peripheral" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Startup" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\user\inc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_common" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_device" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\code" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/CameraParams.o: F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/CameraParams.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\Libraries\doc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Core" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Ld" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Peripheral" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Startup" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\user\inc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_common" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_device" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\code" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/Cross.o: F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/Cross.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\Libraries\doc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Core" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Ld" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Peripheral" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Startup" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\user\inc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_common" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_device" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\code" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/Encoder.o: F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/Encoder.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\Libraries\doc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Core" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Ld" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Peripheral" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Startup" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\user\inc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_common" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_device" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\code" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/Initall.o: F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/Initall.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\Libraries\doc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Core" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Ld" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Peripheral" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Startup" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\user\inc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_common" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_device" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\code" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/Menu.o: F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/Menu.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\Libraries\doc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Core" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Ld" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Peripheral" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Startup" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\user\inc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_common" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_device" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\code" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/PM_Control.o: F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/PM_Control.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\Libraries\doc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Core" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Ld" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Peripheral" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Startup" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\user\inc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_common" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_device" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\code" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/QMath.o: F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/QMath.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\Libraries\doc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Core" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Ld" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Peripheral" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Startup" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\user\inc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_common" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_device" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\code" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/Roundabout.o: F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/Roundabout.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\Libraries\doc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Core" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Ld" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Peripheral" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Startup" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\user\inc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_common" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_device" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\code" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/Steering.o: F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/Steering.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\Libraries\doc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Core" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Ld" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Peripheral" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Startup" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\user\inc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_common" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_device" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\code" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/adc_dc.o: F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/adc_dc.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\Libraries\doc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Core" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Ld" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Peripheral" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Startup" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\user\inc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_common" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_device" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\code" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/data.o: F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/data.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\Libraries\doc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Core" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Ld" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Peripheral" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Startup" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\user\inc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_common" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_device" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\code" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/imagpro.o: F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/imagpro.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\Libraries\doc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Core" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Ld" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Peripheral" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Startup" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\user\inc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_common" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_device" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\code" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/imu.o: F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/imu.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\Libraries\doc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Core" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Ld" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Peripheral" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Startup" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\user\inc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_common" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_device" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\code" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@
code/key.o: F:/Smartcar/Seekfree_CH32V307VCT6_Opensource_Library(1)/project/code/key.c
	@	@	riscv-none-embed-gcc -march=rv32imafc -mabi=ilp32f -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -pedantic -Wunused -Wuninitialized -Wall  -g -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\Libraries\doc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Core" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Ld" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Peripheral" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\sdk\Startup" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\user\inc" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_common" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_device" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\project\code" -I"F:\Smartcar\Seekfree_CH32V307VCT6_Opensource_Library(1)\libraries\zf_driver" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

