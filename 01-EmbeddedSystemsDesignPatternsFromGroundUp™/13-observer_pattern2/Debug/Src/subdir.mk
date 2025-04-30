################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/adc_driver.c \
../Src/env_display_client.c \
../Src/env_sensor.c \
../Src/fertilizer_mixer_client.c \
../Src/gpio_driver.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/uart.c 

OBJS += \
./Src/adc_driver.o \
./Src/env_display_client.o \
./Src/env_sensor.o \
./Src/fertilizer_mixer_client.o \
./Src/gpio_driver.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/uart.o 

C_DEPS += \
./Src/adc_driver.d \
./Src/env_display_client.d \
./Src/env_sensor.d \
./Src/fertilizer_mixer_client.d \
./Src/gpio_driver.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DSTM32F446xx -c -I../Inc -I../$(ProjDirPath)/chip_headers/CMSIS/Include -I../$(ProjDirPath)/chip_headers/CMSIS/Device/ST/STM32F4xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/adc_driver.cyclo ./Src/adc_driver.d ./Src/adc_driver.o ./Src/adc_driver.su ./Src/env_display_client.cyclo ./Src/env_display_client.d ./Src/env_display_client.o ./Src/env_display_client.su ./Src/env_sensor.cyclo ./Src/env_sensor.d ./Src/env_sensor.o ./Src/env_sensor.su ./Src/fertilizer_mixer_client.cyclo ./Src/fertilizer_mixer_client.d ./Src/fertilizer_mixer_client.o ./Src/fertilizer_mixer_client.su ./Src/gpio_driver.cyclo ./Src/gpio_driver.d ./Src/gpio_driver.o ./Src/gpio_driver.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/uart.cyclo ./Src/uart.d ./Src/uart.o ./Src/uart.su

.PHONY: clean-Src

