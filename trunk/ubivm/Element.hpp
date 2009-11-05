#ifndef UBIVM_ELEMENT_HPP
#define UBIVM_ELEMENT_HPP

#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <vector>

class CElement;

#include "EntityDefinition.hpp"
#include "Literal.hpp"


/**
	@author Alex Sandro Garzão <alexgarzao@gmail.com>
*/
class CElement
{
public:
    CElement() : _entity(NULL), _thread(NULL) { }
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
	void bind_event(std::string event_name, CElement* element, CMethodDefinition* method);
	void run_event(std::string event_name);
	std::pair<CElement*, CMethodDefinition*> get_event(std::string event_name);

// private:
	boost::thread* _thread;
	std::vector<CLiteral> _propertyList;
	std::map<std::string, std::pair<CElement*, CMethodDefinition*> > _events;
};

#endif

