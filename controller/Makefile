all: test libController.so

libController.so: controller.cpp controller.hh canonicalMsg.hh ulapi.cpp ulapi.hh
	g++  -g3 --shared -fPIC -o libController.so controller.cpp ulapi.cpp -I ../AutoGen

test: test.cpp myController.cpp libController.so
	g++  -g3 -o test test.cpp myController.cpp -l Controller -L./ -I ../AutoGen -lpthread

clean:
	rm -rf *.o libController.so test *~
