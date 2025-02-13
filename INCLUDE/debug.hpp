#ifndef _DEBUG_HPP_
#define _DEBUG_HPP_
#include <iostream>
extern bool DEBUG_FLAG;

inline void debug_print(const std::string& str) {
	if (DEBUG_FLAG) std::cout << str << std::endl;
}
#endif