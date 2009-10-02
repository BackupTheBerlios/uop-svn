#include "DataStack.hpp"


#include <ncurses.h>


extern "C" void uvm_os_wrap_libncurses_writeln(CDataStack& dataStack)
{
	int argNumber = dataStack.pop().getInteger();
	std::string out;

	for (int arg=0; arg < argNumber; arg++) {
		out = dataStack.pop().getText() + out;
	}
	printw("%s\n", out.c_str());
}





extern "C" void uvm_os_wrap_libncurses_addch(CDataStack& dataStack)
{
	const chtype p1= (const chtype) dataStack.pop().getInteger();
	int result=addch(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_addchnstr(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	const chtype* p1= (const chtype*) dataStack.pop().getInteger();
	int result=addchnstr(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_addchstr(CDataStack& dataStack)
{
	const chtype* p1= (const chtype*) dataStack.pop().getInteger();
	int result=addchstr(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_addnstr(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	const char* p1= (const char*) dataStack.pop().getInteger();
	int result=addnstr(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_addstr(CDataStack& dataStack)
{
	const char* p1= (const char*) dataStack.pop().getInteger();
	int result=addstr(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_attroff(CDataStack& dataStack)
{
	NCURSES_ATTR_T p1= (NCURSES_ATTR_T) dataStack.pop().getInteger();
	int result=attroff(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_attron(CDataStack& dataStack)
{
	NCURSES_ATTR_T p1= (NCURSES_ATTR_T) dataStack.pop().getInteger();
	int result=attron(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_attrset(CDataStack& dataStack)
{
	NCURSES_ATTR_T p1= (NCURSES_ATTR_T) dataStack.pop().getInteger();
	int result=attrset(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_attr_get(CDataStack& dataStack)
{
	void* p3= (void*) dataStack.pop().getInteger();
	short* p2= (short*) dataStack.pop().getInteger();
	attr_t* p1= (attr_t*) dataStack.pop().getString().c_str();
	int result=attr_get(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_attr_off(CDataStack& dataStack)
{
	void* p2= (void*) dataStack.pop().getInteger();
	attr_t p1= (attr_t) dataStack.pop().getInteger();
	int result=attr_off(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_attr_on(CDataStack& dataStack)
{
	void* p2= (void*) dataStack.pop().getInteger();
	attr_t p1= (attr_t) dataStack.pop().getInteger();
	int result=attr_on(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_attr_set(CDataStack& dataStack)
{
	void* p3= (void*) dataStack.pop().getInteger();
	short p2= (short) dataStack.pop().getInteger();
	attr_t p1= (attr_t) dataStack.pop().getInteger();
	int result=attr_set(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_baudrate(CDataStack& dataStack)
{
	int result=baudrate();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_beep(CDataStack& dataStack)
{
	int result=beep();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_bkgd(CDataStack& dataStack)
{
	chtype p1= (chtype) dataStack.pop().getInteger();
	int result=bkgd(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_bkgdset(CDataStack& dataStack)
{
	chtype p1= (chtype) dataStack.pop().getInteger();
	bkgdset(p1);
}

extern "C" void uvm_os_wrap_libncurses_border(CDataStack& dataStack)
{
	chtype p8= (chtype) dataStack.pop().getInteger();
	chtype p7= (chtype) dataStack.pop().getInteger();
	chtype p6= (chtype) dataStack.pop().getInteger();
	chtype p5= (chtype) dataStack.pop().getInteger();
	chtype p4= (chtype) dataStack.pop().getInteger();
	chtype p3= (chtype) dataStack.pop().getInteger();
	chtype p2= (chtype) dataStack.pop().getInteger();
	chtype p1= (chtype) dataStack.pop().getInteger();
	int result=border(p1, p2, p3, p4, p5, p6, p7, p8);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_box(CDataStack& dataStack)
{
	chtype p3= (chtype) dataStack.pop().getInteger();
	char p2= (char) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=box(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_can_change_color(CDataStack& dataStack)
{
	bool result=can_change_color();

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_cbreak(CDataStack& dataStack)
{
	int result=cbreak();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_chgat(CDataStack& dataStack)
{
	const void* p4= (const void*) dataStack.pop().getInteger();
	short p3= (short) dataStack.pop().getInteger();
	attr_t p2= (attr_t) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=chgat(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_clear(CDataStack& dataStack)
{
	int result=clear();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_clearok(CDataStack& dataStack)
{
	bool p2= (bool) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=clearok(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_clrtobot(CDataStack& dataStack)
{
	int result=clrtobot();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_clrtoeol(CDataStack& dataStack)
{
	int result=clrtoeol();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_color_content(CDataStack& dataStack)
{
	short* p4= (short*) dataStack.pop().getInteger();
	short* p3= (short*) dataStack.pop().getInteger();
	short* p2= (short*) dataStack.pop().getInteger();
	short p1= (short) dataStack.pop().getInteger();
	int result=color_content(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_color_set(CDataStack& dataStack)
{
	void* p2= (void*) dataStack.pop().getInteger();
	short p1= (short) dataStack.pop().getInteger();
	int result=color_set(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_COLOR_PAIR(CDataStack& dataStack)
{
	int p1= (int) dataStack.pop().getInteger();
	int result=COLOR_PAIR(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_copywin(CDataStack& dataStack)
{
	int p9= (int) dataStack.pop().getInteger();
	int p8= (int) dataStack.pop().getInteger();
	int p7= (int) dataStack.pop().getInteger();
	int p6= (int) dataStack.pop().getInteger();
	int p5= (int) dataStack.pop().getInteger();
	int p4= (int) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	WINDOW* p2= (WINDOW*) dataStack.pop().getInteger();
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	int result=copywin(p1, p2, p3, p4, p5, p6, p7, p8, p9);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_curs_set(CDataStack& dataStack)
{
	int p1= (int) dataStack.pop().getInteger();
	int result=curs_set(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_def_prog_mode(CDataStack& dataStack)
{
	int result=def_prog_mode();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_def_shell_mode(CDataStack& dataStack)
{
	int result=def_shell_mode();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_delay_output(CDataStack& dataStack)
{
	int p1= (int) dataStack.pop().getInteger();
	int result=delay_output(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_delch(CDataStack& dataStack)
{
	int result=delch();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_delscreen(CDataStack& dataStack)
{
	SCREEN* p1= (SCREEN*) dataStack.pop().getInteger();
	delscreen(p1);
}

extern "C" void uvm_os_wrap_libncurses_delwin(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=delwin(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_deleteln(CDataStack& dataStack)
{
	int result=deleteln();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_derwin(CDataStack& dataStack)
{
	int p5= (int) dataStack.pop().getInteger();
	int p4= (int) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	WINDOW* result=derwin(p1, p2, p3, p4, p5);

	dataStack.push( (int*) result);
}

extern "C" void uvm_os_wrap_libncurses_doupdate(CDataStack& dataStack)
{
	int result=doupdate();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_dupwin(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	WINDOW* result=dupwin(p1);

	dataStack.push( (int*) result);
}

extern "C" void uvm_os_wrap_libncurses_echo(CDataStack& dataStack)
{
	int result=echo();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_echochar(CDataStack& dataStack)
{
	const chtype p1= (const chtype) dataStack.pop().getInteger();
	int result=echochar(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_erase(CDataStack& dataStack)
{
	int result=erase();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_endwin(CDataStack& dataStack)
{
	int result=endwin();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_erasechar(CDataStack& dataStack)
{
	char result=erasechar();

	dataStack.push( (char) result);
}

extern "C" void uvm_os_wrap_libncurses_filter(CDataStack& dataStack)
{
	filter();
}

extern "C" void uvm_os_wrap_libncurses_flash(CDataStack& dataStack)
{
	int result=flash();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_flushinp(CDataStack& dataStack)
{
	int result=flushinp();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_getbkgd(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	chtype result=getbkgd(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_getch(CDataStack& dataStack)
{
	int result=getch();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_getnstr(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	char* p1= (char*) dataStack.pop().getString().c_str();
	int result=getnstr(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_getstr(CDataStack& dataStack)
{
	char* p1= (char*) dataStack.pop().getString().c_str();
	int result=getstr(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_getwin(CDataStack& dataStack)
{
	FILE* p1= (FILE*) dataStack.pop().getInteger();
	WINDOW* result=getwin(p1);

	dataStack.push( (int*) result);
}

extern "C" void uvm_os_wrap_libncurses_halfdelay(CDataStack& dataStack)
{
	int p1= (int) dataStack.pop().getInteger();
	int result=halfdelay(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_has_colors(CDataStack& dataStack)
{
	bool result=has_colors();

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_has_ic(CDataStack& dataStack)
{
	bool result=has_ic();

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_has_il(CDataStack& dataStack)
{
	bool result=has_il();

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_hline(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	chtype p1= (chtype) dataStack.pop().getInteger();
	int result=hline(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_idcok(CDataStack& dataStack)
{
	bool p2= (bool) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	idcok(p1, p2);
}

extern "C" void uvm_os_wrap_libncurses_idlok(CDataStack& dataStack)
{
	bool p2= (bool) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=idlok(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_immedok(CDataStack& dataStack)
{
	bool p2= (bool) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	immedok(p1, p2);
}

extern "C" void uvm_os_wrap_libncurses_inch(CDataStack& dataStack)
{
	chtype result=inch();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_inchnstr(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	chtype* p1= (chtype*) dataStack.pop().getString().c_str();
	int result=inchnstr(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_inchstr(CDataStack& dataStack)
{
	chtype* p1= (chtype*) dataStack.pop().getString().c_str();
	int result=inchstr(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_initscr(CDataStack& dataStack)
{
	WINDOW* result=initscr();

	dataStack.push( (int*) result);
}

extern "C" void uvm_os_wrap_libncurses_init_color(CDataStack& dataStack)
{
	short p4= (short) dataStack.pop().getInteger();
	short p3= (short) dataStack.pop().getInteger();
	short p2= (short) dataStack.pop().getInteger();
	short p1= (short) dataStack.pop().getInteger();
	int result=init_color(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_init_pair(CDataStack& dataStack)
{
	short p3= (short) dataStack.pop().getInteger();
	short p2= (short) dataStack.pop().getInteger();
	short p1= (short) dataStack.pop().getInteger();
	int result=init_pair(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_innstr(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	char* p1= (char*) dataStack.pop().getString().c_str();
	int result=innstr(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_insch(CDataStack& dataStack)
{
	chtype p1= (chtype) dataStack.pop().getInteger();
	int result=insch(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_insdelln(CDataStack& dataStack)
{
	int p1= (int) dataStack.pop().getInteger();
	int result=insdelln(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_insertln(CDataStack& dataStack)
{
	int result=insertln();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_insnstr(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	const char* p1= (const char*) dataStack.pop().getInteger();
	int result=insnstr(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_insstr(CDataStack& dataStack)
{
	const char* p1= (const char*) dataStack.pop().getInteger();
	int result=insstr(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_instr(CDataStack& dataStack)
{
	char* p1= (char*) dataStack.pop().getString().c_str();
	int result=instr(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_intrflush(CDataStack& dataStack)
{
	bool p2= (bool) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=intrflush(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_isendwin(CDataStack& dataStack)
{
	bool result=isendwin();

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_is_linetouched(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	bool result=is_linetouched(p1, p2);

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_is_wintouched(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	bool result=is_wintouched(p1);

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_keyname(CDataStack& dataStack)
{
	int p1= (int) dataStack.pop().getInteger();
	const char* result=keyname(p1);

	dataStack.push( (const char*) result);
}

extern "C" void uvm_os_wrap_libncurses_keypad(CDataStack& dataStack)
{
	bool p2= (bool) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=keypad(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_killchar(CDataStack& dataStack)
{
	char result=killchar();

	dataStack.push( (char) result);
}

extern "C" void uvm_os_wrap_libncurses_leaveok(CDataStack& dataStack)
{
	bool p2= (bool) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=leaveok(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_longname(CDataStack& dataStack)
{
	char* result=longname();

	dataStack.push( (char*) result);
}

extern "C" void uvm_os_wrap_libncurses_meta(CDataStack& dataStack)
{
	bool p2= (bool) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=meta(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_move(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=move(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvaddch(CDataStack& dataStack)
{
	const chtype p3= (const chtype) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvaddch(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvaddchnstr(CDataStack& dataStack)
{
	int p4= (int) dataStack.pop().getInteger();
	const chtype* p3= (const chtype*) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvaddchnstr(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvaddchstr(CDataStack& dataStack)
{
	const chtype* p3= (const chtype*) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvaddchstr(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvaddnstr(CDataStack& dataStack)
{
	int p4= (int) dataStack.pop().getInteger();
	const char* p3= (const char*) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvaddnstr(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvaddstr(CDataStack& dataStack)
{
	const char* p3= (const char*) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvaddstr(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvchgat(CDataStack& dataStack)
{
	const void* p6= (const void*) dataStack.pop().getInteger();
	short p5= (short) dataStack.pop().getInteger();
	attr_t p4= (attr_t) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvchgat(p1, p2, p3, p4, p5, p6);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvcur(CDataStack& dataStack)
{
	int p4= (int) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvcur(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvdelch(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvdelch(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvderwin(CDataStack& dataStack)
{
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvderwin(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvgetch(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvgetch(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvgetnstr(CDataStack& dataStack)
{
	int p4= (int) dataStack.pop().getInteger();
	char* p3= (char*) dataStack.pop().getString().c_str();
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvgetnstr(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvgetstr(CDataStack& dataStack)
{
	char* p3= (char*) dataStack.pop().getString().c_str();
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvgetstr(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvhline(CDataStack& dataStack)
{
	int p4= (int) dataStack.pop().getInteger();
	chtype p3= (chtype) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvhline(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvinch(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	chtype result=mvinch(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvinchnstr(CDataStack& dataStack)
{
	int p4= (int) dataStack.pop().getInteger();
	chtype* p3= (chtype*) dataStack.pop().getString().c_str();
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvinchnstr(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvinchstr(CDataStack& dataStack)
{
	chtype* p3= (chtype*) dataStack.pop().getString().c_str();
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvinchstr(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvinnstr(CDataStack& dataStack)
{
	int p4= (int) dataStack.pop().getInteger();
	char* p3= (char*) dataStack.pop().getString().c_str();
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvinnstr(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvinsch(CDataStack& dataStack)
{
	chtype p3= (chtype) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvinsch(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvinsnstr(CDataStack& dataStack)
{
	int p4= (int) dataStack.pop().getInteger();
	const char* p3= (const char*) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvinsnstr(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvinsstr(CDataStack& dataStack)
{
	const char* p3= (const char*) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvinsstr(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvinstr(CDataStack& dataStack)
{
	char* p3= (char*) dataStack.pop().getString().c_str();
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvinstr(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvvline(CDataStack& dataStack)
{
	int p4= (int) dataStack.pop().getInteger();
	chtype p3= (chtype) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=mvvline(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwaddch(CDataStack& dataStack)
{
	const chtype p4= (const chtype) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwaddch(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwaddchnstr(CDataStack& dataStack)
{
	int p5= (int) dataStack.pop().getInteger();
	const chtype* p4= (const chtype*) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwaddchnstr(p1, p2, p3, p4, p5);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwaddchstr(CDataStack& dataStack)
{
	const chtype* p4= (const chtype*) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwaddchstr(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwaddnstr(CDataStack& dataStack)
{
	int p5= (int) dataStack.pop().getInteger();
	const char* p4= (const char*) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwaddnstr(p1, p2, p3, p4, p5);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwaddstr(CDataStack& dataStack)
{
	const char* p4= (const char*) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwaddstr(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwchgat(CDataStack& dataStack)
{
	const void* p7= (const void*) dataStack.pop().getInteger();
	short p6= (short) dataStack.pop().getInteger();
	attr_t p5= (attr_t) dataStack.pop().getInteger();
	int p4= (int) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwchgat(p1, p2, p3, p4, p5, p6, p7);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwdelch(CDataStack& dataStack)
{
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwdelch(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwgetch(CDataStack& dataStack)
{
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwgetch(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwgetnstr(CDataStack& dataStack)
{
	int p5= (int) dataStack.pop().getInteger();
	char* p4= (char*) dataStack.pop().getString().c_str();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwgetnstr(p1, p2, p3, p4, p5);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwgetstr(CDataStack& dataStack)
{
	char* p4= (char*) dataStack.pop().getString().c_str();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwgetstr(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwhline(CDataStack& dataStack)
{
	int p5= (int) dataStack.pop().getInteger();
	chtype p4= (chtype) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwhline(p1, p2, p3, p4, p5);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwin(CDataStack& dataStack)
{
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwin(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwinch(CDataStack& dataStack)
{
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	chtype result=mvwinch(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwinchnstr(CDataStack& dataStack)
{
	int p5= (int) dataStack.pop().getInteger();
	chtype* p4= (chtype*) dataStack.pop().getString().c_str();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwinchnstr(p1, p2, p3, p4, p5);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwinchstr(CDataStack& dataStack)
{
	chtype* p4= (chtype*) dataStack.pop().getString().c_str();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwinchstr(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwinnstr(CDataStack& dataStack)
{
	int p5= (int) dataStack.pop().getInteger();
	char* p4= (char*) dataStack.pop().getString().c_str();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwinnstr(p1, p2, p3, p4, p5);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwinsch(CDataStack& dataStack)
{
	chtype p4= (chtype) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwinsch(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwinsnstr(CDataStack& dataStack)
{
	int p5= (int) dataStack.pop().getInteger();
	const char* p4= (const char*) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwinsnstr(p1, p2, p3, p4, p5);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwinsstr(CDataStack& dataStack)
{
	const char* p4= (const char*) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwinsstr(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwinstr(CDataStack& dataStack)
{
	char* p4= (char*) dataStack.pop().getString().c_str();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwinstr(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mvwvline(CDataStack& dataStack)
{
	int p5= (int) dataStack.pop().getInteger();
	chtype p4= (chtype) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=mvwvline(p1, p2, p3, p4, p5);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_napms(CDataStack& dataStack)
{
	int p1= (int) dataStack.pop().getInteger();
	int result=napms(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_newpad(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	WINDOW* result=newpad(p1, p2);

	dataStack.push( (int*) result);
}

extern "C" void uvm_os_wrap_libncurses_newterm(CDataStack& dataStack)
{
	FILE* p3= (FILE*) dataStack.pop().getInteger();
	FILE* p2= (FILE*) dataStack.pop().getInteger();
	const char* p1= (const char*) dataStack.pop().getInteger();
	SCREEN* result=newterm(p1, p2, p3);

	dataStack.push( (int*) result);
}

extern "C" void uvm_os_wrap_libncurses_newwin(CDataStack& dataStack)
{
	int p4= (int) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	WINDOW* result=newwin(p1, p2, p3, p4);

	dataStack.push( (int*) result);
}

extern "C" void uvm_os_wrap_libncurses_nl(CDataStack& dataStack)
{
	int result=nl();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_nocbreak(CDataStack& dataStack)
{
	int result=nocbreak();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_nodelay(CDataStack& dataStack)
{
	bool p2= (bool) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=nodelay(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_noecho(CDataStack& dataStack)
{
	int result=noecho();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_nonl(CDataStack& dataStack)
{
	int result=nonl();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_noqiflush(CDataStack& dataStack)
{
	noqiflush();
}

extern "C" void uvm_os_wrap_libncurses_noraw(CDataStack& dataStack)
{
	int result=noraw();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_notimeout(CDataStack& dataStack)
{
	bool p2= (bool) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=notimeout(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_overlay(CDataStack& dataStack)
{
	WINDOW* p2= (WINDOW*) dataStack.pop().getInteger();
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	int result=overlay(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_overwrite(CDataStack& dataStack)
{
	WINDOW* p2= (WINDOW*) dataStack.pop().getInteger();
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	int result=overwrite(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_pair_content(CDataStack& dataStack)
{
	short* p3= (short*) dataStack.pop().getInteger();
	short* p2= (short*) dataStack.pop().getInteger();
	short p1= (short) dataStack.pop().getInteger();
	int result=pair_content(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_PAIR_NUMBER(CDataStack& dataStack)
{
	int p1= (int) dataStack.pop().getInteger();
	int result=PAIR_NUMBER(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_pechochar(CDataStack& dataStack)
{
	const chtype p2= (const chtype) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=pechochar(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_pnoutrefresh(CDataStack& dataStack)
{
	int p7= (int) dataStack.pop().getInteger();
	int p6= (int) dataStack.pop().getInteger();
	int p5= (int) dataStack.pop().getInteger();
	int p4= (int) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=pnoutrefresh(p1, p2, p3, p4, p5, p6, p7);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_prefresh(CDataStack& dataStack)
{
	int p7= (int) dataStack.pop().getInteger();
	int p6= (int) dataStack.pop().getInteger();
	int p5= (int) dataStack.pop().getInteger();
	int p4= (int) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=prefresh(p1, p2, p3, p4, p5, p6, p7);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_putwin(CDataStack& dataStack)
{
	FILE* p2= (FILE*) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=putwin(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_qiflush(CDataStack& dataStack)
{
	qiflush();
}

extern "C" void uvm_os_wrap_libncurses_raw(CDataStack& dataStack)
{
	int result=raw();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_redrawwin(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=redrawwin(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_refresh(CDataStack& dataStack)
{
	int result=refresh();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_resetty(CDataStack& dataStack)
{
	int result=resetty();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_reset_prog_mode(CDataStack& dataStack)
{
	int result=reset_prog_mode();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_reset_shell_mode(CDataStack& dataStack)
{
	int result=reset_shell_mode();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_savetty(CDataStack& dataStack)
{
	int result=savetty();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_scr_dump(CDataStack& dataStack)
{
	const char* p1= (const char*) dataStack.pop().getInteger();
	int result=scr_dump(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_scr_init(CDataStack& dataStack)
{
	const char* p1= (const char*) dataStack.pop().getInteger();
	int result=scr_init(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_scrl(CDataStack& dataStack)
{
	int p1= (int) dataStack.pop().getInteger();
	int result=scrl(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_scroll(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=scroll(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_scrollok(CDataStack& dataStack)
{
	bool p2= (bool) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=scrollok(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_scr_restore(CDataStack& dataStack)
{
	const char* p1= (const char*) dataStack.pop().getInteger();
	int result=scr_restore(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_scr_set(CDataStack& dataStack)
{
	const char* p1= (const char*) dataStack.pop().getInteger();
	int result=scr_set(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_setscrreg(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=setscrreg(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_set_term(CDataStack& dataStack)
{
	SCREEN* p1= (SCREEN*) dataStack.pop().getInteger();
	SCREEN* result=set_term(p1);

	dataStack.push( (int*) result);
}

extern "C" void uvm_os_wrap_libncurses_slk_attroff(CDataStack& dataStack)
{
	const chtype p1= (const chtype) dataStack.pop().getInteger();
	int result=slk_attroff(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_slk_attr_off(CDataStack& dataStack)
{
	void* p2= (void*) dataStack.pop().getInteger();
	const attr_t p1= (const attr_t) dataStack.pop().getInteger();
	int result=slk_attr_off(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_slk_attron(CDataStack& dataStack)
{
	const chtype p1= (const chtype) dataStack.pop().getInteger();
	int result=slk_attron(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_slk_attr_on(CDataStack& dataStack)
{
	void* p2= (void*) dataStack.pop().getInteger();
	attr_t p1= (attr_t) dataStack.pop().getInteger();
	int result=slk_attr_on(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_slk_attrset(CDataStack& dataStack)
{
	const chtype p1= (const chtype) dataStack.pop().getInteger();
	int result=slk_attrset(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_slk_attr(CDataStack& dataStack)
{
	attr_t result=slk_attr();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_slk_attr_set(CDataStack& dataStack)
{
	void* p3= (void*) dataStack.pop().getInteger();
	short p2= (short) dataStack.pop().getInteger();
	const attr_t p1= (const attr_t) dataStack.pop().getInteger();
	int result=slk_attr_set(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_slk_clear(CDataStack& dataStack)
{
	int result=slk_clear();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_slk_color(CDataStack& dataStack)
{
	short p1= (short) dataStack.pop().getInteger();
	int result=slk_color(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_slk_init(CDataStack& dataStack)
{
	int p1= (int) dataStack.pop().getInteger();
	int result=slk_init(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_slk_label(CDataStack& dataStack)
{
	int p1= (int) dataStack.pop().getInteger();
	char* result=slk_label(p1);

	dataStack.push( (char*) result);
}

extern "C" void uvm_os_wrap_libncurses_slk_noutrefresh(CDataStack& dataStack)
{
	int result=slk_noutrefresh();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_slk_refresh(CDataStack& dataStack)
{
	int result=slk_refresh();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_slk_restore(CDataStack& dataStack)
{
	int result=slk_restore();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_slk_set(CDataStack& dataStack)
{
	int p3= (int) dataStack.pop().getInteger();
	const char* p2= (const char*) dataStack.pop().getInteger();
	int p1= (int) dataStack.pop().getInteger();
	int result=slk_set(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_slk_touch(CDataStack& dataStack)
{
	int result=slk_touch();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_standout(CDataStack& dataStack)
{
	int result=standout();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_standend(CDataStack& dataStack)
{
	int result=standend();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_start_color(CDataStack& dataStack)
{
	int result=start_color();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_subpad(CDataStack& dataStack)
{
	int p5= (int) dataStack.pop().getInteger();
	int p4= (int) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	WINDOW* result=subpad(p1, p2, p3, p4, p5);

	dataStack.push( (int*) result);
}

extern "C" void uvm_os_wrap_libncurses_subwin(CDataStack& dataStack)
{
	int p5= (int) dataStack.pop().getInteger();
	int p4= (int) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	WINDOW* result=subwin(p1, p2, p3, p4, p5);

	dataStack.push( (int*) result);
}

extern "C" void uvm_os_wrap_libncurses_syncok(CDataStack& dataStack)
{
	bool p2= (bool) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=syncok(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_termattrs(CDataStack& dataStack)
{
	chtype result=termattrs();

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_termname(CDataStack& dataStack)
{
	char* result=termname();

	dataStack.push( (char*) result);
}

extern "C" void uvm_os_wrap_libncurses_timeout(CDataStack& dataStack)
{
	int p1= (int) dataStack.pop().getInteger();
	timeout(p1);
}

extern "C" void uvm_os_wrap_libncurses_touchline(CDataStack& dataStack)
{
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=touchline(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_touchwin(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=touchwin(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_typeahead(CDataStack& dataStack)
{
	int p1= (int) dataStack.pop().getInteger();
	int result=typeahead(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_ungetch(CDataStack& dataStack)
{
	int p1= (int) dataStack.pop().getInteger();
	int result=ungetch(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_untouchwin(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=untouchwin(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_use_env(CDataStack& dataStack)
{
	bool p1= (bool) dataStack.pop().getInteger();
	use_env(p1);
}

extern "C" void uvm_os_wrap_libncurses_vidattr(CDataStack& dataStack)
{
	chtype p1= (chtype) dataStack.pop().getInteger();
	int result=vidattr(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_vline(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	chtype p1= (chtype) dataStack.pop().getInteger();
	int result=vline(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_waddch(CDataStack& dataStack)
{
	const chtype p2= (const chtype) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=waddch(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_waddchnstr(CDataStack& dataStack)
{
	int p3= (int) dataStack.pop().getInteger();
	const chtype* p2= (const chtype*) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=waddchnstr(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_waddchstr(CDataStack& dataStack)
{
	const chtype* p2= (const chtype*) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=waddchstr(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_waddnstr(CDataStack& dataStack)
{
	int p3= (int) dataStack.pop().getInteger();
	const char* p2= (const char*) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=waddnstr(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_waddstr(CDataStack& dataStack)
{
	const char* p2= (const char*) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=waddstr(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wattron(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wattron(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wattroff(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wattroff(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wattrset(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wattrset(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wattr_get(CDataStack& dataStack)
{
	void* p4= (void*) dataStack.pop().getInteger();
	short* p3= (short*) dataStack.pop().getInteger();
	attr_t* p2= (attr_t*) dataStack.pop().getString().c_str();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wattr_get(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wattr_on(CDataStack& dataStack)
{
	void* p3= (void*) dataStack.pop().getInteger();
	attr_t p2= (attr_t) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wattr_on(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wattr_off(CDataStack& dataStack)
{
	void* p3= (void*) dataStack.pop().getInteger();
	attr_t p2= (attr_t) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wattr_off(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wattr_set(CDataStack& dataStack)
{
	void* p4= (void*) dataStack.pop().getInteger();
	short p3= (short) dataStack.pop().getInteger();
	attr_t p2= (attr_t) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wattr_set(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wbkgd(CDataStack& dataStack)
{
	chtype p2= (chtype) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wbkgd(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wbkgdset(CDataStack& dataStack)
{
	chtype p2= (chtype) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	wbkgdset(p1, p2);
}

extern "C" void uvm_os_wrap_libncurses_wborder(CDataStack& dataStack)
{
	chtype p9= (chtype) dataStack.pop().getInteger();
	chtype p8= (chtype) dataStack.pop().getInteger();
	chtype p7= (chtype) dataStack.pop().getInteger();
	chtype p6= (chtype) dataStack.pop().getInteger();
	chtype p5= (chtype) dataStack.pop().getInteger();
	chtype p4= (chtype) dataStack.pop().getInteger();
	chtype p3= (chtype) dataStack.pop().getInteger();
	chtype p2= (chtype) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wborder(p1, p2, p3, p4, p5, p6, p7, p8, p9);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wchgat(CDataStack& dataStack)
{
	const void* p5= (const void*) dataStack.pop().getInteger();
	short p4= (short) dataStack.pop().getInteger();
	attr_t p3= (attr_t) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wchgat(p1, p2, p3, p4, p5);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wclear(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wclear(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wclrtobot(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wclrtobot(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wclrtoeol(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wclrtoeol(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wcolor_set(CDataStack& dataStack)
{
	void* p3= (void*) dataStack.pop().getInteger();
	short p2= (short) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wcolor_set(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wcursyncup(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	wcursyncup(p1);
}

extern "C" void uvm_os_wrap_libncurses_wdelch(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wdelch(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wdeleteln(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wdeleteln(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wechochar(CDataStack& dataStack)
{
	const chtype p2= (const chtype) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wechochar(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_werase(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=werase(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wgetch(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wgetch(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wgetnstr(CDataStack& dataStack)
{
	int p3= (int) dataStack.pop().getInteger();
	char* p2= (char*) dataStack.pop().getString().c_str();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wgetnstr(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wgetstr(CDataStack& dataStack)
{
	char* p2= (char*) dataStack.pop().getString().c_str();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wgetstr(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_whline(CDataStack& dataStack)
{
	int p3= (int) dataStack.pop().getInteger();
	chtype p2= (chtype) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=whline(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_winch(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	chtype result=winch(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_winchnstr(CDataStack& dataStack)
{
	int p3= (int) dataStack.pop().getInteger();
	chtype* p2= (chtype*) dataStack.pop().getString().c_str();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=winchnstr(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_winchstr(CDataStack& dataStack)
{
	chtype* p2= (chtype*) dataStack.pop().getString().c_str();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=winchstr(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_winnstr(CDataStack& dataStack)
{
	int p3= (int) dataStack.pop().getInteger();
	char* p2= (char*) dataStack.pop().getString().c_str();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=winnstr(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_winsch(CDataStack& dataStack)
{
	chtype p2= (chtype) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=winsch(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_winsdelln(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=winsdelln(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_winsertln(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=winsertln(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_winsnstr(CDataStack& dataStack)
{
	int p3= (int) dataStack.pop().getInteger();
	const char* p2= (const char*) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=winsnstr(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_winsstr(CDataStack& dataStack)
{
	const char* p2= (const char*) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=winsstr(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_winstr(CDataStack& dataStack)
{
	char* p2= (char*) dataStack.pop().getString().c_str();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=winstr(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wmove(CDataStack& dataStack)
{
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wmove(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wnoutrefresh(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wnoutrefresh(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wredrawln(CDataStack& dataStack)
{
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wredrawln(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wrefresh(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wrefresh(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wscrl(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wscrl(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wsetscrreg(CDataStack& dataStack)
{
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wsetscrreg(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wstandout(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wstandout(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wstandend(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wstandend(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wsyncdown(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	wsyncdown(p1);
}

extern "C" void uvm_os_wrap_libncurses_wsyncup(CDataStack& dataStack)
{
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	wsyncup(p1);
}

extern "C" void uvm_os_wrap_libncurses_wtimeout(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	wtimeout(p1, p2);
}

extern "C" void uvm_os_wrap_libncurses_wtouchln(CDataStack& dataStack)
{
	int p4= (int) dataStack.pop().getInteger();
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wtouchln(p1, p2, p3, p4);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wvline(CDataStack& dataStack)
{
	int p3= (int) dataStack.pop().getInteger();
	chtype p2= (chtype) dataStack.pop().getInteger();
	WINDOW* p1= (WINDOW*) dataStack.pop().getInteger();
	int result=wvline(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_tigetflag(CDataStack& dataStack)
{
	const char* p1= (const char*) dataStack.pop().getInteger();
	int result=tigetflag(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_tigetnum(CDataStack& dataStack)
{
	const char* p1= (const char*) dataStack.pop().getInteger();
	int result=tigetnum(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_tigetstr(CDataStack& dataStack)
{
	const char* p1= (const char*) dataStack.pop().getInteger();
	char* result=tigetstr(p1);

	dataStack.push( (char*) result);
}

extern "C" void uvm_os_wrap_libncurses_putp(CDataStack& dataStack)
{
	const char* p1= (const char*) dataStack.pop().getInteger();
	int result=putp(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_getattrs(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	int result=getattrs(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_getcurx(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	int result=getcurx(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_getcury(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	int result=getcury(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_getbegx(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	int result=getbegx(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_getbegy(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	int result=getbegy(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_getmaxx(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	int result=getmaxx(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_getmaxy(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	int result=getmaxy(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_getparx(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	int result=getparx(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_getpary(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	int result=getpary(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wgetparent(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	WINDOW* result=wgetparent(p1);

	dataStack.push( (int*) result);
}

extern "C" void uvm_os_wrap_libncurses_is_cleared(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	bool result=is_cleared(p1);

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_is_idcok(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	bool result=is_idcok(p1);

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_is_idlok(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	bool result=is_idlok(p1);

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_is_immedok(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	bool result=is_immedok(p1);

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_is_keypad(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	bool result=is_keypad(p1);

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_is_leaveok(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	bool result=is_leaveok(p1);

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_is_nodelay(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	bool result=is_nodelay(p1);

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_is_notimeout(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	bool result=is_notimeout(p1);

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_is_scrollok(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	bool result=is_scrollok(p1);

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_is_syncok(CDataStack& dataStack)
{
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	bool result=is_syncok(p1);

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_wgetscrreg(CDataStack& dataStack)
{
	int* p3= (int*) dataStack.pop().getInteger();
	int* p2= (int*) dataStack.pop().getInteger();
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	int result=wgetscrreg(p1, p2, p3);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_getmouse(CDataStack& dataStack)
{
	MEVENT* p1= (MEVENT*) dataStack.pop().getInteger();
	int result=getmouse(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_ungetmouse(CDataStack& dataStack)
{
	MEVENT* p1= (MEVENT*) dataStack.pop().getInteger();
	int result=ungetmouse(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_mousemask(CDataStack& dataStack)
{
	mmask_t* p2= (mmask_t*) dataStack.pop().getInteger();
	mmask_t p1= (mmask_t) dataStack.pop().getInteger();
	mmask_t result=mousemask(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wenclose(CDataStack& dataStack)
{
	int p3= (int) dataStack.pop().getInteger();
	int p2= (int) dataStack.pop().getInteger();
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	bool result=wenclose(p1, p2, p3);

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_mouseinterval(CDataStack& dataStack)
{
	int p1= (int) dataStack.pop().getInteger();
	int result=mouseinterval(p1);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_wmouse_trafo(CDataStack& dataStack)
{
	bool p4= (bool) dataStack.pop().getInteger();
	int* p3= (int*) dataStack.pop().getInteger();
	int* p2= (int*) dataStack.pop().getInteger();
	const WINDOW* p1= (const WINDOW*) dataStack.pop().getInteger();
	bool result=wmouse_trafo(p1, p2, p3, p4);

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_mouse_trafo(CDataStack& dataStack)
{
	bool p3= (bool) dataStack.pop().getInteger();
	int* p2= (int*) dataStack.pop().getInteger();
	int* p1= (int*) dataStack.pop().getInteger();
	bool result=mouse_trafo(p1, p2, p3);

	dataStack.push( (bool) result);
}

extern "C" void uvm_os_wrap_libncurses_mcprint(CDataStack& dataStack)
{
	int p2= (int) dataStack.pop().getInteger();
	char* p1= (char*) dataStack.pop().getString().c_str();
	int result=mcprint(p1, p2);

	dataStack.push( (int) result);
}

extern "C" void uvm_os_wrap_libncurses_has_key(CDataStack& dataStack)
{
	int p1= (int) dataStack.pop().getInteger();
	int result=has_key(p1);

	dataStack.push( (int) result);
}

