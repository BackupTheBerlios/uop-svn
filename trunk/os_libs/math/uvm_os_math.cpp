#include <math.h>

// #include "uvm_os_libs.h"

#include "DataStack.hpp"

extern "C" {

void uvm_os_wrap_libmath_cos(CDataStack& dataStack)
{
	double x = dataStack.pop().getReal();
	double ret = cos(x);
	dataStack.push(ret);
}

void uvm_os_wrap_libmath_mod(CDataStack& dataStack)
{
	int y = dataStack.pop().getInteger();
	int x = dataStack.pop().getInteger();
	int ret = x % y;
	dataStack.push(ret);
}

void uvm_os_libmath_init(void)
{
// 	uvm_os_func_register("libmath", "cos", CTYPE_DOUBLE, CTYPE_DOUBLE, uvm_os_wrap_libmath_cos);
// 	uvm_func_register("libtest", "soma_double", CTYPE_DOUBLE, PARAM(CTYPE_DOUBLE, CTYPE_DOUBLE), __wrap__libtest__soma_double)
// 	uvm_map_types(CTYPE_INT, "int") // nao precisa por enquanto
// 	uvm_map_types(CTYPE_DOUBLE, "real") // nao precisa por enquanto
}


//void libtest_init()
//{
//	uvm_func_register("libtest", "soma_int", CTYPE_INT, PARAM(CTYPE_INT, CTYPE_INT), __wrap__libtest__soma_int)
//	uvm_func_register("libtest", "soma_double", CTYPE_DOUBLE, PARAM(CTYPE_DOUBLE, CTYPE_DOUBLE), __wrap__libtest__soma_double)
//	uvm_map_types(CTYPE_INT, "int") // nao precisa por enquanto
//	uvm_map_types(CTYPE_DOUBLE, "real") // nao precisa por enquanto
//}
//
//void __wrap__libtest__soma_int(DataStack& dataStack)
//{
//	int y = dataStack.pop().toInt();
//	int x = dataStack.pop().toInt();
//	int ret = soma_int(x, y);
//	dataStack.push(ret);
//}
//
//void __wrap__libtest__soma_double(DataStack& dataStack)
//{
//	double y = dataStack.pop().toReal();
//	double x = dataStack.pop().toReal();
//	double ret = soma_double(x, y);
//	dataStack.push(ret);
//}



}
