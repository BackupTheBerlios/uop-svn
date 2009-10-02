
/* Put header files here or function declarations like below */
#include <math.h>


#include "DataStack.hpp"

extern "C" void uvm_os_wrap_libmath_cos(CDataStack& dataStack)
{
	double x=dataStack.pop().getReal();
	double result=cos(x);

	dataStack.push(result);
}
extern "C" void uvm_os_wrap_libmath_cosf(CDataStack& dataStack)
{
	float x=dataStack.pop().getReal();
	float result=cosf(x);

	dataStack.push(result);
}
extern "C" void uvm_os_wrap_libmath_cosl(CDataStack& dataStack)
{
	long double x=dataStack.pop().getReal();
	long double result=cosl(x);

	dataStack.push(result);
}
