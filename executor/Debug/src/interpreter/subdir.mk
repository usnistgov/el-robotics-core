################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/interpreter/CanonicalRobotCommand.cc \
../src/interpreter/FileOperator.cc \
../src/interpreter/KittingPDDLProblem.cc \
../src/interpreter/KittingPlan.cc 

OBJS += \
./src/interpreter/CanonicalRobotCommand.o \
./src/interpreter/FileOperator.o \
./src/interpreter/KittingPDDLProblem.o \
./src/interpreter/KittingPlan.o 

CC_DEPS += \
./src/interpreter/CanonicalRobotCommand.d \
./src/interpreter/FileOperator.d \
./src/interpreter/KittingPDDLProblem.d \
./src/interpreter/KittingPlan.d 


# Each subdirectory must supply rules for building sources it contributes
src/interpreter/%.o: ../src/interpreter/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/zeid/workspace/executor/src/controller" -O0 -g3 -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


