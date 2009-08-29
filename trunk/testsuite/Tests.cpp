#include "Tests.hpp"

CTests::CTests()
{
}

CTests::~CTests()
{
}

void CTests::config()
{
	// Config compiler tests
	compiler.setInputPath("./ubic/input/");
	compiler.setOutputPath("./ubic/output/");
	compiler.setExpectedPath("./ubic/expected/");
	compiler.addExecutionCommandLine("../ubic/ubic -o %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.uvm "
                                     "-a %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.asm "
                                     "%COMPILERARGS% "
                                     "%INPUTPATH%/%TEST%.ubil "
                                     "> %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.out");
	compiler.addCopyingResultsCommandLine("cp %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.uvm %EXPECTEDPATH%/");
	compiler.addCopyingResultsCommandLine("cp %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.asm %EXPECTEDPATH%/");
	compiler.addCopyingResultsCommandLine("cp %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.out %EXPECTEDPATH%/");
	compiler.addTestingResultsCommandLine("cmp %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.uvm %EXPECTEDPATH%/%TEST%%SUBTESTNUMBER%.uvm -s","");
	compiler.addTestingResultsCommandLine("cmp %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.asm %EXPECTEDPATH%/%TEST%%SUBTESTNUMBER%.asm -s",
			"vimdiff %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.asm %EXPECTEDPATH%/%TEST%%SUBTESTNUMBER%.asm");
	compiler.addTestingResultsCommandLine("cmp %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.out %EXPECTEDPATH%/%TEST%%SUBTESTNUMBER%.out -s",
			"vimdiff %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.out %EXPECTEDPATH%/%TEST%%SUBTESTNUMBER%.out");
	compiler.addShowOutputCommandLine("cat %INPUTPATH%/%TEST%.ubil");
	compiler.addShowOutputCommandLine("cat %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.asm");
	compiler.addShowOutputCommandLine("cat %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.out");
	compiler.addClearOutputCommandLine("rm -f %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.asm");
	compiler.addClearOutputCommandLine("rm -f %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.out");

	// Config vm tests
	vm.setInputPath("./ubic/output/");
	vm.setOutputPath("./ubivm/output/");
	vm.setExpectedPath("./ubivm/expected/");
	vm.addExecutionCommandLine("../ubivm/ubivm -a %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.asm "
                               "%VMARGS% "
                               "%INPUTPATH%/%TEST%%SUBTESTNUMBER%"
                               "%TESTARGS% "
                               "> %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.out");
	vm.addCopyingResultsCommandLine("cp %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.asm %EXPECTEDPATH%");
	vm.addCopyingResultsCommandLine("cp %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.out %EXPECTEDPATH%");
	vm.addTestingResultsCommandLine("cmp %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.asm %EXPECTEDPATH%/%TEST%%SUBTESTNUMBER%.asm -s",
			"vimdiff %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.asm %EXPECTEDPATH%/%TEST%%SUBTESTNUMBER%.asm");
	vm.addTestingResultsCommandLine("cmp %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.out %EXPECTEDPATH%/%TEST%%SUBTESTNUMBER%.out -s",
			"vimdiff %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.out %EXPECTEDPATH%/%TEST%%SUBTESTNUMBER%.out");
	// TODO: nao ficou legal a abordagem abaixo :-/
	vm.addTestingResultsCommandLine("cmp ./ubic/output/%TEST%%SUBTESTNUMBER%.asm %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.asm -s",
			"vimdiff ./ubic/output/%TEST%%SUBTESTNUMBER%.asm %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.asm");
	vm.addShowOutputCommandLine("cat %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.asm");
	vm.addShowOutputCommandLine("cat %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.out");
	vm.addClearOutputCommandLine("rm -f %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.asm");
	vm.addClearOutputCommandLine("rm -f %OUTPUTPATH%/%TEST%%SUBTESTNUMBER%.out");
}

