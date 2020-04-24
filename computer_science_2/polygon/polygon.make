#File: polygon.make

TARGET = test-polygon
$(TARGET): test-polygon.o triangle.o polygon.o
	c++ -o test-polygon test-polygon.o triangle.o polygon.o
test-polygon.o: triangle.h polygon.h
	c++ -c test-polygon.cpp
#polygon.o: polygon.h
	#c++ -c polygon.cpp
triangle.o: triangle.h polygon.h
	c++ -c triangle.cpp
clean:
	rm -rf $(TARGET) *.o *~core* \#*\#

