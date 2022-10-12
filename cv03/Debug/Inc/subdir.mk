################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Inc/sct.c 

OBJS += \
./Inc/sct.o 

C_DEPS += \
./Inc/sct.d 


# Each subdirectory must supply rules for building sources it contributes
Inc/%.o Inc/%.su: ../Inc/%.c Inc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0 -std=gnu11 -g3 -DDEBUG -DSTM32F030x8 -DSTM32F030R8Tx -DSTM32 -DSTM32F0 -DNUCLEO_F030R8 -c -I../Inc -I"C:/Temp/Sedlacek/MKS/cv03/CMSIS/Include" -I"C:/Temp/Sedlacek/MKS/cv03/CMSIS/Device/ST/STM32F0xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Inc

clean-Inc:
	-$(RM) ./Inc/sct.d ./Inc/sct.o ./Inc/sct.su

.PHONY: clean-Inc

