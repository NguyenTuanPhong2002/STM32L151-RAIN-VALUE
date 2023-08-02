################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/SIM7600/sim7600.c 

OBJS += \
./Core/SIM7600/sim7600.o 

C_DEPS += \
./Core/SIM7600/sim7600.d 


# Each subdirectory must supply rules for building sources it contributes
Core/SIM7600/%.o Core/SIM7600/%.su Core/SIM7600/%.cyclo: ../Core/SIM7600/%.c Core/SIM7600/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L151xC -c -I../Core/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-SIM7600

clean-Core-2f-SIM7600:
	-$(RM) ./Core/SIM7600/sim7600.cyclo ./Core/SIM7600/sim7600.d ./Core/SIM7600/sim7600.o ./Core/SIM7600/sim7600.su

.PHONY: clean-Core-2f-SIM7600

