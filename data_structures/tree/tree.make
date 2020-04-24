#File: polygon.make

TARGET = test
$(TARGET): main.o tree.o queue.o
	c++ -o test main.o tree.o queue.o
main.o: tree.h queue.h
	c++ -c main.cpp
tree.o: tree.h queue.h
	c++ -c tree.cpp
#polygon.o: polygon.h
	#c++ -c polygon.cpp
clean:
	rm -rf $(TARGET) *.o *~core* \#*\#
all: test clean


