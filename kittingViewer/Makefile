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
                      ofiles/xmlSchemaInstance.o \
                      -L/usr/lib -lboost_regex

bin/kittingViewer: ofiles/commandParser.o      \
                   ofiles/canonicalMsgView.o   \
                   ofiles/mouse.o              \
                   ofiles/kittingViewer.o      \
                   ofiles/viewKitting.o        \
                   ofiles/kittingClassesView.o \
                   ofiles/kittingLexView.o     \
                   ofiles/kittingYACCView.o    \
                   ofiles/Pose.o               \
                   ofiles/xmlSchemaInstance.o
	$(LINLINK) -o $@ ofiles/commandParser.o      \
                         ofiles/kittingViewer.o      \
                         ofiles/canonicalMsgView.o   \
                         ofiles/mouse.o              \
                         ofiles/viewKitting.o        \
                         ofiles/kittingClassesView.o \
                         ofiles/kittingLexView.o     \
                         ofiles/kittingYACCView.o    \
                         ofiles/Pose.o               \
                         ofiles/xmlSchemaInstance.o  \
                         $(GLUT_LIBS) -L/usr/lib -lboost_regex

bin/commandParser: ofiles/commandParserMain.o \
                   ofiles/commandParser.o     \
                   ofiles/canonicalMsg.o
	$(LINLINK) -o $@ ofiles/commandParserMain.o \
                         ofiles/commandParser.o     \
                         ofiles/canonicalMsg.o

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
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingClasses.cc

ofiles/kittingClassesView.o : source/kittingClassesView.hh \
                              source/kittingYACC.hh        \
                              source/xmlSchemaInstance.hh  \
                              source/kittingClassesView.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingClassesView.cc

ofiles/kittingLex.o : source/kittingLex.cc \
                      source/kittingYACC.hh
	$(LINCOMPILE) -o $@  -DNO_ECHO $(INCLUD) source/kittingLex.cc

ofiles/kittingLexView.o : source/kittingLex.cc \
                          source/kittingYACC.hh
	$(LINCOMPILE) -o $@ -DNO_ECHO -DVIEWER $(INCLUD) source/kittingLex.cc

ofiles/kittingParser.o : source/kittingParser.cc
	$(LINCOMPILE) -o $@  $(INCLUD) source/kittingParser.cc

ofiles/kittingViewer.o: source/canonicalMsg.hh       \
                        source/kittingClassesView.hh \
                        source/commandParser.hh      \
                        source/kittingViewer.cc      \
                        source/kittingViewer.hh      \
                        source/view.hh
	$(LINCOMPILE) -o $@ source/kittingViewer.cc

ofiles/kittingYACC.o : source/kittingYACC.hh        \
                       source/kittingClassesView.hh \
                       source/xmlSchemaInstance.hh  \
                       source/kittingYACC.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingYACC.cc

ofiles/kittingYACCView.o : source/kittingYACC.hh        \
                           source/kittingClassesView.hh \
                           source/xmlSchemaInstance.hh  \
                           source/kittingYACC.cc
	$(LINCOMPILE) -o $@ -DVIEWER $(INCLUD) source/kittingYACC.cc

ofiles/mouse.o:  source/mouse.cc  \
                 source/mouse.hh
	$(LINCOMPILE) -o $@ source/mouse.cc

ofiles/Pose.o:  source/Pose.cc  \
                source/Pose.h
	$(LINCOMPILE) -o $@ source/Pose.cc

ofiles/viewKitting.o: source/viewKitting.cc \
                      source/mouse.hh       \
                      source/view.hh
	$(LINCOMPILE) -o $@ source/viewKitting.cc

ofiles/xmlSchemaInstance.o : source/xmlSchemaInstance.cc \
                          source/xmlSchemaInstance.hh
	$(LINCOMPILE) -o $@ source/xmlSchemaInstance.cc

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

source/kittingLex.cc : source/kitting.lex
	flex -L -t source/kitting.lex > source/kittingLex.cc
