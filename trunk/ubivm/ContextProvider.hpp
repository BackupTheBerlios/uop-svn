#ifndef CONTEXTPROVIDER_HPP
#define CONTEXTPROVIDER_HPP

#include <string>

#include "UbivmDefs.hpp"
#include "Tuple.hpp"
#include "BinString.hpp"
#include "MultiIndex.hpp"
#include "Context.hpp"
#include "RunBytecode.hpp"

/**
	@author Alex Sandro Garzão <alexgarzao@gmail.com>
*/
class CContextProvider {
public:
	static CContextProvider* getInstance()
	{
		static CContextProvider *instance = NULL;
		return instance ? instance : (instance = new CContextProvider());
	}
	void setConfig(std::map<std::string, CContext*>* contextList);
	~CContextProvider();
	void sendRequestPublishdOpcode(SVmId vmId, std::string contextName, CTuple tuple);
	void sendRequestFinddOpcode(SVmId vmId, std::string contextName, CTuple tuple);
	void sendRequestGetdOpcode(SVmId vmId, std::string contextName, CTuple tuple);
	void sendRequestFinddnbOpcode(SVmId vmId, std::string contextName, CTuple tuple);
	void sendRequestGetdnbOpcode(SVmId vmId, std::string contextName, CTuple tuple);
	void sendRequestListdOpcode(SVmId vmId, std::string contextName);
	void sendRequestPublishsOpcode(SVmId vmId, std::string contextName, std::string serviceName);
	void sendRequestRemovesOpcode(SVmId vmId, std::string contextName, std::string serviceName);
	void sendRequestRunsOpcode(SVmId vmId, std::string contextName, std::string serviceName);
	void processPublishdRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket);
	void processFinddRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket);
	void processFinddnbRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket);
	void processGetdRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket);
	void processGetdnbRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket);
	void processListdRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket);
	void processPublishsRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket);
	void processRemovesRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket);
	void processRunsRequest(CBinString& requestPacket, SPacketHeader& requestHeader, CBinString& replyPacket);
	void processFinddReply(CBinString& replyPacket, SPacketHeader& replyHeader); //, udp::endpoint& sender_endpoint);
	void processFinddnbReply(CBinString& replyPacket, SPacketHeader& replyHeader);
	void processGetdReply(CBinString& replyPacket, SPacketHeader& replyHeader);
	void processGetdnbReply(CBinString& replyPacket, SPacketHeader& replyHeader);
	void processListdReply(CBinString& replyPacket, SPacketHeader& replyHeader);
	void processRunsReply(CBinString& replyPacket, SPacketHeader& replyHeader);
	void register_bce(uint id, CRunBytecode* bce);
	std::map<uint, CRunBytecode*> _bce_list;
private:
	CContextProvider()
	{
		_contextList = NULL;
	}
	std::map<std::string, CContext*>* _contextList;
};

#endif
