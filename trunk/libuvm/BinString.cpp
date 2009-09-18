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
#include "BinString.hpp"

CBinString::CBinString()
	: _data("")
{
}

CBinString::~CBinString()
{
}

void CBinString::save(const void* data, size_t size)
{
	_data += std::string((char*)data, size);
}

void CBinString::load(const void* data, size_t size)
{
	_data.copy((char*)data, size);
//	_data.erase(size);
	_data.erase(0, size);
}

void CBinString::assign(std::string data)
{
	_data = data;
}


void CBinString::load(std::string& data)
{
	size_t size;
	load(&size, sizeof(size));
	char* buffer = new char[size];
	load(buffer, size);
	data = std::string(buffer, size);
	delete []buffer;
}
