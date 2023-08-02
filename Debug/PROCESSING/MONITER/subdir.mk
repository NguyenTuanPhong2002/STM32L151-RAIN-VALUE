################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PROCESSING/MONITER/moniter.c 

OBJS += \
./PROCESSING/MONITER/moniter.o 

C_DEPS += \
./PROCESSING/MONITER/moniter.d 


# Each subdirectory must supply rules for building sources it contributes
PROCESSING/MONITER/%.o PROCESSING/MONITER/%.su PROCESSING/MONITER/%.cyclo: ../PROCESSING/MONITER/%.c PROCESSING/MONITER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L151xC -c -I../Core/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L1xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-PROCESSING-2f-MONITER

clean-PROCESSING-2f-MONITER:
	-$(RM) ./PROCESSING/MONITER/moniter.cyclo ./PROCESSING/MONITER/moniter.d ./PROCESSING/MONITER/moniter.o ./PROCESSING/MONITER/moniter.su

.PHONY: clean-PROCESSING-2f-MONITER

