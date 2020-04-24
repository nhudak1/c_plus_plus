#File: record_keeper.make

TARGET = record_keeper
$(TARGET): record_keeper.o dollar_amount.o
	c++ -o record_keeper record_keeper.o dollar_amount.o
record_keeper.o: record_keeper.cpp dollar_amount.h
	c++ -c record_keeper.cpp
dollar_amount.o: dollar_amount.cpp dollar_amount.h
	c++ -c dollar_amount.cpp
clean:
	rm -rf $(TARGET) *.o *~core~ \#*\#
