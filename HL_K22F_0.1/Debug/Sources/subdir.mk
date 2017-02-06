################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Events.c \
../Sources/MMA8451.c \
../Sources/SendData.c \
../Sources/lumiere.c \
../Sources/main.c 

OBJS += \
./Sources/Events.o \
./Sources/MMA8451.o \
./Sources/SendData.o \
./Sources/lumiere.o \
./Sources/main.o 

C_DEPS += \
./Sources/Events.d \
./Sources/MMA8451.d \
./Sources/SendData.d \
./Sources/lumiere.d \
./Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/Repositories/Kinetis_Repository/lib/Kinetis/pdd2/MK22FN512DC12/system" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:\Freescale\KDS_v3\eclipse\ProcessorExpert/lib/Kinetis/iofiles" -I"C:/Users/Romain/workspace.kds/HL_K22F_0.1/Sources" -I"C:/Users/Romain/workspace.kds/HL_K22F_0.1/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


