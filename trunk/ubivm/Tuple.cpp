#include "Tuple.hpp"


CTuple::CTuple()
{
}


void CTuple::addKeyAtBegin(CLiteral name)
{
	_keyList.insert(_keyList.begin(), name);
}


void CTuple::addValueAtBegin(CLiteral name)
{
	_valueList.insert(_valueList.begin(), name);
}


void CTuple::addKeyAtEnd(CLiteral name)
{
	_keyList.push_back(name);
// 	_keyList.insert(_keyList.begin(), name);
}


void CTuple::addValueAtEnd(CLiteral name)
{
	_valueList.push_back(name);
// 	_valueList.insert(_valueList.begin(), name);
}


std::string CTuple::getComposedKeys()
{
	std::string result;

	for(std::vector<CLiteral>::iterator key = _keyList.begin(); key != _keyList.end(); key++) {
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

	for(std::vector<CLiteral>::iterator value = _valueList.begin(); value != _valueList.end(); value++) {
		if (value != _valueList.begin()) {
			result += "::";
		}
		result += (*value).getText();
	}

	return result;
}
