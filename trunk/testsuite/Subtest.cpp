#include "Subtest.hpp"

CSubtest::CSubtest(uint number, SResult expectedResult, CArgs args)
	: _number(number), _expectedResult(expectedResult), _args1(args), _status(UNDEFINED)
{
}

CSubtest::CSubtest(uint number, SResult expectedResult, CArgs args1, CArgs args2)
	: _number(number), _expectedResult(expectedResult), _args1(args1), _args2(args2), _status(UNDEFINED)
{
}

CSubtest::~CSubtest()
{
}
