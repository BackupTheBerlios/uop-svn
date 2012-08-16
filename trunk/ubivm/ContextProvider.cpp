//
// C++ Implementation: ContextProvider
//
// Description:
//
//
// Author: Alex Sandro Garzão <alexgarzao@gmail.com>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "ContextProvider.hpp"
#include "CommunicationProvider.hpp"
#include "UbiVM.hpp"


void CContextProvider::setConfig(std::map<std::string, CContext*>* contextList)
{
	_contextList = contextList;
}


CContextProvider::~CContextProvider()
{
}


// TODO: seria um request ou notice ???
void CContextProvider::sendRequestPublishdOpcode(SVmId vmId, std::string contextName, CTuple tuple)
{
	CBinString    packet;
	SPacketHeader header;
	SVmId         dstVmId(0,0);

	header._srcVmId      = vmId;
	header._dstVmId      = dstVmId;
	header._packetNumber = CCommunicationProvider::getInstance()->getNextPacketNumber();
	header._opcode       = CPUBLISH_OPCODE;
	header._operation    = REQUEST_OPERATION;

	packet.save(&header, sizeof(header));
	packet.save(contextName);
	tuple.saveBytecode(packet);

	CCommunicationProvider::getInstance()->sendBroadcastPacket(packet.getData().c_str(), packet.size());
}


void CContextProvider::sendRequestFinddOpcode(SVmId vmId, std::string contextName, CTuple tuple)
{
	CBinString    packet;
	SPacketHeader header;
	SVmId         dstVmId(0,0);

	header._srcVmId      = vmId;
	header._dstVmId      = dstVmId;
	header._packetNumber = CCommunicationProvider::getInstance()->getNextPacketNumber();
	header._opcode       = CFIND_OPCODE;
	header._operation    = REQUEST_OPERATION;

	packet.save(&header, sizeof(header));
	packet.save(contextName);
	tuple.saveBytecode(packet);

	_bce_list[vmId._bce]->_dataReady = false;

	while( _bce_list[vmId._bce]->_dataReady == false) {
		CCommunicationProvider::getInstance()->sendBroadcastPacket(packet.getData().c_str(), packet.size());
		sleep(REQUEST_TIMEOUT);
	}
}


void CContextProvider::sendRequestGetdOpcode(SVmId vmId, std::string contextName, CTuple tuple)
{
	CBinString    packet;
	SPacketHeader header;
	SVmId         dstVmId(0,0);

	header._srcVmId      = vmId;
	header._dstVmId      = dstVmId;
	header._packetNumber = CCommunicationProvider::getInstance()->getNextPacketNumber();
	header._opcode       = CFIND_OPCODE;
	header._operation    = REQUEST_OPERATION;
	packet.save(&header, sizeof(header));

	// Context name
	packet.save(contextName);

	// Tuple key
	tuple.saveBytecode(packet);

	_bce_list[vmId._bce]->_dataReady = false;

	while( _bce_list[vmId._bce]->_dataReady == false) {
		CCommunicationProvider::getInstance()->sendBroadcastPacket(packet.getData().c_str(), packet.size());
		sleep(REQUEST_TIMEOUT);
	}

	// Envia um DQU unicast
	CBinString dqu_packet;
	header._dstVmId = _bce_list[vmId._bce]->_lastSrcVmId; // TODO: como descobrir a VM correta ???;
	header._opcode = CGET_OPCODE;
	dqu_packet.save(&header, sizeof(header));
	dqu_packet.save(contextName);
	tuple.saveBytecode(dqu_packet);

	_bce_list[vmId._bce]->_dataReady = false;

	while(_bce_list[vmId._bce]->_dataReady == false) {
		CCommunicationProvider::getInstance()->sendBroadcastPacket(dqu_packet.getData().c_str(), dqu_packet.size());
		sleep(REQUEST_TIMEOUT);
	}

	// Retira a informacao inserida na pilha pelo dqu porque o qu ja inseriu
	_bce_list[header._srcVmId._bce]->_dataStack.pop();
}


