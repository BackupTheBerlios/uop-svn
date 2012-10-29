#include <fstream>
#include <dlfcn.h>

#include "UbiVM.hpp"
#include "ContextProvider.hpp"


int CUbiVM::run()
{
	_load_providers();

	_readFromFile(_options->sourcefile);

	if (_options->asmFilename != "") {
		std::ofstream out(_options->asmFilename.c_str(), std::ios_base::out);
		out << _toTextAssembly();
	}

	CContextProvider::getInstance()->setConfig(&_contextList);

	CCommunicationProvider::getInstance()->setConfig(&_contextList, _options->bindPort, _options->sendPort);
	CCommunicationProvider::getInstance()->run();

	CRunBytecode bytecode;

	return bytecode.run();
}


std::string CUbiVM::_toTextAssembly()
{
	return _asmDef.toTextAssembly(false);
}


bool CUbiVM::_readFromFile(std::string name)
{
	if (_asmDef.loadBytecode(name) == false) {
		std::cout << "Erro na carga do arquivo UVM" << std::endl;
		return false;
	}

	return true;
}


int CUbiVM::_load_providers()
{
	for(std::list<std::string>::iterator provider_name = _options->provider_list.begin(); provider_name != _options->provider_list.end(); provider_name++) {
		std::cout << "Loading provider " << *provider_name << std::endl;
		_load_provider(*provider_name);
	}
	return 0;
}


int CUbiVM::_load_provider(std::string provider_name)
{
	std::string lib_name = "libuop_p_" + provider_name;

	void *dlhandler = NULL;
	char *error;

//	std::string libPath = std::string("../../ubiprovider/") + provider_name + "/" + lib_name + ".so";
	std::string libPath = lib_name + ".so";
	dlhandler = dlopen(libPath.c_str(), RTLD_LAZY|RTLD_GLOBAL);
	if (!dlhandler) {
		fprintf (stderr, "dlopen(%s): %s\n", libPath.c_str(), dlerror());
		exit(1);
	}
	dlerror();    // Clear any existing error

	// run provider initialization
	int (*func_init)(std::map<std::string, CLiteral>*);

	func_init = (int (*)(std::map<std::string, CLiteral>*)) dlsym(dlhandler, "ubip_init");
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "dlsym(ubip_init): %s\n", error);
		exit(1);
	}
	(*func_init)(&_contextsInfo);

	// run provider main code
	int (*func_run)();

	func_run = (int (*)()) dlsym(dlhandler, "ubip_run");
	if ((error = dlerror()) != NULL) {
		fprintf (stderr, "dlsym(ubip_run): %s\n", error);
		exit(1);
	}
	(*func_run)();

	return 0;
}


void CUbiVM::setConfig(SOptions * options)
{
	_options = options;
}
