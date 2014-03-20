LINCOMPILE = /usr/bin/g++ -c -v -g -Wall
LINLINK = /usr/bin/g++ -v
INCLUD = -I ../source

bin/compactOwl : source/compactOwl.cc
	/usr/bin/g++ -v -g -Wall -o $@ source/compactOwl.cc

bin/compareOwl : source/compareOwl.cc
	/usr/bin/g++ -v -g -Wall -o $@ source/compareOwl.cc

bin/xmlInstanceParserGenerator : ofiles/xmlInstanceParserGenerator.o \
                                 ofiles/xmlSchemaYACC.o              \
                                 ofiles/xmlSchemaLex.o               \
                                 ofiles/xmlSchemaClasses.o           \
                                 ofiles/patternLex.o                 \
                                 ofiles/patternYACC.o
	$(LINLINK) -o $@ ofiles/xmlInstanceParserGenerator.o  \
                         ofiles/xmlSchemaYACC.o               \
                         ofiles/xmlSchemaLex.o                \
                         ofiles/xmlSchemaClasses.o            \
                         ofiles/patternLex.o                  \
                         ofiles/patternYACC.o

bin/xmlSchemaOwlClassGenerator : ofiles/xmlSchemaOwlClassGenerator.o \
                                 ofiles/xmlSchemaOwlYACC.o           \
                                 ofiles/xmlSchemaLex.o               \
                                 ofiles/xmlSchemaClasses.o
	$(LINLINK) -o $@ ofiles/xmlSchemaOwlClassGenerator.o \
                         ofiles/xmlSchemaOwlYACC.o           \
                         ofiles/xmlSchemaLex.o               \
                         ofiles/xmlSchemaClasses.o

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

bin/xml2owlGenerator : ofiles/xml2owlGenerator.o \
                       ofiles/xmlSchemaOwlYACC.o \
                       ofiles/xmlSchemaLex.o     \
                       ofiles/xmlSchemaClasses.o
	$(LINLINK) -o $@ ofiles/xml2owlGenerator.o \
                         ofiles/xmlSchemaOwlYACC.o \
                         ofiles/xmlSchemaLex.o     \
                         ofiles/xmlSchemaClasses.o

ofiles/xmlInstanceParserGenerator.o : source/xmlInstanceParserGenerator.hh \
                                      source/xmlInstanceParserGenerator.cc \
                                      source/xmlSchemaClasses.hh
	$(LINCOMPILE) -o $@ source/xmlInstanceParserGenerator.cc

ofiles/owlInstancePrinter.o : source/xmlSchemaInstance.hh  \
                              source/owlInstancePrinter.hh \
                              source/owlInstancePrinter.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/owlInstancePrinter.cc

ofiles/patternLex.o : source/patternLex.cc \
                      source/patternYACC.hh
	$(LINCOMPILE) -o $@ source/patternLex.cc

ofiles/patternYACC.o : source/patternYACC.cc \
                       source/patternYACC.hh
	$(LINCOMPILE) -o $@ source/patternYACC.cc

ofiles/xmlSchemaClasses.o : source/xmlSchemaClasses.hh \
                            source/xmlSchemaClasses.cc
	$(LINCOMPILE) -o $@ source/xmlSchemaClasses.cc

ofiles/xmlSchemaInstance.o : source/xmlSchemaInstance.cc \
                             source/xmlSchemaInstance.hh
	$(LINCOMPILE) -o $@ source/xmlSchemaInstance.cc

ofiles/xmlSchemaLex.o : source/xmlSchemaLex.cc\
                        source/xmlSchemaYACC.hh
	$(LINCOMPILE) -o $@ source/xmlSchemaLex.cc

ofiles/xmlSchemaOwlClassGenerator.o : source/xmlSchemaClasses.hh           \
                                      source/xmlSchemaOwlClassGenerator.hh \
                                      source/xmlSchemaOwlClassGenerator.cc
	$(LINCOMPILE) -o $@ source/xmlSchemaOwlClassGenerator.cc

ofiles/xmlSchemaOwlYACC.o : source/xmlSchemaYACC.cc \
                            source/xmlSchemaYACC.hh
	$(LINCOMPILE) -o $@ -D NOPATTERN source/xmlSchemaYACC.cc

ofiles/xmlSchemaParser.o : source/xmlSchemaClasses.hh \
                           source/xmlSchemaParser.cc
	$(LINCOMPILE) -o $@ source/xmlSchemaParser.cc

ofiles/xmlSchemaYACC.o : source/xmlSchemaYACC.cc \
                         source/xmlSchemaYACC.hh
	$(LINCOMPILE) -o $@ source/xmlSchemaYACC.cc

ofiles/xml2owlGenerator.o : source/xmlSchemaClasses.hh \
                            source/xml2owlGenerator.hh \
                            source/xml2owlGenerator.cc
	$(LINCOMPILE) -o $@ source/xml2owlGenerator.cc

source/compactOwl.cc : source/compactOwl.lex
	flex -L -t  source/compactOwl.lex > source/compactOwl.cc

source/patternLex.cc : source/pattern.lex source/patternYACC.cc
	flex -L -t  -Pyyre source/pattern.lex > source/patternLex.cc

source/patternYACC.cc : source/pattern.y
	bison -d -l -p yyre -o $@ source/pattern.y

source/xmlSchemaLex.cc : source/xmlSchema.lex       \
                         source/xmlSchemaYACC.cc    \
                         source/xmlSchemaClasses.hh
	flex -L -t source/xmlSchema.lex > source/xmlSchemaLex.cc

source/xmlSchemaYACC.cc : source/xmlSchema.y \
                          source/xmlSchemaClasses.hh
	bison -d -l -o $@ source/xmlSchema.y
