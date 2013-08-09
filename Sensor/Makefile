PROJECTNAME := sensorcheck

IPMAS_DIR := ../
OBGEN_DIR := $(IPMAS_DIR)/objectGen/src/
BINDIR:= bin
ODIR := build
IDIR := include
SRCDIR := src
EXTERN_OBJ_FILES := $(ODIR)/partModel.o $(ODIR)/genericModel.o $(ODIR)/recurseLocation.o
CPP_FILES := $(wildcard $(SRCDIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRCDIR)/%, $(ODIR)/%, $(CPP_FILES:.cpp=.o))
LD_FLAGS := -L$(IPMAS_DIR)/AutoGen -lpthread -lsqlKit -lmysqlcppconn
CXX_FLAGS := -MMD -I$(IDIR) -I$(IPMAS_DIR)/AutoGen -I$(IPMAS_DIR)/objectGen/include -g

all: $(BINDIR)/$(PROJECTNAME)

$(BINDIR)/$(PROJECTNAME): $(OBJ_FILES) $(EXTERN_OBJ_FILES)
	$(CXX) -o $@ $^ $(LD_FLAGS)

$(OBJ_FILES): $(ODIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

$(EXTERN_OBJ_FILES): $(ODIR)/%.o: $(OBGEN_DIR)/%.cpp
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

-include $(OBJ_FILES:.o=.d)

.PHONY: clean

clean:
	rm -rf $(BINDIR)/* $(ODIR)/* *~
	
