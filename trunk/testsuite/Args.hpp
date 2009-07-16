#ifndef TESTSUITE_ARGS_HPP
#define TESTSUITE_ARGS_HPP

#include <string>

class CArgs
{
public:
	CArgs();
	CArgs(std::string name, std::string value);
	~CArgs();
//private:
	std::string _name;
	std::string _value;
};

#endif
