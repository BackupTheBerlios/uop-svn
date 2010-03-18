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
#include <iomanip>

#include "InstructionDefinition.hpp"

//namespace ASSEMBLY_DEFINITION {

const int MAX_MNEMONIC_SIZE = 12;

enum OpcodeArgumentType {
	NoOpcodeArgumentType        = 0,
	VariableOpcodeArgumentType  = 1,
	ConstantOpcodeArgumentType  = 2,
	SymbolOpcodeArgumentType    = 3,
	LabelOpcodeArgumentType     = 4,
	ParameterOpcodeArgumentType = 5, // TODO: se unificar a tabela de simbolos, talvez esse tipo nao seja mais necessario...
	NumberOpcodeArgumentType    = 6,
 	PropertyOpcodeArgumentType  = 7
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
	{ LCALL_OPCODE, "lcall", SymbolOpcodeArgumentType },
	{ MCALL_OPCODE, "mcall", SymbolOpcodeArgumentType },
	{ EXIT_OPCODE, "exit", NoOpcodeArgumentType },
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
	{ LDPARAM_OPCODE, "ldparam", ParameterOpcodeArgumentType },
	{ STPARAM_OPCODE, "stparam", ParameterOpcodeArgumentType },
	{ IFNOT_OPCODE, "ifnot", LabelOpcodeArgumentType },
	{ IF_OPCODE, "if", LabelOpcodeArgumentType },
	{ JMP_OPCODE, "jmp", LabelOpcodeArgumentType },
	{ NEWELEM_OPCODE, "newelem", SymbolOpcodeArgumentType },
	{ LDSELF_OPCODE, "ldself", NoOpcodeArgumentType },
	{ MJOIN_OPCODE, "mjoin", NoOpcodeArgumentType },
	{ MLEAVE_OPCODE, "mleave", NoOpcodeArgumentType },
	{ CPUBLISH_OPCODE, "cpublish", NoOpcodeArgumentType },
	{ CGET_OPCODE, "cget", NoOpcodeArgumentType },
	{ CFIND_OPCODE,    "cfind",    NoOpcodeArgumentType },
	{ CFINDNB_OPCODE,    "cfindnb",    NoOpcodeArgumentType },
	{ CGETNB_OPCODE,    "cgetnb",    NoOpcodeArgumentType },
	{ CLIST_OPCODE,  "clist",  NoOpcodeArgumentType },
	{ MLIST_OPCODE, "mlist",  NoOpcodeArgumentType },
	{ SLIST_OPCODE, "slist",  NoOpcodeArgumentType },
	{ SPUBLISH_OPCODE, "spublish", NoOpcodeArgumentType },
	{ SREM_OPCODE, "srem", NoOpcodeArgumentType },
	{ SRUN_OPCODE, "runs", NoOpcodeArgumentType },
	{ SFIND_OPCODE, "sfind", NoOpcodeArgumentType },
//	{ SBIND_OPCODE,     "sbind",     NoOpcodeArgumentType },
	{ LDCONTEXTI_OPCODE, "ldcontexti", SymbolOpcodeArgumentType },
	{ STCONTEXTI_OPCODE, "stcontexti", SymbolOpcodeArgumentType },
	{ STTAB_OPCODE,     "sttab",     NoOpcodeArgumentType },
	{ LDTAB_OPCODE,     "ldtab",     NoOpcodeArgumentType },
	{ LDTUPLEK_OPCODE,  "ldtuplek",  VariableOpcodeArgumentType },
	{ LDTUPLER_OPCODE,  "ldtupler",  VariableOpcodeArgumentType },
	{ STTUPLEK_OPCODE,  "sttuplek",  VariableOpcodeArgumentType },
	{ STTUPLER_OPCODE,  "sttupler",  VariableOpcodeArgumentType },
	{ TABSIZE_OPCODE,   "tabsize",   NoOpcodeArgumentType },
	{ LDPROP_OPCODE,    "ldprop",    PropertyOpcodeArgumentType },
	{ STPROP_OPCODE,    "stprop",    PropertyOpcodeArgumentType },
	{ BELEMENTEV_OPCODE, "belementev", VariableOpcodeArgumentType },
	{ BCONTEXTIEV_OPCODE, "bcontextiev", SymbolOpcodeArgumentType },
	{ BCONTEXTEV_OPCODE, "bcontextev",   NoOpcodeArgumentType },
/*	{ LDIDENTITY_OPCODE, "ldidentity", ConstantOpcodeArgumentType },
	{ LDLOCATION_OPCODE, "ldlocation", ConstantOpcodeArgumentType },
	{ LDTIME_OPCODE, "ldtime", ConstantOpcodeArgumentType },
	{ LDACTIVITY_OPCODE, "ldactivity", ConstantOpcodeArgumentType },*/
	{ INVALID_OPCODE,   "invalid",   NoOpcodeArgumentType }
};


