################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ACTUATOR_program.c \
../CommunicationLinker.c \
../DIO_program.c \
../EXTI_program.c \
../GIE_program.c \
../PORT_program.c \
../SPI_program.c \
../TIMERS_program.c \
../UART_program.c \
../application.c 

OBJS += \
./ACTUATOR_program.o \
./CommunicationLinker.o \
./DIO_program.o \
./EXTI_program.o \
./GIE_program.o \
./PORT_program.o \
./SPI_program.o \
./TIMERS_program.o \
./UART_program.o \
./application.o 

C_DEPS += \
./ACTUATOR_program.d \
./CommunicationLinker.d \
./DIO_program.d \
./EXTI_program.d \
./GIE_program.d \
./PORT_program.d \
./SPI_program.d \
./TIMERS_program.d \
./UART_program.d \
./application.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


