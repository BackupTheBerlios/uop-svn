#ifndef ACTIVATIONRECORD_HPP
#define ACTIVATIONRECORD_HPP

#include <vector>

class CActivationRecord;

#include "UbivmDefs.hpp"
#include "Literal.hpp"

#include "RunBytecode.hpp"

/**
	@author Alex Sandro Garzão <alexgarzao@gmail.com>
*/
class CActivationRecord{
public:
	CActivationRecord(CRunBytecode* bce, CElement* element, std::string methodName, SIp& currentIp, CDataStack& dataStack);
	CActivationRecord() { } // TODO: retirar isso
	~CActivationRecord();
	void restore_state(CDataStack& dataStack, SIp& currentIp);

	CRunBytecode* _bce;
// 	std::string _entityName;
	std::string _methodName;
	SIp _lastIp;
	std::vector<CLiteral> _localVarList;
	std::vector<CLiteral> _paramList;
	std::vector<CLiteral> _resultList;
// 	std::vector<CMultiIndex<CLiteral> > _localTabList;
	CElement* _element;
	CMethodDefinition* _method;
	
};

#endif
