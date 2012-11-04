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

libdatabase_a_HEADERS = BoxVolume.h \
BoxyObject.h \
Connection.h \
DAO.h \
DataThing.h \
EndEffector.h \
EndEffectorChangingStation.h \
EndEffectorHolder.h \
GripperEffector.h \
Kit.h \
KitDesign.h \
KitTray.h \
KittingWorkstation.h \
LargeBoxWithEmptyKitTrays.h \
LargeBoxWithKits.h \
LargeContainer.h \
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
BoxyObject.cpp \
Connection.cpp \
DAO.cpp \
DataThing.cpp \
EndEffector.cpp \
EndEffectorChangingStation.cpp \
EndEffectorHolder.cpp \
GripperEffector.cpp \
Kit.cpp \
KitDesign.cpp \
KitTray.cpp \
KittingWorkstation.cpp \
LargeBoxWithEmptyKitTrays.cpp \
LargeBoxWithKits.cpp \
LargeContainer.cpp \
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

