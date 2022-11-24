################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/DAC_ADC.c \
../source/DMAfunctions.c \
../source/Freqtones.c \
../source/TPMfunctions.c \
../source/autocorrelate.c \
../source/mtb.c \
../source/semihost_hardfault.c \
../source/systick.c \
../source/test_sine.c 

O_SRCS += \
../source/fp_trig.o 

C_DEPS += \
./source/DAC_ADC.d \
./source/DMAfunctions.d \
./source/Freqtones.d \
./source/TPMfunctions.d \
./source/autocorrelate.d \
./source/mtb.d \
./source/semihost_hardfault.d \
./source/systick.d \
./source/test_sine.d 

OBJS += \
./source/DAC_ADC.o \
./source/DMAfunctions.o \
./source/Freqtones.o \
./source/TPMfunctions.o \
./source/autocorrelate.o \
./source/mtb.o \
./source/semihost_hardfault.o \
./source/systick.o \
./source/test_sine.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DPRINTF_FLOAT_ENABLE=1 -DSDK_DEBUGCONSOLE_UART -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -DSDK_DEBUGCONSOLE=0 -I"C:\Users\USER\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Freqtones\board" -I"C:\Users\USER\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Freqtones\source" -I"C:\Users\USER\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Freqtones" -I"C:\Users\USER\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Freqtones\drivers" -I"C:\Users\USER\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Freqtones\CMSIS" -I"C:\Users\USER\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Freqtones\utilities" -I"C:\Users\USER\Documents\MCUXpressoIDE_11.6.0_8187\workspace\Freqtones\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/DAC_ADC.d ./source/DAC_ADC.o ./source/DMAfunctions.d ./source/DMAfunctions.o ./source/Freqtones.d ./source/Freqtones.o ./source/TPMfunctions.d ./source/TPMfunctions.o ./source/autocorrelate.d ./source/autocorrelate.o ./source/mtb.d ./source/mtb.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o ./source/systick.d ./source/systick.o ./source/test_sine.d ./source/test_sine.o

.PHONY: clean-source

