LINCOMPILE = /usr/bin/g++ -c -v -g -Wall
LINLINK = /usr/bin/g++ -v 
INCLUD = -I ../common/source

bin/kittingWorkstationParser : ofiles/kittingWorkstationParser.o   \
                               ofiles/kittingWorkstationClasses.o  \
                               ofiles/kittingWorkstationLex.o      \
                               ofiles/kittingWorkstationYACC.o     \
                               ../common/ofiles/xmlSchemaInstance.o
	$(LINLINK) -o $@ ofiles/kittingWorkstationParser.o   \
                         ofiles/kittingWorkstationClasses.o  \
                         ofiles/kittingWorkstationLex.o      \
                         ofiles/kittingWorkstationYACC.o     \
                         ../common/ofiles/xmlSchemaInstance.o

bin/owlKittingWorkstationPrinter : ofiles/owlKittingWorkstationPrinter.o \
                                   ofiles/owlKittingWorkstationYACC.o    \
                                   ofiles/owlKittingWorkstationLex.o     \
                                   ofiles/owlKittingWorkstationClasses.o \
                                   ../common/ofiles/owlInstancePrinter.o \
                                   ../common/ofiles/xmlSchemaInstance.o
	$(LINLINK) -o $@ ofiles/owlKittingWorkstationPrinter.o \
                         ofiles/owlKittingWorkstationYACC.o    \
                         ofiles/owlKittingWorkstationLex.o     \
                         ofiles/owlKittingWorkstationClasses.o \
                         ../common/ofiles/owlInstancePrinter.o \
                         ../common/ofiles/xmlSchemaInstance.o

ofiles/kittingWorkstationClasses.o : source/kittingWorkstationClasses.hh    \
                                     ../common/source/owlInstancePrinter.hh \
                                     ../common/source/xmlSchemaInstance.hh  \
                                     source/kittingWorkstationClasses.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingWorkstationClasses.cc

ofiles/kittingWorkstationLex.o : source/kittingWorkstationLex.cc \
                                 source/kittingWorkstationYACC.hh
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingWorkstationLex.cc

ofiles/kittingWorkstationParser.o : source/kittingWorkstationParser.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingWorkstationParser.cc

ofiles/kittingWorkstationYACC.o : source/kittingWorkstationYACC.hh       \
                                  source/owlKittingWorkstationClasses.hh \
                                  ../common/source/xmlSchemaInstance.hh  \
                                  source/kittingWorkstationYACC.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingWorkstationYACC.cc

ofiles/owlKittingWorkstationClasses.o : source/owlKittingWorkstationClasses.hh \
                                        source/kittingWorkstationYACC.hh       \
                                        ../common/source/owlInstancePrinter.hh \
                                        ../common/source/xmlSchemaInstance.hh  \
                                        source/owlKittingWorkstationClasses.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/owlKittingWorkstationClasses.cc

ofiles/owlKittingWorkstationLex.o : source/kittingWorkstationLex.cc \
                                    source/kittingWorkstationYACC.hh
	$(LINCOMPILE) -DNO_ECHO -DOWL -o $@ $(INCLUD) source/kittingWorkstationLex.cc

ofiles/owlKittingWorkstationPrinter.o : source/owlKittingWorkstationClasses.hh \
                                        source/owlKittingWorkstationPrinter.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/owlKittingWorkstationPrinter.cc

ofiles/owlKittingWorkstationYACC.o : source/kittingWorkstationYACC.hh       \
                                     source/owlKittingWorkstationClasses.hh \
                                     ../common/source/xmlSchemaInstance.hh  \
                                     source/kittingWorkstationYACC.cc
	$(LINCOMPILE) -DOWL -o $@ $(INCLUD) source/kittingWorkstationYACC.cc

source/kittingWorkstationYACC.hh : source/kittingWorkstationYACC.cc

source/kittingWorkstationYACC.cc : source/kittingWorkstation.y
	bison -d -l -o $@ source/kittingWorkstation.y

source/kittingWorkstationLex.cc : source/kittingWorkstation.lex
	flex -L -t source/kittingWorkstation.lex > source/kittingWorkstationLex.cc

