LINCOMPILE = /usr/bin/g++ -c -v -g -Wall
LINLINK = /usr/bin/g++ -v 
INCLUD = -I ../common/source

bin/soapParser : ofiles/soapParser.o   \
                               ofiles/soapClasses.o  \
                               ofiles/soapLex.o      \
                               ofiles/soapYACC.o     \
                               ofiles/kittingWorkstationClasses.o     \
                               ../common/ofiles/xmlSchemaInstance.o
	$(LINLINK) -o $@ ofiles/soapParser.o   \
                         ofiles/soapClasses.o  \
                         ofiles/soapLex.o      \
                         ofiles/soapYACC.o     \
                         ofiles/kittingWorkstationClasses.o     \
                         ../common/ofiles/xmlSchemaInstance.o

bin/owlSoapPrinter : ofiles/owlSoapPrinter.o    \
			ofiles/owlSoapClasses.o    \
			ofiles/owlSoapYACC.o       \
			ofiles/owlSoapLex.o        \
			../common/ofiles/owlInstancePrinter.o \
			../common/ofiles/xmlSchemaInstance.o
	$(LINLINK) -o $@ ofiles/owlSoapPrinter.o    \
                         ofiles/owlSoapClasses.o    \
                         ofiles/owlSoapYACC.o       \
                         ofiles/owlSoapLex.o        \
                         ../common/ofiles/owlInstancePrinter.o \
                         ../common/ofiles/xmlSchemaInstance.o                         
                         
ofiles/soapClasses.o : source/soapClasses.hh    \
			source/soapYACC.hh         \
			../common/source/xmlSchemaInstance.hh  \
			source/soapClasses.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/soapClasses.cc


ofiles/kittingWorkstationClasses.o : source/kittingWorkstationClasses.hh    \
                                     ../common/source/xmlSchemaInstance.hh \
                                     source/kittingWorkstationClasses.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/kittingWorkstationClasses.cc
	
ofiles/soapLex.o : source/soapLex.cc \
			source/soapYACC.hh
	$(LINCOMPILE) -DNO_ECHO -o $@ $(INCLUD) source/soapLex.cc

ofiles/soapParser.o : source/soapParser.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/soapParser.cc

ofiles/soapYACC.o : source/soapClasses.hh       \
                    source/soapYACC.hh \
                    ../common/source/xmlSchemaInstance.hh  \
                    source/soapYACC.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/soapYACC.cc

ofiles/owlSoapClasses.o : source/owlSoapClasses.hh \
                                        source/soapYACC.hh       \
                                        ../common/source/owlInstancePrinter.hh \
                                        ../common/source/xmlSchemaInstance.hh  \
                                        source/owlSoapClasses.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/owlSoapClasses.cc

ofiles/owlSoapLex.o : source/soapLex.cc \
                                    source/soapYACC.hh
	$(LINCOMPILE) -DNO_ECHO -DOWL -o $@ $(INCLUD) source/soapLex.cc

ofiles/owlSoapPrinter.o : source/owlSoapClasses.hh \
                                        source/owlSoapPrinter.cc
	$(LINCOMPILE) -o $@ $(INCLUD) source/owlSoapPrinter.cc

ofiles/owlSoapYACC.o : source/soapYACC.hh       \
                                     source/owlSoapClasses.hh \
                                     ../common/source/xmlSchemaInstance.hh  \
                                     source/soapYACC.cc
	$(LINCOMPILE) -DOWL -o $@ $(INCLUD) source/soapYACC.cc

source/soapYACC.hh : source/soapYACC.cc

source/soapYACC.cc : source/soap.y
	bison -d -l -o $@ source/soap.y

source/soapLex.cc : source/soap.lex
	flex -L -t source/soap.lex > source/soapLex.cc

