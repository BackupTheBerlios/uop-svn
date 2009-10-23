#ifndef GROUPPROVIDER_HPP
#define GROUPPROVIDER_HPP

#include <string>

#include "UbivmDefs.hpp"
#include "Tuple.hpp"
#include "BinString.hpp"
#include "MultiIndex.hpp"
#include "Group.hpp"
#include "RunBytecode.hpp"

/**
	@author Alex Sandro Garzão <alexgarzao@gmail.com>
*/
class CGroupProvider {
public:
	static CGroupProvider* getInstance()
	{
		static CGroupProvider *instance = NULL;
		return instance ? instance : (instance = new CGroupProvider());
	}
	void setConfig(std::map<std::string, CGroup*>* groupList);
	~CGroupProvider();
	void sendRequestDataquOpcode(SVmId vmId, std::string groupName, CTuple tuple);
	void sendRequestDatadquOpcode(SVmId vmId, std::string groupName, CTuple tuple);
	void sendRequestDatanbquOpcode(SVmId vmId, std::string groupName, CTuple tuple);
	void sendRequestDatanbdquOpcode(SVmId vmId, std::string groupName, CTuple tuple);
	void sendRequestDatalistOpcode(SVmId vmId, std::string groupName);
	void sendRequestScallOpcode(SVmId vmId, std::string groupName, std::string serviceName);
	void processDataquRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket);
	void processDatanbquRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket);
	void processDatadquRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket);
	void processDatanbdquRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket);
	void processDatalistRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket);
	void processScallRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket);
	void processDataquReply(CBinString& replyPacket, SPacketHeader& replyHeader); //, udp::endpoint& sender_endpoint);
	void processDatanbquReply(CBinString& replyPacket, SPacketHeader& replyHeader);
	void processDatadquReply(CBinString& replyPacket, SPacketHeader& replyHeader);
	void processDatanbdquReply(CBinString& replyPacket, SPacketHeader& replyHeader);
	void processDatalistReply(CBinString& replyPacket, SPacketHeader& replyHeader);
	void processScallReply(CBinString& replyPacket, SPacketHeader& replyHeader);
	void register_bce(uint id, CRunBytecode* bce);
	std::map<uint, CRunBytecode*> _bce_list;
private:
	CGroupProvider()
	{
		_groupList          = NULL;
	}
	std::map<std::string, CGroup*>* _groupList;
};

#endif
