#include <curses.h>

#include "DataStack.hpp"


extern "C" void uvm_os_wrap_libncurses_initscr(CDataStack& dataStack)
{
	WINDOW* ret = initscr();
	dataStack.push(ret);
}


//	int printw (const char *,...)


extern "C" void uvm_os_wrap_libncurses_writeln(CDataStack& dataStack)
{
	int argNumber = dataStack.pop().getInteger();
	std::string out;

	for (int arg=0; arg < argNumber; arg++) {
		out = dataStack.pop().getText() + out;
	}
	printw("%s\n", out.c_str());
}


extern "C" void uvm_os_wrap_libncurses_refresh(CDataStack& dataStack)
{
	int ret = refresh();
	dataStack.push(ret);
}


extern "C" void uvm_os_wrap_libncurses_getch(CDataStack& dataStack)
{
	int ret = getch();
	dataStack.push(ret);
}


extern "C" void uvm_os_wrap_libncurses_endwin(CDataStack& dataStack)
{
	int ret = endwin();
	dataStack.push(ret);
}


//void uvm_os_wrap_libmath_cos(CDataStack& dataStack)
//{
//	double x = dataStack.pop().getReal();
//	double ret = cos(x);
//	dataStack.push(ret);
//}


//void uvm_os_wrap_libmath_mod(CDataStack& dataStack)
//{
//	int y = dataStack.pop().getInteger();
//	int x = dataStack.pop().getInteger();
//	int ret = x % y;
//	dataStack.push(ret);
//}


void uvm_os_libncurses_init(void)
{
// 	uvm_os_func_register("libmath", "cos", CTYPE_DOUBLE, CTYPE_DOUBLE, uvm_os_wrap_libmath_cos);
// 	uvm_func_register("libtest", "soma_double", CTYPE_DOUBLE, PARAM(CTYPE_DOUBLE, CTYPE_DOUBLE), __wrap__libtest__soma_double)
// 	uvm_map_types(CTYPE_INT, "int") // nao precisa por enquanto
// 	uvm_map_types(CTYPE_DOUBLE, "real") // nao precisa por enquanto
}

