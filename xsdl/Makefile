LINCOMPILE = /usr/bin/g++ -c -v -g -Wall
LINLINK = /usr/bin/g++ -v

bin/xmlSchemaParser : ofiles/xmlSchemaParser.o  \
                      ofiles/xmlSchemaYACC.o    \
                      ofiles/xmlSchemaLex.o     \
                      ofiles/xmlSchemaClasses.o \
                      ofiles/patternLex.o       \
                      ofiles/patternYACC.o
	$(LINLINK) -o $@ ofiles/xmlSchemaParser.o  \
                         ofiles/xmlSchemaYACC.o    \
                         ofiles/xmlSchemaLex.o     \
                         ofiles/xmlSchemaClasses.o \
                         ofiles/patternLex.o       \
                         ofiles/patternYACC.o

bin/xmlSchemaOwlPrinter : ofiles/xmlSchemaOwlPrinter.o \
                          ofiles/xmlSchemaOwlYACC.o    \
                          ofiles/xmlSchemaLex.o        \
                          ofiles/xmlSchemaClasses.o
	$(LINLINK) -o $@ ofiles/xmlSchemaOwlPrinter.o \
                         ofiles/xmlSchemaOwlYACC.o    \
                         ofiles/xmlSchemaLex.o        \
                         ofiles/xmlSchemaClasses.o

ofiles/patternLex.o : source/patternLex.cc \
                      source/patternYACC.hh
	$(LINCOMPILE) -o $@ source/patternLex.cc


ofiles/patternYACC.o : source/patternYACC.cc \
                       source/patternYACC.hh
	$(LINCOMPILE) -o $@ source/patternYACC.cc

ofiles/xmlSchemaClasses.o : source/xmlSchemaClasses.hh \
                            source/xmlSchemaClasses.cc
	$(LINCOMPILE) -o $@ source/xmlSchemaClasses.cc

ofiles/xmlSchemaClassesOwl.o : source/xmlSchemaClassesOwl.hh \
                               source/xmlSchemaClassesOwl.cc
	$(LINCOMPILE) -o $@ source/xmlSchemaClassesOwl.cc

ofiles/xmlSchemaOwlYACC.o : source/xmlSchemaYACC.cc \
                            source/xmlSchemaYACC.hh
	$(LINCOMPILE) -o $@ -D NOPATTERN source/xmlSchemaYACC.cc

ofiles/xmlSchemaLex.o : source/xmlSchemaLex.cc\
                        source/xmlSchemaYACC.hh
	$(LINCOMPILE) -o $@ source/xmlSchemaLex.cc

ofiles/xmlSchemaParser.o : source/xmlSchemaClasses.hh \
                           source/xmlSchemaParser.cc
	$(LINCOMPILE) -o $@ source/xmlSchemaParser.cc

ofiles/xmlSchemaOwlPrinter.o : source/xmlSchemaClasses.hh \
                               source/xmlSchemaOwlPrinter.hh \
                               source/xmlSchemaOwlPrinter.cc
	$(LINCOMPILE) -o $@ source/xmlSchemaOwlPrinter.cc

ofiles/xmlSchemaYACC.o : source/xmlSchemaYACC.cc \
                         source/xmlSchemaYACC.hh
	$(LINCOMPILE) -o $@ source/xmlSchemaYACC.cc

source/xmlSchemaYACC.cc : source/xmlSchema.y \
                          source/xmlSchemaClasses.hh
	bison -d -l -o $@ source/xmlSchema.y

source/xmlSchemaLex.cc : source/xmlSchema.lex       \
                         source/xmlSchemaYACC.cc    \
                         source/xmlSchemaClasses.hh
	flex -L -t source/xmlSchema.lex > source/xmlSchemaLex.cc

source/patternYACC.cc : source/pattern.y
	bison -d -l -p yyre -o $@ source/pattern.y

source/patternLex.cc : source/pattern.lex source/patternYACC.cc
	flex -L -t  -Pyyre source/pattern.lex > source/patternLex.cc
