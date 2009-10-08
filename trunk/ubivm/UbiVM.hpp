#ifndef UBI_VM_HPP
#define UBI_VM_HPP


#include "UbivmDefs.hpp"
#include "RunBytecode.hpp"


class CUbiVM
{
public:
	CUbiVM(SOptions *options);
	int run();
private:
	bool _readFromFile(std::string name);
	std::string _toTextAssembly();
	int _load_providers();
	int _load_provider(std::string provider_name);

	SOptions *_options;
	std::map<std::string, void*> _syslibHandlerList;
	CAssemblyDefinition _asmDef;
	std::map<std::string, CGroup*> _groupList;
	std::map<std::string, CLiteral> _contextsInfo;
	std::vector<CElement*> _elementList;
	CCommunicationProvider* _cp;
};

#endif
