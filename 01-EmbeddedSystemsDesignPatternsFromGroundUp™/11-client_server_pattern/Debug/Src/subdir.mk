################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ArrythmiaDetector.c \
../Src/ECG_Module.c \
../Src/HistogramDisplay.c \
../Src/QRSDetector.c \
../Src/SystemManager.c \
../Src/TMDQueue.c \
../Src/adc_driver.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/uart.c 

OBJS += \
./Src/ArrythmiaDetector.o \
./Src/ECG_Module.o \
./Src/HistogramDisplay.o \
./Src/QRSDetector.o \
./Src/SystemManager.o \
./Src/TMDQueue.o \
./Src/adc_driver.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/uart.o 

C_DEPS += \
./Src/ArrythmiaDetector.d \
./Src/ECG_Module.d \
./Src/HistogramDisplay.d \
./Src/QRSDetector.d \
./Src/SystemManager.d \
./Src/TMDQueue.d \
./Src/adc_driver.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -DNUCLEO_F446RE -DSTM32F446xx -c -I../Inc -I../$(ProjDirPath)/chip_headers/CMSIS/Include -I../$(ProjDirPath)/chip_headers/CMSIS/Device/ST/STM32F4xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/ArrythmiaDetector.cyclo ./Src/ArrythmiaDetector.d ./Src/ArrythmiaDetector.o ./Src/ArrythmiaDetector.su ./Src/ECG_Module.cyclo ./Src/ECG_Module.d ./Src/ECG_Module.o ./Src/ECG_Module.su ./Src/HistogramDisplay.cyclo ./Src/HistogramDisplay.d ./Src/HistogramDisplay.o ./Src/HistogramDisplay.su ./Src/QRSDetector.cyclo ./Src/QRSDetector.d ./Src/QRSDetector.o ./Src/QRSDetector.su ./Src/SystemManager.cyclo ./Src/SystemManager.d ./Src/SystemManager.o ./Src/SystemManager.su ./Src/TMDQueue.cyclo ./Src/TMDQueue.d ./Src/TMDQueue.o ./Src/TMDQueue.su ./Src/adc_driver.cyclo ./Src/adc_driver.d ./Src/adc_driver.o ./Src/adc_driver.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/uart.cyclo ./Src/uart.d ./Src/uart.o ./Src/uart.su

.PHONY: clean-Src

