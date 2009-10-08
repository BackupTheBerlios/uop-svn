#include "CommunicationProvider.hpp"



#include <stdlib.h>


enum { max_length = 1024 };

static const uint REQUEST_TIMEOUT = 1;


CCommunicationProvider::CCommunicationProvider(std::map<std::string, CGroup*>* groupList, CDataStack* dataStack, uint bindPort, uint sendPort)
	: _packetNumber(0), _groupList(groupList), _dataStack(dataStack), _dataReadyInDataList(false), _dataReadyInDataQu(false), _bindPort(bindPort), _sendPort(sendPort), _dataListReplyTable(NULL)
{
}


void CCommunicationProvider::run()
{
// 	boost::thread thr1( boost::bind( &CCommunicationProvider::run, this ) );
	_thread = new boost::thread( boost::bind( &CCommunicationProvider::threadedCode, this));
}


std::string CCommunicationProvider::dumpPacket(const char* char_packet, uint length)
{
	CBinString packet;

	packet.assign(std::string(char_packet, length));
	SPacketHeader header;
	packet.load(&header, sizeof(header));

	std::string result;

	result += "VmID: ";
	result += itoa(header._vmId);
	result += " Number: ";
	result += itoa(header._packetNumber);
	result += " Opcode: ";
	result += itoa(header._opcode);
	result += " Operation: ";
	result += itoa(header._operation);

	return result;
}


void CCommunicationProvider::threadedCode()
{
// 	udp::socket sock(io_service, udp::endpoint(boost::asio::ip::address_v4::any(), _bindPort));

	boost::asio::ip::udp::socket sock(_io_service);
	boost::asio::ip::udp::endpoint listen_endpoint(boost::asio::ip::address_v4::any(), _bindPort);
	sock.open(listen_endpoint.protocol());
	sock.set_option(boost::asio::ip::udp::socket::reuse_address(true));
	sock.bind(listen_endpoint);


	for (;;) {
		char data[max_length];
		udp::endpoint sender_endpoint;
		size_t length = sock.receive_from(boost::asio::buffer(data, max_length), sender_endpoint);
		processReceivedPacket(data, length, sock, sender_endpoint);
	}
}


void CCommunicationProvider::sendBroadcastPacket(const char* packet, size_t length)
{
	udp::socket s(_io_service, udp::endpoint(udp::v4(), 0));

	boost::asio::socket_base::broadcast option(true);
	s.set_option(option);

	udp::resolver resolver(_io_service);
	udp::resolver::query query(udp::v4(), "255.255.255.255", itoa(_sendPort));
	udp::resolver::iterator iterator = resolver.resolve(query);

// 	std::cout << "Enviando pacote..." << std::endl;
	s.send_to(boost::asio::buffer(packet, length), *iterator);

// 	std::cout << getpid() << ": TX [" << dumpPacket(packet, length) << "]" << std::endl;

// 	udp::endpoint sender_endpointXXX;

// 	processReceivedPacket(packet, length, s, sender_endpointXXX); // Forca o bradcast a ser processado
	
	return;
	
/*	// Put the socket into non-blocking mode.
	udp::socket::non_blocking_io non_blocking_io(true);
	s.io_control(non_blocking_io);

	char reply[max_length];
	udp::endpoint sender_endpoint;
	size_t retries = 1;
 	while(retries <= 5) {
		size_t reply_length;
		try {
			reply_length = s.receive_from(boost::asio::buffer(reply, max_length), sender_endpoint);
		} catch (std::exception& e)
		{
			reply_length = 0;
		}

		if (reply_length > 0) {
			processReceivedPacket(reply, reply_length, s, sender_endpoint);
			retries = 1;
		} else {
			retries++;
			sleep(1);
		}
 	}*/
}


