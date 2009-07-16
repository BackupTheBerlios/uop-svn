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

   while ((i = getopt(argc, argv, "a:h")) != -1) {
      switch (i) {
         case 'a': // Make assembly text file
            options.asmFilename = std::string(optarg);
            break;
         case 'h':
            showSyntax();
            return EXIT_SUCCESS;
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

   CUbiVM ubivm( &options );

   int result = ubivm.run();

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
                                                                        << std::endl;
}

