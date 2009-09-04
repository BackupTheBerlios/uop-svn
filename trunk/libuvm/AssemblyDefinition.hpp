#ifndef LIBUVM_ASSEMBLY_DEFINITION_HPP
#define LIBUVM_ASSEMBLY_DEFINITION_HPP

#include <string>
#include <map>
#include <list>

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
	std::string toTextAssembly();
	int saveBytecode(std::string name);
	bool loadBytecode(std::string name);
	CEntityDefinition* getEntity(std::string name);
	void addImport(std::string name);
	bool isLibrary(std::string name);
private:
	std::map<std::string, CEntityDefinition*> _entityList;
	CUvmHeader* _header;
	std::map<std::string,std::string> _importList;
};

//}


#endif

