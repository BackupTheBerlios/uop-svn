#ifndef LIBUVM_METHOD_DEFINITION_HPP
#define LIBUVM_METHOD_DEFINITION_HPP

//namespace ASSEMBLY_DEFINITION {

//#include <string.h>
//#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "SymbolTable.hpp"
#include "LibuvmDefs.hpp"
#include "ParameterDefinition.hpp"
#include "LocalVarDefinition.hpp"
#include "ResultDefinition.hpp"
#include "InstructionDefinition.hpp"
#include "BinString.hpp"

class CMethodDefinition
{
public:
	CMethodDefinition(CSymbolTable* symbolTable);
	CMethodDefinition(CSymbolTable *symbolTable, VisibilityType visibility, std::string name);
	CParameterDefinition *addParameter(LiteralType type, std::string name);
	void addParameter(CParameterDefinition* parameter);
	CLocalVarDefinition *addLocalVar(LiteralType type, std::string name);
	CResultDefinition *addResult(LiteralType type);
	void addResult(CResultDefinition* result);
	CInstructionDefinition *addInstruction(OpcodeType opcode);
	CInstructionDefinition *addInstruction(OpcodeType opcode, ArgType arg1);
	std::string toTextAssembly();
	void saveBytecode(CBinString& bytecode);
	bool loadBytecode(CBinString& bytecode);
	void addIfStatement();
	void addWhileStatement();
	void addForStatement();
	std::string getName() const;
	CInstructionDefinition* getInstruction(ushort number);
	size_t getVarIndex(std::string name);
	size_t getParamIndex(std::string name);
	int getNewLabel() {
		return _nextLabel++;
	}
	int setNextInstructionLabel(int label);
	void resolveLabels();
	void addLoadInstruction(std::string identifier);

	std::vector<CLocalVarDefinition*>            _localVarList;
	std::vector<CParameterDefinition*>           _parameterList;

private:
	void adjustInstructionsLabels();

//	std::map<const char *, CParamDefinition*> _test;
//	std::vector<CParameterDefinition*>           _parameterVector;
//	std::map<std::string, CParameterDefinition*> _parameterMap;
//	std::map<std::string, CLocalVarDefinition*>  _localVarList;
	std::vector<CResultDefinition*>              _resultList;
	std::vector<CInstructionDefinition*>         _instructionList;
	CSymbolTable *_symbolTable;
	VisibilityType _visibility;
	std::string    _name;
	std::map<std::string, size_t> _localVarNumber;
	std::map<std::string, size_t> _parameterNumber;
	int _nextLabel;
	std::vector<int> _nextInstructionLabelList;
	std::map<int,int> _labelAddress;
};

//}


#endif