void CTests::define()
{
	CTest* test = compiler.addTest(PASS, "hello_world");
//	test->addSubtest(PASS, CArgs("COMPILERARGS", ""));
	test = vm.addTest(PASS, "hello_world");

	test = compiler.addTest(PASS, "hello_world2");
	test = vm.addTest(PASS, "hello_world2");

	test = compiler.addTest(PASS, "hello_world3");
	test = vm.addTest(PASS, "hello_world3");

	test = compiler.addTest(PASS, "writeln_varios_tipos");
	test = vm.addTest(PASS, "writeln_varios_tipos");

//	test->addSubtest(PASS, CArgs("VMARGS", ""), CArgs("TESTARGS", ""));
//	test->addSubtest(PASS, CArgs("VMARGS", "varg3 varg4"), CArgs("TESTARGS", "aarg3 aarg4"));

//	test = compiler.addTest("test2");
//	test->addSubtest(FAIL, CArgs("COMPILERARGS", "carg1 carg2"));



//	CTest* test = compiler.addTest("test1");
//	test->addSubtest(PASS, CArgs("COMPILERARGS", "carg1 carg2"));
//	test->addSubtest(PASS, CArgs("COMPILERARGS", "carg3 carg4"));
//
//	test = vm.addTest("test1");
//	test->addSubtest(PASS, CArgs("VMARGS", "varg1 varg2"), CArgs("TESTARGS", "aarg1 aarg2"));
//	test->addSubtest(PASS, CArgs("VMARGS", "varg3 varg4"), CArgs("TESTARGS", "aarg3 aarg4"));
//
//	test = compiler.addTest("test2");
//	test->addSubtest(FAIL, CArgs("COMPILERARGS", "carg1 carg2"));
//	//...
	test = compiler.addTest(PASS, "expr1");
	test = vm.addTest(PASS, "expr1");

	test = compiler.addTest(PASS, "expr2");
	test = vm.addTest(PASS, "expr2");

	test = compiler.addTest(PASS, "expr3");
	test = vm.addTest(PASS, "expr3");

	test = compiler.addTest(PASS, "expr4");
	test = vm.addTest(PASS, "expr4");

	test = compiler.addTest(PASS, "expr5");
	test = vm.addTest(PASS, "expr5");

	test = compiler.addTest(PASS, "expr6");
	test = vm.addTest(PASS, "expr6");

	test = compiler.addTest(PASS, "expr7");
	test = vm.addTest(PASS, "expr7");

	test = compiler.addTest(PASS, "expr8");
	test = vm.addTest(PASS, "expr8");

	test = compiler.addTest(PASS, "expr9");
	test = vm.addTest(PASS, "expr9");

	test = compiler.addTest(PASS, "expr_real_1");
	test = vm.addTest(PASS, "expr_real_1");

	test = compiler.addTest(PASS, "expr_real_2");
	test = vm.addTest(PASS, "expr_real_2");

	test = compiler.addTest(PASS, "expr_real_3");
	test = vm.addTest(PASS, "expr_real_3");

	test = compiler.addTest(PASS, "expr_real_4");
	test = vm.addTest(PASS, "expr_real_4");

	test = compiler.addTest(PASS, "expr_real_5");
	test = vm.addTest(PASS, "expr_real_5");

	test = compiler.addTest(PASS, "expr_real_6");
	test = vm.addTest(PASS, "expr_real_6");

	test = compiler.addTest(PASS, "expr_real_7");
	test = vm.addTest(PASS, "expr_real_7");

	test = compiler.addTest(PASS, "expr_real_8");
	test = vm.addTest(PASS, "expr_real_8");

	test = compiler.addTest(PASS, "expr_real_9");
	test = vm.addTest(PASS, "expr_real_9");

	test = compiler.addTest(PASS, "def_vars");
	test = vm.addTest(PASS, "def_vars");

	test = compiler.addTest(PASS, "attr_int_1");
	test = vm.addTest(PASS, "attr_int_1");

	test = compiler.addTest(PASS, "attr_int_2");
	test = vm.addTest(PASS, "attr_int_2");

	test = compiler.addTest(PASS, "attr_int_3");
	test = vm.addTest(PASS, "attr_int_3");

	test = compiler.addTest(PASS, "attr_real_1");
	test = vm.addTest(PASS, "attr_real_1");

	test = compiler.addTest(PASS, "attr_real_2");
	test = vm.addTest(PASS, "attr_real_2");

	test = compiler.addTest(PASS, "attr_real_3");
	test = vm.addTest(PASS, "attr_real_3");

	test = compiler.addTest(PASS, "attr_string_1");
	test = vm.addTest(PASS, "attr_string_1");

	test = compiler.addTest(PASS, "attr_string_2");
	test = vm.addTest(PASS, "attr_string_2");

	test = compiler.addTest(PASS, "attr_string_3");
	test = vm.addTest(PASS, "attr_string_3");

	test = compiler.addTest(PASS, "add_with_var_int");
	test = vm.addTest(PASS, "add_with_var_int");

	test = compiler.addTest(PASS, "add_with_var_real");
	test = vm.addTest(PASS, "add_with_var_real");

	test = compiler.addTest(PASS, "add_with_var_string");
	test = vm.addTest(PASS, "add_with_var_string");

	test = compiler.addTest(PASS, "if_1");
	test = vm.addTest(PASS, "if_1");

	test = compiler.addTest(PASS, "if_2");
	test = vm.addTest(PASS, "if_2");

	test = compiler.addTest(PASS, "if_3");
	test = vm.addTest(PASS, "if_3");

	test = compiler.addTest(PASS, "if_4");
	test = vm.addTest(PASS, "if_4");

	test = compiler.addTest(PASS, "for_1");
	test = vm.addTest(PASS, "for_1");

	test = compiler.addTest(PASS, "while_1");
	test = vm.addTest(PASS, "while_1");

	test = compiler.addTest(PASS, "repeat_until_1");
	test = vm.addTest(PASS, "repeat_until_1");

	test = compiler.addTest(PASS, "method_1");
	test = vm.addTest(PASS, "method_1");

	test = compiler.addTest(PASS, "method_2");
	test = vm.addTest(PASS, "method_2");

	test = compiler.addTest(PASS, "method_3");
	test = vm.addTest(PASS, "method_3");

	test = compiler.addTest(PASS, "method_4");
	test = vm.addTest(PASS, "method_4");

	test = compiler.addTest(PASS, "method_5");
	test = vm.addTest(PASS, "method_5");

	test = compiler.addTest(PASS, "method_with_result_1");
	test = vm.addTest(PASS, "method_with_result_1");

	test = compiler.addTest(PASS, "method_with_result_2");
	test = vm.addTest(PASS, "method_with_result_2");

	test = compiler.addTest(PASS, "method_with_result_3");
	test = vm.addTest(PASS, "method_with_result_3");

	test = compiler.addTest(PASS, "method_with_result_4");
	test = vm.addTest(PASS, "method_with_result_4");

	test = compiler.addTest(PASS, "method_with_result_5");
	test = vm.addTest(PASS, "method_with_result_5");

	test = compiler.addTest(PASS, "method_with_result_6");
	test = vm.addTest(PASS, "method_with_result_6");

	test = compiler.addTest(PASS, "fatorial");
	test = vm.addTest(PASS, "fatorial");

	test = compiler.addTest(PASS, "element_1");
	test = vm.addTest(PASS, "element_1");

	test = compiler.addTest(PASS, "element_2");
	test = vm.addTest(PASS, "element_2");

	test = compiler.addTest(PASS, "element_3");
	test = vm.addTest(PASS, "element_3");

	test = compiler.addTest(PASS, "element_4");
	test = vm.addTest(PASS, "element_4");

	test = compiler.addTest(PASS, "element_5");
	test = vm.addTest(PASS, "element_5");

	test = compiler.addTest(PASS, "element_6");
	test = vm.addTest(PASS, "element_6");

	test = compiler.addTest(PASS, "element_7");
	test = vm.addTest(PASS, "element_7");

	test = compiler.addTest(PASS, "element_method_with_result_1");
	test = vm.addTest(PASS, "element_method_with_result_1");

	test = compiler.addTest(PASS, "element_method_with_result_2");
	test = vm.addTest(PASS, "element_method_with_result_2");

	test = compiler.addTest(PASS, "element_method_with_result_3");
	test = vm.addTest(PASS, "element_method_with_result_3");

	test = compiler.addTest(PASS, "element_method_with_result_4");
	test = vm.addTest(PASS, "element_method_with_result_4");

	test = compiler.addTest(PASS, "element_method_with_result_5");
	test = vm.addTest(PASS, "element_method_with_result_5");

	test = compiler.addTest(PASS, "element_method_with_result_6");
	test = vm.addTest(PASS, "element_method_with_result_6");

	test = compiler.addTest(PASS, "group_1");
	test = vm.addTest(PASS, "group_1");

	test = compiler.addTest(PASS, "group_2");
	test = vm.addTest(PASS, "group_2");

	test = compiler.addTest(PASS, "group_3");
	test = vm.addTest(PASS, "group_3");

	test = compiler.addTest(PASS, "group_4");
	test = vm.addTest(PASS, "group_4");

	test = compiler.addTest(PASS, "service_1");
	test = vm.addTest(PASS, "service_1");

	test = compiler.addTest(PASS, "context_1");
	test = vm.addTest(PASS, "context_1");

	// proximos testes...
	// testes com expressoes matematicas "complexas" tb para o tipo real
}