CInstructionDefinition::CInstructionDefinition(CSymbolTable *symbolTable, LabelType label, OpcodeType opcode, ArgType arg1)
	: _symbolTable(symbolTable), _label(label), _opcode(opcode), _arg1(arg1), _label_used(false)
{
}


CInstructionDefinition::CInstructionDefinition(CSymbolTable *symbolTable)
	: _symbolTable(symbolTable), _label(-1), _label_used(false)
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


std::string CInstructionDefinition::toTextAssembly(bool high_level, const std::vector<CPropertyDefinition*> &propertyList, const std::vector<CLocalVarDefinition*> &localVarList, const std::vector<CParameterDefinition*> &paramList)
{
	std::stringstream result;

	result << "\t";
	if (_label != -1) {
		result << ":" << std::setw(5) << std::left << _label;
		result << "  ";
	} else {
		result << "        ";
	}

	// TODO: implementacao ineficiente... mas eh um teste apenas...
	int pos = opcodeIndex(_opcode);
	if (pos != -1) {
//		std::cout.setf ( std::ios::left, std::ios::adjustfield );
		result << std::setw(12) << std::left << opcodeListDesc[pos]._mnemonic;
		if (opcodeListDesc[pos].size() > 1) {
			if (high_level == false) {
				if (opcodeListDesc[pos]._argType == ConstantOpcodeArgumentType || opcodeListDesc[pos]._argType == SymbolOpcodeArgumentType) {
					result << " " << _arg1 << " --> [" << _symbolTable->getSymbolByIndex(_arg1)->_name << "]";
				} else if (opcodeListDesc[pos]._argType == VariableOpcodeArgumentType) {
					result << " " << _arg1 << " --> [" << localVarList[_arg1]->_name << "]";
				} else if (opcodeListDesc[pos]._argType == PropertyOpcodeArgumentType) {
					result << " " << _arg1 << " --> [" << propertyList[_arg1]->_name << "]";
				} else if (opcodeListDesc[pos]._argType == ParameterOpcodeArgumentType) {
					result << " " << _arg1 << " --> [" << paramList[_arg1]->_name << "]";
				} else if (opcodeListDesc[pos]._argType == LabelOpcodeArgumentType) {
					result << " " << _arg1 << " --> [" << _arg1 << "]";
				} else if (opcodeListDesc[pos]._argType == NumberOpcodeArgumentType) {
					result << " " << _arg1;
				}
			} else {
				if (opcodeListDesc[pos]._argType == ConstantOpcodeArgumentType) {
					if (_symbolTable->getSymbolByIndex(_arg1)->_type == StringType) {
						result << " \"" << _symbolTable->getSymbolByIndex(_arg1)->_name << "\"";
					} else {
						result << " " << _symbolTable->getSymbolByIndex(_arg1)->_name;
					}
				} else if (opcodeListDesc[pos]._argType == SymbolOpcodeArgumentType) {
					result << " " << _symbolTable->getSymbolByIndex(_arg1)->_name;
				} else if (opcodeListDesc[pos]._argType == VariableOpcodeArgumentType) {
					result << " " << localVarList[_arg1]->_name;
				} else if (opcodeListDesc[pos]._argType == PropertyOpcodeArgumentType) {
					result << " " << propertyList[_arg1]->_name;
				} else if (opcodeListDesc[pos]._argType == ParameterOpcodeArgumentType) {
					result << " " << paramList[_arg1]->_name;
				} else if (opcodeListDesc[pos]._argType == LabelOpcodeArgumentType) {
					result << " " << _arg1;
				} else if (opcodeListDesc[pos]._argType == NumberOpcodeArgumentType) {
					result << " " << _arg1;
				}
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
