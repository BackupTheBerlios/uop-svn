#include <fstream>

#include "UbiVM.hpp"
#include "RunBytecode.hpp"


CUbiVM::CUbiVM(SOptions *options) : _options(options)
{
}


int CUbiVM::run()
{
//	std::ifstream in(_options->sourcefile.c_str(), std::ios::in|std::ios::binary);
   CRunBytecode bytecode(_options);

	bytecode.load_providers();

//   bytecode.readFromFile(in);
   bytecode.readFromFile(_options->sourcefile);

	if (_options->asmFilename != "") {
            std::ofstream out(_options->asmFilename.c_str(), std::ios_base::out);
            out << bytecode.toTextAssembly();
         }

   return bytecode.run();
}
