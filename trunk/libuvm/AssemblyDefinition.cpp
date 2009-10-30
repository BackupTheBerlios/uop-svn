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
	CEntityDefinition* entity = new CEntityDefinition(name);
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

std::string CAssemblyDefinition::toTextAssembly()
{
	std::string result;

	foreach(CEntityDefinition* entity, _entityList) {
		result += entity->toTextAssembly();
	}

	return result;
}

int CAssemblyDefinition::saveBytecode(std::string name)
{
	CBinString bytecode;

	_header->setEntitiesCount(_entityList.size());
	_header->saveBytecode(bytecode);
	//bytecode.insert(bytecode.end(), bytecode.begin(), bytecode.end());
	foreach(CEntityDefinition* entity, _entityList) {
		entity->saveBytecode(bytecode);
	}

//	std::cout << "Formato binario com " << bytecode.size() << " bytes:" << std::endl;
//
//	for(size_t pos = 0; pos < bytecode.size(); pos++) {
//		char temp[12];
//		snprintf(temp, 12, " %.2X (%.3d)", bytecode.get(pos), bytecode.get(pos));
//		std::cout << temp << " ";
//		if ((pos+1) % 10 == 0) {
//			std::cout << std::endl;
//		}
//	}
//
//	std::cout << std::endl;

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

//	std::cout << "Formato binario lido com " << bytecode.size() << " bytes:" << std::endl;
//
//	for(size_t pos = 0; pos < bytecode.size(); pos++) {
//		char temp[12];
//		snprintf(temp, 12, " %.2X (%.3d)", bytecode.get(pos), bytecode.get(pos));
//		std::cout << temp << " ";
//		if ((pos+1) % 10 == 0) {
//			std::cout << std::endl;
//		}
//	}
//
//	std::cout << std::endl;

	if (!_header->loadBytecode(bytecode)) {
		CLog::log("Erro lendo header !!!");
		// ERRO
		return false;
	}

	for(uint count = 0; count < _header->getEntitiesCount(); count++) {
		CEntityDefinition* entity = new CEntityDefinition();
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
