//
// C++ Implementation: GroupProvider
//
// Description:
//
//
// Author: Alex Sandro Garzão <alexgarzao@gmail.com>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "GroupProvider.hpp"
#include "CommunicationProvider.hpp"
#include "UbiVM.hpp"


void CGroupProvider::setConfig(std::map<std::string, CGroup*>* groupList)
{
	_groupList = groupList;
}


CGroupProvider::~CGroupProvider()
{
}


void CGroupProvider::sendRequestDataquOpcode(SVmId vmId, std::string groupName, CTuple tuple)
{
	CBinString    packet;
	SPacketHeader header;
	SVmId         dstVmId(0,0);

	header._srcVmId      = vmId;
	header._dstVmId      = dstVmId;
	header._packetNumber = CCommunicationProvider::getInstance()->getNextPacketNumber();
	header._opcode       = DATAQU_OPCODE;
	header._operation    = REQUEST_OPERATION;

	packet.save(&header, sizeof(header));
	packet.save(groupName);
	packet.save(tuple.getComposedKeys());

// 	std::cout << "Request ainda nao foi enviado em sendRequestDataqu" << std::endl;
// 	std::cout << "antes lock mutex em sendRequestDataqu" << std::endl;
// 	boost::unique_lock<boost::mutex> lock(_mutex);
// 	std::cout << getpid() << ": Enviando dataqu request" << std::endl;
	_bce_list[vmId._bce]->_dataReady = false;
// 	sendBroadcastPacket(packet.getData().c_str(), packet.size());
// 	std::cout << "Request foi enviado em sendRequestDataqu" << std::endl;
// 	while(!_dataReadyInDataQu) {
// 		std::cout << "antes cond.wait em sendRequestDataqu" << std::endl;
// 		_cond.wait(lock);
// 		std::cout << "depois cond.wait em sendRequestDataqu" << std::endl;
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


void CGroupProvider::sendRequestDatadquOpcode(SVmId vmId, std::string groupName, CTuple tuple)
{
	CBinString    packet;
	SPacketHeader header;
	SVmId         dstVmId(0,0);

	header._srcVmId      = vmId;
	header._dstVmId      = dstVmId;
	header._packetNumber = CCommunicationProvider::getInstance()->getNextPacketNumber();
	header._opcode       = DATAQU_OPCODE;
	header._operation    = REQUEST_OPERATION;
	packet.save(&header, sizeof(header));

	// Group name
	packet.save(groupName);

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
	header._opcode = DATADQU_OPCODE;
	dqu_packet.save(&header, sizeof(header));
	dqu_packet.save(groupName);
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


void CGroupProvider::sendRequestDatanbquOpcode(SVmId vmId, std::string groupName, CTuple tuple)
{
	CBinString    packet;
	SPacketHeader header;
	SVmId         dstVmId(0,0);

	header._srcVmId      = vmId;
	header._dstVmId      = dstVmId;
	header._packetNumber = CCommunicationProvider::getInstance()->getNextPacketNumber();
	header._opcode       = DATANBQU_OPCODE;
	header._operation    = REQUEST_OPERATION;
	packet.save(&header, sizeof(header));

	// Group name
	packet.save(groupName);

	// Tuple key
	packet.save(tuple.getComposedKeys());

// 	std::cout << "Request ainda nao foi enviado em sendRequestDataqu" << std::endl;
// 	std::cout << "antes lock mutex em sendRequestDataqu" << std::endl;
// 	boost::unique_lock<boost::mutex> lock(_mutex);
// 	std::cout << getpid() << ": Enviando dataqu request" << std::endl;
	_bce_list[vmId._bce]->_dataReady = false;
// 	sendBroadcastPacket(packet.getData().c_str(), packet.size());
// 	std::cout << "Request foi enviado em sendRequestDataqu" << std::endl;
// 	while(!_dataReadyInDataQu) {
// 		std::cout << "antes cond.wait em sendRequestDataqu" << std::endl;
// 		_cond.wait(lock);
// 		std::cout << "depois cond.wait em sendRequestDataqu" << std::endl;
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


void CGroupProvider::sendRequestDatanbdquOpcode(SVmId vmId, std::string groupName, CTuple tuple)
{
	CBinString    packet;
	SPacketHeader header;
	SVmId         dstVmId(0,0);

	header._srcVmId      = vmId;
	header._dstVmId      = dstVmId;
	header._packetNumber = CCommunicationProvider::getInstance()->getNextPacketNumber();
	header._opcode       = DATAQU_OPCODE;
	header._operation    = REQUEST_OPERATION;

	packet.save(&header, sizeof(header));
	packet.save(groupName);
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
	header._opcode = DATADQU_OPCODE;
	dqu_packet.save(&header, sizeof(header));
	dqu_packet.save(groupName);
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

void CGroupProvider::sendRequestDatalistOpcode(SVmId vmId, std::string groupName)
{
	CBinString    packet;
	SPacketHeader header;
	SVmId         dstVmId(0,0);

	header._srcVmId      = vmId;
	header._dstVmId      = dstVmId;
	header._packetNumber = CCommunicationProvider::getInstance()->getNextPacketNumber();
	header._opcode       = DATALIST_OPCODE;
	header._operation    = REQUEST_OPERATION;
	packet.save(&header, sizeof(header));

	packet.save(groupName.c_str());

// 	std::cout << "Request ainda nao foi enviado em sendRequestDatalist" << std::endl;
// 	std::cout << "antes lock mutex em sendRequestDataqu" << std::endl;
// 	boost::unique_lock<boost::mutex> lock(_mutex);
//  	std::cout << getpid() << ": Enviando datalist request" << std::endl;

	_bce_list[vmId._bce]->_dataListReplyTable = new CMultiIndex<CLiteral>();

	_bce_list[vmId._bce]->_dataReady = false;
	CCommunicationProvider::getInstance()->sendBroadcastPacket(packet.getData().c_str(), packet.size());
// 	std::cout << "Request foi enviado em sendRequestDatalist" << std::endl;
// 	while(!_dataReadyInDataList) {
// 		std::cout << "antes cond.wait em sendRequestDataqu" << std::endl;
// 		_cond.wait(lock);
// 		std::cout << "depois cond.wait em sendRequestDataqu" << std::endl;
// 		sleep(1);
// 		std::cout << "DataReady=" << _dataReady << std::endl;
// 		std::cout << "Aguardando dados depois do sendBroadcast em sendRequestDatalist" << std::endl;
//  	}
	sleep(REQUEST_TIMEOUT);

// 	std::cout << "_dataListReplyTable" << _dataListReplyTable->size() << std::endl;
// 	_dataStack->push(CLiteral(_dataListReplyTable));
	_bce_list[vmId._bce]->_dataStack.push(CLiteral(_bce_list[vmId._bce]->_dataListReplyTable));


// 	boost::mutex::scoped_lock lk(_mutex);
// 	_cond.wait(lk);
}


void CGroupProvider::sendRequestScallOpcode(SVmId vmId, std::string groupName, std::string serviceName)
{
	CBinString    packet;
	SPacketHeader header;
	SVmId         dstVmId(0,0);

	header._srcVmId      = vmId;
	header._dstVmId      = dstVmId;
	header._packetNumber = CCommunicationProvider::getInstance()->getNextPacketNumber();
	header._opcode       = SCALL_OPCODE;
	header._operation    = REQUEST_OPERATION;

	packet.save(&header, sizeof(header));
	packet.save(groupName);
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


void CGroupProvider::processDataquRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket)
{
	SPacketHeader replyHeader;
	CTuple*       tuple;

	std::string groupName;
	requestPacket.load(groupName);

	std::string tupleKey;
	requestPacket.load(tupleKey);

	CTuple tupleToFind;
	tupleToFind.addKeyAtEnd(tupleKey);
	tuple = (*_groupList)[groupName]->getTuple(&tupleToFind);

	if (tuple == NULL) {
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

// 		std::cout << "Enviando reply packet" << std::endl;
// 		sock.send_to(boost::asio::buffer(replyPacket.getData(), replyPacket.size()), sender_endpoint);
// 		std::cout << getpid() << ": Enviando dataqu reply" << std::endl;
}


void CGroupProvider::processDatanbquRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket)
{
	processDataquRequest(requestPacket, requestHeader, replyPacket);
}


void CGroupProvider::processDatadquRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket)
{
	SPacketHeader replyHeader;
	CTuple*       tuple;

	std::string groupName;
	requestPacket.load(groupName);

	std::string tupleKey;
	requestPacket.load(tupleKey);

	CTuple tupleToFind;
	tupleToFind.addKeyAtEnd(tupleKey);
	tuple = (*_groupList)[groupName]->getTuple(&tupleToFind);

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

	(*_groupList)[groupName]->remTuple(&tupleToFind);
// 	std::cout << __FUNCTION__ << ": tupla " << tupleKey << " removida !!!" << std::endl;
}


void CGroupProvider::processDatanbdquRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket)
{
	processDatadquRequest(requestPacket, requestHeader, replyPacket);
}


void CGroupProvider::processDatalistRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket)
{
	size_t size;
	SPacketHeader replyHeader;
// 	CTuple* tuple;

// 	std::cout << "Processando Datalist Request" << std::endl;

	std::string groupName;
	requestPacket.load(groupName);

	// Verify if group exist...
	if (_groupList->find(groupName) == _groupList->end()) {
		return;
	}

	if ((*_groupList)[groupName]->_dataList.size() == 0) {
		return;
	}

	// -- Packing reply --

	// Packing header
	replyHeader._dstVmId      = requestHeader._srcVmId;
	replyHeader._srcVmId      = requestHeader._dstVmId;
	replyHeader._packetNumber = requestHeader._packetNumber;
	replyHeader._operation    = REPLY_OPERATION;
	replyHeader._opcode       = DATALIST_OPCODE;
	replyPacket.save(&replyHeader, sizeof(replyHeader));

	// Packing tuple count
	size = (*_groupList)[groupName]->_dataList.size();
	replyPacket.save(&size, sizeof(size));

	// Packing tuples
	for(std::map<std::string, CTuple*>::iterator data = (*_groupList)[groupName]->_dataList.begin();
			data != (*_groupList)[groupName]->_dataList.end(); data++) {

		CTuple* tuple = (*data).second;

		// Packing keys count
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
		}
	}

// 	std::cout << "Enviando datalist reply packet" << std::endl;
// 	sock.send_to(boost::asio::buffer(replyPacket.getData(), replyPacket.size()), sender_endpoint);
// 	std::cout << getpid() << ": Enviando datalist reply" << std::endl;
}


