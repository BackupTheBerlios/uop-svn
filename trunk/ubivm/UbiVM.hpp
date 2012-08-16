#ifndef UBI_VM_HPP
#define UBI_VM_HPP


#include "UbivmDefs.hpp"
#include "RunBytecode.hpp"


class CUbiVM
{
public:
	static CUbiVM* getInstance()
	{
		static CUbiVM *instance = NULL;
		return instance ? instance : (instance = new CUbiVM());
	}
	void setConfig(SOptions *options);
	int run();

	SOptions* getOptions()
	{
		return _options;
	}

	CAssemblyDefinition* getAsmDef()
	{
		return &_asmDef;
	}

	std::map<std::string, void*>* getSyslibHandlerList()
	{
		return &_syslibHandlerList;
	}

	std::vector<CElement*>* getElementList()
	{
		return &_elementList;
	}

	std::map<std::string, CContext*>* getContextList()
	{
		return &_contextList;
	}

	std::map<std::string, CLiteral>* getContextsInfo()
	{
		return &_contextsInfo;
	}

private:
	CUbiVM() { }
	bool _readFromFile(std::string name);
	std::string _toTextAssembly();
	int _load_providers();
	int _load_provider(std::string provider_name);

	SOptions *_options;
	std::map<std::string, void*> _syslibHandlerList;
	CAssemblyDefinition _asmDef;
	std::map<std::string, CContext*> _contextList;
	std::vector<CElement*> _elementList;
	std::map<std::string, CLiteral> _contextsInfo;
};

#endif
