LINCOMPILE = /usr/bin/g++ -c -v -g -Wall
LINLINK = /usr/bin/g++ -v
INCLUD = -I ../source

bin/kittingPlanParser : ofiles/kittingPlanParser.o  \
                        ofiles/kittingPlanClasses.o \
                        ofiles/kittingPlanLex.o     \
                        ofiles/kittingPlanYACC.o    \
                        ofiles/xmlSchemaInstance.o
	$(LINLINK) -o $@ ofiles/kittingPlanParser.o  \
                         ofiles/kittingPlanClasses.o \
                         ofiles/kittingPlanLex.o     \
                         ofiles/kittingPlanYACC.o    \
                         ofiles/xmlSchemaInstance.o

ofiles/kittingPlanClasses.o : source/kittingPlanClasses.hh  \
                              source/kittingPlanYACC.hh     \
                              source/xmlSchemaInstance.hh   \
                              source/kittingPlanClasses.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingPlanClasses.cc

ofiles/kittingPlanLex.o : source/kittingPlanLex.cc  \
                              source/kittingPlanYACC.hh
	$(LINCOMPILE) -DNO_ECHO -o $@ $(INCLUD) source/kittingPlanLex.cc

ofiles/kittingPlanParser.o : source/kittingPlanParser.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingPlanParser.cc

ofiles/kittingPlanYACC.o : source/kittingPlanClasses.hh \
                           source/kittingPlanYACC.hh    \
                           source/xmlSchemaInstance.hh  \
                           source/kittingPlanYACC.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingPlanYACC.cc

ofiles/xmlSchemaInstance.o : source/xmlSchemaInstance.cc \
                             source/xmlSchemaInstance.hh
	$(LINCOMPILE) -o $@ source/xmlSchemaInstance.cc

source/kittingPlanYACC.hh : source/kittingPlanYACC.cc

source/kittingPlanYACC.cc : source/kittingPlan.y
	bison -d -l -o $@ source/kittingPlan.y

source/kittingPlanLex.cc : source/kittingPlan.lex
	flex -L -t source/kittingPlan.lex > source/kittingPlanLex.cc

