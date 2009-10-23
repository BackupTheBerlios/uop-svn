#include <iostream>
#include <string>

#include "UbivmDefs.hpp"
#include "UbiVM.hpp"


void showSyntax();


int main(int argc, char *argv[])
{
	int i;
	SOptions options;

	std::cout << "UbiVM - Release 0.1.0 (development release)" << std::endl;

	options.bindPort = 45555;
	options.sendPort = 45555;

	while ((i = getopt(argc, argv, "a:hl:s:p:")) != -1) {
		switch (i) {
		case 'a': // Make assembly text file
			options.asmFilename = std::string(optarg);
			break;
		case 'h':
			showSyntax();
			return EXIT_SUCCESS;
			break;
		case 'l': // Port to listen (bind)
			options.bindPort = atoi(optarg);
			break;
		case 's': // Port to send
			options.sendPort = atoi(optarg);
			break;
		case 'p': // Provider name
			options.provider_list.push_back(optarg);
			break;
		default:
			break;
      }
   }

   argc -= optind;
   argv += optind;

   if (argc < 1) {
      showSyntax();
      return EXIT_FAILURE;
   }

   options.sourcefile = std::string(argv[0]) + ".uvm";

//   cout << "Running " << options.sourcefile << "..." << endl;

   CUbiVM::getInstance()->setConfig( &options );

   int result = CUbiVM::getInstance()->run();

   return result;
}


void showSyntax() {
	std::cout << std::endl
			<< "Desenvolvido por Alex Sandro Garzao (alexgarzao@gmail.com)" << std::endl
			<< "Junho, 2009"                                                << std::endl
			                                                                << std::endl
			<< "Syntax: ubivm [options] file"                               << std::endl
			<< "Options:"                                                   << std::endl
			<< "         -a asmfile"                                        << std::endl
			<< "         -h help"                                           << std::endl
			<< "         -l port_to_listen"                                 << std::endl
			<< "         -s port_to_send"                                   << std::endl
			<< "         -p provider_name"                                  << std::endl
			<< std::endl;
}
