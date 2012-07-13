all: test libController.so

libController.so: controller.cpp controller.hh canonicalMsg.hh ulapi.cpp ulapi.hh ../AutoGen/*.h ../AutoGen/*.cpp
	g++  -g3 --shared -fPIC -o libController.so controller.cpp ulapi.cpp ../AutoGen/*.cpp -I ../AutoGen/ -lmysqlcppconn

test: test.cpp myController.cpp libController.so
	g++  -g3 -o test test.cpp myController.cpp -l Controller -L./ -I ../AutoGen -lpthread

clean:
	rm -rf *.o libController.so test *~
