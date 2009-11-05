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
#include <sstream>

#include "InstructionDefinition.hpp"

//namespace ASSEMBLY_DEFINITION {

const int MAX_MNEMONIC_SIZE = 12;

enum OpcodeArgumentType {
	NoOpcodeArgumentType = 0,
	VariableOpcodeArgumentType = 1,
	ConstantOpcodeArgumentType = 2,
	LabelOpcodeArgumentType    = 3,
	ParameterOpcodeArgumentType = 4, // TODO: se unificar a tabela de simbolos, talvez esse tipo nao seja mais necessario...
	NumberOpcodeArgumentType = 5,
 	PropertyOpcodeArgumentType = 6
};

typedef struct Mnemonic_t {
	OpcodeType _opcode;
	char _mnemonic[ MAX_MNEMONIC_SIZE ];
	OpcodeArgumentType _argType;
	const char *mnemonic( )
	{
		return _mnemonic;
	}
	OpcodeArgumentType argType( )
	{
		return _argType;
	}
	int size( )
	{
		return _argType == NoOpcodeArgumentType ? 1 : 2;
	}
};

static Mnemonic_t opcodeListDesc [ ] = {
//	{ "nop", NoOpcodeArgumentType },
//	{ "hlt", NoOpcodeArgumentType },
//	{ "ret", NoOpcodeArgumentType },
	{ LDCONST_OPCODE, "ldconst", ConstantOpcodeArgumentType },
	{ LCALL_OPCODE, "lcall", ConstantOpcodeArgumentType },
	{ MCALL_OPCODE, "mcall", ConstantOpcodeArgumentType },
	{ STOP_OPCODE, "stop", NoOpcodeArgumentType },
	{ RET_OPCODE, "ret", NoOpcodeArgumentType },
	{ ADD_OPCODE, "add", NoOpcodeArgumentType },
	{ SUB_OPCODE, "sub", NoOpcodeArgumentType },
	{ OR_OPCODE, "or", NoOpcodeArgumentType },
	{ AND_OPCODE, "and", NoOpcodeArgumentType },
	{ EQ_OPCODE, "eq", NoOpcodeArgumentType },
	{ NE_OPCODE, "ne", NoOpcodeArgumentType },
	{ GT_OPCODE, "gt", NoOpcodeArgumentType },
	{ GE_OPCODE, "ge", NoOpcodeArgumentType },
	{ LT_OPCODE, "lt", NoOpcodeArgumentType },
	{ LE_OPCODE, "le", NoOpcodeArgumentType },
	{ DIV_OPCODE, "div", NoOpcodeArgumentType },
	{ MUL_OPCODE, "mul", NoOpcodeArgumentType },
	{ MOD_OPCODE, "mod", NoOpcodeArgumentType },
	{ LDVAR_OPCODE, "ldvar", VariableOpcodeArgumentType },
	{ STVAR_OPCODE, "stvar", VariableOpcodeArgumentType },
	{ STRESULT_OPCODE, "stresult", NumberOpcodeArgumentType },
	{ LDPARAM_OPCODE, "ldpar", ParameterOpcodeArgumentType },
	{ STPARAM_OPCODE, "stpar", ParameterOpcodeArgumentType },
	{ IFNOT_OPCODE, "ifnot", LabelOpcodeArgumentType },
	{ IF_OPCODE, "if", LabelOpcodeArgumentType },
	{ JMP_OPCODE, "jmp", LabelOpcodeArgumentType },
	{ NEWELEM_OPCODE, "newelem", ConstantOpcodeArgumentType },
	{ LDSELF_OPCODE, "ldself", NoOpcodeArgumentType },
	{ BINDG_OPCODE, "bindg", NoOpcodeArgumentType },
	{ LEAVEG_OPCODE, "leaveg", NoOpcodeArgumentType },
	{ DATAAF_OPCODE, "dataaf", NoOpcodeArgumentType },
	{ DATADQU_OPCODE, "datadqu", NoOpcodeArgumentType },
	{ DATAQU_OPCODE,    "dataqu",    NoOpcodeArgumentType },
	{ DATANBQU_OPCODE,    "datanbqu",    NoOpcodeArgumentType },
	{ DATANBDQU_OPCODE,    "datanbdqu",    NoOpcodeArgumentType },
	{ DATALIST_OPCODE,  "datalist",  NoOpcodeArgumentType },
	{ PUBLISHS_OPCODE, "publishs", ConstantOpcodeArgumentType },
	{ SCALL_OPCODE, "scall", ConstantOpcodeArgumentType },
	{ FINDS_OPCODE, "finds", NoOpcodeArgumentType },
	{ BINDS_OPCODE,     "binds",     NoOpcodeArgumentType },
	{ LDCONTEXT_OPCODE, "ldcontext", ConstantOpcodeArgumentType },
	{ STCONTEXT_OPCODE, "stcontext", ConstantOpcodeArgumentType },
	{ STTAB_OPCODE,     "sttab",     VariableOpcodeArgumentType },
	{ LDTAB_OPCODE,     "ldtab",     VariableOpcodeArgumentType },
	{ LDTUPLEK_OPCODE,  "ldtuplek",  VariableOpcodeArgumentType },
	{ LDTUPLEV_OPCODE,  "ldtuplev",  VariableOpcodeArgumentType },
	{ STTUPLEK_OPCODE,  "sttuplek",  VariableOpcodeArgumentType },
	{ STTUPLEV_OPCODE,  "sttuplev",  VariableOpcodeArgumentType },
	{ TABSIZE_OPCODE,   "tabsize",   VariableOpcodeArgumentType },
	{ LDPROP_OPCODE,    "ldprop",    PropertyOpcodeArgumentType },
	{ STPROP_OPCODE,    "stprop",    PropertyOpcodeArgumentType },
	{ BELEMENTEV_OPCODE, "belementev", VariableOpcodeArgumentType },
	{ BCONTEXTEV_OPCODE, "bcontextev", ConstantOpcodeArgumentType },
	{ BGROUPEV_OPCODE,   "bgroupev",   NoOpcodeArgumentType },
/*	{ LDIDENTITY_OPCODE, "ldidentity", ConstantOpcodeArgumentType },
	{ LDLOCATION_OPCODE, "ldlocation", ConstantOpcodeArgumentType },
	{ LDTIME_OPCODE, "ldtime", ConstantOpcodeArgumentType },
	{ LDACTIVITY_OPCODE, "ldactivity", ConstantOpcodeArgumentType },*/
	{ INVALID_OPCODE,   "invalid",   NoOpcodeArgumentType }
};


