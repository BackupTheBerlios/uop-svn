#include "Group.hpp"

#include "RunBytecode.hpp"

CContext::CContext(std::string name) : _name(name)
{
}


void CContext::addObject(std::string name)
{
	_objectList.insert(name);
}


void CContext::remObject(std::string name)
{
	_objectList.erase(name);
}


void CContext::addTuple(CTuple* tuple)
{
	_listd[tuple->getComposedKeys()] = tuple;
}


void CContext::remTuple(CTuple* tuple)
{
// 	std::cout << "Antes de remover: " << _listd[tuple->getComposedKeys()] << " size=" << _listd.size() <<  std::endl;
	_listd.erase(tuple->getComposedKeys());
// 	std::cout << "Depois de remover: " << _listd[tuple->getComposedKeys()] << " size=" << _listd.size() << std::endl;
}


CTuple* CContext::getTuple(CTuple* tuple)
{
	return _listd[tuple->getComposedKeys()];
}


void CContext::addService(std::string serviceName, std::string element)
{
	_serviceList[serviceName] = element;
}

void CContext::remService(std::string serviceName)
{
	_serviceList.erase(serviceName);
}

std::string CContext::findService(std::string serviceName)
{
	std::map<std::string, std::string>::iterator service = _serviceList.find(serviceName);
	if (service == _serviceList.end())
		return "";
	else
		return (*service).second;
}


CTuple * CContext::findTuple(CTuple* tuple)
{
	return NULL; // TODO
}

void CContext::run_insert_data_event(std::string keys, std::string values)
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

void CContext::run_remove_data_event(std::string keys, std::string values)
{
	std::map<std::string, std::pair<CElement*, CMethodDefinition*> >::iterator event = _events.find("on_remove_data");

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

void CContext::run_insert_service_event(std::string service_name)
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


void CContext::run_remove_service_event(std::string service_name)
{
	std::map<std::string, std::pair<CElement*, CMethodDefinition*> >::iterator event = _events.find("on_remove_service");

	if (event != _events.end()) {
		CRunBytecode* rb = new CRunBytecode();

		rb->_dataStack.push(service_name);

		CActivationRecord* ar = new CActivationRecord(rb, (*event).second.first, (*event).second.second->getName(), rb->_ip, rb->_dataStack);
		rb->_controlStack.push(ar);
		rb->run_bytecode_until(RET_OPCODE);

		delete rb;
	}
}
