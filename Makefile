output:test.o 
	g++ test.o -o output
test.o:test.cpp bstset.h
	g++ -c test.cpp