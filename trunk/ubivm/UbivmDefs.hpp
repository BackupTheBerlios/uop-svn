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

#endif
