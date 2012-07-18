all: commandParser test libController.so

libController.so: controller.cpp controller.hh canonicalMsg.hh ulapi.cpp ulapi.hh \
                  commandParser.hh commandParser.cpp \
                  ../AutoGen/*.h ../AutoGen/*.cpp
	g++  -g3 --shared -fPIC -o libController.so controller.cpp ulapi.cpp ../AutoGen/*.cpp commandParser.cpp -I ../AutoGen/ -lmysqlcppconn

test: test.cpp myController.cpp libController.so
	g++  -g3 -o test test.cpp myController.cpp -l Controller -L./ -I ../AutoGen -lpthread

commandParser: commandParser.cpp commandParserMain.cpp myController.cpp libController.so
	g++  -g3 -o commandParser commandParserMain.cpp myController.cpp -l Controller -L./ -I ../AutoGen -lpthread

clean:
	rm -rf *.o libController.so test commandParser *~
