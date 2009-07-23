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
#include <sstream>
#include <map>
#include <iostream>

#include "Symbol.hpp"

CSymbol::CSymbol()
{
}

CSymbol::CSymbol(std::string name, LiteralType type, size_t index)
	: _name(name), _type(type), _index(index)
{
	setValue(_type, _name);
}


CSymbol::~CSymbol()
{
}

std::string CSymbol::toTextAssembly()
{
	std::stringstream result;

	result << "\t" << _index << " " << (char)_type << " " << _name << std::endl;

	return result.str();
}

void CSymbol::saveBytecode(CBinString& bytecode)
{
	// Salva o tamanho do simbolo e o simbolo
	size_t symbolSize = _name.size();
	bytecode.save(&symbolSize, sizeof(symbolSize));
	bytecode.save(_name.c_str(), symbolSize);

	// Salva o tipo do simbolo
	bytecode.save(&_type, sizeof(_type));
}

bool CSymbol::loadBytecode(CBinString& bytecode)
{
	// Carrega o tamanho do simbolo e o simbolo
	size_t symbolSize;
	bytecode.load(&symbolSize, sizeof(symbolSize));
	char* buffer = new char[symbolSize+1];
	bytecode.load(buffer, symbolSize);
	buffer[symbolSize] = NULL;
	_name = std::string(buffer).substr(0, symbolSize);

	delete []buffer;

	// Carrega o tipo do simbolo
	bytecode.load(&_type, sizeof(_type));

	setValue(_type, _name);

	return true;
}


//bool CSymbol::loadBytecode(CBinString& bytecode)
//{
//	// Carrega o tamanho do simbolo e o simbolo
//	size_t symbolSize;
//	bytecode.load(&symbolSize, sizeof(symbolSize));
//	char buffer[symbolSize+1];
//	bytecode.load(buffer, symbolSize);
//	buffer[symbolSize+1] = NULL;
//	_name = std::string(buffer).substr(0, symbolSize);
//
//	// Carrega o tipo do simbolo
//	bytecode.load(&_type, sizeof(_type));
//
//	setValue(_type, _name);
//
//	return true;
//}


void CSymbol::setValue(LiteralType type, const void* value)
{
	_type = type;
	
	if (_type == StringType) {
		_value.stringValue = new std::string();
		*_value.stringValue = *((std::string*) value);
//		std::cout << "Simbolo string contendo " << *_value.stringValue << std::endl;
	} else {
		std::map<LiteralType, size_t> typeSizeMap;

		typeSizeMap[IntegerType] = sizeof(int);
		typeSizeMap[RealType] = sizeof(double);
		typeSizeMap[BooleanType] = sizeof(bool);

		memcpy(&_value, value, typeSizeMap[_type]);
	}
}

void CSymbol::setValue(LiteralType type, std::string value)
{
	_type = type;
	
	if ( _type == StringType) {
		_value.stringValue = new std::string();
		*_value.stringValue = value;
//		std::cout << "Simbolo string contendo " << *_value.stringValue << std::endl;
	} else if (_type == IntegerType) {
		_value.integerValue = atoi(value.c_str());
	} else if (_type == RealType) {
		_value.realValue = atof(value.c_str());
	} else if (_type == BooleanType) {
		// TODO: fazer conversao descentemente...
		_value.booleanValue = (value == "true");
	}
}

const void* CSymbol::getValue()
{
	if (_type == StringType) {
		return _value.stringValue;
	} else {
		return &_value;
	}
}

std::string CSymbol::getString()
{
	return *_value.stringValue;
}

int CSymbol::getInteger()
{
	return _value.integerValue;
}

double CSymbol::getReal()
{
	return _value.realValue;
}

bool CSymbol::getBoolean()
{
	return _value.booleanValue;
}

