################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SD_CARD/fatfs_sd.c \
../SD_CARD/sd.c 

OBJS += \
./SD_CARD/fatfs_sd.o \
./SD_CARD/sd.o 

C_DEPS += \
./SD_CARD/fatfs_sd.d \
./SD_CARD/sd.d 


# Each subdirectory must supply rules for building sources it contributes
SD_CARD/%.o SD_CARD/%.su SD_CARD/%.cyclo: ../SD_CARD/%.c SD_CARD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L151xC -c -I../Core/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L1xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-SD_CARD

clean-SD_CARD:
	-$(RM) ./SD_CARD/fatfs_sd.cyclo ./SD_CARD/fatfs_sd.d ./SD_CARD/fatfs_sd.o ./SD_CARD/fatfs_sd.su ./SD_CARD/sd.cyclo ./SD_CARD/sd.d ./SD_CARD/sd.o ./SD_CARD/sd.su

.PHONY: clean-SD_CARD

