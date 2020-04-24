#File: polygon.make

TARGET = test-polygon
$(TARGET): test-polygon.o trapezoid.o polygon.o
	c++ -o test-polygon test-polygon.o trapezoid.o polygon.o
test-polygon.o: trapezoid.h polygon.h
	c++ -c test-polygon.cpp
trapezoid.o: trapezoid.h polygon.h
	c++ -c trapezoid.cpp
#polygon.o: polygon.h
	#c++ -c polygon.cpp
clean:
	rm -rf $(TARGET) *.o *~core* \#*\#
all: test-polygon clean