void CCommunicationProvider::sendRequestDataquOpcode(std::string groupName, CTuple tuple)
{
	CBinString packet;
	SPacketHeader header;
	size_t size;

	_packetNumber++;
	header._packetNumber = _packetNumber;
	header._opcode       = DATAQU_OPCODE;
	header._operation    = REQUEST_OPERATION;
	packet.save(&header, sizeof(header));

	// Group name
	size = groupName.length();
	packet.save(&size, sizeof(size));
	packet.save(groupName.c_str(), size);

	// Tuple key
	size = tuple.getComposedKeys().length();
	packet.save(&size, sizeof(size));
	packet.save(tuple.getComposedKeys().c_str(), size);

// 	std::cout << "Request ainda nao foi enviado em sendRequestDataqu" << std::endl;
// 	std::cout << "antes lock mutex em sendRequestDataqu" << std::endl;
// 	boost::unique_lock<boost::mutex> lock(_mutex);
// 	std::cout << getpid() << ": Enviando dataqu request" << std::endl;
	_dataReadyInDataQu = false;
	sendBroadcastPacket(packet.getData().c_str(), packet.size());
// 	std::cout << "Request foi enviado em sendRequestDataqu" << std::endl;
// 	while(!_dataReadyInDataQu) {
// 		std::cout << "antes cond.wait em sendRequestDataqu" << std::endl;
// 		_cond.wait(lock);
// 		std::cout << "depois cond.wait em sendRequestDataqu" << std::endl;
// 		sleep(1);
// 		std::cout << "DataReady=" << _dataReady << std::endl;
//  	}
	sleep(REQUEST_TIMEOUT);

// 	boost::mutex::scoped_lock lk(_mutex);
// 	_cond.wait(lk);
}


void CCommunicationProvider::sendRequestDatalistOpcode(std::string groupName)
{
	CBinString packet;
	SPacketHeader header;
	size_t size;

	_packetNumber++;
	header._packetNumber = _packetNumber;
	header._opcode       = DATALIST_OPCODE;
	header._operation    = REQUEST_OPERATION;
	packet.save(&header, sizeof(header));

	// Group name
	size = groupName.length();
	packet.save(&size, sizeof(size));
	packet.save(groupName.c_str(), size);

// 	std::cout << "Request ainda nao foi enviado em sendRequestDatalist" << std::endl;
// 	std::cout << "antes lock mutex em sendRequestDataqu" << std::endl;
// 	boost::unique_lock<boost::mutex> lock(_mutex);
//  	std::cout << getpid() << ": Enviando datalist request" << std::endl;

	_dataListReplyTable = new CMultiIndex<CLiteral>();

	_dataReadyInDataList = false;
	sendBroadcastPacket(packet.getData().c_str(), packet.size());
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
	_dataStack->push(CLiteral(_dataListReplyTable));

	
// 	boost::mutex::scoped_lock lk(_mutex);
// 	_cond.wait(lk);
}




void CCommunicationProvider::processReceivedPacket(const char* char_packet, size_t length, udp::socket& sock, udp::endpoint& sender_endpoint)
{
	CBinString packet;

	packet.assign(std::string(char_packet, length));
	SPacketHeader header;
	packet.load(&header, sizeof(header));

// 	std::cout << getpid() << ": RX [" << dumpPacket(char_packet, length) << "]" << std::endl;

	if (header._operation == REQUEST_OPERATION) {
		processRequestOperation(packet, sock, sender_endpoint, header);
	} else if (header._operation == REPLY_OPERATION) {
		if (header._vmId != getpid()) {
			return;
		}

		processReplyOperation(packet, sock, sender_endpoint, header);
	} else {
		std::cout << "Invalid packet operation !!!" << std::endl;
		return;
	}
}


void CCommunicationProvider::processRequestOperation(CBinString& requestPacket, udp::socket& sock, udp::endpoint& sender_endpoint, SPacketHeader& requestHeader)
{
	size_t size;
	CBinString replyPacket;
	SPacketHeader replyHeader;
	CTuple* tuple;

// 	std::cout << "Processando Request Operation" << std::endl;

	if (requestHeader._opcode == DATAQU_OPCODE) {
		// Group name
		requestPacket.load(&size, sizeof(size));
		char* buffer = new char[size];
		requestPacket.load(buffer, size);
		std::string groupName(buffer, size);
		delete []buffer;

		// Tuple key
		requestPacket.load(&size, sizeof(size));
		buffer = new char[size];
		requestPacket.load(buffer, size);
		std::string tupleKey(buffer, size);
		delete []buffer;

		CTuple tupleToFind;
		tupleToFind.addKeyAtEnd(tupleKey);
		tuple = (*_groupList)[groupName]->getTuple(&tupleToFind);

		if (tuple == NULL) {
			return;
		}

		replyHeader._vmId         = requestHeader._vmId;
		replyHeader._packetNumber = requestHeader._packetNumber;
		replyHeader._operation    = REPLY_OPERATION;
		replyHeader._opcode       = requestHeader._opcode;
		replyPacket.save(&replyHeader, sizeof(replyHeader));

		size = tuple->getComposedKeys().length();
		replyPacket.save(&size, sizeof(size));
		replyPacket.save(tuple->getComposedKeys().c_str(), size);

		size = tuple->getComposedValues().length();
		replyPacket.save(&size, sizeof(size));
		replyPacket.save(tuple->getComposedValues().c_str(), size);

// 		std::cout << "Enviando reply packet" << std::endl;
// 		sock.send_to(boost::asio::buffer(replyPacket.getData(), replyPacket.size()), sender_endpoint);
// 		std::cout << getpid() << ": Enviando dataqu reply" << std::endl;
		sendBroadcastPacket(replyPacket.getData().c_str(), replyPacket.size());
	} else if (requestHeader._opcode == DATALIST_OPCODE) {
		processDatalistRequest(requestPacket, sock, sender_endpoint, requestHeader);
	} else {
		std::cout << "Error in processPacket !!!" << std::endl;
	}
}


