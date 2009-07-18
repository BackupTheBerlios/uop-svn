#ifndef UVM_FILEPARAMETERDEFINITION_HPP
#define UVM_FILEPARAMETERDEFINITION_HPP

#include <string>

#include "BinString.hpp"
#include "LibuvmDefs.hpp"
#include "SymbolTable.hpp"

//namespace ASSEMBLY_DEFINITION {

/**
	@author Alex Sandro Garzão <alexgarzao@gmail.com>
*/
class CParameterDefinition{
public:
    CParameterDefinition(CSymbolTable* symbolTable, size_t index);
    CParameterDefinition(CSymbolTable* symbolTable, size_t index, LiteralType type, std::string name);
    ~CParameterDefinition();
	void saveBytecode(CBinString& bytecode);
	bool loadBytecode(CBinString& bytecode);
	std::string toTextAssembly();
//private:
	CSymbolTable* _symbolTable;
	size_t _index;
	LiteralType _type;
	std::string _name;
};

//}

#endif
