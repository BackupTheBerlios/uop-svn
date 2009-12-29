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

void CTuple::saveBytecode(CBinString& bytecode)
{
	size_t size;

	// Packing keys count
	size = _keyList.size();
	bytecode.save(&size, sizeof(size));

	// Packing keys
	for(size_t key = 0; key < _keyList.size(); key++) {
		_keyList[key].saveBytecode(bytecode);
	}

	// Packing values count
	size = _valueList.size();
	bytecode.save(&size, sizeof(size));

	// Packing values
	for(size_t value = 0; value < _valueList.size(); value++) {
		_valueList[value].saveBytecode(bytecode);
	}
}


bool CTuple::loadBytecode(CBinString& bytecode)
{
	size_t size;

	// Unpacking keys count
	bytecode.load(&size, sizeof(size));

	// Unpacking keys
	for(size_t key = 0; key < size; key++) {
		CLiteral key;
		key.loadBytecode(bytecode);
		_keyList.push_back(key);
	}

	// Unpacking values count
	bytecode.load(&size, sizeof(size));

	// Unpacking values
	for(size_t value = 0; value < size; value++) {
		CLiteral value;
		value.loadBytecode(bytecode);
		_valueList.push_back(value);
	}

	return true;
}
