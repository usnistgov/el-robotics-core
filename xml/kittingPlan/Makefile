LINCOMPILE = /usr/bin/g++ -c -v -g -Wall
LINLINK = /usr/bin/g++ -v
INCLUD = -I ../common/source

bin/kittingPlanParser : ofiles/kittingPlanParser.o           \
                        ofiles/kittingPlanClasses.o          \
                        ofiles/kittingWorkstationClasses.o   \
                        ofiles/kittingPlanLex.o              \
                        ofiles/kittingPlanYACC.o             \
                        ../common/ofiles/xmlSchemaInstance.o
	$(LINLINK) -o $@ ofiles/kittingPlanParser.o           \
                         ofiles/kittingPlanClasses.o          \
                         ofiles/kittingWorkstationClasses.o   \
                         ofiles/kittingPlanLex.o              \
                         ofiles/kittingPlanYACC.o             \
                         ../common/ofiles/xmlSchemaInstance.o

bin/owlKittingPlanPrinter : ofiles/owlKittingPlanPrinter.o        \
                            ofiles/owlKittingPlanClasses.o        \
                            ofiles/owlKittingPlanYACC.o           \
                            ofiles/owlKittingPlanLex.o            \
                            ../common/ofiles/owlInstancePrinter.o \
                            ../common/ofiles/xmlSchemaInstance.o
	$(LINLINK) -o $@ ofiles/owlKittingPlanPrinter.o        \
                         ofiles/owlKittingPlanClasses.o        \
                         ofiles/owlKittingPlanYACC.o           \
                         ofiles/owlKittingPlanLex.o            \
                         ../common/ofiles/owlInstancePrinter.o \
                         ../common/ofiles/xmlSchemaInstance.o

ofiles/kittingPlanClasses.o : source/kittingPlanClasses.hh           \
                              ../common/source/xmlSchemaInstance.hh  \
                              source/kittingPlanClasses.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingPlanClasses.cc

ofiles/kittingWorkstationClasses.o : source/kittingWorkstationClasses.hh   \
                                     ../common/source/xmlSchemaInstance.hh \
                                     source/kittingWorkstationClasses.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingWorkstationClasses.cc

ofiles/kittingPlanLex.o : source/kittingPlanLex.cc  \
                          source/kittingPlanYACC.hh
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingPlanLex.cc

ofiles/kittingPlanParser.o : source/kittingPlanParser.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingPlanParser.cc

ofiles/kittingPlanYACC.o : source/kittingPlanClasses.hh          \
                           source/kittingPlanYACC.hh             \
                           ../common/source/xmlSchemaInstance.hh \
                           source/kittingPlanYACC.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingPlanYACC.cc

ofiles/owlKittingPlanClasses.o : source/owlKittingPlanClasses.hh        \
                                 source/kittingPlanYACC.hh              \
                                 ../common/source/owlInstancePrinter.hh \
                                 ../common/source/xmlSchemaInstance.hh  \
                                 source/owlKittingPlanClasses.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/owlKittingPlanClasses.cc

ofiles/owlKittingPlanLex.o : source/kittingPlanLex.cc \
                             source/kittingPlanYACC.hh
	$(LINCOMPILE) -DNO_ECHO -DOWL -o $@ $(INCLUD) source/kittingPlanLex.cc

ofiles/owlKittingPlanPrinter.o : source/owlKittingPlanClasses.hh \
                                 source/owlKittingPlanPrinter.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/owlKittingPlanPrinter.cc

ofiles/owlKittingPlanYACC.o : source/kittingPlanYACC.hh             \
                              source/owlKittingPlanClasses.hh       \
                              ../common/source/xmlSchemaInstance.hh \
                              source/kittingPlanYACC.cc
	$(LINCOMPILE) -DOWL -o $@ $(INCLUD) source/kittingPlanYACC.cc

source/kittingPlanYACC.hh : source/kittingPlanYACC.cc

source/kittingPlanYACC.cc : source/kittingPlan.y
	bison -d -l -o $@ source/kittingPlan.y

source/kittingPlanLex.cc : source/kittingPlan.lex
	flex -L -t source/kittingPlan.lex > source/kittingPlanLex.cc

