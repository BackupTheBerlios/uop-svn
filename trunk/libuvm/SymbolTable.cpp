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

#include "SymbolTable.hpp"

#include "Tools.hpp"


size_t CSymbolTable::getSymbolType(std::string name, LiteralType type)
{
	return 0;
}

size_t CSymbolTable::getSymbolIndex(std::string name, LiteralType type)
{
	return getSymbol(name, type)->_index;
}

std::string CSymbolTable::getStandardValue(std::string symbol, LiteralType type)
{
	if (type == IntegerType) {
		symbol = itoa(atoi(symbol.c_str()));
	} else if (type == RealType) {
		symbol = ftoa(atof(symbol.c_str()));
	}

	return symbol;
}

CSymbol* CSymbolTable::getSymbol(std::string name, LiteralType type)
{
	name = getStandardValue(name, type);
	std::string key;
	key += type;
	key += "::";
	key += name;
//	std::cout << "Buscando simbolo chave " << key << std::endl;
	std::map<std::string, CSymbol*>::iterator symbolFound = _symbolList.find(key);
	CSymbol* symbol;
	if (symbolFound == _symbolList.end()) {
		symbol = new CSymbol(name, type, _symbolListByIndex.size());
		_symbolList[key] = symbol;
//		std::cout << "Adicionando simbolo chave " << key << " nome " << symbol->_name << " index " << symbol->_index << std::endl;
		_symbolListByIndex.push_back(symbol);
		return symbol;
	} else {
		return symbolFound->second;
	}
}

CSymbol* CSymbolTable::getSymbolByIndex(size_t index)
{
	return _symbolListByIndex[index];
}

CSymbolTable::CSymbolTable()
{
}

CSymbolTable::~CSymbolTable()
{
}

//COPIADO GPT
//
//bool CSymbolTable::readFromBinary(CBinString &bin)
//{
//   int size;
//   bin.readInt(size);
//   for (int count=0; count < size; count++) {
//      CSymbol *symbol = new CSymbol();
//      symbol->readFromBinary(bin);
//      add(symbol);
//   }
//   return true;
//}

std::string CSymbolTable::toTextAssembly()
{
	std::string result;

	result += ".constant_pool\n";

	for(std::vector<CSymbol*>::iterator symbol = _symbolListByIndex.begin();
		symbol != _symbolListByIndex.end(); symbol++) {
		result += "\t" + (*symbol)->toTextAssembly() + "\n";
	}

// 	for(std::map<std::string, CSymbol*>::iterator symbol = _symbolList.begin();
// 		symbol != _symbolList.end(); symbol++) {
// 		result += "\t";
// 		result += symbol->second->toTextAssembly();
// 	}

	result += ".end\n";

	return result;
}

void CSymbolTable::saveBytecode(CBinString& bytecode)
{
	// Salva o numero de simbolos
	size_t symbolCount = _symbolListByIndex.size();
	bytecode.save(&symbolCount, sizeof(symbolCount));

	// Salva os simbolos
	for(std::vector<CSymbol*>::iterator symbol = _symbolListByIndex.begin(); symbol != _symbolListByIndex.end(); symbol++) {
		(*symbol)->saveBytecode(bytecode);
	}
}

bool CSymbolTable::loadBytecode(CBinString& bytecode)
{
	// Carrega o numero de simbolos
	size_t symbolCount;
	bytecode.load(&symbolCount, sizeof(symbolCount));

	// Carrega os simbolos
	for(u_int count = 0; count < symbolCount; count++) {
		std::string key;
		CSymbol* symbol = new CSymbol();
		symbol->loadBytecode(bytecode);
		key += symbol->_type;
		key += "::";
		key += symbol->_name;
		symbol->_index = _symbolListByIndex.size();
		_symbolList[key] = symbol;
//		std::cout << "Adicionando simbolo chave " << key << " nome " << symbol->_name << " index " << symbol->_index << std::endl;
		_symbolListByIndex.push_back(symbol);
	}

	return true;
}

