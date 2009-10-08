#ifndef LIBUVM_ENTITY_DEFINITION_HPP
#define LIBUVM_ENTITY_DEFINITION_HPP

// namespace ASSEMBLY_DEFINITION {

#include <vector>

#include "SymbolTable.hpp"
#include "PropertyDefinition.hpp"
#include "MethodDefinition.hpp"
#include "LibuvmDefs.hpp"
#include "BinString.hpp"

class CEntityDefinition
{
public:
	CEntityDefinition();
	CEntityDefinition(std::string name);
	CPropertyDefinition *addProperty(VisibilityType visibility, LiteralType type, std::string name);
	CMethodDefinition *addMethod(VisibilityType visibility, std::string name);
	size_t getSymbolIndex(std::string name, LiteralType type);
	SymbolType getSymbolType(std::string name);
	CSymbol* getSymbolByIndex(size_t index);
	std::string toTextAssembly();
	void saveBytecode(CBinString& bytecode);
	bool loadBytecode(CBinString& bytecode);
	CMethodDefinition* getMethod(std::string name);
	std::string getName() const
	{
		return _name;
	}
	bool isParallel() const;
private:
	std::vector<CPropertyDefinition*> _propertyList;
	std::vector<CMethodDefinition*> _methodList;
	std::string _name;
	CSymbolTable _symbolTable;
};

#endif