void CCommunicationProvider::processDatalistRequest(CBinString& requestPacket, udp::socket& sock, udp::endpoint& sender_endpoint, SPacketHeader& requestHeader)
{
	size_t size;
	CBinString replyPacket;
	SPacketHeader replyHeader;
// 	CTuple* tuple;

// 	std::cout << "Processando Datalist Request" << std::endl;

	// Group name
	requestPacket.load(&size, sizeof(size));
	char* buffer = new char[size];
	requestPacket.load(buffer, size);
	std::string groupName(buffer, size);
	delete []buffer;

	// Verify if group exist...
	if (_groupList->find(groupName) == _groupList->end()) {
		return;
	}

	// -- Packing reply --

	// Packing header
	replyHeader._vmId         = requestHeader._vmId;
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
			size = tuple->_keyList[key].getText().length();
			replyPacket.save(&size, sizeof(size));
			replyPacket.save(tuple->_keyList[key].getText().c_str(), size);
		}

		// Packing values count
		size = tuple->_valueList.size();
		replyPacket.save(&size, sizeof(size));

		// Packing values
		for(size_t value = 0; value < tuple->_valueList.size(); value++) {
			size = tuple->_valueList[value].getText().length();
			replyPacket.save(&size, sizeof(size));
			replyPacket.save(tuple->_valueList[value].getText().c_str(), size);
		}
	}

// 	std::cout << "Enviando datalist reply packet" << std::endl;
// 	sock.send_to(boost::asio::buffer(replyPacket.getData(), replyPacket.size()), sender_endpoint);
// 	std::cout << getpid() << ": Enviando datalist reply" << std::endl;
	sendBroadcastPacket(replyPacket.getData().c_str(), replyPacket.size());
}


void CCommunicationProvider::processReplyOperation(CBinString& requestPacket, udp::socket& sock, udp::endpoint& sender_endpoint, SPacketHeader& requestHeader)
{
	size_t size;
	CBinString replyPacket;
// 	SPacketHeader replyHeader;
	char* buffer;

// 	std::cout << "Processando Reply Operation" << std::endl;

	if (requestHeader._opcode == DATAQU_OPCODE) {
		CTuple* tuple = new CTuple();

		// Tuple key
		requestPacket.load(&size, sizeof(size));
		buffer = new char[size];
		requestPacket.load(buffer, size);
		std::string tupleKey(buffer, size);
		delete []buffer;

		// Tuple value
		requestPacket.load(&size, sizeof(size));
		buffer = new char[size];
		requestPacket.load(buffer, size);
		std::string tupleValue(buffer, size);
		delete []buffer;

		tuple->addKeyAtEnd(tupleKey);
		tuple->addValueAtEnd(tupleValue);

		_dataStack->push(CLiteral(tuple));

// 		_dataStack->push(tupleValue);
// 		std::cout << "antes lock mutex em processReply" << std::endl;
// 		boost::unique_lock<boost::mutex> lock(_mutex);
// 		std::cout << "antes cond.notify em reply operation" << std::endl;
// 		{
// 			boost::lock_guard<boost::mutex> lock(_mutex);
			_dataReadyInDataQu=true;
// 			std::cout << "DataReady setado para true" << std::endl;
// 		}

//  		_cond.notify_one();
	} else if (requestHeader._opcode == DATALIST_OPCODE) {
		processDatalistReply(requestPacket, sock, sender_endpoint, requestHeader);
	} else {
		std::cout << "Error in processPacket !!!" << std::endl;
	}
}


void CCommunicationProvider::processDatalistReply(CBinString& replyPacket, udp::socket& sock, udp::endpoint& sender_endpoint, SPacketHeader& requestHeader)
{
	size_t tuplesCount;
// 	CBinString replyPacket;
// 	char* buffer;

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

		_dataListReplyTable->add(itoa(_dataListReplyTable->size()), CLiteral(tuple));
	}

	_dataReadyInDataList=true;
// 	std::cout << "DataReady setado para true em DataList reply" << std::endl;
}
