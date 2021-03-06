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
#include "ParameterDefinition.hpp"
#include "LibUvmCommon.hpp"
#include "Tools.hpp"

//namespace ASSEMBLY_DEFINITION {

CParameterDefinition::CParameterDefinition(CSymbolTable* symbolTable, size_t index, LiteralType type, std::string name)
	: _symbolTable(symbolTable), _index(index), _type(type), _name(name)
{
	_symbolTable->getSymbolIndex(_name, StringType); // forca o simbolo a ser criado na tabela de simbolos
}

CParameterDefinition::CParameterDefinition(CSymbolTable*symbolTable, size_t index)
	: _symbolTable(symbolTable), _index(index)
{
}


CParameterDefinition::~CParameterDefinition()
{
}

void CParameterDefinition::saveBytecode(CBinString& bytecode)
{
	u_int indexName = _symbolTable->getSymbolIndex(_name, StringType);

	bytecode.save(&_type, sizeof(_type));
	bytecode.save(&indexName, sizeof(indexName));
}

bool CParameterDefinition::loadBytecode(CBinString& bytecode)
{
	u_int indexName;

	bytecode.load(&_type, sizeof(_type));
	bytecode.load(&indexName, sizeof(indexName));

	_name = _symbolTable->getSymbolByIndex(indexName)->_name;

	return true;
}

std::string CParameterDefinition::toTextAssembly()
{
	std::string result;

	result += itoa(_index);
	result += " ";
	result += typeToText(_type);
	result += " ";
	result += _name;

	return result;
}

//}
