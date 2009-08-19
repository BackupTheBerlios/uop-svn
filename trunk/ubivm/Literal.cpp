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
#include <map>

#include <sys/types.h>

#include "Literal.hpp"

#include "Tools.hpp"

//static size_t typeSizeList[] = {
//{ 
//};

CLiteral::CLiteral(const CLiteral& literal)
{
	_type = literal._type;
	_value = literal._value;
	if (_type == StringType) {
		_value.stringValue = new std::string();
		*_value.stringValue = *literal._value.stringValue;
	}
}

CLiteral::CLiteral(LiteralType type, const void* value)
{
	setValue(type, value);
}

CLiteral::CLiteral(LiteralType type)
	: _type(type)
{
	//std::cout << "Adicionando tipo " << _type << std::endl;
	if (_type == StringType) {
		_value.stringValue = new std::string();
	} else if (_type == IntegerType) {
		_value.integerValue = 0;
	} else if (_type == RealType) {
		_value.realValue = 0.0;
	} else if (_type == BooleanType) {
		_value.booleanValue = false;
	} else if (_type == ElementType) {
		_value.elementValue = new CElement();
	} else if (_type == UserdataType) {
		//_value.elementValue = new CElement();
		//TODO: userdata
	}
}


CLiteral::~CLiteral()
{
}

const void* CLiteral::getValue()
{
	if (_type == StringType) {
		return _value.stringValue;
	} else if (_type == ElementType) {
		return _value.elementValue;
	} else {
		return &_value;
	}
	//TODO: userdata
}

// void CLiteral::setValue(const void* value)
// {
// }

void CLiteral::setValue(LiteralType type, const void* value)
{
	_type = type;

	if (_type == StringType) {
		_value.stringValue = new std::string();
		*_value.stringValue = *((std::string*) value);
		//std::cout << "Literal string contendo " << *_value.stringValue << std::endl;
	} else if (_type == ElementType) {
		_value.elementValue = ((CElement*) value);
// 		std::cout << "Element contendo " << _value.elementValue << std::endl;
	} else {
		std::map<LiteralType, size_t> typeSizeMap;

		typeSizeMap[IntegerType] = sizeof(int);
		typeSizeMap[RealType] = sizeof(double);
		typeSizeMap[BooleanType] = sizeof(bool);
//		typeSizeMap[ElementType] = sizeof(CElement*);

		memcpy(&_value, value, typeSizeMap[type]);
	}
	// TODO: userdata
}

std::string CLiteral::getText()
{
	if ( _type == StringType) {
		return *_value.stringValue;
	} else if (_type == IntegerType) {
		return itoa(_value.integerValue);
	} else if (_type == RealType) {
		return ftoa(_value.realValue);
	} else if (_type == BooleanType) {
		// TODO: fazer conversao descente...
		if (_value.booleanValue == true) {
			return "true";
		} else {
			return "false";
		}
	} else if (_type == ElementType) {
		return "Element*";
	}
	// TODO: userdata
	return "Invalid literal value !!!";
}

std::string CLiteral::getString()
{
	return *_value.stringValue;
}

int CLiteral::getInteger()
{
	return _value.integerValue;
}

double CLiteral::getReal()
{
	return _value.realValue;
}

bool CLiteral::getBoolean()
{
	return _value.booleanValue;
}

CElement* CLiteral::getElement()
{
// 	std::cout << "getElement: " << _value.elementValue << std::endl;
	return _value.elementValue;
}
