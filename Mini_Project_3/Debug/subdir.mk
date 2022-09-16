################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Driver.c \
../App.c \
../GPIO.c \
../LCD.c \
../dc_motor.c \
../lm35_sensor.c \
../pwm_Driver.c 

OBJS += \
./ADC_Driver.o \
./App.o \
./GPIO.o \
./LCD.o \
./dc_motor.o \
./lm35_sensor.o \
./pwm_Driver.o 

C_DEPS += \
./ADC_Driver.d \
./App.d \
./GPIO.d \
./LCD.d \
./dc_motor.d \
./lm35_sensor.d \
./pwm_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


