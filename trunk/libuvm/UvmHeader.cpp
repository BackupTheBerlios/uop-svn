#include "UvmHeader.hpp"

typedef struct SUvmHeader {
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
//	char* pheader = (char*)&header;
	memset(&header, 0, sizeof(header));
	header.binaryId = _binaryId;
	strncpy((char*)header.strVersion, _strVersion.c_str(), sizeof(header.strVersion)-1);
	header.version = _version;
	header.entitiesCount = _entitiesCount;

	bytecode.save(&header, sizeof(header));
//	for(u_int i = 0; i < sizeof(header); i++) {
//		result.push_back(*pheader);
//		pheader++;
//	}
}


//std::vector<u_char> CUvmHeader::getBinary()
//{
//	std::vector<u_char> result;
//
//	//TODO: assert(_entitiesCount != 0, "Nao foi definido o numero de entidades !!!");
//
//	SUvmHeader header;
//	u_char* pheader = (u_char*)&header;
//	memset(&header, 0, sizeof(header));
//	header.binaryId = _binaryId;
//	strncpy((char*)header.strVersion, _strVersion.c_str(), sizeof(header.strVersion)-1);
//	header.version = _version;
//	header.entitiesCount = _entitiesCount;
//
//	for(u_int i = 0; i < sizeof(header); i++) {
//		result.push_back(*pheader);
//		pheader++;
//	}
//
//	return result;
//}


bool CUvmHeader::loadBytecode(CBinString& bytecode)
{
//   bool result = bin.removeIfEqual(0x1234) &&
//                 bin.removeIfEqual("GVM version 0.1") &&
//                 bin.removeIfEqual((char)0) &&
//                 bin.removeIfEqual((char)1);
//
//   if (result == false) {
//      return false;
//   }
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
