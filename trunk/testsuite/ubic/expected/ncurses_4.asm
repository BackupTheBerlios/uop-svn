.constant_pool
	0   S start
	1   S constructor
	2   S main_win
	3   S perfil_win
	4   S ncurses.initscr
	5   S ncurses.refresh
	6   I 17
	7   I 80
	8   I 0
	9   S ncurses.newwin
	10  S ncurses.box
	11  I 1
	12  I 5
	13  S Nome: 
	14  I 4
	15  S ncurses.mvwwrite
	16  I 2
	17  S Interesse geral: 
	18  I 3
	19  S Interesse especifico
	20  S Localização: 
	21  S ncurses.wrefresh
	22  S ncurses.getch
	23  S ncurses.endwin
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int main_win
		.var 1 int perfil_win
		lcall 4 --> [ncurses.initscr]
		lcall 5 --> [ncurses.refresh]
		ldconst 6 --> [17]
		ldconst 7 --> [80]
		ldconst 8 --> [0]
		ldconst 8 --> [0]
		lcall 9 --> [ncurses.newwin]
		stvar 1 --> [perfil_win]
		ldvar 1 --> [perfil_win]
		ldconst 8 --> [0]
		ldconst 8 --> [0]
		lcall 10 --> [ncurses.box]
		ldvar 1 --> [perfil_win]
		ldconst 11 --> [1]
		ldconst 12 --> [5]
		ldconst 13 --> [Nome: ]
		ldconst 14 --> [4]
		lcall 15 --> [ncurses.mvwwrite]
		ldvar 1 --> [perfil_win]
		ldconst 16 --> [2]
		ldconst 12 --> [5]
		ldconst 17 --> [Interesse geral: ]
		ldconst 14 --> [4]
		lcall 15 --> [ncurses.mvwwrite]
		ldvar 1 --> [perfil_win]
		ldconst 18 --> [3]
		ldconst 12 --> [5]
		ldconst 19 --> [Interesse especifico]
		ldconst 14 --> [4]
		lcall 15 --> [ncurses.mvwwrite]
		ldvar 1 --> [perfil_win]
		ldconst 14 --> [4]
		ldconst 12 --> [5]
		ldconst 20 --> [Localização: ]
		ldconst 14 --> [4]
		lcall 15 --> [ncurses.mvwwrite]
		ldvar 1 --> [perfil_win]
		lcall 21 --> [ncurses.wrefresh]
		lcall 5 --> [ncurses.refresh]
		lcall 22 --> [ncurses.getch]
		lcall 23 --> [ncurses.endwin]
		stop
	.end
.end
