#ifndef UVM_FILE_LOCALVAR_DEFINITION_HPP
#define UVM_FILE_LOCALVAR_DEFINITION_HPP

//namespace ASSEMBLY_DEFINITION {

#include <string>

#include "LibuvmDefs.hpp"
#include "BinString.hpp"
#include "SymbolTable.hpp"

/**
	@author Alex Sandro Garzão <alexgarzao@gmail.com>
*/
class CLocalVarDefinition{
public:
	CLocalVarDefinition(CSymbolTable *symbolTable, size_t index);
	CLocalVarDefinition(CSymbolTable *symbolTable, size_t index, LiteralType type, std::string name);
	~CLocalVarDefinition();
	std::string toTextAssembly();
	void saveBytecode(CBinString& bytecode);
	bool loadBytecode(CBinString& bytecode);

	CSymbolTable *_symbolTable;
	size_t _index;
	LiteralType _type;
	std::string _name;
};

//}

#endif
