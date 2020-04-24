#File: polygon.make

TARGET = test-polygon-1
$(TARGET): test-polygon-1.o triangle.o trapez.o polygon.o
	c++ -o test-polygon-1 test-polygon-1.o triangle.o trapez.o polygon.o
test-polygon-1.o: triangle.h trapez.h polygon.h
	c++ -c test-polygon-1.cpp
triangle.o: triangle.h polygon.h
	c++ -c triangle.cpp
trapez.o: trapez.h polygon.h
	c++ -c trapez.cpp
#polygon.o: polygon.h
	#c++ -c polygon.cpp
clean:
	rm -rf $(TARGET) *.o *~core* \#*\#
all: test-polygon-1 clean

