#include "CommunicationProvider.hpp"
#include "GroupProvider.hpp"

#include <stdlib.h>

enum { max_length = 1024 };




void CCommunicationProvider::setConfig(std::map<std::string, CGroup*>* groupList, uint bindPort, uint sendPort)
{
	_packetNumber = 0;
	_bindPort = bindPort;
	_sendPort = sendPort;


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

	result += "SrcVmID[pid=";
	result += itoa(header._srcVmId._pid);
	result += ",bceid=";
	result += itoa(header._srcVmId._bce);
	result += "] ";
	result += "DstVmID[pid=";
	result += itoa(header._dstVmId._pid);
	result += ",bceid=";
	result += itoa(header._dstVmId._bce);
	result += "] ";
	result += "Number: ";
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
	boost::asio::ip::udp::socket socket(_io_service);

	boost::asio::ip::udp::endpoint listen_endpoint(boost::asio::ip::address_v4::any(), _bindPort);
	socket.open(listen_endpoint.protocol());
	socket.set_option(boost::asio::ip::udp::socket::reuse_address(true));
	socket.bind(listen_endpoint);

	for (;;) {
		char data[max_length];
		udp::endpoint sender_endpoint;
		size_t length = socket.receive_from(boost::asio::buffer(data, max_length), sender_endpoint);
		processReceivedPacket(data, length, socket, sender_endpoint);
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


void CCommunicationProvider::sendUnicastReply(const char* packet, size_t length, udp::endpoint& endpoint)
{
// 	udp::socket s(_io_service, udp::endpoint(udp::v4(), 0));
// 	udp::socket s(_io_service, endpoint);

// 	boost::asio::socket_base::broadcast option(true);
// 	s.set_option(option);

// 	udp::resolver resolver(_io_service);
// 	udp::resolver::query query(udp::v4(), "255.255.255.255", itoa(_sendPort));
// 	udp::resolver::iterator iterator = resolver.resolve(query);

// 	s.send_to(boost::asio::buffer(packet, length), *iterator);

// 	udp::socket sock(_io_service, udp::endpoint(udp::v4(), _sendPort));
	


// 	udp::socket sock(_io_service, udp::endpoint(udp::v4(), 0)); // deveria ser especificada a porta.. alias, o mesmo socket aberto no bind deveria ser compartilhado ???
// 	_socket->send_to(boost::asio::buffer(packet, length), endpoint);
}


void CCommunicationProvider::processReceivedPacket(const char* char_packet, size_t length, udp::socket& sock, udp::endpoint& sender_endpoint)
{
	CBinString packet;

	packet.assign(std::string(char_packet, length));
	SPacketHeader header;
	packet.load(&header, sizeof(header));

	if (header._dstVmId._pid != 0 && header._dstVmId._pid != getpid()) {
// 		std::cout << getpid() << " nao eh o meu pid !!!" << std::endl;
		return;
	}

// 	std::cout << getpid() << ": RX [" << dumpPacket(char_packet, length) << "]" << std::endl;
	

	if (header._operation == REQUEST_OPERATION) {
		processRequestOperation(packet, sock, sender_endpoint, header);
	} else if (header._operation == REPLY_OPERATION) {
		// TODO: esse teste deve existir !!!
// 		std::cout << "Reply valido !!!" << std::endl;
//		if (header._vmId != getpid()) {
//			return;
//		}

		processReplyOperation(packet, sock, sender_endpoint, header);
	} else {
// 		std::cout << "Invalid packet operation !!!" << std::endl;
		return;
	}
}


void CCommunicationProvider::processRequestOperation(CBinString& requestPacket, udp::socket& sock, udp::endpoint& sender_endpoint, SPacketHeader& requestHeader)
{
	CBinString replyPacket;

	requestHeader._dstVmId._pid = getpid();

	if (requestHeader._opcode == DATAQU_OPCODE) {
		CGroupProvider::getInstance()->processDataquRequest(requestPacket, requestHeader, replyPacket);
	} else if (requestHeader._opcode == DATADQU_OPCODE) {
		CGroupProvider::getInstance()->processDatadquRequest(requestPacket, requestHeader, replyPacket);
	} else if (requestHeader._opcode == DATANBQU_OPCODE) {
		CGroupProvider::getInstance()->processDatanbquRequest(requestPacket, requestHeader, replyPacket);
	} else if (requestHeader._opcode == DATANBDQU_OPCODE) {
		CGroupProvider::getInstance()->processDatanbdquRequest(requestPacket, requestHeader, replyPacket);
	} else if (requestHeader._opcode == DATALIST_OPCODE) {
		CGroupProvider::getInstance()->processDatalistRequest(requestPacket, requestHeader, replyPacket);
	} else if (requestHeader._opcode == SCALL_OPCODE) {
		CGroupProvider::getInstance()->processScallRequest(requestPacket, requestHeader, replyPacket);
	} else {
		std::cout << "Error in processPacket !!!" << std::endl;
	}
	if (replyPacket.size() > 0) {
		sendBroadcastPacket(replyPacket.getData().c_str(), replyPacket.size());
	}
}


void CCommunicationProvider::processReplyOperation(CBinString& replyPacket, udp::socket& sock, udp::endpoint& sender_endpoint, SPacketHeader& replyHeader)
{
	if (replyHeader._dstVmId._pid != getpid()) {
// 		std::cout << "Descartando reply VMID=" << header._vmId << std::endl;
		return;
	}

	if (CGroupProvider::getInstance()->_bce_list.find(replyHeader._dstVmId._bce) == CGroupProvider::getInstance()->_bce_list.end()) {
		return;
	}

	if (CGroupProvider::getInstance()->_bce_list[replyHeader._dstVmId._bce]->_dataReady == true && replyHeader._opcode != DATALIST_OPCODE) {
		return;
	}

	if (replyHeader._opcode == DATAQU_OPCODE) {
		CGroupProvider::getInstance()->processDataquReply(replyPacket, replyHeader); //, sender_endpoint);
	} else if (replyHeader._opcode == DATANBQU_OPCODE) {
		CGroupProvider::getInstance()->processDataquReply(replyPacket, replyHeader); //, sender_endpoint);
// 		CGroupProvider::getInstance()->processDatanbquReply(replyPacket, requestHeader);
	} else if (replyHeader._opcode == DATADQU_OPCODE) {
		CGroupProvider::getInstance()->processDataquReply(replyPacket, replyHeader); //, sender_endpoint);
// 		CGroupProvider::getInstance()->processDatadquReply(replyPacket, requestHeader);
	} else if (replyHeader._opcode == DATANBDQU_OPCODE) {
		CGroupProvider::getInstance()->processDataquReply(replyPacket, replyHeader); //, sender_endpoint);
// 		CGroupProvider::getInstance()->processDatanbdquReply(replyPacket, requestHeader);
	} else if (replyHeader._opcode == DATALIST_OPCODE) {
		CGroupProvider::getInstance()->processDatalistReply(replyPacket, replyHeader);
	} else if (replyHeader._opcode == SCALL_OPCODE) {
		CGroupProvider::getInstance()->processScallReply(replyPacket, replyHeader);
	} else {
		std::cout << "Error in processPacket !!!" << std::endl;
	}
}
