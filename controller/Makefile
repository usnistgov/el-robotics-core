all: commandParser test libController.a

obj/controller.o: controller.cpp controller.hh
	g++  -g3 -c -o obj/controller.o controller.cpp -I../AutoGen -L../AutoGen
obj/ulapi.o: ulapi.cpp ulapi.hh
	g++  -g3 -c -o obj/ulapi.o ulapi.cpp -I../AutoGen
obj/commandParser.o: commandParser.cpp commandParser.hh
	g++  -g3 -c -o obj/commandParser.o commandParser.cpp -I../AutoGen -L../AutoGen

libController.a: obj/controller.o obj/ulapi.o obj/commandParser.o
	ar rcs libController.a obj/controller.o obj/ulapi.o obj/commandParser.o
	ranlib libController.a

test: test.cpp myController.cpp libController.a
	g++  -g3 -o test test.cpp myController.cpp -L./ -L../AutoGen -lController -lpthread -lsqlKit -lmysqlcppconn -I ../AutoGen

commandParser: commandParser.cpp commandParserMain.cpp myController.cpp libController.a
	g++  -g3 -o commandParser commandParserMain.cpp myController.cpp -L./ -L../AutoGen -lController -lpthread -lsqlKit -lmysqlcppconn -I ../AutoGen 

clean:
	rm -rf obj/*.o libController.a test commandParser *~
