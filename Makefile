CFLAGS = -Wall -I ./INCLUDE/
cesare: init.cpp INCLUDE/debug.hpp INCLUDE/cesare.hpp INCLUDE/cesare.cpp
	clang++ $(CFLAGS) -o $@ $<