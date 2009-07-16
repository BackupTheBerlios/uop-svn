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
#include "LocalVarDefinition.hpp"

#include "Tools.hpp"

CLocalVarDefinition::CLocalVarDefinition(CSymbolTable *symbolTable, size_t index)
	: _symbolTable(symbolTable), _index(index)
{
}


CLocalVarDefinition::CLocalVarDefinition(CSymbolTable *symbolTable, size_t index, LiteralType type, std::string name)
	: _symbolTable(symbolTable), _index(index), _type(type), _name(name)
{
	_symbolTable->getSymbolIndex(_name, StringType);
}


CLocalVarDefinition::~CLocalVarDefinition()
{
}

const std::string typeToText(const LiteralType &type)
{
	if (type == StringType) {
		return "string";
	} else if (type == IntegerType) {
		return "int";
	} else if (type == RealType) {
		return "real";
	} else if (type == BooleanType) {
		return "bool";
	}

	return "ERRO !!!";
}


std::string CLocalVarDefinition::toTextAssembly()
{
	std::string result;

	result += "\t\t\t";
	result += itoa(_index);
	result += " ";
	result += typeToText(_type);
	result += " ";
	result += _name;
	result += "\n";

	return result;
}

void CLocalVarDefinition::saveBytecode(CBinString& bytecode)
{
	u_int indexName = _symbolTable->getSymbolIndex(_name, StringType);

	bytecode.save(&_type, sizeof(_type));
	bytecode.save(&indexName, sizeof(indexName));
}

bool CLocalVarDefinition::loadBytecode(CBinString& bytecode)
{
	u_int indexName;

	bytecode.load(&_type, sizeof(_type));
	bytecode.load(&indexName, sizeof(indexName));

	_name = _symbolTable->getSymbolByIndex(indexName)->_name;

	return true;
}