void CTests::runAll()
{
	compiler.runAll();
	vm.runAll();

	// TODO: teste !!!!
//	compiler.resultOk("test1");
//	compiler.checkTest("test1");
}

void CTests::run(std::string name)
{
	compiler.runTest(name);
	// Se name=test1...
	// Executa "ubic -o ./ubic/output/test1.1.uvm -d ./ubic/output/test1.1.asm carg1 carg2 ./ubic/input/test1 > ./ubic/output/test1.1.out"
	// Executa "ubic -o ./ubic/output/test1.2.uvm -d ./ubic/output/test1.2.asm carg3 carg4 ./ubic/input/test1 > ./ubic/output/test1.2.out"

	vm.runTest(name);
	// Se name=test1...
	// Executa "ubivm -d ./ubivm/output/test1.1.asm ./ubic/expected/test1.1 arg1 arg2 > ./ubivm/output/test1.1.out"
	// Executa "ubivm -d ./ubivm/output/test1.2.asm ./ubic/expected/test1.2 arg3 arg4 > ./ubivm/output/test1.2.out"
}

void CTests::testOkAll()
{
	compiler.testOkAll();
	vm.testOkAll();
}

void CTests::testOk(std::string name)
{
	compiler.testOk(name);
	// Se name=test1...
	// Copia ./ubic/output/test1.1.uvm para ./ubic/expected/test1.1.uvm
	// Copia ./ubic/output/test1.2.uvm para ./ubic/expected/test1.2.uvm
	// Copia ./ubic/output/test1.1.asm para ./ubic/expected/test1.1.asm
	// Copia ./ubic/output/test1.2.asm para ./ubic/expected/test1.2.asm
	// Copia ./ubic/output/test1.1.out para ./ubic/expected/test1.1.out
	// Copia ./ubic/output/test1.2.out para ./ubic/expected/test1.2.out

	vm.testOk(name);
	// Se name=test1...
	// Copia ./ubivm/output/test1.1.asm para ./ubivm/expected/test1.1.asm
	// Copia ./ubivm/output/test1.2.asm para ./ubivm/expected/test1.2.asm
	// Copia ./ubivm/output/test1.1.out para ./ubivm/expected/test1.1.out
	// Copia ./ubivm/output/test1.2.out para ./ubivm/expected/test1.2.out
}

void CTests::checkAll()
{
	compiler.checkAll();
	vm.checkAll();

	compiler.report();
	vm.report();
}

void CTests::check(std::string name)
{
	compiler.check(name);
	vm.check(name);
}

void CTests::showDiffAll()
{
	compiler.showDiffAll();
	vm.showDiffAll();
}

void CTests::showDiff(std::string name)
{
	compiler.showDiff(name);
	vm.showDiff(name);
}

void CTests::showOutputAll()
{
	compiler.showOutputAll();
	vm.showOutputAll();
}

void CTests::showOutput(std::string name)
{
	compiler.showOutput(name);
	vm.showOutput(name);
}
