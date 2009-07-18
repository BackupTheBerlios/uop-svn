#ifndef UVM_FILERESULTDEFINITION_HPP
#define UVM_FILERESULTDEFINITION_HPP

#include "BinString.hpp"

#include "LibuvmDefs.hpp"

//namespace ASSEMBLY_DEFINITION {

/**
	@author Alex Sandro Garzão <alexgarzao@gmail.com>
*/
class CResultDefinition{
public:
    CResultDefinition(size_t index);
    CResultDefinition(size_t index, LiteralType type);
    ~CResultDefinition();
	void saveBytecode(CBinString& bytecode);
	bool loadBytecode(CBinString& bytecode);
	std::string toTextAssembly();
//private:
	size_t _index;
	LiteralType _type;
};

//}

#endif
