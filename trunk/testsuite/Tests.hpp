#ifndef TESTSUITE_TESTS_HPP
#define TESTSUITE_TESTS_HPP

#include <string>

#include "Tool.hpp"

class CTests
{
public:
	CTests();
	~CTests();
	void config();
	void define();
	void run(std::string name);
	void runAll();
	void check(std::string name);
	void checkAll();
	void testOk(std::string name);
	void testOkAll();
	void showDiff(std::string name);
	void showDiffAll();
private:
	CTool compiler;
	CTool vm;
};

#endif