void CContextProvider::sendRequestFinddnbOpcode(SVmId vmId, std::string contextName, CTuple tuple)
{
	CBinString    packet;
	SPacketHeader header;
	SVmId         dstVmId(0,0);

	header._srcVmId      = vmId;
	header._dstVmId      = dstVmId;
	header._packetNumber = CCommunicationProvider::getInstance()->getNextPacketNumber();
	header._opcode       = CFINDNB_OPCODE;
	header._operation    = REQUEST_OPERATION;
	packet.save(&header, sizeof(header));

	// Context name
	packet.save(contextName);

	// Tuple key
	tuple.saveBytecode(packet);

	_bce_list[vmId._bce]->_dataReady = false;

	CCommunicationProvider::getInstance()->sendBroadcastPacket(packet.getData().c_str(), packet.size());
	sleep(REQUEST_TIMEOUT);
	if (_bce_list[vmId._bce]->_dataReady == false) {
	 	CTuple* tuple2 = new CTuple();
		_bce_list[header._dstVmId._bce]->_dataStack.push(CLiteral(tuple2));
	}
}


void CContextProvider::sendRequestGetdnbOpcode(SVmId vmId, std::string contextName, CTuple tuple)
{
	CBinString    packet;
	SPacketHeader header;
	SVmId         dstVmId(0,0);

	header._srcVmId      = vmId;
	header._dstVmId      = dstVmId;
	header._packetNumber = CCommunicationProvider::getInstance()->getNextPacketNumber();
	header._opcode       = CFIND_OPCODE;
	header._operation    = REQUEST_OPERATION;

	packet.save(&header, sizeof(header));
	packet.save(contextName);
	tuple.saveBytecode(packet);

	_bce_list[vmId._bce]->_dataReady = false;

	CCommunicationProvider::getInstance()->sendBroadcastPacket(packet.getData().c_str(), packet.size());
	sleep(REQUEST_TIMEOUT);

	if (_bce_list[vmId._bce]->_dataReady == false) {
	 	CTuple* tuple2 = new CTuple();
		_bce_list[header._dstVmId._bce]->_dataStack.push(CLiteral(tuple2));

		return;
	}

	// Envia um DQU unicast
	CBinString dqu_packet;
	header._dstVmId = _bce_list[vmId._bce]->_lastSrcVmId; // TODO: como descobrir a VM correta ???;
	header._opcode = CGET_OPCODE;
	dqu_packet.save(&header, sizeof(header));
	dqu_packet.save(contextName);
	tuple.saveBytecode(dqu_packet);

	_bce_list[vmId._bce]->_dataReady = false;

	CCommunicationProvider::getInstance()->sendBroadcastPacket(dqu_packet.getData().c_str(), dqu_packet.size());
	sleep(REQUEST_TIMEOUT);

	if (_bce_list[vmId._bce]->_dataReady == false) {
		return;
	}

	// Retira a informacao inserida na pilha pelo dqu porque o qu ja inseriu
	_bce_list[header._srcVmId._bce]->_dataStack.pop();
}

void CContextProvider::sendRequestListdOpcode(SVmId vmId, std::string contextName)
{
	CBinString    packet;
	SPacketHeader header;
	SVmId         dstVmId(0,0);

	header._srcVmId      = vmId;
	header._dstVmId      = dstVmId;
	header._packetNumber = CCommunicationProvider::getInstance()->getNextPacketNumber();
	header._opcode       = CLIST_OPCODE;
	header._operation    = REQUEST_OPERATION;
	packet.save(&header, sizeof(header));

	packet.save(contextName.c_str());

	_bce_list[vmId._bce]->_listdReplyTable = new CMultiIndex<CLiteral>();

	_bce_list[vmId._bce]->_dataReady = false;
	CCommunicationProvider::getInstance()->sendBroadcastPacket(packet.getData().c_str(), packet.size());

	sleep(REQUEST_TIMEOUT);

	_bce_list[vmId._bce]->_dataStack.push(CLiteral(_bce_list[vmId._bce]->_listdReplyTable));
}


