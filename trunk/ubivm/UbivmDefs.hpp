#ifndef UBIVM_DEFS_HPP
#define UBIVM_DEFS_HPP

#include "EntityDefinition.hpp"
#include "MethodDefinition.hpp"
#include "Element.hpp"

typedef struct SOptions {
	std::string sourcefile;
	std::string asmFilename;
	uint bindPort;
	uint sendPort;
};

struct SIp {
	CElement *element;
	CMethodDefinition *method;
	u_short ip;
};

enum PacketOperationType {
	REQUEST_OPERATION,
	REPLY_OPERATION
};

#endif
