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
	header._opcode       = PUBLISHD_OPCODE;
	header._operation    = REQUEST_OPERATION;

	packet.save(&header, sizeof(header));
	packet.save(contextName);
	packet.save(tuple.getComposedKeys());
	packet.save(tuple.getComposedValues());

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
	header._opcode       = FINDD_OPCODE;
	header._operation    = REQUEST_OPERATION;

	packet.save(&header, sizeof(header));
	packet.save(contextName);
	packet.save(tuple.getComposedKeys());

// 	std::cout << "Request ainda nao foi enviado em sendRequestFindd" << std::endl;
// 	std::cout << "antes lock mutex em sendRequestFindd" << std::endl;
// 	boost::unique_lock<boost::mutex> lock(_mutex);
// 	std::cout << getpid() << ": Enviando findd request" << std::endl;
	_bce_list[vmId._bce]->_dataReady = false;
// 	sendBroadcastPacket(packet.getData().c_str(), packet.size());
// 	std::cout << "Request foi enviado em sendRequestFindd" << std::endl;
// 	while(!_dataReadyInFindd) {
// 		std::cout << "antes cond.wait em sendRequestFindd" << std::endl;
// 		_cond.wait(lock);
// 		std::cout << "depois cond.wait em sendRequestFindd" << std::endl;
// 		sleep(1);
// 		std::cout << "DataReady=" << _dataReady << std::endl;
//  	}
// 	sleep(REQUEST_TIMEOUT);

// 	boost::mutex::scoped_lock lk(_mutex);
// 	_cond.wait(lk);
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
	header._opcode       = FINDD_OPCODE;
	header._operation    = REQUEST_OPERATION;
	packet.save(&header, sizeof(header));

	// Context name
	packet.save(contextName);

	// Tuple key
	packet.save(tuple.getComposedKeys());

	_bce_list[vmId._bce]->_dataReady = false;

	while( _bce_list[vmId._bce]->_dataReady == false) {
		CCommunicationProvider::getInstance()->sendBroadcastPacket(packet.getData().c_str(), packet.size());
		sleep(REQUEST_TIMEOUT);
	}

	// Envia um DQU unicast
	CBinString dqu_packet;
	header._dstVmId = _bce_list[vmId._bce]->_lastSrcVmId; // TODO: como descobrir a VM correta ???;
	header._opcode = GETD_OPCODE;
	dqu_packet.save(&header, sizeof(header));
	dqu_packet.save(contextName);
	dqu_packet.save(tuple.getComposedKeys());

	_bce_list[vmId._bce]->_dataReady = false;

	while(_bce_list[vmId._bce]->_dataReady == false) {
// 		std::cout << getpid() << ": vou envia unicast reply" << std::endl;
// 		std::cout << "last_endpoint=" << _bce_list[vmId._bce]->_last_endpoint << std::endl;
// 		CCommunicationProvider::getInstance()->sendUnicastReply(dqu_packet.getData().c_str(), dqu_packet.size(), _bce_list[vmId._bce]->_last_endpoint);
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
	header._opcode       = FINDDNB_OPCODE;
	header._operation    = REQUEST_OPERATION;
	packet.save(&header, sizeof(header));

	// Context name
	packet.save(contextName);

	// Tuple key
	packet.save(tuple.getComposedKeys());

// 	std::cout << "Request ainda nao foi enviado em sendRequestFindd" << std::endl;
// 	std::cout << "antes lock mutex em sendRequestFindd" << std::endl;
// 	boost::unique_lock<boost::mutex> lock(_mutex);
// 	std::cout << getpid() << ": Enviando findd request" << std::endl;
	_bce_list[vmId._bce]->_dataReady = false;
// 	sendBroadcastPacket(packet.getData().c_str(), packet.size());
// 	std::cout << "Request foi enviado em sendRequestFindd" << std::endl;
// 	while(!_dataReadyInFindd) {
// 		std::cout << "antes cond.wait em sendRequestFindd" << std::endl;
// 		_cond.wait(lock);
// 		std::cout << "depois cond.wait em sendRequestFindd" << std::endl;
// 		sleep(1);
// 		std::cout << "DataReady=" << _dataReady << std::endl;
//  	}
// 	sleep(REQUEST_TIMEOUT);

// 	boost::mutex::scoped_lock lk(_mutex);
// 	_cond.wait(lk);

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
	header._opcode       = FINDD_OPCODE;
	header._operation    = REQUEST_OPERATION;

	packet.save(&header, sizeof(header));
	packet.save(contextName);
	packet.save(tuple.getComposedKeys());

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
	header._opcode = GETD_OPCODE;
	dqu_packet.save(&header, sizeof(header));
	dqu_packet.save(contextName);
	dqu_packet.save(tuple.getComposedKeys());

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
	header._opcode       = LISTD_OPCODE;
	header._operation    = REQUEST_OPERATION;
	packet.save(&header, sizeof(header));

	packet.save(contextName.c_str());

// 	std::cout << "Request ainda nao foi enviado em sendRequestListd" << std::endl;
// 	std::cout << "antes lock mutex em sendRequestFindd" << std::endl;
// 	boost::unique_lock<boost::mutex> lock(_mutex);
//  	std::cout << getpid() << ": Enviando listd request" << std::endl;

	_bce_list[vmId._bce]->_listdReplyTable = new CMultiIndex<CLiteral>();

	_bce_list[vmId._bce]->_dataReady = false;
	CCommunicationProvider::getInstance()->sendBroadcastPacket(packet.getData().c_str(), packet.size());
// 	std::cout << "Request foi enviado em sendRequestListd" << std::endl;
// 	while(!_dataReadyInListd) {
// 		std::cout << "antes cond.wait em sendRequestFindd" << std::endl;
// 		_cond.wait(lock);
// 		std::cout << "depois cond.wait em sendRequestFindd" << std::endl;
// 		sleep(1);
// 		std::cout << "DataReady=" << _dataReady << std::endl;
// 		std::cout << "Aguardando dados depois do sendBroadcast em sendRequestListd" << std::endl;
//  	}
	sleep(REQUEST_TIMEOUT);

// 	std::cout << "_listdReplyTable" << _listdReplyTable->size() << std::endl;
// 	_dataStack->push(CLiteral(_listdReplyTable));
	_bce_list[vmId._bce]->_dataStack.push(CLiteral(_bce_list[vmId._bce]->_listdReplyTable));


// 	boost::mutex::scoped_lock lk(_mutex);
// 	_cond.wait(lk);
}


