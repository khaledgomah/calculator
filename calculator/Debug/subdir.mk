################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_prog.c \
../KBD_prog.c \
../LCD_prog.c \
../main.c \
../math_functions.c 

OBJS += \
./DIO_prog.o \
./KBD_prog.o \
./LCD_prog.o \
./main.o \
./math_functions.o 

C_DEPS += \
./DIO_prog.d \
./KBD_prog.d \
./LCD_prog.d \
./main.d \
./math_functions.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


