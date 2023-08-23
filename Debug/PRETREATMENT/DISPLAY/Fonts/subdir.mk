################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PRETREATMENT/DISPLAY/Fonts/font12.c \
../PRETREATMENT/DISPLAY/Fonts/font12CN.c \
../PRETREATMENT/DISPLAY/Fonts/font16.c \
../PRETREATMENT/DISPLAY/Fonts/font20.c \
../PRETREATMENT/DISPLAY/Fonts/font24.c \
../PRETREATMENT/DISPLAY/Fonts/font24CN.c \
../PRETREATMENT/DISPLAY/Fonts/font8.c 

OBJS += \
./PRETREATMENT/DISPLAY/Fonts/font12.o \
./PRETREATMENT/DISPLAY/Fonts/font12CN.o \
./PRETREATMENT/DISPLAY/Fonts/font16.o \
./PRETREATMENT/DISPLAY/Fonts/font20.o \
./PRETREATMENT/DISPLAY/Fonts/font24.o \
./PRETREATMENT/DISPLAY/Fonts/font24CN.o \
./PRETREATMENT/DISPLAY/Fonts/font8.o 

C_DEPS += \
./PRETREATMENT/DISPLAY/Fonts/font12.d \
./PRETREATMENT/DISPLAY/Fonts/font12CN.d \
./PRETREATMENT/DISPLAY/Fonts/font16.d \
./PRETREATMENT/DISPLAY/Fonts/font20.d \
./PRETREATMENT/DISPLAY/Fonts/font24.d \
./PRETREATMENT/DISPLAY/Fonts/font24CN.d \
./PRETREATMENT/DISPLAY/Fonts/font8.d 


# Each subdirectory must supply rules for building sources it contributes
PRETREATMENT/DISPLAY/Fonts/%.o PRETREATMENT/DISPLAY/Fonts/%.su PRETREATMENT/DISPLAY/Fonts/%.cyclo: ../PRETREATMENT/DISPLAY/Fonts/%.c PRETREATMENT/DISPLAY/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L151xC -c -I../Core/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L1xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-PRETREATMENT-2f-DISPLAY-2f-Fonts

clean-PRETREATMENT-2f-DISPLAY-2f-Fonts:
	-$(RM) ./PRETREATMENT/DISPLAY/Fonts/font12.cyclo ./PRETREATMENT/DISPLAY/Fonts/font12.d ./PRETREATMENT/DISPLAY/Fonts/font12.o ./PRETREATMENT/DISPLAY/Fonts/font12.su ./PRETREATMENT/DISPLAY/Fonts/font12CN.cyclo ./PRETREATMENT/DISPLAY/Fonts/font12CN.d ./PRETREATMENT/DISPLAY/Fonts/font12CN.o ./PRETREATMENT/DISPLAY/Fonts/font12CN.su ./PRETREATMENT/DISPLAY/Fonts/font16.cyclo ./PRETREATMENT/DISPLAY/Fonts/font16.d ./PRETREATMENT/DISPLAY/Fonts/font16.o ./PRETREATMENT/DISPLAY/Fonts/font16.su ./PRETREATMENT/DISPLAY/Fonts/font20.cyclo ./PRETREATMENT/DISPLAY/Fonts/font20.d ./PRETREATMENT/DISPLAY/Fonts/font20.o ./PRETREATMENT/DISPLAY/Fonts/font20.su ./PRETREATMENT/DISPLAY/Fonts/font24.cyclo ./PRETREATMENT/DISPLAY/Fonts/font24.d ./PRETREATMENT/DISPLAY/Fonts/font24.o ./PRETREATMENT/DISPLAY/Fonts/font24.su ./PRETREATMENT/DISPLAY/Fonts/font24CN.cyclo ./PRETREATMENT/DISPLAY/Fonts/font24CN.d ./PRETREATMENT/DISPLAY/Fonts/font24CN.o ./PRETREATMENT/DISPLAY/Fonts/font24CN.su ./PRETREATMENT/DISPLAY/Fonts/font8.cyclo ./PRETREATMENT/DISPLAY/Fonts/font8.d ./PRETREATMENT/DISPLAY/Fonts/font8.o ./PRETREATMENT/DISPLAY/Fonts/font8.su

.PHONY: clean-PRETREATMENT-2f-DISPLAY-2f-Fonts

