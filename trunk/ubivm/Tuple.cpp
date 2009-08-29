#include "Tuple.hpp"


CTuple::CTuple()
{
}


void CTuple::addKeyAtEnd(CLiteral name)
{
	_keyList.push_front(name);
}


void CTuple::addValueAtEnd(CLiteral name)
{
	_valueList.push_front(name);
}


std::string CTuple::getComposedKey()
{
	std::string result;

	for(std::list<CLiteral>::iterator key = _keyList.begin(); key != _keyList.end(); key++) {
		if (key != _keyList.begin()) {
			result += "::";
		}
		result += (*key).getText();
	}

	return result;
}


std::string CTuple::getComposedValues()
{
	std::string result;

	for(std::list<CLiteral>::iterator value = _valueList.begin(); value != _valueList.end(); value++) {
		if (value != _valueList.begin()) {
			result += "::";
		}
		result += (*value).getText();
	}

	return result;
}
