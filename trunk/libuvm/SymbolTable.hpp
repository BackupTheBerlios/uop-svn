#ifndef LIBUVM_SYMBOL_TABLE_HPP
#define LIBUVM_SYMBOL_TABLE_HPP

#include <string>
#include <map>
#include <vector>

#include "LibuvmDefs.hpp"
#include "Symbol.hpp"
#include "BinString.hpp"

class CSymbolTable
{
public:
	CSymbolTable();
	~CSymbolTable();
	size_t getSymbolType(std::string name, LiteralType type);
	size_t getSymbolIndex(std::string name, LiteralType type);
	CSymbol* getSymbol(std::string name, LiteralType type);
	CSymbol* getSymbolByIndex(size_t index);
	std::string toTextAssembly();
	void saveBytecode(CBinString& bytecode);
	bool loadBytecode(CBinString& bytecode);
	std::string getStandardValue(std::string symbol, LiteralType type);
private:
	std::map<std::string, CSymbol*> _symbolList;
	std::vector<CSymbol*> _symbolListByIndex;
};

#endif

