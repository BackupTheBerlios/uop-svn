/***************************************************************************
 *   Copyright (C) 2009 by Alex Sandro Garzão   *
 *   alexgarzao@gmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include <iostream>

#include "ParameterDefinition.hpp"
#include "MethodDefinition.hpp"

struct SMethodHeader {
	u_int indexName; // Indice na constant pool que contem o nome do metodo
	u_int parametersCount; // Numero de parametros do metodo
	u_int resultsCount; // Numero de resultados do metodo
	u_int localVarCount; // Numero de variaveis locais
	u_int instructionsCount; // Numero de instrucoes do metodo
};


CParameterDefinition* CMethodDefinition::addParameter(LiteralType type, std::string name)
{
	CParameterDefinition* parameter = new CParameterDefinition(_symbolTable, _parameterList.size(), type, name);

	addParameter(parameter);

//	addLocalVar(type, name);

	return parameter;
}

void CMethodDefinition::addParameter(CParameterDefinition* parameter)
{
	_parameterList.push_back(parameter);
}

CLocalVarDefinition* CMethodDefinition::addLocalVar(LiteralType type, std::string name)
{
	CLocalVarDefinition* var = new CLocalVarDefinition(_symbolTable, _localVarList.size(), type, name);

	_localVarList.push_back(var);

	return var;
}

CResultDefinition* CMethodDefinition::addResult(LiteralType type)
{
// 	std::cout << __FUNCTION__ << ": Tipo=" << type << std::endl;

	CResultDefinition* result = new CResultDefinition(_resultList.size(), type);

	addResult(result);

	return result;
}

void CMethodDefinition::addResult(CResultDefinition* result)
{
	_resultList.push_back(result);
}

CInstructionDefinition * CMethodDefinition::addInstruction(OpcodeType opcode)
{
	return addInstruction(opcode, -1);
}

CInstructionDefinition * CMethodDefinition::addInstruction(OpcodeType opcode, ArgType arg1)
{
	CInstructionDefinition* instruction;
	int label = -1;

	if (_pushInstructions == false) {
		if (_nextInstructionLabelList.size() > 0) {
			// TODO: eu devo guardar o numero da instrucao ou a posicao no bytecode gerado ???
			for(std::vector<int>::iterator label = _nextInstructionLabelList.begin();
				label != _nextInstructionLabelList.end();
				label++) {
				_labelAddress[*label] = _instructionList.size();
			}
		}

		// TODO: E nesse caso, como eu coloco varios labels em uma intrucao ??? E precisa ???
		if (_nextInstructionLabelList.size() > 0) {
			label = _nextInstructionLabelList[0];
		}
		instruction = new CInstructionDefinition(_symbolTable, label, opcode, arg1);
		_instructionList.push_back(instruction);

		_nextInstructionLabelList.clear();
	} else {
		instruction = new CInstructionDefinition(_symbolTable, label, opcode, arg1);
		_pushedInstructions.push_back(instruction);
	}

	return instruction;
}

void CMethodDefinition::addIfStatement()
{
}

void CMethodDefinition::addWhileStatement()
{
}

void CMethodDefinition::addForStatement()
{
}

std::string CMethodDefinition::toTextAssembly(bool high_level, bool onlyCode)
{
	std::string result;

	result += "\t.method " + _name + '\n';
	// TODO: listar parametros

	for(std::vector<CParameterDefinition*>::iterator par = _parameterList.begin(); par != _parameterList.end(); par++) {
		result += "\t\t.param " + (*par)->toTextAssembly() + "\n";
	}

	for(std::vector<CLocalVarDefinition*>::iterator var = _localVarList.begin(); var != _localVarList.end(); var++) {
		result += "\t\t.var " + (*var)->toTextAssembly() + "\n";
	}

	for(std::vector<CResultDefinition*>::iterator res = _resultList.begin(); res != _resultList.end(); res++) {
		result += "\t\t.result " + (*res)->toTextAssembly() + "\n";
	}

	// TODO: nao daria para testar essa flag no inicio deste metodo ???
	if (onlyCode == true) {
		result = "";
	}

	for(std::vector<CInstructionDefinition*>::iterator instruction = _instructionList.begin(); instruction != _instructionList.end(); instruction++) {
		result += (*instruction)->toTextAssembly(high_level, _entity->_propertyList, _localVarList, _parameterList);
	}

	if (onlyCode == false) {
		result += "\t.end\n";
	}

	return result;
}

void CMethodDefinition::saveBytecode(CBinString& bytecode)
{
	SMethodHeader header;

	header.indexName         = _symbolTable->getSymbolIndex(_name, StringType);
	header.parametersCount   = _parameterList.size();
	header.resultsCount      = _resultList.size();
	header.localVarCount     = _localVarList.size();
	header.instructionsCount = _instructionList.size();

	// Salva o header do metodo
	bytecode.save(&header, sizeof(header));

	// Salva os parametros do metodo
	for(std::vector<CParameterDefinition*>::iterator parameter = _parameterList.begin(); parameter != _parameterList.end(); parameter++) {
		(*parameter)->saveBytecode(bytecode);
	}

	// Salva os resultados do metodo
	for(std::vector<CResultDefinition*>::iterator result = _resultList.begin(); result != _resultList.end(); result++) {
		(*result)->saveBytecode(bytecode);
	}

	// Salva as variaveis locais do metodo
	for(std::vector<CLocalVarDefinition*>::iterator var = _localVarList.begin(); var != _localVarList.end(); var++) {
		(*var)->saveBytecode(bytecode);
	}

	// Salva as intrucoes do metodo
	for(std::vector<CInstructionDefinition*>::iterator instruction = _instructionList.begin(); instruction != _instructionList.end(); instruction++) {
		(*instruction)->saveBytecode(bytecode);
	}
}

bool CMethodDefinition::loadBytecode(CBinString& bytecode)
{
	SMethodHeader header;

	// Carrega o header do metodo
	bytecode.load(&header, sizeof(header));

	_name = _symbolTable->getSymbolByIndex(header.indexName)->_name;

	// Carrega os parametros do metodo
	for(u_int count = 0; count < header.parametersCount; count++) {
		CParameterDefinition* parameter = new CParameterDefinition(_symbolTable, _parameterList.size());
		parameter->loadBytecode(bytecode);
		addParameter(parameter);
	}

	// Carrega os resultados do metodo
	for(u_int count = 0; count < header.resultsCount; count++) {
		CResultDefinition* result = new CResultDefinition(_resultList.size());
		result->loadBytecode(bytecode);
		addResult(result);
	}

	// Carrega as variaveis locais do metodo
	for(u_int count = 0; count < header.localVarCount; count++) {
		CLocalVarDefinition* var = new CLocalVarDefinition(_symbolTable, count);
		var->loadBytecode(bytecode);
		//addLocalVar(var);
		_localVarList.push_back(var);
	}

	// Carrega as intrucoes do metodo
	for(u_int count = 0; count < header.instructionsCount; count++) {
		CInstructionDefinition* instruction = new CInstructionDefinition(_symbolTable);
		instruction->loadBytecode(bytecode);
		_instructionList.push_back(instruction);
	}

	adjustInstructionsLabels();

	return true;
}

CMethodDefinition::CMethodDefinition(CEntityDefinition* entity, CSymbolTable* symbolTable)
	: _entity(entity), _symbolTable(symbolTable), _nextLabel(0), _pushInstructions(false)//, _nextInstructionLabel(-1)
{
}

CMethodDefinition::CMethodDefinition(CEntityDefinition* entity, CSymbolTable *symbolTable, VisibilityType visibility, std::string name)
	: _entity(entity), _symbolTable(symbolTable), _visibility(visibility), _name(name), _nextLabel(0), _pushInstructions(false)//, _nextInstructionLabel(-1)
{
	// Forca que o simbolo seja criado na tabela de simbolos...
	// TODO: ta meio estranho o codigo, melhorar...
	_symbolTable->getSymbol(name, StringType); // TODO: deveria ser MethodType...
}


std::string CMethodDefinition::getName() const
{
	return _name;
}

CInstructionDefinition* CMethodDefinition::getInstruction(ushort number)
{
	if (number >= _instructionList.size()) {
		return NULL;
	}

	return _instructionList[number];
}

size_t CMethodDefinition::getVarIndex(std::string name)
{
	CLocalVarDefinition* var = findLocalVarDefinition(name);
	if (var == NULL) {
		std::cout << "Forgot to define " << name << std::endl;
	}
	return var->_index;
}

size_t CMethodDefinition::getParamIndex(std::string name)
{
	std::map<std::string, size_t>::iterator param = _parameterNumber.find(name);
	if (param == _parameterNumber.end()) {
		size_t number = _parameterNumber.size();
		_parameterNumber[name] = number;
		return number;
	} else {
		return param->second;
	}
}

void CMethodDefinition::resolveLabels()
{
	for(std::vector<CInstructionDefinition*>::iterator instruction = _instructionList.begin(); instruction != _instructionList.end(); instruction++) {
		// Troca argumentos (label) de IFNOT e JMP pelo endereco correto
		if ((*instruction)->_opcode == IFNOT_OPCODE || (*instruction)->_opcode == IF_OPCODE || (*instruction)->_opcode == JMP_OPCODE) {
			std::map<int,int>::iterator address = _labelAddress.find((*instruction)->_arg1);
			if (address == _labelAddress.end()) {
				std::cerr << "Label " << (*instruction)->_arg1 << " inexistente !!!" << std::endl;
			} else {
				(*instruction)->_arg1 = address->second;
				_instructionList[address->second]->_label_used = true;
			}
		}

		// Troca label da instrucao pelo numero da instrucao
		if ((*instruction)->_label != -1) {
// 			if ((*instruction)->_label_used) {
				(*instruction)->_label = instruction - _instructionList.begin();
// 			}
		}
	}

	// Elimina labels nao utilizados
	for(std::vector<CInstructionDefinition*>::iterator instruction = _instructionList.begin(); instruction != _instructionList.end(); instruction++) {
		if ((*instruction)->_label_used == false) {
			(*instruction)->_label = -1;
		}
	}
}

// void CMethodDefinition::resolveLabels()
// {
// 	for(std::vector<CInstructionDefinition*>::iterator instruction = _instructionList.begin(); instruction != _instructionList.end(); instruction++) {
// 		// Troca argumentos (label) de IFNOT e JMP pelo endereco correto
// 		if ((*instruction)->_opcode == IFNOT_OPCODE || (*instruction)->_opcode == IF_OPCODE || (*instruction)->_opcode == JMP_OPCODE) {
// 			if ((*instruction)->_arg1 >= _labelAddress.size()) {
// 				std::cerr << "Label " << (*instruction)->_arg1 << " inexistente !!!" << std::endl;
// 				std::cerr << "LabelAddress.size()=" << _labelAddress.size() << std::endl;
// 			} else {
// 				(*instruction)->_arg1 = _labelAddress[(*instruction)->_arg1];
// 			}
// 		}
//
// 		// Troca label da instrucao pelo numero da instrucao
// 		if ((*instruction)->_label != -1) {
// 			(*instruction)->_label = instruction - _instructionList.begin();
// 		}
// 	}
// }

int CMethodDefinition::setNextInstructionLabel(int label)
{
//	if (_nextInstructionLabel != -1) {
//		std::cerr << "Label " << _nextInstructionLabel << " foi sobrescrito !!!" << std::endl;
//	}
	_nextInstructionLabelList.push_back(label);

	return label;
}

void CMethodDefinition::adjustInstructionsLabels()
{
	for(std::vector<CInstructionDefinition*>::iterator instruction = _instructionList.begin(); instruction != _instructionList.end(); instruction++) {
		if ((*instruction)->_opcode == IFNOT_OPCODE || (*instruction)->_opcode == IF_OPCODE || (*instruction)->_opcode == JMP_OPCODE) {
			if ((*instruction)->_arg1 >= _instructionList.size()) {
				std::cerr << "Instrucao de salto apontando para instrucao inexistente: " << (*instruction)->_arg1  << std::endl;
			} else {
				_instructionList[(*instruction)->_arg1]->_label = (*instruction)->_arg1;
			}
		}
	}
}

void CMethodDefinition::addLoadInstruction(std::string identifier, bool tableInstruction)
{
	// TODO: improve this...
	CLocalVarDefinition* var = findLocalVarDefinition(identifier);
	if (var != NULL) {
		if (tableInstruction == true) {
			addInstruction(LDTAB_OPCODE, var->_index);
		} else {
			addInstruction(LDVAR_OPCODE, var->_index);
		}
	} else {
		CPropertyDefinition* property = _entity->findProperty(identifier);
		if (property != NULL) {
			addInstruction(LDPROP_OPCODE, property->_index);
		} else {
			addInstruction(LDPARAM_OPCODE, getParamIndex(identifier));
		}
	}
}

void CMethodDefinition::addStoreInstruction(std::string identifier, bool tableInstruction)
{
	// TODO: improve this...
	CLocalVarDefinition* var = findLocalVarDefinition(identifier);
	if (var != NULL) {
		if (tableInstruction == true) {
 			addInstruction(STTAB_OPCODE, var->_index);
 		} else {
			addInstruction(STVAR_OPCODE, var->_index);
 		}
	} else {
		CPropertyDefinition* property = _entity->findProperty(identifier);
		if (property != NULL) {
			addInstruction(STPROP_OPCODE, property->_index);
		} else {
			addInstruction(STPARAM_OPCODE, getParamIndex(identifier));
		}
	}
}

void CMethodDefinition::pushInstructions()
{
	_pushInstructions = true;
}

void CMethodDefinition::addInstructions()
{
	_pushInstructions = false;
}

void CMethodDefinition::addPushedInstructions()
{
	// TODO: e se houver labels para serem gerados ??? talvez o ideal seria salvar o opcode e arg mesmo em _pushedInstructions, e essa rotina invocaria a rotina normal para gerar opcodes...
	_instructionList.insert(_instructionList.end(), _pushedInstructions.begin(), _pushedInstructions.end());
	_pushedInstructions.clear();
}

CLocalVarDefinition * CMethodDefinition::findLocalVarDefinition(std::string identifier)
{
	for(std::vector<CLocalVarDefinition*>::iterator var = _localVarList.begin(); var != _localVarList.end(); var++) {
		if ((*var)->_name == identifier) {
			return (*var);
		}
	}

	return NULL;
}
