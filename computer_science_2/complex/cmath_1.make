#File: cmath_1.make

TARGET = cmath_1
$(TARGET): cmath_1.o complex_1.o
	c++ -o cmath_1 cmath_1.o complex_1.o
cmath_1.o: cmath_1.cpp complex_1.h
	c++ -c cmath_1.cpp
complex_1.o: complex_1.cpp complex_1.h
	c++ -c complex_1.cpp
clean:
	rm -rf $(TARGET) *.o *~core* \#*\#
