#include <stdlib.h>

#include <iostream>

#include "Tool.hpp"
#include "Tools.hpp"

CTool::CTool()
{
}

CTool::~CTool()
{
}

void CTool::addExecutionCommandLine(std::string commandLine)
{
	_execCommandLine.push_back(commandLine);
}

void CTool::setInputPath(std::string path)
{
	_inputPath = path;
}

void CTool::setOutputPath(std::string path)
{
	_outputPath = path;
}

void CTool::setExpectedPath(std::string path)
{
	_expectedPath = path;
}

void CTool::addCopyingResultsCommandLine(std::string commandLine)
{
	_copyCommandLine.push_back(commandLine);
}

void CTool::addTestingResultsCommandLine(std::string commandLine, std::string whenError)
{
	_testCommandLine.push_back(STestCommand(commandLine, whenError));
}

CTest* CTool::getTest(std::string name)
{
	for(std::vector<CTest*>::iterator test = _testList.begin(); test != _testList.end(); test++) {
		if ((*test)->_name == name) {
			return *test;
		}
	}

	return NULL;
}

std::string CTool::replaceTag(std::string command, std::string tag, std::string value)
{
	tag = "%" + tag + "%";

	size_t pos = command.find(tag);
	while(pos != std::string::npos) {
		command = command.replace(pos, tag.length(), value);
		pos = command.find(tag);
	}

	return command;
}

std::string CTool::replaceAllTags(std::string command, CTest* test, CSubtest* subtest)
{
	// TODO: ta incompleto...
	command = replaceTag(command, "TEST"      , test->_name);
	command = replaceTag(command, "INPUTPATH" , _inputPath);
	command = replaceTag(command, "OUTPUTPATH", _outputPath);
	command = replaceTag(command, "EXPECTEDPATH", _expectedPath);
	if (subtest->_number != 0) {
		command = replaceTag(command, "SUBTESTNUMBER", std::string(".") + std::string(itoa(subtest->_number)));
	}
	if (subtest->_args1._name.size() > 0) {
		command = replaceTag(command, subtest->_args1._name, subtest->_args1._value);
		if (subtest->_args2._name.size() > 0) {
			command = replaceTag(command, subtest->_args2._name, subtest->_args2._value);
		}
	}

	// Tags with undefined values must be cleared
	size_t pos1 = command.find("%");
	while(pos1 != std::string::npos) {
		size_t pos2 = command.find("%", pos1+1);
		if (pos2 == std::string::npos) {
			break;
		}
		command = command.erase(pos1, pos2-pos1+1);
		pos1 = command.find("%");
	}

	return command;
}

int CTool::runTest(std::string name)
{
	std::cout << "Running test " << name << std::endl;
	CTest* test = getTest(name); // usar map, hash_map ou afins...
	if (test == NULL) {
		std::cout << "Test " << name << " not defined !!!" << std::endl;
		return 1;
	}
	for(std::vector<CSubtest*>::iterator subtest = test->_subtestList.begin(); subtest != test->_subtestList.end(); subtest++ ) {
		for(std::vector<std::string>::iterator command = _execCommandLine.begin(); command != _execCommandLine.end(); command++) {
			std::string commandToExec = replaceAllTags((*command), test, (*subtest));
			std::cout << "\t" << commandToExec;
//			std::cout << "\tCommand line: " << commandToExec << std::endl;
			if (system(commandToExec.c_str()) == 0) {
				std::cout << " (OK)";
			} else {
				std::cout << " (FAIL)";
			}
			std::cout << std::endl;
		}
	}

	return 0;
}

