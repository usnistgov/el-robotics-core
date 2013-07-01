# this is example-file: src/database/Makefile.am

# additional include pathes necessary to compile the C++ library
AM_CXXFLAGS = -I$(top_srcdir)/src @AM_CXXFLAGS@
AM_CPPFLAGS = -I$(top_srcdir)/src @AM_CPPFLAGS@

#INCLUDES = -I@top_srcdir@/src/database
###############################################################################
# THE LIBRARIES TO BUILD
###############################################################################


noinst_LIBRARIES = libdatabase.a

# where to install the headers on the system
libdatabase_adir = $(top_srcdir)/src/database
#libdatabase_adir = $(top_srcdir)/lib

libdatabase_a_HEADERS =  \
BoxVolume.h \
BoxyShape.h \
Connection.h \
DAO.h \
DataThing.h \
EndEffectorChangingStation.h \
EndEffector.h \
EndEffectorHolder.h \
ExternalShape.h \
GripperEffector.h \
InternalShape.h \
KitDesign.h \
Kit.h \
KittingWorkstation.h \
KitTray.h \
LargeBoxWithEmptyKitTrays.h \
LargeBoxWithKits.h \
LargeContainer.h \
MechanicalComponent.h \
Part.h \
PartRefAndPose.h \
PartsBin.h \
PartsTray.h \
PartsTrayWithParts.h \
PhysicalLocation.h \
Point.h \
PoseLocation.h \
PoseLocationIn.h \
PoseLocationOn.h \
PoseOnlyLocation.h \
RelativeLocation.h \
RelativeLocationIn.h \
RelativeLocationOn.h \
Robot.h \
ShapeDesign.h \
SolidObject.h \
StockKeepingUnit.h \
VacuumEffector.h \
VacuumEffectorMultiCup.h \
VacuumEffectorSingleCup.h \
Vector.h \
WorkTable.h 


libdatabase_a_SOURCES = $(libdatabase_a_HEADERS) \
BoxVolume.cpp \
BoxyShape.cpp \
Connection.cpp \
DAO.cpp \
DataThing.cpp \
EndEffectorChangingStation.cpp \
EndEffector.cpp \
EndEffectorHolder.cpp \
ExternalShape.cpp \
GripperEffector.cpp \
InternalShape.cpp \
Kit.cpp \
KitDesign.cpp \
KittingWorkstation.cpp \
KitTray.cpp \
LargeBoxWithEmptyKitTrays.cpp \
LargeBoxWithKits.cpp \
LargeContainer.cpp \
MechanicalComponent.cpp \
Part.cpp \
PartRefAndPose.cpp \
PartsBin.cpp \
PartsTray.cpp \
PartsTrayWithParts.cpp \
PhysicalLocation.cpp \
Point.cpp \
PoseLocation.cpp \
PoseLocationIn.cpp \
PoseLocationOn.cpp \
PoseOnlyLocation.cpp \
RelativeLocation.cpp \
RelativeLocationIn.cpp \
RelativeLocationOn.cpp \
Robot.cpp \
ShapeDesign.cpp \
SolidObject.cpp \
StockKeepingUnit.cpp \
VacuumEffector.cpp \
VacuumEffectorMultiCup.cpp \
VacuumEffectorSingleCup.cpp \
Vector.cpp \
WorkTable.cpp



#INCLUDES = -I@top_srcdir@/src/includes

