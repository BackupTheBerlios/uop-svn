#include "Tuple.hpp"


CTuple::CTuple()
{
}


void CTuple::addKeyAtEnd(std::string name)
{
	_keyList.push_front(name);
}


void CTuple::addValueAtEnd(std::string name)
{
	_valueList.push_front(name);
}


std::string CTuple::getComposedKey()
{
	std::string result;

	for(std::list<std::string>::iterator key = _keyList.begin(); key != _keyList.end(); key++) {
		if (key != _keyList.begin()) {
			result += "::";
		}
		result += (*key);
	}

	return result;
}


std::string CTuple::getComposedValues()
{
	std::string result;

	for(std::list<std::string>::iterator value = _valueList.begin(); value != _valueList.end(); value++) {
		if (value != _valueList.begin()) {
			result += "::";
		}
		result += (*value);
	}

	return result;
}
