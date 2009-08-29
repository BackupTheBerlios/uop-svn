#include "Group.hpp"

CGroup::CGroup(std::string name) : _name(name)
{
}


void CGroup::addObject(std::string name)
{
	_objectList.insert(name);
}


void CGroup::remObject(std::string name)
{
	_objectList.erase(name);
}


void CGroup::addTuple(CTuple* tuple)
{
	_dataList[tuple->getComposedKey()] = tuple;
}


void CGroup::remTuple(CTuple* tuple)
{
}


CTuple* CGroup::getTuple(CTuple* tuple)
{
	return _dataList[tuple->getComposedKey()];
}


void CGroup::addService(std::string serviceName, std::string element)
{
	_serviceList[serviceName] = element;
}

std::string CGroup::findService(std::string serviceName)
{
	std::map<std::string, std::string>::iterator service = _serviceList.find(serviceName);
	if (service == _serviceList.end())
		return "";
	else
		return (*service).second;
}