CInstructionDefinition::CInstructionDefinition(CSymbolTable *symbolTable, LabelType label, OpcodeType opcode, ArgType arg1)
	: _symbolTable(symbolTable), _label(label), _opcode(opcode), _arg1(arg1)
{
}


CInstructionDefinition::CInstructionDefinition(CSymbolTable *symbolTable)
	: _symbolTable(symbolTable), _label(-1)
{
}

CInstructionDefinition::~CInstructionDefinition()
{
}

int CInstructionDefinition::opcodeIndex(OpcodeType opcode)
{
	// TODO: implementacao ineficiente... mas eh um teste apenas...
	for(size_t pos = 0; opcodeListDesc[pos]._opcode != -1; pos++) {
		if (opcodeListDesc[pos]._opcode == opcode) {
			return pos;
		}
	}

	return -1;
}

std::string CInstructionDefinition::getTextOpcode()
{
	int pos = opcodeIndex(_opcode);
	if (pos != -1) {
		return opcodeListDesc[pos]._mnemonic;
	} else {
		return "???";
	}
}


std::string CInstructionDefinition::toTextAssembly(const std::vector<CPropertyDefinition*> &propertyList, const std::vector<CLocalVarDefinition*> &localVarList, const std::vector<CParameterDefinition*> &paramList)
{
	std::stringstream result;

	result << "\t";
	if (_label != -1) {
		result << _label;
		result << ":\t";
	} else {
		result << "\t";
	}
	// TODO: implementacao ineficiente... mas eh um teste apenas...
	int pos = opcodeIndex(_opcode);
	if (pos != -1) {
		result << opcodeListDesc[pos]._mnemonic;
		if (opcodeListDesc[pos].size() > 1) {
//			result << " " << _arg1 << " [" << "]";
			if (opcodeListDesc[pos]._argType == ConstantOpcodeArgumentType) {
				result << " " << _arg1 << " --> [" << _symbolTable->getSymbolByIndex(_arg1)->_name << "]"; //opcodeListDesc[pos].argType();
			} else if (opcodeListDesc[pos]._argType == VariableOpcodeArgumentType) {
// 				std::cout << "arg1=" << _arg1 << " localVarList.size()=" << localVarList.size() << std::endl;
				result << " " << _arg1 << " --> [" << localVarList[_arg1]->_name << "]";
//				result << " LocalVar[" << _arg1 << "]";
			} else if (opcodeListDesc[pos]._argType == PropertyOpcodeArgumentType) {
				result << " " << _arg1 << " --> [" << propertyList[_arg1]->_name << "]";
			} else if (opcodeListDesc[pos]._argType == ParameterOpcodeArgumentType) {
// 				std::cout << "arg1=" << _arg1 << " paramList.size()=" << paramList.size() << std::endl;
				result << " " << _arg1 << " --> [" << paramList[_arg1]->_name << "]";
			} else if (opcodeListDesc[pos]._argType == LabelOpcodeArgumentType) {
				result << " " << _arg1 << " --> [" << _arg1 << "]";
			} else if (opcodeListDesc[pos]._argType == NumberOpcodeArgumentType) {
				result << " " << _arg1;
			}
		}
		result << "\n";
		return result.str();
	}

	return "Invalid instruction !!!\n";
}

void CInstructionDefinition::saveBytecode(CBinString& bytecode)
{
	bytecode.save(&_opcode, sizeof(_opcode));

	if (opcodeListDesc[opcodeIndex(_opcode)].size() > 1) {
		bytecode.save(&_arg1, sizeof(_arg1));
//		bytecode.save(_arg1);
	}
}

bool CInstructionDefinition::loadBytecode(CBinString& bytecode)
{
	bytecode.load(&_opcode, sizeof(_opcode));

	if (opcodeListDesc[opcodeIndex(_opcode)].size() > 1) {
		bytecode.load(&_arg1, sizeof(_arg1));
//		bytecode.load(&_arg1);
	}

	return true;
}
