#ifndef UBIVM_LOG_HPP
#define UBIVM_LOG_HPP

#include <iostream>
#include <string>

/**
	@author Alex Sandro Garzão <alexgarzao@gmail.com>
*/
class CLog
{
public:
	static void log(std::string text)
	{
		std::cout << "log: " << text << std::endl;
	}
};

#endif

