mystring: driver.o mystring.o
	g++ -std=c++11 -o mystring driver.o mystring.o

driver.o: driver.cpp mystring.h
	g++ -std=c++11 -c driver.cpp

mystring.o: mystring.cpp mystring.h
	g++ -std=c++11 -c mystring.cpp

clean:
	rm *.o* mystring
