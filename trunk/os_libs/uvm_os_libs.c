#include "uvm_os_libs.h"

static std::map<std::string, void (*)(CDataStack& dataStack)> _bindings;

// extern "C" {

void uvm_os_func_register(std::string libName, std::string funcName, CTypes returnType, CTypes paramType, TWrapFunc wrapFunc)
{
	_bindings[libName + std::string("::") + funcName] = wrapFunc;
}

TWrapFunc uvm_os_get_func(std::string libName, std::string funcName)
{
	std::string key = libName + std::string("::") + funcName;
	if (_bindings.find(key) == _bindings.end()) {
		return NULL;
	} else {
		return _bindings[key];
	}
}

// }
