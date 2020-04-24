#Nina Hudak
#File: test-watch.make
#April 10, 2019

TARGET = test-watch
$(TARGET): test-watch.o watch.o
	c++ -o test-watch test-watch.o watch.o
test-watch.o: test-watch.cpp watch.h
	c++ -c test-watch.cpp
watch.o: watch.cpp watch.h
	c++ -c watch.cpp
clean:
	rm -rf $(TARGET) *.o *~core* \#*\#
