#ifndef UVM_OS_LIBS
#define UVM_OS_LIBS

#include "DataStack.hpp"

// extern "C" {

enum CTypes {
	CTYPE_INT    = 1,
 	CTYPE_DOUBLE = 2
};

typedef void (*TWrapFunc)(CDataStack& dataStack);

void uvm_os_func_register(std::string libName, std::string funcName, CTypes returnType, CTypes paramType, TWrapFunc wrapFunc);
TWrapFunc uvm_os_get_func(std::string libName, std::string funcName);

// }

#endif
