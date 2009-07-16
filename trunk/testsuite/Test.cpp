#include "Test.hpp"

CTest::CTest(std::string name)
	: _name(name)
{
}

CTest::~CTest()
{
}

CSubtest* CTest::addSubtest(SResult expectedResult, CArgs args)
{
	CSubtest* subtest = new CSubtest(_subtestList.size(), expectedResult, args);
	_subtestList.push_back(subtest);

	return subtest;
}

CSubtest* CTest::addSubtest(SResult expectedResult, CArgs args1, CArgs args2)
{
	CSubtest* subtest = new CSubtest(_subtestList.size()+1, expectedResult, args1, args2);
	_subtestList.push_back(subtest);

	return subtest;
}

