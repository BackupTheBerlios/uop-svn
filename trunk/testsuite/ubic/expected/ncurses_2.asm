.constant_pool
	0   S start
	1   S constructor
	2   S ncurses.initscr
	3   I 1
	4   I 5
	5   S Nome: 
	6   I 3
	7   S ncurses.mvwriteln
	8   I 2
	9   S Interesse geral: 
	10  S Interesse especifico
	11  I 4
	12  S Localização: 
	13  S ncurses.refresh
	14  S ncurses.getch
	15  S ncurses.endwin
.end
.entity start
	.valid_context_when (always)
	.method constructor
		lcall 2 --> [ncurses.initscr]
		ldconst 3 --> [1]
		ldconst 4 --> [5]
		ldconst 5 --> [Nome: ]
		ldconst 6 --> [3]
		lcall 7 --> [ncurses.mvwriteln]
		ldconst 8 --> [2]
		ldconst 4 --> [5]
		ldconst 9 --> [Interesse geral: ]
		ldconst 6 --> [3]
		lcall 7 --> [ncurses.mvwriteln]
		ldconst 6 --> [3]
		ldconst 4 --> [5]
		ldconst 10 --> [Interesse especifico]
		ldconst 6 --> [3]
		lcall 7 --> [ncurses.mvwriteln]
		ldconst 11 --> [4]
		ldconst 4 --> [5]
		ldconst 12 --> [Localização: ]
		ldconst 6 --> [3]
		lcall 7 --> [ncurses.mvwriteln]
		lcall 13 --> [ncurses.refresh]
		lcall 14 --> [ncurses.getch]
		lcall 15 --> [ncurses.endwin]
		stop
	.end
.end
