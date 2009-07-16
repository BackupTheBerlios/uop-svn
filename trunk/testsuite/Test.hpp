#ifndef TESTSUITE_TEST_HPP
#define TESTSUITE_TEST_HPP

#include <string>
#include <vector>

#include "TestSuiteDefs.hpp"
#include "Args.hpp"
#include "Subtest.hpp"

class CTest
{
public:
	CTest(std::string name);
	~CTest();
	CSubtest* addSubtest(SResult expectedResult, CArgs args);
	CSubtest* addSubtest(SResult expectedResult, CArgs args1, CArgs args2);
//private:
	std::string _name;
	std::vector<CSubtest*> _subtestList;
};

#endif
