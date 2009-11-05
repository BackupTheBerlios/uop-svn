#include "Group.hpp"

#include "RunBytecode.hpp"

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
	_dataList[tuple->getComposedKeys()] = tuple;
}


void CGroup::remTuple(CTuple* tuple)
{
// 	std::cout << "Antes de remover: " << _dataList[tuple->getComposedKeys()] << std::endl;
	_dataList.erase(tuple->getComposedKeys());
// 	std::cout << "Depois de remover: " << _dataList[tuple->getComposedKeys()] << std::endl;
}


CTuple* CGroup::getTuple(CTuple* tuple)
{
	return _dataList[tuple->getComposedKeys()];
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


CTuple * CGroup::findTuple(CTuple* tuple)
{
	return NULL; // TODO
}

void CGroup::run_insert_data_event(std::string keys, std::string values)
{
	std::map<std::string, std::pair<CElement*, CMethodDefinition*> >::iterator event = _events.find("on_insert_data");

	if (event != _events.end()) {
		CRunBytecode* rb = new CRunBytecode();

		rb->_dataStack.push(keys);
		rb->_dataStack.push(values);

		CActivationRecord* ar = new CActivationRecord(rb, (*event).second.first, (*event).second.second->getName(), rb->_ip, rb->_dataStack);
		rb->_controlStack.push(ar);
		rb->run_bytecode_until(RET_OPCODE);

		delete rb;
	}
}

void CGroup::run_insert_service_event(std::string service_name)
{
	std::map<std::string, std::pair<CElement*, CMethodDefinition*> >::iterator event = _events.find("on_insert_service");

	if (event != _events.end()) {
		CRunBytecode* rb = new CRunBytecode();

		rb->_dataStack.push(service_name);

		CActivationRecord* ar = new CActivationRecord(rb, (*event).second.first, (*event).second.second->getName(), rb->_ip, rb->_dataStack);
		rb->_controlStack.push(ar);
		rb->run_bytecode_until(RET_OPCODE);

		delete rb;
	}
}
