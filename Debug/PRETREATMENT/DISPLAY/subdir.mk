################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PRETREATMENT/DISPLAY/GUI_Paint.c \
../PRETREATMENT/DISPLAY/configure.c \
../PRETREATMENT/DISPLAY/display.c 

OBJS += \
./PRETREATMENT/DISPLAY/GUI_Paint.o \
./PRETREATMENT/DISPLAY/configure.o \
./PRETREATMENT/DISPLAY/display.o 

C_DEPS += \
./PRETREATMENT/DISPLAY/GUI_Paint.d \
./PRETREATMENT/DISPLAY/configure.d \
./PRETREATMENT/DISPLAY/display.d 


# Each subdirectory must supply rules for building sources it contributes
PRETREATMENT/DISPLAY/%.o PRETREATMENT/DISPLAY/%.su PRETREATMENT/DISPLAY/%.cyclo: ../PRETREATMENT/DISPLAY/%.c PRETREATMENT/DISPLAY/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L151xC -c -I../Core/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L1xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-PRETREATMENT-2f-DISPLAY

clean-PRETREATMENT-2f-DISPLAY:
	-$(RM) ./PRETREATMENT/DISPLAY/GUI_Paint.cyclo ./PRETREATMENT/DISPLAY/GUI_Paint.d ./PRETREATMENT/DISPLAY/GUI_Paint.o ./PRETREATMENT/DISPLAY/GUI_Paint.su ./PRETREATMENT/DISPLAY/configure.cyclo ./PRETREATMENT/DISPLAY/configure.d ./PRETREATMENT/DISPLAY/configure.o ./PRETREATMENT/DISPLAY/configure.su ./PRETREATMENT/DISPLAY/display.cyclo ./PRETREATMENT/DISPLAY/display.d ./PRETREATMENT/DISPLAY/display.o ./PRETREATMENT/DISPLAY/display.su

.PHONY: clean-PRETREATMENT-2f-DISPLAY

