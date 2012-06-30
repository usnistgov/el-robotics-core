################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/controller/controller.cpp \
../src/controller/myController.cpp \
../src/controller/ulapi.cpp 

OBJS += \
./src/controller/controller.o \
./src/controller/myController.o \
./src/controller/ulapi.o 

CPP_DEPS += \
./src/controller/controller.d \
./src/controller/myController.d \
./src/controller/ulapi.d 


# Each subdirectory must supply rules for building sources it contributes
src/controller/%.o: ../src/controller/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/zeid/workspace/executor/src/controller" -O0 -g3 -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