void CGroupProvider::processScallRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket)
{
	SPacketHeader replyHeader;

	std::string groupName;
	requestPacket.load(groupName);

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

	if (bce->scallCode(groupName, serviceName, arguments, results) == false) {
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


void CGroupProvider::processDataquReply(CBinString& replyPacket, SPacketHeader& replyHeader)//, udp::endpoint& sender_endpoint)
{
 	CTuple* tuple = new CTuple();

	std::string tupleKey;
	std::string tupleValue;

	replyPacket.load(tupleKey);
	replyPacket.load(tupleValue);

	tuple->addKeyAtEnd(tupleKey);
	tuple->addValueAtEnd(tupleValue);

// 		std::cout << "Current VMID: " << getpid() << std::endl;

// 		std::cout << __FUNCTION__ << ": VMID: " << requestHeader._vmId << " DATAQU reply recebido: tuplekey=" << tupleKey << " tupleValue=" << tupleValue << std::endl;

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


void CGroupProvider::processDatalistReply(CBinString& replyPacket, SPacketHeader& replyHeader)
{
	size_t tuplesCount;

// 	std::cout << "Processando DataList Reply" << std::endl;

	// Unpacking tuple count
	replyPacket.load(&tuplesCount, sizeof(tuplesCount));

	// Unpacking tuples
	for(size_t tupleNumber = 0; tupleNumber < tuplesCount; tupleNumber++) {
		CTuple* tuple = new CTuple();
		size_t keysCount;
		size_t valuesCount;

		// Unpacking keys count
		replyPacket.load(&keysCount, sizeof(keysCount));

		// Unpacking keys
		for(size_t keyNumber = 0; keyNumber < keysCount; keyNumber++) {
			std::string key;
			replyPacket.load(key);
			tuple->addKeyAtEnd(key);
		}

		// Unpacking values count
		replyPacket.load(&valuesCount, sizeof(valuesCount));

		// Unpacking values
		for(size_t valueNumber = 0; valueNumber < valuesCount; valueNumber++) {
			std::string value;
			replyPacket.load(value);
			tuple->addValueAtEnd(value);
		}

		_bce_list[replyHeader._dstVmId._bce]->_dataListReplyTable->add(itoa(_bce_list[replyHeader._dstVmId._bce]->_dataListReplyTable->size()), CLiteral(tuple));
	}

	_bce_list[replyHeader._dstVmId._bce]->_dataReady     = true;
// 	_bce_list[replyHeader._dstVmId._bce]->_last_endpoint = sender_endpoint;
	_bce_list[replyHeader._dstVmId._bce]->_lastSrcVmId   = replyHeader._srcVmId;

// 	std::cout << "DataReady setado para true em DataList reply" << std::endl;
}


void CGroupProvider::processScallReply(CBinString& replyPacket, SPacketHeader& replyHeader)
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


void CGroupProvider::register_bce(uint bceId, CRunBytecode* bce)
{
	_bce_list[bceId] = bce;
// 	std::cout << "Registrado BCE com id " << bceId << std::endl;
}
