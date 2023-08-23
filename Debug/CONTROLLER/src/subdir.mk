################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CONTROLLER/src/getdata.c \
../CONTROLLER/src/maincontroller.c 

OBJS += \
./CONTROLLER/src/getdata.o \
./CONTROLLER/src/maincontroller.o 

C_DEPS += \
./CONTROLLER/src/getdata.d \
./CONTROLLER/src/maincontroller.d 


# Each subdirectory must supply rules for building sources it contributes
CONTROLLER/src/%.o CONTROLLER/src/%.su CONTROLLER/src/%.cyclo: ../CONTROLLER/src/%.c CONTROLLER/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L151xC -c -I../Core/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L1xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-CONTROLLER-2f-src

clean-CONTROLLER-2f-src:
	-$(RM) ./CONTROLLER/src/getdata.cyclo ./CONTROLLER/src/getdata.d ./CONTROLLER/src/getdata.o ./CONTROLLER/src/getdata.su ./CONTROLLER/src/maincontroller.cyclo ./CONTROLLER/src/maincontroller.d ./CONTROLLER/src/maincontroller.o ./CONTROLLER/src/maincontroller.su

.PHONY: clean-CONTROLLER-2f-src

