################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DISPLAY/Fonts/font12.c \
../DISPLAY/Fonts/font12CN.c \
../DISPLAY/Fonts/font16.c \
../DISPLAY/Fonts/font20.c \
../DISPLAY/Fonts/font24.c \
../DISPLAY/Fonts/font24CN.c \
../DISPLAY/Fonts/font8.c 

OBJS += \
./DISPLAY/Fonts/font12.o \
./DISPLAY/Fonts/font12CN.o \
./DISPLAY/Fonts/font16.o \
./DISPLAY/Fonts/font20.o \
./DISPLAY/Fonts/font24.o \
./DISPLAY/Fonts/font24CN.o \
./DISPLAY/Fonts/font8.o 

C_DEPS += \
./DISPLAY/Fonts/font12.d \
./DISPLAY/Fonts/font12CN.d \
./DISPLAY/Fonts/font16.d \
./DISPLAY/Fonts/font20.d \
./DISPLAY/Fonts/font24.d \
./DISPLAY/Fonts/font24CN.d \
./DISPLAY/Fonts/font8.d 


# Each subdirectory must supply rules for building sources it contributes
DISPLAY/Fonts/%.o DISPLAY/Fonts/%.su DISPLAY/Fonts/%.cyclo: ../DISPLAY/Fonts/%.c DISPLAY/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L151xC -c -I../Core/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L1xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-DISPLAY-2f-Fonts

clean-DISPLAY-2f-Fonts:
	-$(RM) ./DISPLAY/Fonts/font12.cyclo ./DISPLAY/Fonts/font12.d ./DISPLAY/Fonts/font12.o ./DISPLAY/Fonts/font12.su ./DISPLAY/Fonts/font12CN.cyclo ./DISPLAY/Fonts/font12CN.d ./DISPLAY/Fonts/font12CN.o ./DISPLAY/Fonts/font12CN.su ./DISPLAY/Fonts/font16.cyclo ./DISPLAY/Fonts/font16.d ./DISPLAY/Fonts/font16.o ./DISPLAY/Fonts/font16.su ./DISPLAY/Fonts/font20.cyclo ./DISPLAY/Fonts/font20.d ./DISPLAY/Fonts/font20.o ./DISPLAY/Fonts/font20.su ./DISPLAY/Fonts/font24.cyclo ./DISPLAY/Fonts/font24.d ./DISPLAY/Fonts/font24.o ./DISPLAY/Fonts/font24.su ./DISPLAY/Fonts/font24CN.cyclo ./DISPLAY/Fonts/font24CN.d ./DISPLAY/Fonts/font24CN.o ./DISPLAY/Fonts/font24CN.su ./DISPLAY/Fonts/font8.cyclo ./DISPLAY/Fonts/font8.d ./DISPLAY/Fonts/font8.o ./DISPLAY/Fonts/font8.su

.PHONY: clean-DISPLAY-2f-Fonts

