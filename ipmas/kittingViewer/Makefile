LINCOMPILE = /usr/bin/g++ -c -v -g -Wall
LINLINK = /usr/bin/g++ -v
GLUT_LIBS = -lglut  -lSM -lICE -lXmu -lXi  -lGLU -lGL
//GLUT_LIBS = -lglut -lGLU -lGL

bin/kittingWorkstationParser : ofiles/kittingWorkstationParser.o   \
                               ofiles/kittingWorkstationYACC.o     \
                               ofiles/kittingWorkstationLex.o      \
                               ofiles/kittingWorkstationClasses.o  \
                               ofiles/xmlSchemaInstance.o
	$(LINLINK) -o $@ ofiles/kittingWorkstationParser.o  \
                      ofiles/kittingWorkstationYACC.o       \
                      ofiles/kittingWorkstationLex.o        \
                      ofiles/kittingWorkstationClasses.o    \
                      ofiles/xmlSchemaInstance.o

bin/kittingViewer: ofiles/commandParser.o                 \
                   ofiles/canonicalMsgView.o              \
                   ofiles/mouse.o                         \
                   ofiles/kittingViewer.o                 \
                   ofiles/viewKitting.o                   \
                   ofiles/kittingWorkstationClassesView.o \
                   ofiles/kittingWorkstationLexView.o     \
                   ofiles/kittingWorkstationYACCView.o    \
                   ofiles/Pose.o                          \
                   ofiles/scoreKittingClasses.o           \
                   ofiles/scoreKittingLex.o               \
                   ofiles/scoreKittingYACC.o              \
                   ofiles/xmlSchemaInstance.o
	$(LINLINK) -o $@ ofiles/commandParser.o                  \
                         ofiles/kittingViewer.o                  \
                         ofiles/canonicalMsgView.o               \
                         ofiles/mouse.o                          \
                         ofiles/viewKitting.o                    \
                         ofiles/kittingWorkstationClassesView.o  \
                         ofiles/kittingWorkstationLexView.o      \
                         ofiles/kittingWorkstationYACCView.o     \
                         ofiles/Pose.o                           \
                         ofiles/scoreKittingClasses.o            \
                         ofiles/scoreKittingLex.o                \
                         ofiles/scoreKittingYACC.o               \
                         ofiles/xmlSchemaInstance.o              \
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

ofiles/kittingWorkstationClasses.o : source/kittingWorkstationClasses.hh \
                          source/kittingWorkstationYACC.hh               \
                          source/kittingWorkstationClasses.cc            \
                          source/xmlSchemaInstance.hh
	$(LINCOMPILE) -o $@ source/kittingWorkstationClasses.cc

ofiles/kittingWorkstationClassesView.o: source/kittingWorkstationClassesView.hh\
                                        source/kittingWorkstationYACC.hh       \
                                        source/kittingWorkstationClassesView.cc\
                                        source/xmlSchemaInstance.hh
	$(LINCOMPILE) -o $@ source/kittingWorkstationClassesView.cc

ofiles/kittingWorkstationLex.o : source/kittingWorkstationLex.cc \
                                 source/kittingWorkstationYACC.hh
	$(LINCOMPILE) -o $@ source/kittingWorkstationLex.cc

ofiles/kittingWorkstationLexView.o : source/kittingWorkstationLex.cc  \
                                     source/kittingWorkstationYACC.hh \
                                     source/xmlSchemaInstance.hh
	$(LINCOMPILE) -o $@ -DNO_ECHO -DVIEWER source/kittingWorkstationLex.cc

ofiles/kittingWorkstationParser.o : source/kittingWorkstationClasses.hh \
                                    source/kittingWorkstationParser.cc  \
                                    source/xmlSchemaInstance.hh
	$(LINCOMPILE) -o $@ source/kittingWorkstationParser.cc

ofiles/kittingViewer.o: source/canonicalMsg.hh                  \
                        source/kittingWorkstationClassesView.hh \
                        source/commandParser.hh                 \
                        source/kittingViewer.cc                 \
                        source/kittingViewer.hh                 \
                        source/view.hh                          \
                        source/xmlSchemaInstance.hh
	$(LINCOMPILE) -o $@ source/kittingViewer.cc

ofiles/kittingWorkstationYACC.o : source/kittingWorkstationYACC.hh    \
                                  source/kittingWorkstationClasses.hh \
                                  source/kittingWorkstationYACC.cc    \
                                  source/xmlSchemaInstance.hh
	$(LINCOMPILE) -o $@ source/kittingWorkstationYACC.cc

ofiles/kittingWorkstationYACCView.o : source/kittingWorkstationYACC.hh        \
                                      source/kittingWorkstationClassesView.hh \
                                      source/kittingWorkstationYACC.cc        \
                                      source/xmlSchemaInstance.hh
	$(LINCOMPILE) -o $@ -DVIEWER source/kittingWorkstationYACC.cc

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

source/kittingWorkstationLex.cc : source/kittingWorkstation.lex
	flex -L -t source/kittingWorkstation.lex > source/kittingWorkstationLex.cc

source/kittingWorkstationYACC.cc: source/kittingWorkstation.y
	bison -d -l -o $@ source/kittingWorkstation.y

source/kittingWorkstationYACC.hh: source/kittingWorkstation.y
	bison -d -l -o $@ source/kittingWorkstation.y

# After regenerating kittingWorkstationYACC.cc or kittingWorkstationLex.cc,
# remember to change

# #include "kittingWorkstationClasses.hh"   // for kitting classes

# to

# #ifdef VIEWER
# #include "kittingWorkstationClassesView.hh"   // for kitting classes
# #else
# #include "kittingWorkstationClasses.hh"   // for kitting classes
# #endif

source/scoreKittingLex.cc : source/scoreKitting.lex
	flex -L --prefix=yysc -t source/scoreKitting.lex > source/scoreKittingLex.cc

source/scoreKittingYACC.cc: source/scoreKitting.y
	bison -d -l -p yysc -o $@ source/scoreKitting.y

