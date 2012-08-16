#include "UvmHeader.hpp"

#include <string.h>

struct SUvmHeader {
	u_int   binaryId;
	char    strVersion[16];
	u_short version;
	u_short entitiesCount;
};


CUvmHeader::CUvmHeader(u_int binaryId, std::string strVersion, u_short version)
	: _binaryId(binaryId), _strVersion(strVersion), _version(version), _entitiesCount(0)
{
}


CUvmHeader::~CUvmHeader()
{
}


void CUvmHeader::saveBytecode(CBinString& bytecode)
{
	//TODO: assert(_entitiesCount != 0, "Nao foi definido o numero de entidades !!!");

	SUvmHeader header;
	memset(&header, 0, sizeof(header));
	header.binaryId = _binaryId;
	strncpy((char*)header.strVersion, _strVersion.c_str(), sizeof(header.strVersion)-1);
	header.version = _version;
	header.entitiesCount = _entitiesCount;

	bytecode.save(&header, sizeof(header));
}


bool CUvmHeader::loadBytecode(CBinString& bytecode)
{
	SUvmHeader header;
	bytecode.load(&header, sizeof(header));

	if (_binaryId == header.binaryId &&
			_strVersion == header.strVersion &&
			_version == header.version) {
		_entitiesCount = header.entitiesCount;
//		// TODO
//		_entitiesCount = 1;
		return true;
	}

	return false;
}

void CUvmHeader::setEntitiesCount(u_short entitiesCount)
{
	_entitiesCount = entitiesCount;
}
