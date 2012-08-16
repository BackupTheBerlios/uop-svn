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
#include "ResultDefinition.hpp"
#include "Tools.hpp"
#include "LibUvmCommon.hpp"

//namespace ASSEMBLY_DEFINITION {

CResultDefinition::CResultDefinition(size_t index)
	: _index(index)
{
}

CResultDefinition::CResultDefinition(size_t index, LiteralType type)
	: _index(index), _type(type)
{
}

CResultDefinition::~CResultDefinition()
{
}

void CResultDefinition::saveBytecode(CBinString& bytecode)
{
	bytecode.save(&_type, sizeof(_type));
}

bool CResultDefinition::loadBytecode(CBinString& bytecode)
{
	bytecode.load(&_type, sizeof(_type));

	return true;
}

std::string CResultDefinition::toTextAssembly()
{
	std::string result;

	result += itoa(_index);
	result += " ";
	result += typeToText(_type);

	return result;
}

//}
