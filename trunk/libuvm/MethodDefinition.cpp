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

typedef struct SMethodHeader {
	u_int indexName; // Indice na constant pool que contem o nome do metodo
	u_int parametersCount; // Numero de parametros do metodo
	u_int resultsCount; // Numero de resultados do metodo
	u_int localVarCount; // Numero de variaveis locais
	u_int instructionsCount; // Numero de instrucoes do metodo
};


CParameterDefinition * CMethodDefinition::addParameter(LiteralType type, std::string name)
{
	CParameterDefinition* parameter = new CParameterDefinition(type, name);

	addParameter(parameter);

	return parameter;
}

void CMethodDefinition::addParameter(CParameterDefinition* parameter)
{
	_parameterList.push_back(parameter);
}

CLocalVarDefinition * CMethodDefinition::addLocalVar(LiteralType type, std::string name)
{
	CLocalVarDefinition* var = new CLocalVarDefinition(_symbolTable, _localVarList.size(), type, name);

	_localVarList.push_back(var);
	
	return var;
}

CResultDefinition * CMethodDefinition::addResult(LiteralType type)
{
	CResultDefinition* result = new CResultDefinition(type);

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
	if (_nextInstructionLabelList.size() > 0) {
		// TODO: eu devo guardar o numero da instrucao ou a posicao no bytecode gerado ???
		for(std::vector<int>::iterator label = _nextInstructionLabelList.begin();
			label != _nextInstructionLabelList.end();
			label++) {
			_labelAddress[*label] = _instructionList.size();
		}
// 		std::cout << "Label " << _nextInstructionLabel << " endereco " << _instructionList.size() << std::endl;
	}

	// TODO: E nesse caso, como eu coloco varios labels em uma intrucao ??? E precisa ???
	int label = -1;
	if (_nextInstructionLabelList.size() > 0) {
		label = _nextInstructionLabelList[0];
	}
	CInstructionDefinition* instruction = new CInstructionDefinition(_symbolTable, label, opcode, arg1);
	_instructionList.push_back(instruction);

	_nextInstructionLabelList.clear();

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

std::string CMethodDefinition::toTextAssembly()
{
	std::string result;

	result += "\tDef " + _name + '\n';
	// TODO: listar parametros e retornos

	if (_localVarList.size() == 0) {
		result += "\t\tNo local variables\n";
	} else {
		result += "\t\tLocal variables\n";
		for(std::vector<CLocalVarDefinition*>::iterator var = _localVarList.begin(); var != _localVarList.end(); var++) {
			result += (*var)->toTextAssembly();
		}
		result += "\t\tEnd\n";
	}

	for(std::vector<CInstructionDefinition*>::iterator instruction = _instructionList.begin(); instruction != _instructionList.end(); instruction++) {
		result += (*instruction)->toTextAssembly(_localVarList);
	}

	result += "\tEnd\n";

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
		CParameterDefinition* parameter = new CParameterDefinition();
		parameter->loadBytecode(bytecode);
		addParameter(parameter);
	}

	// Carrega os resultados do metodo
	for(u_int count = 0; count < header.resultsCount; count++) {
		CResultDefinition* result = new CResultDefinition();
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

CMethodDefinition::CMethodDefinition(CSymbolTable* symbolTable)
	: _symbolTable(symbolTable), _nextLabel(0)//, _nextInstructionLabel(-1)
{
}

CMethodDefinition::CMethodDefinition(CSymbolTable *symbolTable, VisibilityType visibility, std::string name)
	: _symbolTable(symbolTable), _visibility(visibility), _name(name), _nextLabel(0)//, _nextInstructionLabel(-1)
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
	std::map<std::string, size_t>::iterator var = _localVarNumber.find(name);
	if (var == _localVarNumber.end()) {
		size_t number = _localVarNumber.size();
		_localVarNumber[name] = number;
		return number;
	} else {
		return var->second;
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
			}
		}

		// Troca label da instrucao pelo numero da instrucao
		if ((*instruction)->_label != -1) {
			(*instruction)->_label = instruction - _instructionList.begin();
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
