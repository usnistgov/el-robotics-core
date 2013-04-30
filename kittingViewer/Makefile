LINCOMPILE = /usr/bin/g++ -c -v -g -Wall
LINLINK = /usr/bin/g++ -v
GLUT_LIBS = -lglut  -lSM -lICE -lXmu -lXi  -lGLU -lGL
//GLUT_LIBS = -lglut -lGLU -lGL

bin/kittingParser : ofiles/kittingParser.o    \
                    ofiles/kittingYACC.o      \
                    ofiles/kittingLex.o       \
                    ofiles/kittingClasses.o   \
                    ofiles/xmlSchemaInstance.o
	$(LINLINK) -o $@ ofiles/kittingParser.o  \
                      ofiles/kittingYACC.o       \
                      ofiles/kittingLex.o        \
                      ofiles/kittingClasses.o    \
                      ofiles/xmlSchemaInstance.o

bin/kittingViewer: ofiles/commandParser.o      \
                   ofiles/canonicalMsgView.o   \
                   ofiles/mouse.o              \
                   ofiles/kittingViewer.o      \
                   ofiles/viewKitting.o        \
                   ofiles/kittingClassesView.o \
                   ofiles/kittingLexView.o     \
                   ofiles/kittingYACCView.o    \
                   ofiles/Pose.o               \
                   ofiles/scoreKittingClasses.o \
                   ofiles/scoreKittingLex.o    \
                   ofiles/scoreKittingYACC.o   \
                   ofiles/xmlSchemaInstance.o
	$(LINLINK) -o $@ ofiles/commandParser.o       \
                         ofiles/kittingViewer.o       \
                         ofiles/canonicalMsgView.o    \
                         ofiles/mouse.o               \
                         ofiles/viewKitting.o         \
                         ofiles/kittingClassesView.o  \
                         ofiles/kittingLexView.o      \
                         ofiles/kittingYACCView.o     \
                         ofiles/Pose.o                \
                         ofiles/scoreKittingClasses.o \
                         ofiles/scoreKittingLex.o     \
                         ofiles/scoreKittingYACC.o    \
                         ofiles/xmlSchemaInstance.o   \
                         $(GLUT_LIBS)

bin/commandParser: ofiles/commandParserMain.o       \
                   ofiles/commandParser.o           \
                   ofiles/canonicalMsg.o
	$(LINLINK) -o $@ ofiles/commandParserMain.o \
                         ofiles/commandParser.o     \
                         ofiles/canonicalMsg.o

bin/scoreKittingParser : ofiles/scoreKittingParser.o  \
                         ofiles/scoreKittingClasses.o \
                         ofiles/scoreKittingLex.o     \
                         ofiles/scoreKittingYACC.o    \
                         ofiles/xmlSchemaInstance.o
	$(LINLINK) -o $@ ofiles/scoreKittingParser.o  \
                         ofiles/scoreKittingClasses.o \
                         ofiles/scoreKittingLex.o     \
                         ofiles/xmlSchemaInstance.o   \
                         ofiles/scoreKittingYACC.o

ofiles/canonicalMsg.o: source/canonicalMsg.hh \
                       source/canonicalMsg.cc
	$(LINCOMPILE) -o $@ source/canonicalMsg.cc

ofiles/canonicalMsgView.o: source/canonicalMsg.hh \
                           source/canonicalMsgView.cc
	$(LINCOMPILE) -o $@ source/canonicalMsgView.cc

ofiles/commandParser.o: source/commandParser.hh \
                        source/commandParser.cc
	$(LINCOMPILE) -o $@ source/commandParser.cc

ofiles/commandParserMain.o: source/commandParser.hh \
                            source/commandParserMain.cc
	$(LINCOMPILE) -o $@ source/commandParserMain.cc

ofiles/kittingClasses.o : source/kittingClasses.hh     \
                          source/kittingYACC.hh        \
                          source/xmlSchemaInstance.hh  \
                          source/kittingClasses.cc
	$(LINCOMPILE) -o $@ source/kittingClasses.cc

ofiles/kittingClassesView.o : source/kittingClassesView.hh \
                              source/kittingYACC.hh        \
                              source/xmlSchemaInstance.hh  \
                              source/kittingClassesView.cc
	$(LINCOMPILE) -o $@ source/kittingClassesView.cc

