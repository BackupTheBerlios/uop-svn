#ifndef TESTSUITE_SUBTEST_PP
#define TESTSUITE_SUBTEST_HPP

#include <string>

#include "TestSuiteDefs.hpp"
#include "Args.hpp"

class CSubtest
{
public:
	CSubtest(uint number, SResult expectedResult, CArgs args);
	CSubtest(uint number, SResult expectedResult, CArgs args1, CArgs args2);
	~CSubtest();
//private:
	uint _number;
	SResult _expectedResult;
	CArgs _args1;
	CArgs _args2;
	SResult _status;
};

#endif
