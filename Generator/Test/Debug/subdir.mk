################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BoxVolume.cpp \
../BoxyObject.cpp \
../Connection.cpp \
../DAO.cpp \
../DataThing.cpp \
../EndEffector.cpp \
../EndEffectorChangingStation.cpp \
../EndEffectorHolder.cpp \
../GripperEffector.cpp \
../Kit.cpp \
../KitDesign.cpp \
../KitInstance.cpp \
../KitTray.cpp \
../KittingWorkstation.cpp \
../LargeBoxWithEmptyKitTrays.cpp \
../LargeBoxWithKits.cpp \
../LargeContainer.cpp \
../Part.cpp \
../PartRefAndPose.cpp \
../PartsBin.cpp \
../PartsTray.cpp \
../PartsTrayWithParts.cpp \
../PhysicalLocation.cpp \
../Point.cpp \
../Pose.cpp \
../PoseLocation.cpp \
../PoseLocationIn.cpp \
../PoseLocationOn.cpp \
../PoseOnlyLocation.cpp \
../RelativeLocation.cpp \
../RelativeLocationIn.cpp \
../RelativeLocationOn.cpp \
../Robot.cpp \
../RollPitchYaw.cpp \
../ShapeDesign.cpp \
../SolidObject.cpp \
../StockKeepingUnit.cpp \
../VacuumEffector.cpp \
../VacuumEffectorMultiCup.cpp \
../VacuumEffectorSingleCup.cpp \
../Vector.cpp \
../WorkTable.cpp 

OBJS += \
./BoxVolume.o \
./BoxyObject.o \
./Connection.o \
./DAO.o \
./DataThing.o \
./EndEffector.o \
./EndEffectorChangingStation.o \
./EndEffectorHolder.o \
./GripperEffector.o \
./Kit.o \
./KitDesign.o \
./KitInstance.o \
./KitTray.o \
./KittingWorkstation.o \
./LargeBoxWithEmptyKitTrays.o \
./LargeBoxWithKits.o \
./LargeContainer.o \
./Part.o \
./PartRefAndPose.o \
./PartsBin.o \
./PartsTray.o \
./PartsTrayWithParts.o \
./PhysicalLocation.o \
./Point.o \
./Pose.o \
./PoseLocation.o \
./PoseLocationIn.o \
./PoseLocationOn.o \
./PoseOnlyLocation.o \
./RelativeLocation.o \
./RelativeLocationIn.o \
./RelativeLocationOn.o \
./Robot.o \
./RollPitchYaw.o \
./ShapeDesign.o \
./SolidObject.o \
./StockKeepingUnit.o \
./VacuumEffector.o \
./VacuumEffectorMultiCup.o \
./VacuumEffectorSingleCup.o \
./Vector.o \
./WorkTable.o 

CPP_DEPS += \
./BoxVolume.d \
./BoxyObject.d \
./Connection.d \
./DAO.d \
./DataThing.d \
./EndEffector.d \
./EndEffectorChangingStation.d \
./EndEffectorHolder.d \
./GripperEffector.d \
./Kit.d \
./KitDesign.d \
./KitInstance.d \
./KitTray.d \
./KittingWorkstation.d \
./LargeBoxWithEmptyKitTrays.d \
./LargeBoxWithKits.d \
./LargeContainer.d \
./Part.d \
./PartRefAndPose.d \
./PartsBin.d \
./PartsTray.d \
./PartsTrayWithParts.d \
./PhysicalLocation.d \
./Point.d \
./Pose.d \
./PoseLocation.d \
./PoseLocationIn.d \
./PoseLocationOn.d \
./PoseOnlyLocation.d \
./RelativeLocation.d \
./RelativeLocationIn.d \
./RelativeLocationOn.d \
./Robot.d \
./RollPitchYaw.d \
./ShapeDesign.d \
./SolidObject.d \
./StockKeepingUnit.d \
./VacuumEffector.d \
./VacuumEffectorMultiCup.d \
./VacuumEffectorSingleCup.d \
./Vector.d \
./WorkTable.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


