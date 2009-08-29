#include <iostream>

#include "Tests.hpp"

void showVersion() {
   std::cerr << "testsuite 0.1.0" << std::endl;
   //std::cerr << rcstagid << " (" << rcsrevid << ")" << endl;
}

void showSyntax(int valor) {
    std::cout << "Use: testsuite [options] testname" << std::endl;
    std::cout << "\t-r\tRun test testname." << std::endl;
    std::cout << "\t-c\tCheck test testname." << std::endl;
    std::cout << "\t-e\tDefine last output as expected result for testname." << std::endl;
    std::cout << "\t-d\tShow diff between last output and expected result for testname." << std::endl;
    std::cout << "\t-o\tShow test output for testname." << std::endl;
    std::cout << "\t-h\tShow this help." << std::endl;
    std::cout << "\t-v\tShow version." << std::endl;
    std::cout << std::endl;
    std::cout << "To report bugs: alexgarzao@gmail.com " << std::endl;
//    std::cout << "To report bugs: " << PACKAGE_BUGREPORT << std::endl;

    exit(valor);
}

int main(int argc, char* argv[])
{
	CTests tests;
	tests.config();
	tests.define();

	if (argc <= 1) {
		std::cerr << "Error: undefined parameters..." << std::endl;
        showSyntax(EXIT_FAILURE);
	}

	int param;
	while ((param = getopt(argc, argv, "r:c:e:d:o:vh")) != -1) {
		switch (param) {
			case 'r': // Run test (all meaning all tests)
				if (strcmp(optarg, "all") == 0) {
					tests.runAll();
				} else {
					tests.run(optarg);
				}
				break;
			case 'c': // Check test (all meaning all tests)
				if (strcmp(optarg, "all") == 0) {
					tests.runAll();
					tests.checkAll();
				} else {
					tests.run(optarg);
					tests.check(optarg);
				}
				break;
			case 'e': // Expected result ok (all meaning all tests)
				if (strcmp(optarg, "all") == 0) {
					tests.testOkAll();
				} else {
					tests.testOk(optarg);
				}
				break;
			case 'd': // Show diff between last output and expected result (all meaning all tests)
				if (strcmp(optarg, "all") == 0) {
					tests.showDiffAll();
				} else {
					tests.showDiff(optarg);
				}
				break;
			case 'o': // Show output (all meaning all tests)
				if (strcmp(optarg, "all") == 0) {
					tests.showOutputAll();
				} else {
					tests.showOutput(optarg);
				}
				break;
			case 'v': // Version
//				showVersion();
				exit(1);
				break;
			case 'h': // Help
				showSyntax(1);
				break;
			default: // Other options
				showSyntax(1);
				break;
		}
	}

	argc -= optind;
	argv += optind;

//    if (argc == 0) {
//        std::cerr << "Error: Undefined filename..." << std::endl;
//        showSyntax(EXIT_FAILURE);
//    }
//	tests.runAll();

	if (argc > 0) {
		std::cerr << "Error: unexpected parameters..." << std::endl;
		showSyntax(EXIT_FAILURE);
	}

	return 0;
}
