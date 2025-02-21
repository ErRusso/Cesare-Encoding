#ifndef _DEBUG_HPP_
#define _DEBUG_HPP_
#include <iostream>
extern bool DEBUG_FLAG;
#define TORED(str)("\033[31m"+str+"\033[0m")

inline void debug_print(const std::string& str) {
	if (DEBUG_FLAG) std::cout << TORED(str) << std::endl;
}
#endif