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

#ifndef UBIVM_GROUP_HPP
#define UBIVM_GROUP_HPP

#include <string>
#include <set>
#include <map>
// #include "LibuvmDefs.hpp"
// #include "Element.hpp"
#include "Tuple.hpp"

/**
	@author Alex Sandro Garzão <alexgarzao@gmail.com>
*/
class CGroup{
public:
	CGroup(std::string name);
	void addObject(std::string name);
	void remObject(std::string name);
	void addTuple(CTuple* tuple);
	void remTuple(CTuple* tuple);
	CTuple* getTuple(CTuple* tuple);
	CTuple* findTuple(CTuple* tuple);
	void addService(std::string serviceName, std::string element);
	std::string findService(std::string serviceName);
	void run_insert_data_event(std::string keys, std::string values);
	void run_insert_service_event(std::string service_name);

	std::string _name;
	std::set<std::string> _objectList;
	std::map<std::string, CTuple*> _dataList;
	std::map<std::string, std::string> _serviceList;
	std::map<std::string, std::pair<CElement*, CMethodDefinition*> > _events;
};

#endif
