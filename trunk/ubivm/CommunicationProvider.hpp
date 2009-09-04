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


#include "Tuple.hpp"
#include "Group.hpp"
#include "DataStack.hpp"
				 

/**
	@author Alex Sandro Garzão <alexgarzao@gmail.com>
*/
class CCommunicationProvider {
public:
	CCommunicationProvider(std::map<std::string, CGroup*>* groupList, CDataStack* dataStack, uint bindPort, uint sendPort);
	void run();
	void sendRequestDataquOpcode(std::string groupName, CTuple tuple);

private:
	void sendBroadcastPacket(const char* packet, size_t length);
	void threadedCode();
	void processReceivedPacket(const char* char_packet, size_t lenght, udp::socket& sock, udp::endpoint& sender_endpoint);
	void processRequestOperation(CBinString& packet, udp::socket& sock, udp::endpoint& sender_endpoint, uint requestNumber, OpcodeType opcode);
	void processReplyOperation(CBinString& packet, udp::socket& sock, udp::endpoint& sender_endpoint, uint requestNumber, OpcodeType opcode);
	boost::thread*   _thread;
	uint             _number;
// 	boost::mutex     _mutex;
// 	boost::condition_variable _cond;
	std::map<std::string, CGroup*>* _groupList;
	CDataStack*      _dataStack;
	boost::asio::io_service io_service;
	bool _dataReady;
	uint _bindPort;
	uint _sendPort;
};

#endif
