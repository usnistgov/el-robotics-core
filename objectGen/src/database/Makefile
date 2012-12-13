IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -g3 -shared

ODIR=obj
LIBS=

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

all: libsqlKit.a

libsqlKit_SOURCES = \
BoxVolume.cpp      \
BoxyObject.cpp     \
BoxyShape.cpp      \
Connection.cpp      \
DAO.cpp      \
DataThing.cpp      \
EndEffectorChangingStation.cpp      \
EndEffector.cpp      \
EndEffectorHolder.cpp      \
GripperEffector.cpp      \
Kit.cpp      \
KitDesign.cpp      \
KittingWorkstation.cpp      \
KitTray.cpp      \
LargeBoxWithEmptyKitTrays.cpp      \
LargeBoxWithKits.cpp      \
LargeContainer.cpp      \
Part.cpp      \
PartRefAndPose.cpp      \
PartsBin.cpp      \
PartsTray.cpp      \
PartsTrayWithParts.cpp      \
PhysicalLocation.cpp      \
Point.cpp      \
PoseLocation.cpp      \
PoseLocationIn.cpp      \
PoseLocationOn.cpp      \
PoseOnlyLocation.cpp      \
RelativeLocation.cpp      \
RelativeLocationIn.cpp      \
RelativeLocationOn.cpp      \
Robot.cpp      \
ShapeDesign.cpp      \
SolidObject.cpp      \
StockKeepingUnit.cpp      \
VacuumEffector.cpp      \
VacuumEffectorMultiCup.cpp      \
VacuumEffectorSingleCup.cpp      \
Vector.cpp      \
WorkTable.cpp      

libsqlKit_OBJECTS=$(patsubst %, $(ODIR)/%,$(libsqlKit_SOURCES:.cpp=.o))

$(ODIR)/%.o: %.cpp %.h $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

libsqlKit.a: $(libsqlKit_OBJECTS)
	ar rcs $(patsubst $@, $@,../$@) $(libsqlKit_OBJECTS)
	ranlib $(patsubst $@, $@,../$@)

.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o genTest objectGen *~ $(INCDIR)/*~ ../libsqlKit.a
