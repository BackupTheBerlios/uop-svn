#ifndef UBIVM_DEFS_HPP
#define UBIVM_DEFS_HPP

#include "EntityDefinition.hpp"
#include "MethodDefinition.hpp"
#include "Element.hpp"

typedef struct SOptions {
	std::string sourcefile;
	std::string asmFilename;
};

struct SIp {
	CElement *element;
	CMethodDefinition *method;
	u_short ip;
};

#endif