int CTool::testOk(std::string name)
{
	std::cout << "Running test ok " << name << std::endl;
	CTest* test = getTest(name); // usar map, hash_map ou afins...
	for(std::vector<CSubtest*>::iterator subtest = test->_subtestList.begin(); subtest != test->_subtestList.end(); subtest++ ) {
		for(std::vector<std::string>::iterator command = _copyCommandLine.begin(); command != _copyCommandLine.end(); command++) {
			std::string commandToExec = replaceAllTags((*command), test, (*subtest));
			std::cout << "\t" << commandToExec;
//			std::cout << "\tCommand line: " << commandToExec << std::endl;
			if (system(commandToExec.c_str()) == 0) {
				std::cout << " (OK)";
			} else {
				std::cout << " (FAIL)";
			}
			std::cout << std::endl;
		}
	}

	return 0;
}

int CTool::check(std::string name)
{
	std::cout << "Running check test " << name << std::endl;
	CTest* test = getTest(name); // usar map, hash_map ou afins...
	for(std::vector<CSubtest*>::iterator subtest = test->_subtestList.begin(); subtest != test->_subtestList.end(); subtest++ ) {
		for(std::vector<STestCommand>::iterator command = _testCommandLine.begin(); command != _testCommandLine.end(); command++) {
			std::string commandToExec = replaceAllTags(command->_testCommand, test, (*subtest));
			std::cout << "\t" << commandToExec;
//			std::cout << "\tCommand line: " << commandToExec << " ";
			if (system(commandToExec.c_str()) != 0) {
				_stat.failed++;
				std::cout << " (FAIL)";
//				if (command->_whenError.size() > 0) {
//					std::string commandToExecWhenError = replaceAllTags(command->_whenError, test, (*subtest));
//					std::cout << "\tCommand line when error: " << commandToExecWhenError << std::endl;
//					//system(commandToExecWhenError.c_str());
//				}
			} else {
				_stat.passed++;
				std::cout << " (OK)";
			}
			std::cout << std::endl;
		}
	}

	return 0;
}

int CTool::showDiff(std::string name)
{
	std::cout << "Running diff test " << name << std::endl;
	CTest* test = getTest(name); // usar map, hash_map ou afins...
	for(std::vector<CSubtest*>::iterator subtest = test->_subtestList.begin(); subtest != test->_subtestList.end(); subtest++ ) {
		for(std::vector<STestCommand>::iterator command = _testCommandLine.begin(); command != _testCommandLine.end(); command++) {
			std::string commandToExec = replaceAllTags(command->_testCommand, test, (*subtest));
			std::cout << "\t" << commandToExec;
			//std::cout << "\tCommand line: " << commandToExec << " ";
			if (system(commandToExec.c_str()) != 0) {
				_stat.failed++;
				std::cout << " (FAIL)" << std::endl;
				if (command->_whenError.size() > 0) {
					std::string commandToExecWhenError = replaceAllTags(command->_whenError, test, (*subtest));
					std::cout << "\t" << commandToExecWhenError << std::endl;
//					std::cout << "\tCommand line when error: " << commandToExecWhenError << std::endl;
					system(commandToExecWhenError.c_str());
				}
			} else {
				_stat.passed++;
				std::cout << " (OK)" << std::endl;
			}
		}
	}

	return 0;
}

CTest* CTool::addTest(SResult expectedResult, std::string name)
{
	CTest* test = new CTest(name);
	test->addSubtest(expectedResult, CArgs("", ""));

	_testList.push_back(test);

	return test;
}

int CTool::runAll()
{
	memset(&_stat, 0, sizeof(&_stat));

	for(std::vector<CTest*>::iterator test = _testList.begin(); test != _testList.end(); test++) {
		runTest((*test)->_name);
	}
	return 0;
}

int CTool::testOkAll()
{
	for(std::vector<CTest*>::iterator test = _testList.begin(); test != _testList.end(); test++) {
		testOk((*test)->_name);
	}
	return 0;
}

int CTool::checkAll()
{
	for(std::vector<CTest*>::iterator test = _testList.begin(); test != _testList.end(); test++) {
		check((*test)->_name);
	}
	return 0;
}

int CTool::showDiffAll()
{
	for(std::vector<CTest*>::iterator test = _testList.begin(); test != _testList.end(); test++) {
		showDiff((*test)->_name);
	}
	return 0;
}

