#include <fstream>
#include <dlfcn.h>

#include "UbiVM.hpp"
#include "GroupProvider.hpp"


// CUbiVM::CUbiVM(SOptions *options) : _options(options)
// {
// }


int CUbiVM::run()
{
//	std::ifstream in(_options->sourcefile.c_str(), std::ios::in|std::ios::binary);

	_load_providers();

//   bytecode.readFromFile(in);
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
// 	return bytecode.run("start", NULL);
}


std::string CUbiVM::_toTextAssembly()
{
	return _asmDef.toTextAssembly();
}


bool CUbiVM::_readFromFile(std::string name)
{
	if (_asmDef.loadBytecode(name) == false) {
		std::cout << "Erro na carga do arquivo UVM" << std::endl;
		return false;
	}

//	std::cout << "Assembly lido: " << std:: endl;
//	std::cout << _asmDef.toTextAssembly() << std::endl;

	return true;
}

/*
bool CRunBytecode::readFromFile(std::ifstream &in)
{
   std::stringstream buf;
   buf << in.rdbuf();
   CBinString bin;
   bin.assign(buf.str());

   _header.readFromBinary(bin) &&
         _symbolTable.readFromBinary(bin);

   _dataStack.assign(bin.readString());
   _dataStack.setBS(_dataStack.size());
   _dataStack.setSP(_dataStack.size());

   _code.assign(bin.readString());

   return true;
}
*/


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

	std::string libPath = std::string("../../ubiprovider/") + provider_name + "/" + lib_name + ".so";
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