void CContextProvider::sendRequestPublishsOpcode(SVmId vmId, std::string contextName, std::string serviceName)
{
	CBinString    packet;
	SPacketHeader header;
	SVmId         dstVmId(0,0);

	header._srcVmId      = vmId;
	header._dstVmId      = dstVmId;
	header._packetNumber = CCommunicationProvider::getInstance()->getNextPacketNumber();
	header._opcode       = SPUBLISH_OPCODE;
	header._operation    = REQUEST_OPERATION;

	packet.save(&header, sizeof(header));
	packet.save(contextName);
	packet.save(serviceName);

	CCommunicationProvider::getInstance()->sendBroadcastPacket(packet.getData().c_str(), packet.size());
}


void CContextProvider::sendRequestRemovesOpcode(SVmId vmId, std::string contextName, std::string serviceName)
{
	CBinString    packet;
	SPacketHeader header;
	SVmId         dstVmId(0,0);

	header._srcVmId      = vmId;
	header._dstVmId      = dstVmId;
	header._packetNumber = CCommunicationProvider::getInstance()->getNextPacketNumber();
	header._opcode       = SREM_OPCODE;
	header._operation    = REQUEST_OPERATION;

	packet.save(&header, sizeof(header));
	packet.save(contextName);
	packet.save(serviceName);

	CCommunicationProvider::getInstance()->sendBroadcastPacket(packet.getData().c_str(), packet.size());
}


void CContextProvider::sendRequestRunsOpcode(SVmId vmId, std::string contextName, std::string serviceName)
{
	CBinString    packet;
	SPacketHeader header;
	SVmId         dstVmId(0,0);

	header._srcVmId      = vmId;
	header._dstVmId      = dstVmId;
	header._packetNumber = CCommunicationProvider::getInstance()->getNextPacketNumber();
	header._opcode       = SRUN_OPCODE;
	header._operation    = REQUEST_OPERATION;

	packet.save(&header, sizeof(header));
	packet.save(contextName);
	packet.save(serviceName);

	uint argsNumber = _bce_list[vmId._bce]->_dataStack.pop().getInteger();
	packet.save(&argsNumber, sizeof(argsNumber));

	for(uint arg=0; arg < argsNumber; arg++) {
		// TODO: nao to mandando na ordem inversa ???
		_bce_list[vmId._bce]->_dataStack.pop().saveBytecode(packet);
	}

	_bce_list[vmId._bce]->_dataReady = false;

	while( _bce_list[vmId._bce]->_dataReady == false) {
		CCommunicationProvider::getInstance()->sendBroadcastPacket(packet.getData().c_str(), packet.size());
		sleep(REQUEST_TIMEOUT);
	}
}


void CContextProvider::processPublishdRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket)
{
	CTuple*       tuple = new CTuple();;

	std::string contextName;
	requestPacket.load(contextName);

	tuple->loadBytecode(requestPacket);

	if (_contextList->find(contextName) != _contextList->end()) {
		(*_contextList)[contextName]->run_insert_data_event(tuple->getComposedKeys(), tuple->getComposedValues());
	}

	delete tuple;
}


