/***************************************************************************
 *   Copyright (C) 2009 by Alex Sandro Garzão   *
 *   alexgarzao@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef UBIVM_COMMUNICATION_PROVIDER_HPP
#define UBIVM_COMMUNICATION_PROVIDER_HPP

#include <string>
#include <boost/thread.hpp>
#include <boost/asio.hpp>

#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>

using boost::asio::ip::udp;

class CCommunicationProvider;
class CRunBytecode;

#include "Tuple.hpp"
#include "Context.hpp"
#include "DataStack.hpp"
#include "UbivmDefs.hpp"
#include "Tools.hpp"
#include "RunBytecode.hpp"




/**
	@author Alex Sandro Garzão <alexgarzao@gmail.com>
*/
class CCommunicationProvider {
public:
	static CCommunicationProvider* getInstance()
	{
		static CCommunicationProvider *instance = NULL;
		return instance ? instance : (instance = new CCommunicationProvider());
	}
	void setConfig(std::map<std::string, CContext*>* contextList, uint bindPort, uint sendPort);
	void run();
	uint getNextPacketNumber()
	{
		return _packetNumber++;
	}
	void sendBroadcastPacket(const char* packet, size_t length);
	void sendUnicastReply(const char* packet, size_t length, udp::endpoint& endpoint);
private:
	CCommunicationProvider() { };
	void threadedCode();
	void processReceivedPacket(const char* char_packet, size_t lenght, udp::socket& sock, udp::endpoint& sender_endpoint);
	void processRequestOperation(CBinString& requestPacket, udp::socket& sock, udp::endpoint& sender_endpoint, SPacketHeader& requestHeader);
// 	void processListdRequest(CBinString& packet, udp::socket& sock, udp::endpoint& sender_endpoint, SPacketHeader& requestHeader);
	void processReplyOperation(CBinString& requestPacket, udp::socket& sock, udp::endpoint& sender_endpoint, SPacketHeader& requestHeader);
// 	void processListdReply(CBinString& requestPacket, udp::socket& sock, udp::endpoint& sender_endpoint, SPacketHeader& requestHeader);
	std::string dumpPacket(const char* packet, uint length);

	boost::thread*   _thread;
	uint             _packetNumber;
// 	boost::mutex     _mutex;
// 	boost::condition_variable _cond;
// 	CDataStack*      _dataStack;
	uint _bindPort;
	uint _sendPort;
 	boost::asio::io_service _io_service;
// 	boost::asio::ip::udp::socket* _socket;
};

#endif
