LINCOMPILE = /usr/bin/g++ -c -v -g -Wall
LINLINK = /usr/bin/g++ -v
INCLUD = -I ../common/source

# When generating source code, use the yyge prefix used by bison and flex.
# From the schema directory, the command should be:
# ../../../generator/bin/generator -x geometryInstances.xsd -p yyge

bin/geometrySchema3Parser : ofiles/geometrySchema3Parser.o  \
                            ofiles/geometrySchema3Classes.o \
                            ofiles/geometrySchema3Lex.o     \
                            ofiles/geometrySchema3YACC.o    \
                            ofiles/CircleAndSphereClasses.o \
                            ofiles/PointAndVectorClasses.o  \
                            ../common/ofiles/xmlSchemaInstance.o
	$(LINLINK) -o $@  ofiles/geometrySchema3Parser.o  \
                          ofiles/geometrySchema3Classes.o \
                          ofiles/geometrySchema3Lex.o     \
                          ofiles/geometrySchema3YACC.o    \
                          ofiles/CircleAndSphereClasses.o \
                          ofiles/PointAndVectorClasses.o  \
                          ../common/ofiles/xmlSchemaInstance.o

bin/owlGeometrySchema3Printer : ofiles/owlGeometrySchema3Printer.o    \
                                ofiles/owlGeometrySchema3Classes.o    \
                                ofiles/owlGeometrySchema3YACC.o       \
                                ofiles/owlGeometrySchema3Lex.o        \
                                ../common/ofiles/owlInstancePrinter.o \
                                ../common/ofiles/xmlSchemaInstance.o
	$(LINLINK) -o $@ ofiles/owlGeometrySchema3Printer.o    \
                         ofiles/owlGeometrySchema3Classes.o    \
                         ofiles/owlGeometrySchema3YACC.o       \
                         ofiles/owlGeometrySchema3Lex.o        \
                         ../common/ofiles/owlInstancePrinter.o \
                         ../common/ofiles/xmlSchemaInstance.o

ofiles/CircleAndSphereClasses.o: source/CircleAndSphereClasses.hh      \
                                 ../common/source/xmlSchemaInstance.hh \
                                 source/CircleAndSphereClasses.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/CircleAndSphereClasses.cc

ofiles/geometrySchema3Classes.o : source/geometrySchema3Classes.hh      \
                                  source/geometrySchema3YACC.hh         \
                                  ../common/source/xmlSchemaInstance.hh \
                                  source/geometrySchema3Classes.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/geometrySchema3Classes.cc

ofiles/geometrySchema3Lex.o : source/geometrySchema3Lex.cc  \
                              source/geometrySchema3YACC.hh
	$(LINCOMPILE) -DNO_ECHO -o $@ $(INCLUD) source/geometrySchema3Lex.cc

ofiles/geometrySchema3Parser.o : source/geometrySchema3Parser.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/geometrySchema3Parser.cc

ofiles/geometrySchema3YACC.o : source/geometrySchema3Classes.hh      \
                               source/geometrySchema3YACC.hh         \
                               ../common/source/xmlSchemaInstance.hh \
                               source/geometrySchema3YACC.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/geometrySchema3YACC.cc

ofiles/owlGeometrySchema3Classes.o : source/owlGeometrySchema3Classes.hh    \
                                     source/geometrySchema3YACC.hh          \
                                     ../common/source/owlInstancePrinter.hh \
                                     ../common/source/xmlSchemaInstance.hh  \
                                     source/owlGeometrySchema3Classes.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/owlGeometrySchema3Classes.cc

ofiles/owlGeometrySchema3Lex.o : source/geometrySchema3Lex.cc \
                                 source/geometrySchema3YACC.hh
	$(LINCOMPILE) -DNO_ECHO -DOWL -o $@ $(INCLUD) source/geometrySchema3Lex.cc

ofiles/owlGeometrySchema3Printer.o : source/owlGeometrySchema3Classes.hh \
                                     source/owlGeometrySchema3Printer.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/owlGeometrySchema3Printer.cc

ofiles/owlGeometrySchema3YACC.o : source/geometrySchema3YACC.hh         \
                                  source/owlGeometrySchema3Classes.hh   \
                                  ../common/source/xmlSchemaInstance.hh \
                                  source/geometrySchema3YACC.cc
	$(LINCOMPILE) -DOWL -o $@ $(INCLUD) source/geometrySchema3YACC.cc

ofiles/PointAndVectorClasses.o: source/PointAndVectorClasses.hh       \
                                ../common/source/xmlSchemaInstance.hh \
                                source/PointAndVectorClasses.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/PointAndVectorClasses.cc

source/geometrySchema3YACC.hh : source/geometrySchema3YACC.cc

source/geometrySchema3YACC.cc : source/geometrySchema3.y
	bison -d -l -o $@ source/geometrySchema3.y

source/geometrySchema3Lex.cc : source/geometrySchema3.lex
	flex -L -t source/geometrySchema3.lex > source/geometrySchema3Lex.cc
