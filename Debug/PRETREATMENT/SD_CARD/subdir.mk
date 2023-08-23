################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PRETREATMENT/SD_CARD/fatfs_sd.c \
../PRETREATMENT/SD_CARD/sd_card.c 

OBJS += \
./PRETREATMENT/SD_CARD/fatfs_sd.o \
./PRETREATMENT/SD_CARD/sd_card.o 

C_DEPS += \
./PRETREATMENT/SD_CARD/fatfs_sd.d \
./PRETREATMENT/SD_CARD/sd_card.d 


# Each subdirectory must supply rules for building sources it contributes
PRETREATMENT/SD_CARD/%.o PRETREATMENT/SD_CARD/%.su PRETREATMENT/SD_CARD/%.cyclo: ../PRETREATMENT/SD_CARD/%.c PRETREATMENT/SD_CARD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L151xC -c -I../Core/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L1xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-PRETREATMENT-2f-SD_CARD

clean-PRETREATMENT-2f-SD_CARD:
	-$(RM) ./PRETREATMENT/SD_CARD/fatfs_sd.cyclo ./PRETREATMENT/SD_CARD/fatfs_sd.d ./PRETREATMENT/SD_CARD/fatfs_sd.o ./PRETREATMENT/SD_CARD/fatfs_sd.su ./PRETREATMENT/SD_CARD/sd_card.cyclo ./PRETREATMENT/SD_CARD/sd_card.d ./PRETREATMENT/SD_CARD/sd_card.o ./PRETREATMENT/SD_CARD/sd_card.su

.PHONY: clean-PRETREATMENT-2f-SD_CARD

