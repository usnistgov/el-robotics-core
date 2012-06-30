################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/database/BoxVolume.cpp \
../src/database/BoxyObject.cpp \
../src/database/Connection.cpp \
../src/database/DAO.cpp \
../src/database/DataThing.cpp \
../src/database/EndEffector.cpp \
../src/database/EndEffectorChangingStation.cpp \
../src/database/EndEffectorHolder.cpp \
../src/database/GripperEffector.cpp \
../src/database/Kit.cpp \
../src/database/KitDesign.cpp \
../src/database/KitTray.cpp \
../src/database/KittingWorkstation.cpp \
../src/database/LargeBoxWithEmptyKitTrays.cpp \
../src/database/LargeBoxWithKits.cpp \
../src/database/LargeContainer.cpp \
../src/database/Part.cpp \
../src/database/PartRefAndPose.cpp \
../src/database/PartsBin.cpp \
../src/database/PartsTray.cpp \
../src/database/PartsTrayWithParts.cpp \
../src/database/PhysicalLocation.cpp \
../src/database/Point.cpp \
../src/database/PoseLocation.cpp \
../src/database/PoseLocationIn.cpp \
../src/database/PoseLocationOn.cpp \
../src/database/PoseOnlyLocation.cpp \
../src/database/RelativeLocation.cpp \
../src/database/RelativeLocationIn.cpp \
../src/database/RelativeLocationOn.cpp \
../src/database/Robot.cpp \
../src/database/ShapeDesign.cpp \
../src/database/SolidObject.cpp \
../src/database/StockKeepingUnit.cpp \
../src/database/VacuumEffector.cpp \
../src/database/VacuumEffectorMultiCup.cpp \
../src/database/VacuumEffectorSingleCup.cpp \
../src/database/Vector.cpp \
../src/database/WorkTable.cpp 

OBJS += \
./src/database/BoxVolume.o \
./src/database/BoxyObject.o \
./src/database/Connection.o \
./src/database/DAO.o \
./src/database/DataThing.o \
./src/database/EndEffector.o \
./src/database/EndEffectorChangingStation.o \
./src/database/EndEffectorHolder.o \
./src/database/GripperEffector.o \
./src/database/Kit.o \
./src/database/KitDesign.o \
./src/database/KitTray.o \
./src/database/KittingWorkstation.o \
./src/database/LargeBoxWithEmptyKitTrays.o \
./src/database/LargeBoxWithKits.o \
./src/database/LargeContainer.o \
./src/database/Part.o \
./src/database/PartRefAndPose.o \
./src/database/PartsBin.o \
./src/database/PartsTray.o \
./src/database/PartsTrayWithParts.o \
./src/database/PhysicalLocation.o \
./src/database/Point.o \
./src/database/PoseLocation.o \
./src/database/PoseLocationIn.o \
./src/database/PoseLocationOn.o \
./src/database/PoseOnlyLocation.o \
./src/database/RelativeLocation.o \
./src/database/RelativeLocationIn.o \
./src/database/RelativeLocationOn.o \
./src/database/Robot.o \
./src/database/ShapeDesign.o \
./src/database/SolidObject.o \
./src/database/StockKeepingUnit.o \
./src/database/VacuumEffector.o \
./src/database/VacuumEffectorMultiCup.o \
./src/database/VacuumEffectorSingleCup.o \
./src/database/Vector.o \
./src/database/WorkTable.o 

CPP_DEPS += \
./src/database/BoxVolume.d \
./src/database/BoxyObject.d \
./src/database/Connection.d \
./src/database/DAO.d \
./src/database/DataThing.d \
./src/database/EndEffector.d \
./src/database/EndEffectorChangingStation.d \
./src/database/EndEffectorHolder.d \
./src/database/GripperEffector.d \
./src/database/Kit.d \
./src/database/KitDesign.d \
./src/database/KitTray.d \
./src/database/KittingWorkstation.d \
./src/database/LargeBoxWithEmptyKitTrays.d \
./src/database/LargeBoxWithKits.d \
./src/database/LargeContainer.d \
./src/database/Part.d \
./src/database/PartRefAndPose.d \
./src/database/PartsBin.d \
./src/database/PartsTray.d \
./src/database/PartsTrayWithParts.d \
./src/database/PhysicalLocation.d \
./src/database/Point.d \
./src/database/PoseLocation.d \
./src/database/PoseLocationIn.d \
./src/database/PoseLocationOn.d \
./src/database/PoseOnlyLocation.d \
./src/database/RelativeLocation.d \
./src/database/RelativeLocationIn.d \
./src/database/RelativeLocationOn.d \
./src/database/Robot.d \
./src/database/ShapeDesign.d \
./src/database/SolidObject.d \
./src/database/StockKeepingUnit.d \
./src/database/VacuumEffector.d \
./src/database/VacuumEffectorMultiCup.d \
./src/database/VacuumEffectorSingleCup.d \
./src/database/Vector.d \
./src/database/WorkTable.d 


# Each subdirectory must supply rules for building sources it contributes
src/database/%.o: ../src/database/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/zeid/workspace/executor/src/controller" -O0 -g3 -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


