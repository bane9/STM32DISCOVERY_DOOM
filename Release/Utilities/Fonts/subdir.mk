################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Utilities/Fonts/font12.c \
../Utilities/Fonts/font16.c \
../Utilities/Fonts/font20.c \
../Utilities/Fonts/font24.c \
../Utilities/Fonts/font8.c 

OBJS += \
./Utilities/Fonts/font12.o \
./Utilities/Fonts/font16.o \
./Utilities/Fonts/font20.o \
./Utilities/Fonts/font24.o \
./Utilities/Fonts/font8.o 

C_DEPS += \
./Utilities/Fonts/font12.d \
./Utilities/Fonts/font16.d \
./Utilities/Fonts/font20.d \
./Utilities/Fonts/font24.d \
./Utilities/Fonts/font8.d 


# Each subdirectory must supply rules for building sources it contributes
Utilities/Fonts/%.o: ../Utilities/Fonts/%.c Utilities/Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../USB_HOST/App -I../USB_HOST/Target -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc -I"C:/Users/Branislav/STM32CubeIDE/new/idk/DOOM/include" -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

