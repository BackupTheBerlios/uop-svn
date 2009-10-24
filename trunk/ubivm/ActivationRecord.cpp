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

CActivationRecord::CActivationRecord(CRunBytecode* bce, std::string entityName, std::string methodName, SIp& currentIp, CDataStack& dataStack)
	: _bce(bce), _entityName(entityName), _methodName(methodName), _lastIp(currentIp)
{
	_element = new CElement(CUbiVM::getInstance()->getAsmDef()->getEntity(entityName));
	
	if (_element == NULL) {
		std::cout << "Entidade " << entityName << " nao encontrada !!!" << std::endl;
		return;
	}

	_method  = _element->getMethod(methodName);

	if (_method == NULL) {
		std::cout << "Metodo " << _methodName << " nao encontrado !!!" << std::endl;
		return;
	}

	currentIp.element = _element;
	currentIp.method  = _method;

	// Define variaveis locais
	for(std::vector<CLocalVarDefinition*>::iterator var = _method->_localVarList.begin();
		var != _method->_localVarList.end(); var++) {
		_localVarList.push_back(CLiteral((*var)->_type));
	}

	for(std::vector<CParameterDefinition*>::iterator par = _method->_parameterList.begin();
			par != _method->_parameterList.end(); par++) {
// 		_paramList.push_back(dataStack.pop());
//  		std::cout << "Parametro inserido: " << (_paramList.end()-1)->getText() << std::endl;
 		_paramList.insert(_paramList.begin(), dataStack.pop());
// 		std::cout << "Parametro inserido: " << _paramList.begin()->getText() << std::endl;
	}

// 	std::cout << __FUNCTION__ << ": _method->_resultList.size()=" << _method->_resultList.size() << std::endl;

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
// 	std::cout << __FUNCTION__ << ": _resultList.size()=" << _resultList.size() << " dataStack.size()=" << dataStack.size() << std::endl;
	
 	for(std::vector<CLiteral>::reverse_iterator ret = _resultList.rbegin();
 			ret != _resultList.rend(); ret++) {
//  		std::cout << __FUNCTION__ << ": Resultado: " << ret->getText() << std::endl;
 		dataStack.push(*ret);
 	}

//  	for(std::vector<CLiteral>::reverse_iterator ret = _resultList.rbegin();
//  			ret != _resultList.rend(); ret++) {
// //  		std::cout << __FUNCTION__ << ": Resultado: " << ret->getText() << std::endl;
//  		dataStack.push(*ret);
//  	}

	currentIp = _lastIp;
}



/*void CActivationRecord::restore_state(CDataStack& dataStack, SIp& currentIp)
{
// 	_element = new CElement(CUbiVM::getInstance()->getAsmDef()->getEntity(_entityName));
// 	
// 	if (_element == NULL) {
// 		std::cout << "Entidade " << _entityName << " nao encontrada !!!" << std::endl;
// 		return;
// 	}
// 
// 	_method  = _element->getMethod(_methodName);
// 
// 	if (_method == NULL) {
// 		std::cout << "Metodo " << _methodName << " nao encontrado !!!" << std::endl;
// 		return;
// 	}

	for(std::vector<CResultDefinition*>::iterator ret = _method->_resultList.begin();
		ret != _method->_resultList.end(); ret++) {
 		std::cout << __FUNCTION__ << ": Resultado: " << ret->getText() << std::endl;
 		dataStack.push(*ret);
	}

	
//  	for(std::vector<CLiteral>::reverse_iterator ret = _method->_resultList.rbegin();
//  			ret != _method->_resultList.rend(); ret++) {
//  		std::cout << __FUNCTION__ << ": Resultado: " << ret->getText() << std::endl;
//  		dataStack.push(*ret);
//  	}

	currentIp = _lastIp;
}*/
