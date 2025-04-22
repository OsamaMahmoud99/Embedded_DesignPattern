################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/LTF_PhotodiodeProxy.c \
../Src/LTF_PulseOximetryAdapter.c \
../Src/OximetryDisplay.c \
../Src/TIA_PhotodiodeProxy.c \
../Src/TIA_PulseOximetryAdapter.c \
../Src/adc_driver.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/uart.c 

OBJS += \
./Src/LTF_PhotodiodeProxy.o \
./Src/LTF_PulseOximetryAdapter.o \
./Src/OximetryDisplay.o \
./Src/TIA_PhotodiodeProxy.o \
./Src/TIA_PulseOximetryAdapter.o \
./Src/adc_driver.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/uart.o 

C_DEPS += \
./Src/LTF_PhotodiodeProxy.d \
./Src/LTF_PulseOximetryAdapter.d \
./Src/OximetryDisplay.d \
./Src/TIA_PhotodiodeProxy.d \
./Src/TIA_PulseOximetryAdapter.d \
./Src/adc_driver.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DSTM32F446xx -c -I../Inc -I"G:/OSAMAA/EmbeddedSystem/17-Embedded C++/EmbeddedSystemsDesignPatternsFromGroundUp™/01-uart_driver/chip_headers/CMSIS/Include" -I"G:/OSAMAA/EmbeddedSystem/17-Embedded C++/EmbeddedSystemsDesignPatternsFromGroundUp™/01-uart_driver/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/LTF_PhotodiodeProxy.cyclo ./Src/LTF_PhotodiodeProxy.d ./Src/LTF_PhotodiodeProxy.o ./Src/LTF_PhotodiodeProxy.su ./Src/LTF_PulseOximetryAdapter.cyclo ./Src/LTF_PulseOximetryAdapter.d ./Src/LTF_PulseOximetryAdapter.o ./Src/LTF_PulseOximetryAdapter.su ./Src/OximetryDisplay.cyclo ./Src/OximetryDisplay.d ./Src/OximetryDisplay.o ./Src/OximetryDisplay.su ./Src/TIA_PhotodiodeProxy.cyclo ./Src/TIA_PhotodiodeProxy.d ./Src/TIA_PhotodiodeProxy.o ./Src/TIA_PhotodiodeProxy.su ./Src/TIA_PulseOximetryAdapter.cyclo ./Src/TIA_PulseOximetryAdapter.d ./Src/TIA_PulseOximetryAdapter.o ./Src/TIA_PulseOximetryAdapter.su ./Src/adc_driver.cyclo ./Src/adc_driver.d ./Src/adc_driver.o ./Src/adc_driver.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/uart.cyclo ./Src/uart.d ./Src/uart.o ./Src/uart.su

.PHONY: clean-Src

