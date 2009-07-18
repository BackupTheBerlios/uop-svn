#ifndef UBIVM_DATASTACK_HPP
#define UBIVM_DATASTACK_HPP

/**
	@author Alex Sandro Garzão <alexgarzao@gmail.com>
*/

#include <sys/types.h>

#include <stack>

#include "Literal.hpp"

class CDataStack
{
public:
    CDataStack();
    ~CDataStack();
	void push(CLiteral data);
	CLiteral pop();
	size_t size() const { return _dataStack.size(); }
private:
//	std::stack<uint> _dataStack;
	std::stack<CLiteral> _dataStack;
};

//}

#endif

