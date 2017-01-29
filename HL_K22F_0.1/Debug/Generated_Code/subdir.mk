################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/AD1.c \
../Generated_Code/AD2.c \
../Generated_Code/ASerialLdd1.c \
../Generated_Code/AdcLdd1.c \
../Generated_Code/AdcLdd2.c \
../Generated_Code/BT1.c \
../Generated_Code/BitIoLdd1.c \
../Generated_Code/CI2C1.c \
../Generated_Code/CLS1.c \
../Generated_Code/CS1.c \
../Generated_Code/Cpu.c \
../Generated_Code/GI2C1.c \
../Generated_Code/KSDK1.c \
../Generated_Code/LED1.c \
../Generated_Code/LEDBlanche.c \
../Generated_Code/LEDRouge.c \
../Generated_Code/LEDVerte.c \
../Generated_Code/LEDpin1.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/Pins1.c \
../Generated_Code/PpgLdd1.c \
../Generated_Code/PpgLdd2.c \
../Generated_Code/PpgLdd3.c \
../Generated_Code/Serial1.c \
../Generated_Code/UTIL1.c \
../Generated_Code/WAIT1.c 

OBJS += \
./Generated_Code/AD1.o \
./Generated_Code/AD2.o \
./Generated_Code/ASerialLdd1.o \
./Generated_Code/AdcLdd1.o \
./Generated_Code/AdcLdd2.o \
./Generated_Code/BT1.o \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/CI2C1.o \
./Generated_Code/CLS1.o \
./Generated_Code/CS1.o \
./Generated_Code/Cpu.o \
./Generated_Code/GI2C1.o \
./Generated_Code/KSDK1.o \
./Generated_Code/LED1.o \
./Generated_Code/LEDBlanche.o \
./Generated_Code/LEDRouge.o \
./Generated_Code/LEDVerte.o \
./Generated_Code/LEDpin1.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/Pins1.o \
./Generated_Code/PpgLdd1.o \
./Generated_Code/PpgLdd2.o \
./Generated_Code/PpgLdd3.o \
./Generated_Code/Serial1.o \
./Generated_Code/UTIL1.o \
./Generated_Code/WAIT1.o 

C_DEPS += \
./Generated_Code/AD1.d \
./Generated_Code/AD2.d \
./Generated_Code/ASerialLdd1.d \
./Generated_Code/AdcLdd1.d \
./Generated_Code/AdcLdd2.d \
./Generated_Code/BT1.d \
./Generated_Code/BitIoLdd1.d \
./Generated_Code/CI2C1.d \
./Generated_Code/CLS1.d \
./Generated_Code/CS1.d \
./Generated_Code/Cpu.d \
./Generated_Code/GI2C1.d \
./Generated_Code/KSDK1.d \
./Generated_Code/LED1.d \
./Generated_Code/LEDBlanche.d \
./Generated_Code/LEDRouge.d \
./Generated_Code/LEDVerte.d \
./Generated_Code/LEDpin1.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/Pins1.d \
./Generated_Code/PpgLdd1.d \
./Generated_Code/PpgLdd2.d \
./Generated_Code/PpgLdd3.d \
./Generated_Code/Serial1.d \
./Generated_Code/UTIL1.d \
./Generated_Code/WAIT1.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/Kinetis_Repository/lib/Kinetis/pdd2/MK22FN512DC12/system" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/iofiles" -I"C:/Users/Romain/workspace.kds/HL_K22F_0.1/Sources" -I"C:/Users/Romain/workspace.kds/HL_K22F_0.1/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


