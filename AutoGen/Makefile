export IDIR =./database
export CC=g++
export CFLAGS=-I$(IDIR) -g -shared

export ODIR=obj
export LIBS=

export _DEPS = 
export DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

IPMAS_DIR =../

OWL_ONTOLOGY=$(IPMAS_DIR)/Ontology/Kitting/kittingClasses.owl

all: libsqlKit.a

#do NOT export source or obj file names
#recursive make calls need to reevaluate these if sources are generated into an empty directory
libsqlKit_SOURCES=$(wildcard *.cpp)

libsqlKit_OBJECTS=$(patsubst %, $(ODIR)/%,$(libsqlKit_SOURCES:.cpp=.o))

libsqlKit_HEADERS=$(wildcard $(IDIR)/*.h)

libsqlKit.a: genSrc $(libsqlKit_OBJECTS) $(libsqlKit_SOURCES) $(libsqlKit_HEADERS) $(DEPS)
	$(MAKE) -f sqlKitMakefile

#dummy target to signal source generation
genSrc: $(OWL_ONTOLOGY)
	$(IPMAS_DIR)/Generator/generator_no_gui.jar -owl $< -cpp ./
	mv *.h $(IDIR)
	touch genSrc
	
.PHONY: clean

clean:
	rm -rf $(ODIR)/*.o *~ $(INCDIR)/*~ ./libsqlKit.a genSrc *.owl*
