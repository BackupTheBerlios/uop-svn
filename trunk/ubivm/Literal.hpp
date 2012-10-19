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
#ifndef UBIVM_LITERAL_HPP
#define UBIVM_LITERAL_HPP

#include <string>

class CLiteral;

#include "LibuvmDefs.hpp"
#include "Element.hpp"
#include "MultiIndex.hpp"


#include "Tuple.hpp"

/**
	@author Alex Sandro Garzão <alexgarzao@gmail.com>
*/
class CLiteral{
public:
	CLiteral();
	CLiteral(const CLiteral& literal);
	CLiteral(LiteralType type, const void* value);
	CLiteral(LiteralType type);
	CLiteral(int value) { setValue(IntegerType, &value); }
	CLiteral(double value) { setValue(RealType, &value); }
	CLiteral(bool value) { setValue(BooleanType, &value); }
	CLiteral(std::string value) { setValue(StringType, &value); }
	CLiteral(char* value) { std::string strvalue(value); setValue(StringType, &strvalue); }
	CLiteral(CElement* value) { setValue(ElementType, value); }
	CLiteral(CMultiIndex<CLiteral>* value) { setValue(TableType, value); }
	CLiteral(CTuple* value) { setValue(TupleType, value); }
	CLiteral(void* value) { setValue(PointerType, value); }
	~CLiteral();
	const void* getValue();
	void setValue(const void* value);
	void setValue(LiteralType type, const void* value);
	std::string getText();
	std::string getString();
	int getInteger();
	double getReal();
	bool getBoolean();
	void saveBytecode(CBinString& bytecode);
	bool loadBytecode(CBinString& bytecode);
	CElement* getElement();
	CMultiIndex<CLiteral>* getTable();  // TODO: deveria retornar o ponteiro ???
	CTuple* getTuple();  // TODO: deveria retornar o ponteiro ???
	void *getPointer();
	void bind_event(std::string event_name, CMethodDefinition* method);
//private:
    LiteralType _type;
	union {
		int integerValue;
		double realValue;
		bool booleanValue;
		std::string* stringValue;
		CElement* elementValue;
		CMultiIndex<CLiteral>* tableValue;
		CTuple* tupleValue;
		void *pointerValue;
	} _value;
	std::map<std::string, CMethodDefinition*> _events;
};

#endif
