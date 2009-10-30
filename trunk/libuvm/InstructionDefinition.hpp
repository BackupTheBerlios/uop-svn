#ifndef LIBUVM_INSTRUCTION_DEFINITION_HPP
#define LIBUVM_INSTRUCTION_DEFINITION_HPP

//namespace ASSEMBLY_DEFINITION {

#include <string>


#include "SymbolTable.hpp"
#include "LibuvmDefs.hpp"
#include "BinString.hpp"
#include "LocalVarDefinition.hpp"
#include "ParameterDefinition.hpp"
#include "PropertyDefinition.hpp"

/**
	@author Alex Sandro Garzão <alexgarzao@gmail.com>
*/
class CInstructionDefinition
{
public:
    CInstructionDefinition(CSymbolTable* symbolTable);
    CInstructionDefinition(CSymbolTable *symbolTable, LabelType label, OpcodeType opcode, ArgType arg1);
    ~CInstructionDefinition();

    std::string toTextAssembly(const std::vector<CPropertyDefinition*> &propertyList, const std::vector<CLocalVarDefinition*> &localVarList, const std::vector<CParameterDefinition*> &paramList);
//    std::string toTextAssembly();
    void saveBytecode(CBinString& bytecode);
    bool loadBytecode(CBinString& bytecode);
	std::string getTextOpcode();
	
	int opcodeIndex(OpcodeType opcode);

	CSymbolTable *_symbolTable;
	LabelType _label;
	OpcodeType _opcode;
	ArgType _arg1;
	ArgType _arg2; // PRECISA ???
	ArgType getArg1() const
	{
		return _arg1;
	}
};

//}

#endif

