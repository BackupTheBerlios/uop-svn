#ifndef ACTIVATIONRECORD_HPP
#define ACTIVATIONRECORD_HPP

#include <vector>

#include "UbivmDefs.hpp"
#include "Literal.hpp"

/**
	@author Alex Sandro Garzão <alexgarzao@gmail.com>
*/
class CActivationRecord{
public:
	CActivationRecord();
	~CActivationRecord();

	SIp _ip;
	std::vector<CLiteral> _localVarList;
	std::vector<CLiteral> _paramList;
	std::vector<CLiteral> _resultList;
	std::vector<CMultiIndex<CLiteral> > _localTabList;
};

#endif
