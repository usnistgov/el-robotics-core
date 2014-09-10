sql2pddl: SQL2PDDL.o PDDLWriter.o
	g++ -Wall -o sql2pddl SQL2PDDL.o PDDLWriter.o ../lib/libsqlKit.a -lmysqlcppconn 

SQL2PDDL.o: SQL2PDDL.cpp PDDLWriter.h

PDDLWriter.o: PDDLWriter.cpp PDDLWriter.h

clean:
	rm -f *.o sql2pddl
