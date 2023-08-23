################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SIM7600/sim7600.c 

OBJS += \
./SIM7600/sim7600.o 

C_DEPS += \
./SIM7600/sim7600.d 


# Each subdirectory must supply rules for building sources it contributes
SIM7600/%.o SIM7600/%.su SIM7600/%.cyclo: ../SIM7600/%.c SIM7600/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L151xC -c -I../Core/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L1xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-SIM7600

clean-SIM7600:
	-$(RM) ./SIM7600/sim7600.cyclo ./SIM7600/sim7600.d ./SIM7600/sim7600.o ./SIM7600/sim7600.su

.PHONY: clean-SIM7600