void CContextProvider::sendRequestPublishsOpcode(SVmId vmId, std::string contextName, std::string serviceName)
{
	CBinString    packet;
	SPacketHeader header;
	SVmId         dstVmId(0,0);

	header._srcVmId      = vmId;
	header._dstVmId      = dstVmId;
	header._packetNumber = CCommunicationProvider::getInstance()->getNextPacketNumber();
	header._opcode       = PUBLISHS_OPCODE;
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
	header._opcode       = REMOVES_OPCODE;
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
	header._opcode       = RUNS_OPCODE;
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

// 	for(uint arg=0; arg < argsNumber; arg++) {
// 		// TODO: nao to mandando na ordem inversa ???
// 		std::string sarg = _bce_list[vmId._bce]->_dataStack.pop().getText();
// 		// TODO: os argumentos estao sendo convertidos para texto... isso nao eh o certo...
// 		packet.save(sarg);
// 	}

	_bce_list[vmId._bce]->_dataReady = false;
// 	std::cout << getpid() << ":dataReady de " << vmId._bce << "setado para false" << std::endl;

	while( _bce_list[vmId._bce]->_dataReady == false) {
		CCommunicationProvider::getInstance()->sendBroadcastPacket(packet.getData().c_str(), packet.size());
		sleep(REQUEST_TIMEOUT);
	}
}


void CContextProvider::processPublishdRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket)
{
// 	SPacketHeader replyHeader;
// 	CTuple*       tuple;

	std::string contextName;
	requestPacket.load(contextName);

	std::string tupleKeys;
	requestPacket.load(tupleKeys);

	std::string tupleValues;
	requestPacket.load(tupleValues);

	if (_contextList->find(contextName) != _contextList->end()) {
		(*_contextList)[contextName]->run_insert_data_event(tupleKeys, tupleValues);
	}
}


