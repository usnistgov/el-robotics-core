IDIR =./database
CC=g++
CFLAGS=-I$(IDIR) -g -shared

ODIR=obj
LIBS=

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

all: libsqlKit.a

# create list with "ls -x > fileList.txt"

libsqlKit_SOURCES = \
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

libsqlKit_OBJECTS=$(patsubst %, $(ODIR)/%,$(libsqlKit_SOURCES:.cpp=.o))

$(ODIR)/%.o: %.cpp ./database/%.h $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

libsqlKit.a: $(libsqlKit_OBJECTS)
	ar rcs $@ $(libsqlKit_OBJECTS)
	ranlib $@

.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o genTest objectGen *~ $(INCDIR)/*~ ../libsqlKit.a
