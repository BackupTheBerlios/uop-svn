#ifndef UBIVM_ELEMENT_HPP
#define UBIVM_ELEMENT_HPP

#include "EntityDefinition.hpp"

/**
	@author Alex Sandro Garzão <alexgarzao@gmail.com>
*/
class CElement
{
public:
    CElement() : _entity(NULL) { }
    CElement(CEntityDefinition* entity);
    ~CElement();
	CEntityDefinition* _entity;
	CMethodDefinition* getMethod(std::string name)
	{
		return _entity->getMethod(name);
	}
	CSymbol* getSymbolByIndex(size_t index)
	{
		return _entity->getSymbolByIndex(index);
	}
	std::string getName()
	{
		return _entity->getName();
	}
};

#endif

