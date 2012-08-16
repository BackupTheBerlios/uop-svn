#include "CommunicationProvider.hpp"
#include "ContextProvider.hpp"

#include <stdlib.h>

enum { max_length = 1024 };


void CCommunicationProvider::setConfig(std::map<std::string, CContext*>* contextList, uint bindPort, uint sendPort)
{
	_packetNumber = 0;
	_bindPort = bindPort;
	_sendPort = sendPort;
}


void CCommunicationProvider::run()
{
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

	s.send_to(boost::asio::buffer(packet, length), *iterator);

	return;
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
		return;
	}

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
		return;
	}
}


void CCommunicationProvider::processRequestOperation(CBinString& requestPacket, udp::socket& sock, udp::endpoint& sender_endpoint, SPacketHeader& requestHeader)
{
	CBinString replyPacket;

	requestHeader._dstVmId._pid = getpid();


	if (requestHeader._opcode == CPUBLISH_OPCODE) {
		CContextProvider::getInstance()->processPublishdRequest(requestPacket, requestHeader, replyPacket);
	} else if (requestHeader._opcode == CFIND_OPCODE) {
		CContextProvider::getInstance()->processFinddRequest(requestPacket, requestHeader, replyPacket);
	} else if (requestHeader._opcode == CGET_OPCODE) {
		CContextProvider::getInstance()->processGetdRequest(requestPacket, requestHeader, replyPacket);
	} else if (requestHeader._opcode == CFINDNB_OPCODE) {
		CContextProvider::getInstance()->processFinddnbRequest(requestPacket, requestHeader, replyPacket);
	} else if (requestHeader._opcode == CGETNB_OPCODE) {
		CContextProvider::getInstance()->processGetdnbRequest(requestPacket, requestHeader, replyPacket);
	} else if (requestHeader._opcode == CLIST_OPCODE) {
		CContextProvider::getInstance()->processListdRequest(requestPacket, requestHeader, replyPacket);
	} else if (requestHeader._opcode == SPUBLISH_OPCODE) {
		CContextProvider::getInstance()->processPublishsRequest(requestPacket, requestHeader, replyPacket);
	} else if (requestHeader._opcode == SREM_OPCODE) {
		CContextProvider::getInstance()->processRemovesRequest(requestPacket, requestHeader, replyPacket);
	} else if (requestHeader._opcode == SRUN_OPCODE) {
		CContextProvider::getInstance()->processRunsRequest(requestPacket, requestHeader, replyPacket);
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
		return;
	}

	if (CContextProvider::getInstance()->_bce_list.find(replyHeader._dstVmId._bce) == CContextProvider::getInstance()->_bce_list.end()) {
		return;
	}

	if (CContextProvider::getInstance()->_bce_list[replyHeader._dstVmId._bce]->_dataReady == true && replyHeader._opcode != CLIST_OPCODE) {
		return;
	}

	if (replyHeader._opcode == CFIND_OPCODE) {
		CContextProvider::getInstance()->processFinddReply(replyPacket, replyHeader);
	} else if (replyHeader._opcode == CFINDNB_OPCODE) {
		CContextProvider::getInstance()->processFinddReply(replyPacket, replyHeader);
	} else if (replyHeader._opcode == CGET_OPCODE) {
		CContextProvider::getInstance()->processFinddReply(replyPacket, replyHeader);
	} else if (replyHeader._opcode == CGETNB_OPCODE) {
		CContextProvider::getInstance()->processFinddReply(replyPacket, replyHeader);
	} else if (replyHeader._opcode == CLIST_OPCODE) {
		CContextProvider::getInstance()->processListdReply(replyPacket, replyHeader);
	} else if (replyHeader._opcode == SRUN_OPCODE) {
		CContextProvider::getInstance()->processRunsReply(replyPacket, replyHeader);
	} else {
		std::cout << "Error in processPacket !!!" << std::endl;
	}
}
