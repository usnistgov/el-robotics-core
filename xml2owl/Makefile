LINCOMPILE = /usr/bin/g++ -c -v -g -Wall
LINLINK = /usr/bin/g++ -v 
INCLUD = -I ../source

bin/kittingParser : ofiles/kittingParser.o    \
                    ofiles/kittingYACC.o      \
                    ofiles/kittingLex.o       \
                    ofiles/kittingClasses.o   \
                    ofiles/xmlSchemaInstance.o
	$(LINLINK) -o $@ ofiles/kittingParser.o   \
                      ofiles/kittingYACC.o        \
                      ofiles/kittingLex.o         \
                      ofiles/kittingClasses.o     \
                      ofiles/xmlSchemaInstance.o  \
                      -L/usr/lib -lboost_regex

bin/owlPrinter : ofiles/owlPrinter.o         \
                 ofiles/kittingYACCOwl.o     \
                 ofiles/kittingLexOwl.o      \
                 ofiles/kittingClassesOwl.o  \
                 ofiles/xmlSchemaInstance.o
	$(LINLINK) -o $@ ofiles/owlPrinter.o      \
                      ofiles/kittingYACCOwl.o     \
                      ofiles/kittingLexOwl.o      \
                      ofiles/kittingClassesOwl.o  \
                      ofiles/xmlSchemaInstance.o  \
                      -L/usr/lib -lboost_regex

bin/compactOwl : source/compactOwl.cc
	/usr/bin/g++ -v -g -Wall -o $@ source/compactOwl.cc

bin/compareOwl : source/compareOwl.cc
	/usr/bin/g++ -v -g -Wall -o $@ source/compareOwl.cc

ofiles/kittingClasses.o : source/kittingClasses.hh    \
                          source/kittingYACC.hh       \
                          source/xmlSchemaInstance.hh \
                          source/kittingClasses.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingClasses.cc

ofiles/kittingClassesOwl.o : source/kittingClassesOwl.hh \
                             source/kittingYACC.hh       \
                             source/xmlSchemaInstance.hh \
                             source/kittingClassesOwl.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingClassesOwl.cc

ofiles/kittingLex.o : source/kittingLex.cc \
                      source/kittingYACC.hh
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingLex.cc

ofiles/kittingLexOwl.o : source/kittingLex.cc \
                         source/kittingYACC.hh
	$(LINCOMPILE) -o $@ -DOWL $(INCLUD) source/kittingLex.cc

ofiles/kittingParser.o : source/kittingParser.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingParser.cc

ofiles/owlPrinter.o : source/kittingClassesOwl.hh \
                      source/owlPrinter.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/owlPrinter.cc

ofiles/kittingYACC.o : source/kittingYACC.hh       \
                       source/kittingClasses.hh    \
                       source/xmlSchemaInstance.hh \
                       source/kittingYACC.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingYACC.cc

ofiles/kittingYACCOwl.o : source/kittingYACC.hh       \
                          source/kittingClassesOwl.hh \
                          source/xmlSchemaInstance.hh \
                          source/kittingYACC.cc
	$(LINCOMPILE) -o $@ -DOWL $(INCLUD) source/kittingYACC.cc

ofiles/xmlSchemaInstance.o : source/xmlSchemaInstance.cc \
                             source/xmlSchemaInstance.hh
	$(LINCOMPILE) -o $@ source/xmlSchemaInstance.cc

# After regenerating kittingYACC.cc or kittingLex.cc, remember to change

# #include "kittingClasses.hh"   // for kitting classes

# to

# #ifdef OWL
# #include "kittingClassesOwl.hh"   // for kitting classes
# #else
# #include "kittingClasses.hh"   // for kitting classes
# #endif

ssource/kittingYACC.cc : source/kitting.y
	bison -d -l -o $@ source/kitting.y

source/kittingLex.cc : source/kitting.lex
	flex -L -t source/kitting.lex > source/kittingLex.cc

source/compactOwl.cc : source/compactOwl.lex
	flex -L -t source/compactOwl.lex > source/compactOwl.cc
