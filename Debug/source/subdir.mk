################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/ADCfunctions.c \
../source/DACfunctions.c \
../source/DMAfunctions.c \
../source/TPMfunctions.c \
../source/autocorrelate.c \
../source/frequencytonesmain.c \
../source/mtb.c \
../source/semihost_hardfault.c \
../source/systick.c \
../source/test_sine.c 

O_SRCS += \
../source/fp_trig.o 

C_DEPS += \
./source/ADCfunctions.d \
./source/DACfunctions.d \
./source/DMAfunctions.d \
./source/TPMfunctions.d \
./source/autocorrelate.d \
./source/frequencytonesmain.d \
./source/mtb.d \
./source/semihost_hardfault.d \
./source/systick.d \
./source/test_sine.d 

OBJS += \
./source/ADCfunctions.o \
./source/DACfunctions.o \
./source/DMAfunctions.o \
./source/TPMfunctions.o \
./source/autocorrelate.o \
./source/frequencytonesmain.o \
./source/mtb.o \
./source/semihost_hardfault.o \
./source/systick.o \
./source/test_sine.o 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DFSL_RTOS_BM -DSDK_OS_BAREMETAL -DSDK_DEBUGCONSOLE=0 -DPRINTF_FLOAT_ENABLE=1 -DSDK_DEBUGCONSOLE_UART -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"C:\Users\USER\Documents\MCUXpressoIDE_11.6.0_8187\workspace\frequencytonesmain\board" -I"C:\Users\USER\Documents\MCUXpressoIDE_11.6.0_8187\workspace\frequencytonesmain\source" -I"C:\Users\USER\Documents\MCUXpressoIDE_11.6.0_8187\workspace\frequencytonesmain" -I"C:\Users\USER\Documents\MCUXpressoIDE_11.6.0_8187\workspace\frequencytonesmain\drivers" -I"C:\Users\USER\Documents\MCUXpressoIDE_11.6.0_8187\workspace\frequencytonesmain\CMSIS" -I"C:\Users\USER\Documents\MCUXpressoIDE_11.6.0_8187\workspace\frequencytonesmain\utilities" -I"C:\Users\USER\Documents\MCUXpressoIDE_11.6.0_8187\workspace\frequencytonesmain\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-source

clean-source:
	-$(RM) ./source/ADCfunctions.d ./source/ADCfunctions.o ./source/DACfunctions.d ./source/DACfunctions.o ./source/DMAfunctions.d ./source/DMAfunctions.o ./source/TPMfunctions.d ./source/TPMfunctions.o ./source/autocorrelate.d ./source/autocorrelate.o ./source/frequencytonesmain.d ./source/frequencytonesmain.o ./source/mtb.d ./source/mtb.o ./source/semihost_hardfault.d ./source/semihost_hardfault.o ./source/systick.d ./source/systick.o ./source/test_sine.d ./source/test_sine.o

.PHONY: clean-source