void CContextProvider::processFinddRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket)
{
	SPacketHeader replyHeader;
	CTuple*       tuple;

	std::string contextName;
	requestPacket.load(contextName);

	CTuple tupleToFind;
	tupleToFind.loadBytecode(requestPacket);
	

	// Verify if context exist...
	if (_contextList->find(contextName) == _contextList->end()) {
		return;
	}

	tuple = (*_contextList)[contextName]->getTuple(&tupleToFind);

	if (tuple == NULL) {
		return;
	}

	replyHeader._srcVmId      = requestHeader._dstVmId;
	replyHeader._dstVmId      = requestHeader._srcVmId;
	replyHeader._packetNumber = requestHeader._packetNumber;
	replyHeader._operation    = REPLY_OPERATION;
	replyHeader._opcode       = requestHeader._opcode;
	replyPacket.save(&replyHeader, sizeof(replyHeader));

	tuple->saveBytecode(replyPacket);
}


void CContextProvider::processFinddnbRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket)
{
	processFinddRequest(requestPacket, requestHeader, replyPacket);
}


void CContextProvider::processGetdRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket)
{
	SPacketHeader replyHeader;
	CTuple*       tuple;

	std::string contextName;
	requestPacket.load(contextName);

	CTuple tupleToFind;
	tupleToFind.loadBytecode(requestPacket);
	
	// Verify if context exist...
	if (_contextList->find(contextName) == _contextList->end()) {
		return;
	}

	tuple = (*_contextList)[contextName]->getTuple(&tupleToFind);

	if (tuple == NULL) {
		return;
	}

	replyHeader._srcVmId      = requestHeader._dstVmId;
	replyHeader._dstVmId      = requestHeader._srcVmId;
	replyHeader._packetNumber = requestHeader._packetNumber;
	replyHeader._operation    = REPLY_OPERATION;
	replyHeader._opcode       = requestHeader._opcode;
	replyPacket.save(&replyHeader, sizeof(replyHeader));

	tuple->saveBytecode(replyPacket);

	// Verify if context exist...
	if (_contextList->find(contextName) == _contextList->end()) {
		return;
	}

	(*_contextList)[contextName]->remTuple(&tupleToFind);

	if (_contextList->find(contextName) != _contextList->end()) {
		// TODO: acho que deveria passar a tupla mesmo no evento abaixo...
		(*_contextList)[contextName]->run_remove_data_event(tuple->getComposedKeys(), tuple->getComposedValues());
	}

}


void CContextProvider::processGetdnbRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket)
{
	processGetdRequest(requestPacket, requestHeader, replyPacket);
}


void CContextProvider::processListdRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket)
{
	size_t size;
	SPacketHeader replyHeader;

	std::string contextName;
	requestPacket.load(contextName);

	// Verify if context exist...
	if (_contextList->find(contextName) == _contextList->end()) {
		return;
	}

	if ((*_contextList)[contextName]->_listd.size() == 0) {
		return;
	}

	// -- Packing reply --

	// Packing header
	replyHeader._dstVmId      = requestHeader._srcVmId;
	replyHeader._srcVmId      = requestHeader._dstVmId;
	replyHeader._packetNumber = requestHeader._packetNumber;
	replyHeader._operation    = REPLY_OPERATION;
	replyHeader._opcode       = CLIST_OPCODE;
	replyPacket.save(&replyHeader, sizeof(replyHeader));

	// Packing tuple count
	size = (*_contextList)[contextName]->_listd.size();
	replyPacket.save(&size, sizeof(size));

	// Packing tuples
	for(std::map<std::string, CTuple*>::iterator data = (*_contextList)[contextName]->_listd.begin();
			data != (*_contextList)[contextName]->_listd.end(); data++) {

		CTuple* tuple = (*data).second;
		tuple->saveBytecode(replyPacket);
	}
}


void CContextProvider::processPublishsRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket)
{
	std::string contextName;
	requestPacket.load(contextName);

	std::string serviceName;
	requestPacket.load(serviceName);

	if (_contextList->find(contextName) != _contextList->end()) {
		(*_contextList)[contextName]->run_insert_service_event(serviceName);
	}
}


