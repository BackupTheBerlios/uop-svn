#ifndef TESTSUITE_TOOL_HPP
#define TESTSUITE_TOOL_HPP

#include <string>
#include <vector>

#include "Test.hpp"

struct STestCommand {
	std::string _testCommand;
	std::string _whenError;
	STestCommand(std::string testCommand, std::string whenError) :
		_testCommand(testCommand), _whenError(whenError)
	{ }
};

struct SStat {
	uint passed;
	uint failed;
	SStat()
		: passed(0), failed(0)
	{}
};

class CTool
{
public:
	CTool();
	~CTool();
	void setInputPath(std::string path);
	void setOutputPath(std::string path);
	void setExpectedPath(std::string path);
	void addExecutionCommandLine(std::string commandLine);
	void addCopyingResultsCommandLine(std::string commandLine);
	void addTestingResultsCommandLine(std::string commandLine, std::string whenError);
	int runTest(std::string name);
	int testOk(std::string name);
	int testOkAll();
	int check(std::string name);
	int checkAll();
	int showDiff(std::string name);
	int showDiffAll();
	CTest* addTest(SResult expectedResult, std::string name);
	int runAll();
	CTest* getTest(std::string name);
	std::string replaceTag(std::string command, std::string tag, std::string value);
	std::string replaceAllTags(std::string command, CTest* test, CSubtest* subtest);
	SStat _stat;
private:
	std::vector<std::string> _execCommandLine;
	std::vector<std::string> _copyCommandLine;
	std::vector<STestCommand> _testCommandLine;
	std::string _inputPath;
	std::string _outputPath;
	std::string _expectedPath;
	std::vector<CTest*> _testList;
};

#endif
