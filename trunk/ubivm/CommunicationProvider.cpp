#include "CommunicationProvider.hpp"
#include "UbivmDefs.hpp"
#include "Tools.hpp"


#include <stdlib.h>


enum { max_length = 1024 };

struct SPacketHeader {
	uint number;
	OpcodeType opcode;
	PacketOperationType operation;
};


CCommunicationProvider::CCommunicationProvider(std::map<std::string, CGroup*>* groupList, CDataStack* dataStack, uint bindPort, uint sendPort)
	: _number(0), _groupList(groupList), _dataStack(dataStack), _dataReady(false), _bindPort(bindPort), _sendPort(sendPort)
{
}


void CCommunicationProvider::run()
{
// 	boost::thread thr1( boost::bind( &CCommunicationProvider::run, this ) );
	_thread = new boost::thread( boost::bind( &CCommunicationProvider::threadedCode, this ) );
}


void CCommunicationProvider::threadedCode()
{
 	boost::asio::io_service io_service;

	udp::socket sock(io_service, udp::endpoint(boost::asio::ip::address_v4::any(), _bindPort));
	for (;;) {
		char data[max_length];
		udp::endpoint sender_endpoint;
		size_t length = sock.receive_from( boost::asio::buffer(data, max_length), sender_endpoint);
 		std::cout << "Pacote recebido na thread" << std::endl;
// 		std::cout << "Antes lock in threadedCode" << std::endl;
// 		boost::unique_lock<boost::mutex> lock(_mutex);
		processReceivedPacket(data, length, sock, sender_endpoint);
	}
}


void CCommunicationProvider::sendRequestDataquOpcode(std::string groupName, CTuple tuple)
{
	CBinString packet;
	SPacketHeader header;
	size_t size;

	_number++;
	header.number    = _number;
	header.opcode    = DATAQU_OPCODE;
	header.operation = REQUEST_OPERATION;
	packet.save(&header, sizeof(header));

	// Group name
	size = groupName.length();
	packet.save(&size, sizeof(size));
	packet.save(groupName.c_str(), size);

	// Tuple key
	size = tuple.getComposedKey().length();
	packet.save(&size, sizeof(size));
	packet.save(tuple.getComposedKey().c_str(), size);

	std::cout << "Request ainda nao foi enviado em sendRequestDataqu" << std::endl;
// 	std::cout << "antes lock mutex em sendRequestDataqu" << std::endl;
// 	boost::unique_lock<boost::mutex> lock(_mutex);
	_dataReady = false;
	sendBroadcastPacket(packet.getData().c_str(), packet.size());
	std::cout << "Request foi enviado em sendRequestDataqu" << std::endl;
	while(!_dataReady) {
// 		std::cout << "antes cond.wait em sendRequestDataqu" << std::endl;
// 		_cond.wait(lock);
// 		std::cout << "depois cond.wait em sendRequestDataqu" << std::endl;
		sleep(1);
		std::cout << "DataReady=" << _dataReady << std::endl;
 	}

// 	boost::mutex::scoped_lock lk(_mutex);
// 	_cond.wait(lk);
}

void CCommunicationProvider::sendBroadcastPacket(const char* packet, size_t length)
{

	udp::socket s(io_service, udp::endpoint(udp::v4(), 0));

	boost::asio::socket_base::broadcast option(true);
	s.set_option(option);

	udp::resolver resolver(io_service);
	udp::resolver::query query(udp::v4(), "255.255.255.255", itoa(_sendPort));
	udp::resolver::iterator iterator = resolver.resolve(query);

// 	std::cout << "Enviando pacote..." << std::endl;
	s.send_to(boost::asio::buffer(packet, length), *iterator);


	char reply[max_length];
	udp::endpoint sender_endpoint;
	size_t reply_length = s.receive_from(boost::asio::buffer(reply, max_length), sender_endpoint);
	processReceivedPacket(reply, reply_length, s, sender_endpoint);
}


void CCommunicationProvider::processReceivedPacket(const char* char_packet, size_t length, udp::socket& sock, udp::endpoint& sender_endpoint)
{
	CBinString packet;

	packet.assign(std::string(char_packet, length));
	SPacketHeader header;
	packet.load(&header, sizeof(header));

	if (header.operation == REQUEST_OPERATION) {
		processRequestOperation(packet, sock, sender_endpoint, header.number, header.opcode);
	} else if (header.operation == REPLY_OPERATION) {
		processReplyOperation(packet, sock, sender_endpoint, header.number, header.opcode);
	} else {
		std::cout << "Invalid packet operation !!!" << std::endl;
		return;
	}
}


void CCommunicationProvider::processRequestOperation(CBinString& requestPacket, udp::socket& sock, udp::endpoint& sender_endpoint, uint requestNumber, OpcodeType opcode)
{
	size_t size;
	CBinString replyPacket;
	SPacketHeader replyHeader;
	CTuple* tuple;

	std::cout << "Processando Request Operation" << std::endl;

	if (opcode == DATAQU_OPCODE) {
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

		replyHeader.number    = requestNumber;
		replyHeader.operation = REPLY_OPERATION;
		replyHeader.opcode    = opcode;
		replyPacket.save(&replyHeader, sizeof(replyHeader));

		size = tuple->getComposedKey().length();
		replyPacket.save(&size, sizeof(size));
		replyPacket.save(tuple->getComposedKey().c_str(), size);

		size = tuple->getComposedValues().length();
		replyPacket.save(&size, sizeof(size));
		replyPacket.save(tuple->getComposedValues().c_str(), size);

		std::cout << "Enviando reply packet" << std::endl;
		sock.send_to(boost::asio::buffer(replyPacket.getData(), replyPacket.size()), sender_endpoint);
	} else {
		std::cout << "Error in processPacket !!!" << std::endl;
	}
}

void CCommunicationProvider::processReplyOperation(CBinString& requestPacket, udp::socket& sock, udp::endpoint& sender_endpoint, uint requestNumber, OpcodeType opcode)
{
	size_t size;
	CBinString replyPacket;
// 	SPacketHeader replyHeader;
	char* buffer;

	std::cout << "Processando Reply Operation" << std::endl;

	if (opcode == DATAQU_OPCODE) {
// 		CTuple tuple;

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

//		tuple.addValueAtEnd(tupleValue);

		_dataStack->push(tupleValue);
// 		std::cout << "antes lock mutex em processReply" << std::endl;
// 		boost::unique_lock<boost::mutex> lock(_mutex);
// 		std::cout << "antes cond.notify em reply operation" << std::endl;
// 		{
// 			boost::lock_guard<boost::mutex> lock(_mutex);
			_dataReady=true;
			std::cout << "DataReady setado para true" << std::endl;
// 		}

//  		_cond.notify_one();
	} else {
		std::cout << "Error in processPacket !!!" << std::endl;
	}
}
