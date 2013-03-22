IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -I ../src -g

ODIR=obj
LIBS=-L./ -lpthread -lsqlKit -lmysqlcppconn

_DEPS = ulapi.hh
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

all: dataTest genTest objectGen

dataTest_SOURCES = dataTest.cpp recurseLocation.cpp partModel.cpp usarSimInf.cpp \
                   ulapi.cpp kitTrayModel.cpp partsTrayModel.cpp genericModel.cpp
dataTest_OBJECTS = $(patsubst %, $(ODIR)/%,$(dataTest_SOURCES:.cpp=.o))

genTest_SOURCES = genTest.cpp ulapi.cpp
genTest_OBJECTS=$(patsubst %, $(ODIR)/%,$(genTest_SOURCES:.cpp=.o))

objectGen_SOURCES = objectGen.cpp ulapi.cpp
objectGen_OBJECTS=$(patsubst %, $(ODIR)/%,$(objectGen_SOURCES:.cpp=.o))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

dataTest: $(dataTest_OBJECTS) libsqlKit.a $(IDIR)/recurseLocation.h $(IDIR)/partModel.h $(IDIR)/kitTrayModel.h $(IDIR)/partsTrayModel.h
	$(CC) -o $@ $(dataTest_OBJECTS) $(CFLAGS) $(LIBS)

genTest: $(genTest_OBJECTS)
	$(CC) -o $@ $(genTest_OBJECTS) $(CFLAGS) $(LIBS)

objectGen: $(objectGen_OBJECTS)
	$(CC) -o $@ $(objectGen_OBJECTS) $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o genTest objectGen *~ $(INCDIR)/*~
