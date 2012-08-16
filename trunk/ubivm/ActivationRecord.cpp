//
// C++ Implementation: ActivationRecord
//
// Description: 
//
//
// Author: Alex Sandro Garzão <alexgarzao@gmail.com>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "ActivationRecord.hpp"

#include "UbiVM.hpp"

CActivationRecord::CActivationRecord(CRunBytecode* bce, CElement* element, std::string methodName, SIp& currentIp, CDataStack& dataStack)
	: _bce(bce), _methodName(methodName), _lastIp(currentIp)
{
	_method  = element->getMethod(methodName);

	if (_method == NULL) {
		std::cout << "Metodo " << _methodName << " nao encontrado !!!" << std::endl;
		return;
	}

	currentIp.element = element;
	currentIp.method  = _method;

	// Define variaveis locais
	for(std::vector<CLocalVarDefinition*>::iterator var = _method->_localVarList.begin();
		var != _method->_localVarList.end(); var++) {
		_localVarList.push_back(CLiteral((*var)->_type));
	}

	for(std::vector<CParameterDefinition*>::iterator par = _method->_parameterList.begin();
			par != _method->_parameterList.end(); par++) {
 		_paramList.insert(_paramList.begin(), dataStack.pop());
	}

	for(std::vector<CResultDefinition*>::iterator ret = _method->_resultList.begin();
			ret != _method->_resultList.end(); ret++) {
	 	_resultList.push_back(CLiteral((*ret)->_type));
	}

	currentIp.ip = 0;
}


CActivationRecord::~CActivationRecord()
{
}

void CActivationRecord::restore_state(CDataStack& dataStack, SIp& currentIp)
{
 	for(std::vector<CLiteral>::reverse_iterator ret = _resultList.rbegin();
 			ret != _resultList.rend(); ret++) {
 		dataStack.push(*ret);
 	}

	currentIp = _lastIp;
}

