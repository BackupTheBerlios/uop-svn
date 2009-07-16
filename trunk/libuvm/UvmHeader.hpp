#ifndef UVM_HEADER_H
#define UVM_HEADER_H

#include <string>
#include <vector>

#include "BinString.hpp"

class CUvmHeader
{
public:
   CUvmHeader(u_int binaryId, std::string strVersion, u_short version);
   ~CUvmHeader();
   void saveBytecode(CBinString& bytecode);
   //std::vector<u_char> getBinary();
//   bool readFromBinary(std::vector<u_char> bin);
   bool loadBytecode(CBinString& bytecode);
   void setEntitiesCount(u_short entitiesCount);
   u_short getEntitiesCount() const
   {
	   return _entitiesCount;
   }
private:
   u_int       _binaryId;
   std::string _strVersion;
   u_short     _version;
   u_short     _entitiesCount;
};

#endif

