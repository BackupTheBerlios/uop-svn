.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [ncurses.initscr]
	.const 3   string   [Hello World !!!]
	.const 4   int      [1]
	.const 5   string   [ncurses.writeln]
	.const 6   string   [ncurses.refresh]
	.const 7   string   [ncurses.getch]
	.const 8   string   [ncurses.endwin]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        lcall        2 --> [ncurses.initscr]
	        ldconst      3 --> [Hello World !!!]
	        ldconst      4 --> [1]
	        lcall        5 --> [ncurses.writeln]
	        lcall        6 --> [ncurses.refresh]
	        lcall        7 --> [ncurses.getch]
	        lcall        8 --> [ncurses.endwin]
	        exit        
	.end
.end
