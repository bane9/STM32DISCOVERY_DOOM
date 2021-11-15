################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../umm_malloc/umm_info.c \
../umm_malloc/umm_integrity.c \
../umm_malloc/umm_malloc.c \
../umm_malloc/umm_poison.c 

OBJS += \
./umm_malloc/umm_info.o \
./umm_malloc/umm_integrity.o \
./umm_malloc/umm_malloc.o \
./umm_malloc/umm_poison.o 

C_DEPS += \
./umm_malloc/umm_info.d \
./umm_malloc/umm_integrity.d \
./umm_malloc/umm_malloc.d \
./umm_malloc/umm_poison.d 


# Each subdirectory must supply rules for building sources it contributes
umm_malloc/%.o: ../umm_malloc/%.c umm_malloc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../USB_HOST/App -I../USB_HOST/Target -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc -I"C:/Users/Branislav/STM32CubeIDE/new/idk/DOOM/include" -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

