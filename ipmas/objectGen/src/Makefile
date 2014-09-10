IDIR =../include
CC=g++
CFLAGS=-I$(IDIR) -I ../src -g -I../../AutoGen -g

ODIR=obj
LIBS=-L../../AutoGen -lpthread -lsqlKit -lmysqlcppconn

_DEPS = ulapi.hh
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

all: genTest objectGen objectDel

objectGen_SOURCES = objectGen.cpp recurseLocation.cpp partModel.cpp usarSimInf.cpp \
                   ulapi.cpp kitTrayModel.cpp partsTrayModel.cpp genericModel.cpp
objectGen_OBJECTS = $(patsubst %, $(ODIR)/%,$(objectGen_SOURCES:.cpp=.o))

objectDel_SOURCES = objectDel.cpp ulapi.cpp 
objectDel_OBJECTS = $(patsubst %, $(ODIR)/%,$(objectDel_SOURCES:.cpp=.o))

genTest_SOURCES = genTest.cpp ulapi.cpp
genTest_OBJECTS=$(patsubst %, $(ODIR)/%,$(genTest_SOURCES:.cpp=.o))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

objectGen: $(objectGen_OBJECTS) ../../AutoGen/libsqlKit.a $(IDIR)/recurseLocation.h $(IDIR)/partModel.h $(IDIR)/kitTrayModel.h $(IDIR)/partsTrayModel.h
	$(CC) -o $@ $(objectGen_OBJECTS) $(CFLAGS) $(LIBS)

objectDel: $(objectDel_OBJECTS) ../../AutoGen/libsqlKit.a 
	$(CC) -o $@ $(objectDel_OBJECTS) $(CFLAGS) $(LIBS)

genTest: $(genTest_OBJECTS)
	$(CC) -o $@ $(genTest_OBJECTS) $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o genTest objectGen objectDel *~ $(INCDIR)/*~
