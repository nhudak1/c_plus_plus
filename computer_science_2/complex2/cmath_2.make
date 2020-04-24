#File: cmath_2.make

TARGET = cmath_2
$(TARGET): cmath_2.o complex_2.o
	c++ -o cmath_2 cmath_2.o complex_2.o
cmath_2.o: cmath_2.cpp complex_2.h
	c++ -c cmath_2.cpp
complex_2.o: complex_2.cpp complex_2.h
	c++ -c complex_2.cpp
clean:
	rm -rf $(TARGET) *.o *~core* \#*\#

