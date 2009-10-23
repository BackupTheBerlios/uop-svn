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
#include "EntityDefinition.hpp"

#include <iostream>

#pragma pack(1)

typedef struct SEntityHeader {
	u_int indexName;       // Indice na constant pool que contem o nome da entidade
	u_int optionsCount;    // Numero de opcoes
	u_int propertiesCount; // Numero de propriedades
	u_int methodsCount;    // Numero de metodos
};

#pragma pack()


CEntityDefinition::CEntityDefinition()
{
}

CEntityDefinition::CEntityDefinition(std::string name)
	: _name(name)
{
}

CPropertyDefinition * CEntityDefinition::addProperty(VisibilityType visibility, LiteralType type, std::string name)
{
	CPropertyDefinition* property = new CPropertyDefinition(visibility, type, name);
	_propertyList.push_back(property);

	return property;
}

CMethodDefinition * CEntityDefinition::addMethod(VisibilityType visibility, std::string name)
{
	CMethodDefinition* method = new CMethodDefinition(&_symbolTable, visibility, name);
	_methodList.push_back(method);

	return method;
}

std::string CEntityDefinition::toTextAssembly()
{
	std::string result;
	result += "Entity " + _name + '\n';

	if (_optionList.size() == 0) {
		result += "\tNo options\n";
	} else {
		result += "\tOptions\n";

		for(std::map<std::string, std::string>::iterator option = _optionList.begin(); option != _optionList.end(); option++) {
			result += std::string("\t\t") + option->first + "\n";
		}

		result += "\tEnd\n";
	}

	result += _symbolTable.toTextAssembly();

	for(std::vector<CMethodDefinition*>::iterator method = _methodList.begin(); method != _methodList.end(); method++) {
		result += (*method)->toTextAssembly();
	}

	result += "End\n";

	return result;
}

void CEntityDefinition::saveBytecode(CBinString& bytecode)
{
	_symbolTable.saveBytecode(bytecode);

	SEntityHeader header;

	memset(&header, 0, sizeof(header));

	header.indexName       = _symbolTable.getSymbolIndex(_name, StringType);
	header.optionsCount    = _optionList.size();
	header.propertiesCount = _propertyList.size();
	header.methodsCount    = _methodList.size();

	// Salva o header da entidade
	bytecode.save(&header, sizeof(header));

	// Salva as opcoes
	for(std::map<std::string, std::string>::iterator option = _optionList.begin(); option != _optionList.end(); option++) {
		bytecode.save(option->first);
//  		std::cout << "salvando a opcao " << option->first << std::endl;
	}

	// Salva as propriedades
	for(std::vector<CPropertyDefinition*>::iterator property = _propertyList.begin(); property != _propertyList.end(); property++) {
		(*property)->saveBytecode(bytecode);
	}

	// Salva os metodos
	for(std::vector<CMethodDefinition*>::iterator method = _methodList.begin(); method != _methodList.end(); method++) {
		(*method)->saveBytecode(bytecode);
	}
}

bool CEntityDefinition::loadBytecode(CBinString& bytecode)
{
	_symbolTable.loadBytecode(bytecode);

	SEntityHeader header;

	// Carrega o header da entidade
	bytecode.load(&header, sizeof(header));

	_name = _symbolTable.getSymbolByIndex(header.indexName)->_name;

	// Carrega as opcoes
	for(u_int count = 0; count < header.optionsCount; count++) {
		std::string option;
		bytecode.load(option);
//  		std::cout << this << ": carregando a opcao " << option << std::endl;
		_optionList[option] = "true";
	}

	// Carrega as propriedades
	for(u_int count = 0; count < header.propertiesCount; count++) {
		CPropertyDefinition* property = new CPropertyDefinition();
		property->loadBytecode(bytecode);
		_propertyList.push_back(property);
	}

	// Carrega os metodos
	for(u_int count = 0; count < header.methodsCount; count++) {
		CMethodDefinition* method = new CMethodDefinition(&_symbolTable);
		method->loadBytecode(bytecode);
		_methodList.push_back(method);
	}

	return true;
}

size_t CEntityDefinition::getSymbolIndex(std::string name, LiteralType type)
{
	return _symbolTable.getSymbolIndex(name, type);
}

SymbolType CEntityDefinition::getSymbolType(std::string name)
{
	return (SymbolType)999;
}

CMethodDefinition* CEntityDefinition::getMethod(std::string name)
{
	for(std::vector<CMethodDefinition*>::iterator method = _methodList.begin(); method != _methodList.end(); method++) {
		if ((*method)->getName() == name) {
			return (*method);
		}
	}

	return NULL;
}


CSymbol* CEntityDefinition::getSymbolByIndex(size_t index)
{
	return _symbolTable.getSymbolByIndex(index);
}


bool CEntityDefinition::isParallel()
{
	// TODO: corrigir depois...
// 	std::cout << _name << ":" << this << ": parallel=" << _optionList["parallel"] << std::endl;
	return (_optionList["parallel"] == "true");
//	return (_name == "concorrente");
}


void CEntityDefinition::setOption(std::string option)
{
// 	std::cout << "setando opcao " << option << " para true" << std::endl;
	_optionList[option]="true";
}
