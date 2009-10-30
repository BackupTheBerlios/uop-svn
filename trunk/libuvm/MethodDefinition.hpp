#ifndef LIBUVM_METHOD_DEFINITION_HPP
#define LIBUVM_METHOD_DEFINITION_HPP

//namespace ASSEMBLY_DEFINITION {

//#include <string.h>
//#include <iostream>
#include <string>
#include <map>
#include <vector>

class CMethodDefinition;

#include "SymbolTable.hpp"
#include "LibuvmDefs.hpp"
#include "ParameterDefinition.hpp"
#include "LocalVarDefinition.hpp"
#include "ResultDefinition.hpp"
#include "InstructionDefinition.hpp"
#include "BinString.hpp"
#include "EntityDefinition.hpp"

class CMethodDefinition
{
public:
	CMethodDefinition(CEntityDefinition* entity, CSymbolTable* symbolTable);
	CMethodDefinition(CEntityDefinition* entity, CSymbolTable *symbolTable, VisibilityType visibility, std::string name);
	CParameterDefinition *addParameter(LiteralType type, std::string name);
	void addParameter(CParameterDefinition* parameter);
	CLocalVarDefinition *addLocalVar(LiteralType type, std::string name);
	CResultDefinition *addResult(LiteralType type);
	void addResult(CResultDefinition* result);
	CInstructionDefinition *addInstruction(OpcodeType opcode);
	CInstructionDefinition *addInstruction(OpcodeType opcode, ArgType arg1);
	std::string toTextAssembly(bool onlyCode=false);
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
	void addLoadInstruction(std::string identifier, bool tableInstruction);
	void addStoreInstruction(std::string identifier, bool tableInstruction);
	void pushInstructions();
	void addInstructions();
	void addPushedInstructions();

	std::vector<CLocalVarDefinition*>            _localVarList;
	std::vector<CParameterDefinition*>           _parameterList;
	std::vector<CResultDefinition*>              _resultList;

private:
	void adjustInstructionsLabels();
	CLocalVarDefinition* _findLocalVarDefinition(std::string identifier);

//	std::map<const char *, CParamDefinition*> _test;
//	std::vector<CParameterDefinition*>           _parameterVector;
//	std::map<std::string, CParameterDefinition*> _parameterMap;
//	std::map<std::string, CLocalVarDefinition*>  _localVarList;
	std::vector<CInstructionDefinition*>         _instructionList;
	std::vector<CInstructionDefinition*>         _pushedInstructions;
	CEntityDefinition* _entity;
	CSymbolTable *_symbolTable;
	VisibilityType _visibility;
	std::string    _name;
// 	std::map<std::string, size_t> _localVarNumber;
	std::map<std::string, size_t> _parameterNumber;
	int _nextLabel;
	std::vector<int> _nextInstructionLabelList;
	std::map<int,int> _labelAddress;
	bool _pushInstructions;
};

//}


#endif

