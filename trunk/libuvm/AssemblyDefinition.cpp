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
#include <fstream>
#include <sstream>

#include <boost/foreach.hpp>
#include <boost/tuple/tuple.hpp>
#define foreach BOOST_FOREACH

#include "AssemblyDefinition.hpp"
#include "BinString.hpp"
#include "Log.hpp"

//namespace ASSEMBLY_DEFINITION {

CAssemblyDefinition::CAssemblyDefinition()
{
	_header = new CUvmHeader(0x1234, "UVM Version 0.1", 0x0001);
}


CAssemblyDefinition::~CAssemblyDefinition()
{
}


//}

CEntityDefinition *CAssemblyDefinition::addEntity(std::string name)
{
	CEntityDefinition* entity = new CEntityDefinition(&_symbolTable, name);
	_entityList.push_back(entity);

	entity->getSymbolIndex(name, StringType);

	return entity;
}


int CAssemblyDefinition::load(void * buffer, size_t bufferSize)
{
	return 1;
}

int CAssemblyDefinition::optimize()
{
	return 1;
}

std::string CAssemblyDefinition::toTextAssembly(bool high_level)
{
	std::string result;

	if (high_level == false) {
		result += _symbolTable.toTextAssembly();
	}

	foreach(CEntityDefinition* entity, _entityList) {
		result += entity->toTextAssembly(high_level);
	}

	return result;
}

int CAssemblyDefinition::saveBytecode(std::string name)
{
	CBinString bytecode;

	_header->setEntitiesCount(_entityList.size());
	_header->saveBytecode(bytecode);

	_symbolTable.saveBytecode(bytecode);

	foreach(CEntityDefinition* entity, _entityList) {
		entity->saveBytecode(bytecode);
	}

	std::ofstream out(name.c_str(), std::ios_base::out);

	out << bytecode.getData();

	return 0;
}

bool CAssemblyDefinition::loadBytecode(std::string name)
{
	std::ifstream in(name.c_str(), std::ios::in|std::ios::binary);
	std::stringstream buf;

	CBinString bytecode;
	buf << in.rdbuf();

	bytecode.assign(buf.str());

	if (!_header->loadBytecode(bytecode)) {
		CLog::log("Erro lendo header !!!");
		// ERRO
		return false;
	}

	_symbolTable.loadBytecode(bytecode);

	for(uint count = 0; count < _header->getEntitiesCount(); count++) {
		CEntityDefinition* entity = new CEntityDefinition(&_symbolTable);
		entity->loadBytecode(bytecode);
		_entityList.push_back(entity);
	}

	return true;
}

CEntityDefinition* CAssemblyDefinition::getEntity(std::string name)
{
	foreach(CEntityDefinition* entity, _entityList) {
		if (entity->getName() == name) {
			return entity;
		}
	}

	return NULL;
}


void CAssemblyDefinition::addImport(std::string name)
{
	_importList[name] = "";
}

bool CAssemblyDefinition::isLibrary(std::string name)
{
	return _importList.find(name) != _importList.end();
}
