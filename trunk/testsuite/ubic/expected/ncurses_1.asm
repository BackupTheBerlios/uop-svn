.constant_pool
	0   S start
	1   S constructor
	2   S ncurses.initscr
	3   S Hello World !!!
	4   I 1
	5   S ncurses.writeln
	6   S ncurses.refresh
	7   S ncurses.getch
	8   S ncurses.endwin
.end
.entity start
	.valid_context_when (always)
	.method constructor
		lcall 2 --> [ncurses.initscr]
		ldconst 3 --> [Hello World !!!]
		ldconst 4 --> [1]
		lcall 5 --> [ncurses.writeln]
		lcall 6 --> [ncurses.refresh]
		lcall 7 --> [ncurses.getch]
		lcall 8 --> [ncurses.endwin]
		stop
	.end
.end