void CContextProvider::processFinddRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket)
{
	SPacketHeader replyHeader;
	CTuple*       tuple;

	std::string contextName;
	requestPacket.load(contextName);

	std::string tupleKey;
	requestPacket.load(tupleKey);

	CTuple tupleToFind;
	tupleToFind.addKeyAtEnd(tupleKey);
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

	// asdfg
	replyPacket.save(tuple->getComposedKeys());
	replyPacket.save(tuple->getComposedValues());

// 		std::cout << "Enviando reply packet" << std::endl;
// 		sock.send_to(boost::asio::buffer(replyPacket.getData(), replyPacket.size()), sender_endpoint);
// 		std::cout << getpid() << ": Enviando Findd reply" << std::endl;
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

	std::string tupleKey;
	requestPacket.load(tupleKey);

	CTuple tupleToFind;
	tupleToFind.addKeyAtEnd(tupleKey);
	tuple = (*_contextList)[contextName]->getTuple(&tupleToFind);

	if (tuple == NULL) {
// 		std::cout << __FUNCTION__ << ": tupla " << tupleKey << " nao encontrada !!!" << std::endl;
		return;
	}

	replyHeader._srcVmId      = requestHeader._dstVmId;
	replyHeader._dstVmId      = requestHeader._srcVmId;
	replyHeader._packetNumber = requestHeader._packetNumber;
	replyHeader._operation    = REPLY_OPERATION;
	replyHeader._opcode       = requestHeader._opcode;
	replyPacket.save(&replyHeader, sizeof(replyHeader));

	replyPacket.save(tuple->getComposedKeys());
	replyPacket.save(tuple->getComposedValues());

	(*_contextList)[contextName]->remTuple(&tupleToFind);
//  	std::cout << __FUNCTION__ << ": tupla " << tupleKey << " removida !!!" << std::endl;

	if (_contextList->find(contextName) != _contextList->end()) {
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
// 	CTuple* tuple;

// 	std::cout << "Processando Listd Request" << std::endl;

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
	replyHeader._opcode       = LISTD_OPCODE;
	replyPacket.save(&replyHeader, sizeof(replyHeader));

	// Packing tuple count
	size = (*_contextList)[contextName]->_listd.size();
	replyPacket.save(&size, sizeof(size));

	// Packing tuples
	for(std::map<std::string, CTuple*>::iterator data = (*_contextList)[contextName]->_listd.begin();
			data != (*_contextList)[contextName]->_listd.end(); data++) {

		CTuple* tuple = (*data).second;
		tuple->saveBytecode(replyPacket);

/*		// Packing keys count
		size = tuple->_keyList.size();
		replyPacket.save(&size, sizeof(size));

		// Packing keys
		for(size_t key = 0; key < tuple->_keyList.size(); key++) {
			replyPacket.save(tuple->_keyList[key].getText());
		}

		// Packing values count
		size = tuple->_valueList.size();
		replyPacket.save(&size, sizeof(size));

		// Packing values
		for(size_t value = 0; value < tuple->_valueList.size(); value++) {
			replyPacket.save(tuple->_valueList[value].getText());
		}*/
	}

// 	std::cout << "Enviando listd reply packet" << std::endl;
// 	sock.send_to(boost::asio::buffer(replyPacket.getData(), replyPacket.size()), sender_endpoint);
// 	std::cout << getpid() << ": Enviando listd reply" << std::endl;
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


void CContextProvider::processFinddReply(CBinString& replyPacket, SPacketHeader& replyHeader)//, udp::endpoint& sender_endpoint)
{
 	CTuple* tuple = new CTuple();

	std::string tupleKey;
	std::string tupleValue;

	replyPacket.load(tupleKey);
	replyPacket.load(tupleValue);

	// asdfg
	tuple->addKeyAtEnd(tupleKey);
	tuple->addValueAtEnd(tupleValue);

// 		std::cout << "Current VMID: " << getpid() << std::endl;

// 		std::cout << __FUNCTION__ << ": VMID: " << requestHeader._vmId << " FINDD reply recebido: tuplekey=" << tupleKey << " tupleValue=" << tupleValue << std::endl;

// 		_bce_list[1]->_dataStack.push(CLiteral(tuple));
	_bce_list[replyHeader._dstVmId._bce]->_dataStack.push(CLiteral(tuple));
// 		_dataStack->push(CLiteral(tuple));

// 		_dataStack->push(tupleValue);
// 		std::cout << "antes lock mutex em processReply" << std::endl;
// 		boost::unique_lock<boost::mutex> lock(_mutex);
// 		std::cout << "antes cond.notify em reply operation" << std::endl;
// 		{
// 			boost::lock_guard<boost::mutex> lock(_mutex);
	_bce_list[replyHeader._dstVmId._bce]->_dataReady     = true;
// 	_bce_list[replyHeader._dstVmId._bce]->_last_endpoint = sender_endpoint;
	_bce_list[replyHeader._dstVmId._bce]->_lastSrcVmId   = replyHeader._srcVmId;
// 	std::cout << "last_endpoint=" << sender_endpoint << std::endl;
// 			std::cout << "DataReady setado para true" << std::endl;
// 		}

//  		_cond.notify_one();
}


void CContextProvider::processListdReply(CBinString& replyPacket, SPacketHeader& replyHeader)
{
	size_t tuplesCount;

// 	std::cout << "Processando Listd Reply" << std::endl;

	// Unpacking tuple count
	replyPacket.load(&tuplesCount, sizeof(tuplesCount));

	// Unpacking tuples
	for(size_t tupleNumber = 0; tupleNumber < tuplesCount; tupleNumber++) {
		CTuple* tuple = new CTuple();
		tuple->loadBytecode(replyPacket);
// 		size_t keysCount;
// 		size_t valuesCount;
//
// 		// Unpacking keys count
// 		replyPacket.load(&keysCount, sizeof(keysCount));
//
// 		// Unpacking keys
// 		for(size_t keyNumber = 0; keyNumber < keysCount; keyNumber++) {
// 			std::string key;
// 			replyPacket.load(key);
// 			tuple->addKeyAtEnd(key);
// 		}
//
// 		// Unpacking values count
// 		replyPacket.load(&valuesCount, sizeof(valuesCount));
//
// 		// Unpacking values
// 		for(size_t valueNumber = 0; valueNumber < valuesCount; valueNumber++) {
// 			std::string value;
// 			replyPacket.load(value);
// 			tuple->addValueAtEnd(value);
// 		}

		_bce_list[replyHeader._dstVmId._bce]->_listdReplyTable->add(itoa(_bce_list[replyHeader._dstVmId._bce]->_listdReplyTable->size()), CLiteral(tuple));
	}

	_bce_list[replyHeader._dstVmId._bce]->_dataReady     = true;
// 	_bce_list[replyHeader._dstVmId._bce]->_last_endpoint = sender_endpoint;
	_bce_list[replyHeader._dstVmId._bce]->_lastSrcVmId   = replyHeader._srcVmId;

// 	std::cout << "DataReady setado para true em Listd reply" << std::endl;
}


void CContextProvider::processRunsReply(CBinString& replyPacket, SPacketHeader& replyHeader)
{
	uint resultCount;
	replyPacket.load(&resultCount, sizeof(resultCount));

	for(uint result = 0; result < resultCount; result++) {
		CLiteral lresult;
		lresult.loadBytecode(replyPacket);
		_bce_list[replyHeader._dstVmId._bce]->_dataStack.push(lresult);
// 		std::cout << "result=" << lresult.getText() << std::endl;
	}
	_bce_list[replyHeader._dstVmId._bce]->_dataReady     = true;
// 	_bce_list[replyHeader._dstVmId._bce]->_last_endpoint = sender_endpoint;
	_bce_list[replyHeader._dstVmId._bce]->_lastSrcVmId   = replyHeader._srcVmId;
// 	std::cout << getpid() << ":dataReady de " << replyHeader._dstVmId._bce << "setado para true" << std::endl;
}


void CContextProvider::register_bce(uint bceId, CRunBytecode* bce)
{
	_bce_list[bceId] = bce;
// 	std::cout << "Registrado BCE com id " << bceId << std::endl;
}
