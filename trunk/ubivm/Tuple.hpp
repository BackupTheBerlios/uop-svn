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

#ifndef UBIVM_TUPLE_HPP
#define UBIVM_TUPLE_HPP

#include <string>
#include <list>

/**
	@author Alex Sandro Garzão <alexgarzao@gmail.com>
*/
class CTuple{
public:
	CTuple();
	void addKeyAtEnd(std::string name);
	void addValueAtEnd(std::string name);
	std::string getComposedKey();
	std::string getComposedValues();

	std::list<std::string> _keyList;
	std::list<std::string> _valueList;
};

#endif
