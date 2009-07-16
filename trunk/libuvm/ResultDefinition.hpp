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
    CResultDefinition();
    CResultDefinition(LiteralType type);
    ~CResultDefinition();
	void saveBytecode(CBinString& bytecode);
	bool loadBytecode(CBinString& bytecode);
private:
	LiteralType _type;
};

//}

#endif
