################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PROCESSING/SIM/sim.c 

OBJS += \
./PROCESSING/SIM/sim.o 

C_DEPS += \
./PROCESSING/SIM/sim.d 


# Each subdirectory must supply rules for building sources it contributes
PROCESSING/SIM/%.o PROCESSING/SIM/%.su PROCESSING/SIM/%.cyclo: ../PROCESSING/SIM/%.c PROCESSING/SIM/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L151xC -c -I../Core/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc -I../Drivers/STM32L1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L1xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-PROCESSING-2f-SIM

clean-PROCESSING-2f-SIM:
	-$(RM) ./PROCESSING/SIM/sim.cyclo ./PROCESSING/SIM/sim.d ./PROCESSING/SIM/sim.o ./PROCESSING/SIM/sim.su

.PHONY: clean-PROCESSING-2f-SIM

