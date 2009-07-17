#ifndef UVM_FILEPARAMETERDEFINITION_HPP
#define UVM_FILEPARAMETERDEFINITION_HPP

#include <string>

#include "BinString.hpp"
#include "LibuvmDefs.hpp"

//namespace ASSEMBLY_DEFINITION {

/**
	@author Alex Sandro Garzão <alexgarzao@gmail.com>
*/
class CParameterDefinition{
public:
    CParameterDefinition();
    CParameterDefinition(LiteralType type, std::string name);
    ~CParameterDefinition();
	void saveBytecode(CBinString& bytecode);
	bool loadBytecode(CBinString& bytecode);
//private:
	LiteralType _type;
	std::string _name;
};

//}

#endif
