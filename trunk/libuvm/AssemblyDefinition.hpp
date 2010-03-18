#ifndef LIBUVM_ASSEMBLY_DEFINITION_HPP
#define LIBUVM_ASSEMBLY_DEFINITION_HPP

#include <string>
#include <vector>
// #include <list>

#include "SymbolTable.hpp"
#include "EntityDefinition.hpp"
#include "UvmHeader.hpp"

//namespace ASSEMBLY_DEFINITION {

class CAssemblyDefinition
{
public:
	CAssemblyDefinition();
	~CAssemblyDefinition();
	CEntityDefinition *addEntity(std::string name);
	int load(void* buffer, size_t bufferSize);
	int optimize();// retorna numero de otimizacoes realizadas
	std::string toTextAssembly(bool high_level);
	int saveBytecode(std::string name);
	bool loadBytecode(std::string name);
	CEntityDefinition* getEntity(std::string name);
	void addImport(std::string name);
	bool isLibrary(std::string name);
	std::vector<CEntityDefinition*> getEntityList() const
	{
		return _entityList;
	}
private:
	std::vector<CEntityDefinition*> _entityList;
	CUvmHeader* _header;
	std::map<std::string,std::string> _importList;
	CSymbolTable _symbolTable;
};

//}


#endif