ofiles/kittingLex.o : source/kittingLex.cc \
                      source/kittingYACC.hh
	$(LINCOMPILE) -o $@  -DNO_ECHO source/kittingLex.cc

ofiles/kittingLexView.o : source/kittingLex.cc        \
                          source/kittingYACC.hh       \
                          source/xmlSchemaInstance.hh
	$(LINCOMPILE) -o $@ -DNO_ECHO -DVIEWER source/kittingLex.cc

ofiles/kittingParser.o : source/kittingClasses.hh    \
                         source/kittingParser.cc     \
                         source/xmlSchemaInstance.hh
	$(LINCOMPILE) -o $@ source/kittingParser.cc

ofiles/kittingViewer.o: source/canonicalMsg.hh       \
                        source/kittingClassesView.hh \
                        source/commandParser.hh      \
                        source/kittingViewer.cc      \
                        source/kittingViewer.hh      \
                        source/view.hh               \
                        source/xmlSchemaInstance.hh
	$(LINCOMPILE) -o $@ source/kittingViewer.cc

ofiles/kittingYACC.o : source/kittingYACC.hh        \
                       source/kittingClassesView.hh \
                       source/xmlSchemaInstance.hh  \
                       source/kittingYACC.cc
	$(LINCOMPILE) -o $@ source/kittingYACC.cc

ofiles/kittingYACCView.o : source/kittingYACC.hh        \
                           source/kittingClassesView.hh \
                           source/xmlSchemaInstance.hh  \
                           source/kittingYACC.cc
	$(LINCOMPILE) -o $@ -DVIEWER source/kittingYACC.cc

ofiles/mouse.o:  source/mouse.cc  \
                 source/mouse.hh
	$(LINCOMPILE) -o $@ source/mouse.cc

ofiles/Pose.o:  source/Pose.cc  \
                source/Pose.h
	$(LINCOMPILE) -o $@ source/Pose.cc

ofiles/scoreKittingParser.o : source/scoreKittingClasses.hh \
                              source/scoreKittingParser.cc  \
                              source/xmlSchemaInstance.hh
	$(LINCOMPILE) -o $@ source/scoreKittingParser.cc

ofiles/scoreKittingClasses.o : source/scoreKittingClasses.hh \
                               source/scoreKittingClasses.cc \
                               source/xmlSchemaInstance.hh
	$(LINCOMPILE) -o $@ source/scoreKittingClasses.cc

ofiles/scoreKittingLex.o : source/scoreKittingYACC.hh \
                           source/scoreKittingLex.cc
	$(LINCOMPILE) -o $@ -DNO_ECHO source/scoreKittingLex.cc

ofiles/scoreKittingYACC.o : source/scoreKittingYACC.hh    \
                            source/scoreKittingClasses.hh \
                            source/xmlSchemaInstance.hh   \
                            source/scoreKittingYACC.cc
	$(LINCOMPILE) -o $@ source/scoreKittingYACC.cc

ofiles/viewKitting.o: source/viewKitting.cc \
                      source/mouse.hh       \
                      source/view.hh
	$(LINCOMPILE) -o $@ source/viewKitting.cc

ofiles/xmlSchemaInstance.o : source/xmlSchemaInstance.cc \
                          source/xmlSchemaInstance.hh
	$(LINCOMPILE) -o $@ source/xmlSchemaInstance.cc

source/kittingLex.cc : source/kitting.lex
	flex -L -t source/kitting.lex > source/kittingLex.cc

source/kittingYACC.cc: source/kitting.y
	bison -d -l -o $@ source/kitting.y

# After regenerating kittingYACC.cc or kittingLex.cc, remember to change

# #include "kittingClasses.hh"   // for kitting classes

# to

# #ifdef VIEWER
# #include "kittingClassesView.hh"   // for kitting classes
# #else
# #include "kittingClasses.hh"   // for kitting classes
# #endif

source/scoreKittingLex.cc : source/scoreKitting.lex
	flex -L --prefix=yysc -t source/scoreKitting.lex > source/scoreKittingLex.cc

source/scoreKittingYACC.cc: source/scoreKitting.y
	bison -d -l -p yysc -o $@ source/scoreKitting.y

