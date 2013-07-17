#-------------------------------------------------
#
# Project created by QtCreator 2013-02-14T15:02:59
#
#-------------------------------------------------

QT       += core gui

TARGET = KTSelector
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    database/WorkTable.cpp \
    database/Vector.cpp \
    database/VacuumEffectorSingleCup.cpp \
    database/VacuumEffectorMultiCup.cpp \
    database/VacuumEffector.cpp \
    database/StockKeepingUnit.cpp \
    database/SolidObject.cpp \
    database/ShapeDesign.cpp \
    database/Robot.cpp \
    database/RelativeLocationOn.cpp \
    database/RelativeLocationIn.cpp \
    database/RelativeLocation.cpp \
    database/PoseOnlyLocation.cpp \
    database/PoseLocationOn.cpp \
    database/PoseLocationIn.cpp \
    database/PoseLocation.cpp \
    database/Point.cpp \
    database/PhysicalLocation.cpp \
    database/PartsTrayWithParts.cpp \
    database/PartsTray.cpp \
    database/PartsBin.cpp \
    database/PartRefAndPose.cpp \
    database/Part.cpp \
    database/MechanicalComponent.cpp \
    database/LargeContainer.cpp \
    database/LargeBoxWithKits.cpp \
    database/LargeBoxWithEmptyKitTrays.cpp \
    database/KitTray.cpp \
    database/KittingWorkstation.cpp \
    database/KitDesign.cpp \
    database/Kit.cpp \
    database/InternalShape.cpp \
    database/GripperEffector.cpp \
    database/ExternalShape.cpp \
    database/EndEffectorHolder.cpp \
    database/EndEffectorChangingStation.cpp \
    database/EndEffector.cpp \
    database/DataThing.cpp \
    database/DAO.cpp \
    database/Connection.cpp \
    database/BoxyShape.cpp \
    database/BoxVolume.cpp \
    usarSimInf.cpp \
    ulapi.cpp \
    recurseLocation.cpp \
    partsTrayModel.cpp \
    partModel.cpp \
    kitTrayModel.cpp \
    genericModel.cpp

HEADERS  += dialog.h \
    database/WorkTable.h \
    database/Vector.h \
    database/VacuumEffectorSingleCup.h \
    database/VacuumEffectorMultiCup.h \
    database/VacuumEffector.h \
    database/StockKeepingUnit.h \
    database/SolidObject.h \
    database/ShapeDesign.h \
    database/Robot.h \
    database/RelativeLocationOn.h \
    database/RelativeLocationIn.h \
    database/RelativeLocation.h \
    database/PoseOnlyLocation.h \
    database/PoseLocationOn.h \
    database/PoseLocationIn.h \
    database/PoseLocation.h \
    database/Point.h \
    database/PhysicalLocation.h \
    database/PartsTrayWithParts.h \
    database/PartsTray.h \
    database/PartsBin.h \
    database/PartRefAndPose.h \
    database/Part.h \
    database/MechanicalComponent.h \
    database/LargeContainer.h \
    database/LargeBoxWithKits.h \
    database/LargeBoxWithEmptyKitTrays.h \
    database/KitTray.h \
    database/KittingWorkstation.h \
    database/KitDesign.h \
    database/Kit.h \
    database/InternalShape.h \
    database/GripperEffector.h \
    database/ExternalShape.h \
    database/EndEffectorHolder.h \
    database/EndEffectorChangingStation.h \
    database/EndEffector.h \
    database/DataThing.h \
    database/DAO.h \
    database/Connection.h \
    database/BoxyShape.h \
    database/BoxVolume.h \
    usarSimInf.h \
    ulapi.hh \
    recurseLocation.h \
    partsTrayModel.h \
    partModel.h \
    kitTrayModel.h \
    genericModel.h

FORMS    += dialog.ui

OTHER_FILES +=

unix|win32: LIBS += -lmysqlcppconn
