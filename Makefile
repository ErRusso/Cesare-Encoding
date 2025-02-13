CFLAGS = -Wall -I ./INCLUDE/
cesare: init.cpp INCLUDE/debug.hpp
	clang++ $(CFLAGS) -o $@ $<