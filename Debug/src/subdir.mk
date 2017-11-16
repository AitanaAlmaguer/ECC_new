################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/APP.c \
../src/Initialization.c \
../src/Measurements.c \
../src/Timer.c \
../src/cr_startup_lpc11xx.c \
../src/crp.c \
../src/gpio.c 

OBJS += \
./src/APP.o \
./src/Initialization.o \
./src/Measurements.o \
./src/Timer.o \
./src/cr_startup_lpc11xx.o \
./src/crp.o \
./src/gpio.o 

C_DEPS += \
./src/APP.d \
./src/Initialization.d \
./src/Measurements.d \
./src/Timer.d \
./src/cr_startup_lpc11xx.d \
./src/crp.d \
./src/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M0 -D__USE_CMSIS=CMSISv2p00_LPC11xx -D__LPC11XX__ -D__REDLIB__ -I"P:\Eigenprojekte\NXP\NXPriment\APP\CMSISv2p00_LPC11xx\inc" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


