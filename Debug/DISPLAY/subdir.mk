################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DISPLAY/GUI_Paint.c \
../DISPLAY/configure.c \
../DISPLAY/display.c 

OBJS += \
./DISPLAY/GUI_Paint.o \
./DISPLAY/configure.o \
./DISPLAY/display.o 

C_DEPS += \
./DISPLAY/GUI_Paint.d \
./DISPLAY/configure.d \
./DISPLAY/display.d 


# Each subdirectory must supply rules for building sources it contributes
DISPLAY/%.o DISPLAY/%.su DISPLAY/%.cyclo: ../DISPLAY/%.c DISPLAY/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L151xC -c -I../Core/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L1xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-DISPLAY

clean-DISPLAY:
	-$(RM) ./DISPLAY/GUI_Paint.cyclo ./DISPLAY/GUI_Paint.d ./DISPLAY/GUI_Paint.o ./DISPLAY/GUI_Paint.su ./DISPLAY/configure.cyclo ./DISPLAY/configure.d ./DISPLAY/configure.o ./DISPLAY/configure.su ./DISPLAY/display.cyclo ./DISPLAY/display.d ./DISPLAY/display.o ./DISPLAY/display.su

.PHONY: clean-DISPLAY

