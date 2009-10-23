#ifndef UBIVM_DEFS_HPP
#define UBIVM_DEFS_HPP

#include <string>
#include <list>

#include "EntityDefinition.hpp"
#include "MethodDefinition.hpp"
#include "Element.hpp"

typedef struct SOptions {
	std::string sourcefile;
	std::string asmFilename;
	uint bindPort;
	uint sendPort;
	std::list<std::string> provider_list;
};

struct SIp {
	CElement *element;
	CMethodDefinition *method;
	u_short ip;
	SIp()
	{
		element = NULL;
		method  = NULL;
		ip      = 0;
	}
};

enum PacketOperationType {
	INVALID_OPERATION = 0,
	REQUEST_OPERATION,
	REPLY_OPERATION
};

struct SVmId { // TODO: Tenho que colocar IP tb no ID...
	pid_t _pid;
	uint  _bce;
	SVmId(pid_t pid, uint bce) : _pid(pid), _bce(bce)
	{ }
	SVmId() : _pid(-1), _bce(-1)
	{ }
};

struct SPacketHeader {
	SVmId               _srcVmId;
	SVmId               _dstVmId;
	uint                _packetNumber;
	OpcodeType          _opcode;
	PacketOperationType _operation;
	SPacketHeader() :
			_packetNumber(0), _opcode(INVALID_OPCODE), _operation(INVALID_OPERATION)
			{
			}
	SPacketHeader(SVmId srcVmId, SVmId dstVmId, uint packetNumber, OpcodeType opcode, PacketOperationType operation) :
			_srcVmId(srcVmId), _dstVmId(dstVmId), _packetNumber(packetNumber), _opcode(opcode), _operation(operation)
			{
			}
};

static const uint REQUEST_TIMEOUT = 1;

#endif