void CContextProvider::processRemovesRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket)
{
	std::string contextName;
	requestPacket.load(contextName);

	std::string serviceName;
	requestPacket.load(serviceName);

	if (_contextList->find(contextName) != _contextList->end()) {
		(*_contextList)[contextName]->run_remove_service_event(serviceName);
	}
}


void CContextProvider::processRunsRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket)
{
	SPacketHeader replyHeader;

	std::string contextName;
	requestPacket.load(contextName);

	std::string serviceName;
	requestPacket.load(serviceName);

	CRunBytecode* bce = new CRunBytecode();

	std::vector<CLiteral> arguments;

	// TODO: talvez nem precisasse enviar o numero de argumentos... mas ao enviar a requisicao, como saber qtos argumentos devem ser serializados ????
	uint argsNumber;
	requestPacket.load(&argsNumber, sizeof(argsNumber));

	for(uint arg = 0; arg < argsNumber; arg++) {
		CLiteral arg;
		arg.loadBytecode(requestPacket);
		arguments.push_back(arg);
	}

	std::vector<CLiteral> results;

	if (bce->runsCode(contextName, serviceName, arguments, results) == false) {
		delete bce;
		return;
	}

	replyHeader._srcVmId      = requestHeader._dstVmId;
	replyHeader._dstVmId      = requestHeader._srcVmId;
	replyHeader._packetNumber = requestHeader._packetNumber;
	replyHeader._operation    = REPLY_OPERATION;
	replyHeader._opcode       = requestHeader._opcode;
	replyPacket.save(&replyHeader, sizeof(replyHeader));

	uint resultCount = results.size();
	replyPacket.save(&resultCount, sizeof(resultCount));

	for(std::vector<CLiteral>::iterator result = results.begin();
		   result != results.end();
		   result++) {
 		result->saveBytecode(replyPacket);
 	}

	delete bce;
}


void CContextProvider::processFinddReply(CBinString& replyPacket, SPacketHeader& replyHeader)
{
 	CTuple* tuple = new CTuple();

	tuple->loadBytecode(replyPacket);
	_bce_list[replyHeader._dstVmId._bce]->_dataStack.push(CLiteral(tuple));
	_bce_list[replyHeader._dstVmId._bce]->_dataReady     = true;
	_bce_list[replyHeader._dstVmId._bce]->_lastSrcVmId   = replyHeader._srcVmId;
}


void CContextProvider::processListdReply(CBinString& replyPacket, SPacketHeader& replyHeader)
{
	size_t tuplesCount;

	// Unpacking tuple count
	replyPacket.load(&tuplesCount, sizeof(tuplesCount));

	// Unpacking tuples
	for(size_t tupleNumber = 0; tupleNumber < tuplesCount; tupleNumber++) {
		CTuple* tuple = new CTuple();
		tuple->loadBytecode(replyPacket);

		_bce_list[replyHeader._dstVmId._bce]->_listdReplyTable->add(itoa(_bce_list[replyHeader._dstVmId._bce]->_listdReplyTable->size()), CLiteral(tuple));
	}

	_bce_list[replyHeader._dstVmId._bce]->_dataReady     = true;
	_bce_list[replyHeader._dstVmId._bce]->_lastSrcVmId   = replyHeader._srcVmId;
}


void CContextProvider::processRunsReply(CBinString& replyPacket, SPacketHeader& replyHeader)
{
	uint resultCount;
	replyPacket.load(&resultCount, sizeof(resultCount));

	for(uint result = 0; result < resultCount; result++) {
		CLiteral lresult;
		lresult.loadBytecode(replyPacket);
		_bce_list[replyHeader._dstVmId._bce]->_dataStack.push(lresult);
	}
	_bce_list[replyHeader._dstVmId._bce]->_dataReady     = true;
	_bce_list[replyHeader._dstVmId._bce]->_lastSrcVmId   = replyHeader._srcVmId;
}


void CContextProvider::register_bce(uint bceId, CRunBytecode* bce)
{
	_bce_list[bceId] = bce;
}
