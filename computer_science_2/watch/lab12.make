#Nina Hudak
#File: test-watch.make
#April 10, 2019

TARGET = lab12
$(TARGET): lab12.o watch.o
	c++ -o lab12 lab12.o watch.o
lab12.o: lab12.cpp watch.h
	c++ -c lab12.cpp
watch.o: watch.cpp watch.h
	c++ -c watch.cpp
clean:
	rm -rf $(TARGET) *.o *~core* \#*\#
