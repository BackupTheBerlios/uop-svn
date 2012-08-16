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
#include "Element.hpp"

CElement::CElement(CEntityDefinition* entity)
	: _entity(entity), _thread(NULL)
{
	// Define as propriedades
	for(std::vector<CPropertyDefinition*>::iterator prop = _entity->_propertyList.begin();
		prop != _entity->_propertyList.end(); prop++) {
		_propertyList.push_back(CLiteral((*prop)->_type));
	}
}

CElement::~CElement()
{
}

void CElement::bind_event(std::string event_name, CElement* element, CMethodDefinition* method)
{
	_events[event_name] = std::pair<CElement*, CMethodDefinition*>(element, method);
}

void CElement::run_event(std::string event_name)
{
	std::map<std::string, std::pair<CElement*, CMethodDefinition*> >::iterator event = _events.find(event_name);
	if (event != _events.end()) {
		std::cout << "Tem evento " << event_name << " para ser executado !!!" << std::endl;
	}
}

std::pair<CElement*, CMethodDefinition*> CElement::get_event(std::string event_name)
{
	std::map<std::string, std::pair<CElement*, CMethodDefinition*> >::iterator event = _events.find(event_name);
	if (event != _events.end()) {
		return event->second;
	} else {
		return std::pair<CElement*, CMethodDefinition*>(NULL, NULL);
	}
}


