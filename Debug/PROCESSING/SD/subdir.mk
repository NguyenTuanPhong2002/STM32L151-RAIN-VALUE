################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PROCESSING/SD/sd.c 

OBJS += \
./PROCESSING/SD/sd.o 

C_DEPS += \
./PROCESSING/SD/sd.d 


# Each subdirectory must supply rules for building sources it contributes
PROCESSING/SD/%.o PROCESSING/SD/%.su PROCESSING/SD/%.cyclo: ../PROCESSING/SD/%.c PROCESSING/SD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L151xC -c -I../Core/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L1xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-PROCESSING-2f-SD

clean-PROCESSING-2f-SD:
	-$(RM) ./PROCESSING/SD/sd.cyclo ./PROCESSING/SD/sd.d ./PROCESSING/SD/sd.o ./PROCESSING/SD/sd.su

.PHONY: clean-PROCESSING-2f-SD

