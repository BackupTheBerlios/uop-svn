.constant_pool
	0   S start
	1   S constructor
	2   S main_win
	3   S perfil_win
	4   S ncurses.initscr
	5   S ncurses.refresh
	6   S ncurses.wrefresh
	7   I 17
	8   I 120
	9   I 0
	10  S ncurses.newwin
	11  S ncurses.box
	12  I 1
	13  S Nome: 
	14  I 4
	15  S ncurses.mvwwrite
	16  S ncurses.wread
	17  S identity.name
	18  I 2
	19  S Interesse geral: 
	20  S identity.general_interest
	21  I 3
	22  S Interesse especifico: 
	23  S identity.specific_interest
	24  S Localização: 
	25  S location.symbolic
	26  I 10
	27  S Dados lidos
	28  I 11
	29  S ncurses.wwrite
	30  S  Interesse geral: 
	31  S  Interesse específico: 
	32  S  Localização: 
	33  S ncurses.getch
	34  S ncurses.endwin
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int main_win
		.var 1 int perfil_win
		lcall 4 --> [ncurses.initscr]
		lcall 5 --> [ncurses.refresh]
		ldvar 0 --> [main_win]
		lcall 6 --> [ncurses.wrefresh]
		ldconst 7 --> [17]
		ldconst 8 --> [120]
		ldconst 9 --> [0]
		ldconst 9 --> [0]
		lcall 10 --> [ncurses.newwin]
		stvar 1 --> [perfil_win]
		ldvar 1 --> [perfil_win]
		ldconst 9 --> [0]
		ldconst 9 --> [0]
		lcall 11 --> [ncurses.box]
		ldvar 1 --> [perfil_win]
		ldconst 12 --> [1]
		ldconst 12 --> [1]
		ldconst 13 --> [Nome: ]
		ldconst 14 --> [4]
		lcall 15 --> [ncurses.mvwwrite]
		ldvar 1 --> [perfil_win]
		lcall 16 --> [ncurses.wread]
		stcontexti 17 --> [identity.name]
		ldvar 1 --> [perfil_win]
		ldconst 18 --> [2]
		ldconst 12 --> [1]
		ldconst 19 --> [Interesse geral: ]
		ldconst 14 --> [4]
		lcall 15 --> [ncurses.mvwwrite]
		ldvar 1 --> [perfil_win]
		lcall 16 --> [ncurses.wread]
		stcontexti 20 --> [identity.general_interest]
		ldvar 1 --> [perfil_win]
		ldconst 21 --> [3]
		ldconst 12 --> [1]
		ldconst 22 --> [Interesse especifico: ]
		ldconst 14 --> [4]
		lcall 15 --> [ncurses.mvwwrite]
		ldvar 1 --> [perfil_win]
		lcall 16 --> [ncurses.wread]
		stcontexti 23 --> [identity.specific_interest]
		ldvar 1 --> [perfil_win]
		ldconst 14 --> [4]
		ldconst 12 --> [1]
		ldconst 24 --> [Localização: ]
		ldconst 14 --> [4]
		lcall 15 --> [ncurses.mvwwrite]
		ldvar 1 --> [perfil_win]
		lcall 16 --> [ncurses.wread]
		stcontexti 25 --> [location.symbolic]
		ldvar 1 --> [perfil_win]
		ldconst 26 --> [10]
		ldconst 12 --> [1]
		ldconst 27 --> [Dados lidos]
		ldconst 14 --> [4]
		lcall 15 --> [ncurses.mvwwrite]
		ldvar 1 --> [perfil_win]
		ldconst 28 --> [11]
		ldconst 12 --> [1]
		ldconst 13 --> [Nome: ]
		ldconst 14 --> [4]
		lcall 15 --> [ncurses.mvwwrite]
		ldvar 1 --> [perfil_win]
		ldcontexti 17 --> [identity.name]
		ldconst 18 --> [2]
		lcall 29 --> [ncurses.wwrite]
		ldvar 1 --> [perfil_win]
		ldconst 30 --> [ Interesse geral: ]
		ldconst 18 --> [2]
		lcall 29 --> [ncurses.wwrite]
		ldvar 1 --> [perfil_win]
		ldcontexti 20 --> [identity.general_interest]
		ldconst 18 --> [2]
		lcall 29 --> [ncurses.wwrite]
		ldvar 1 --> [perfil_win]
		ldconst 31 --> [ Interesse específico: ]
		ldconst 18 --> [2]
		lcall 29 --> [ncurses.wwrite]
		ldvar 1 --> [perfil_win]
		ldcontexti 23 --> [identity.specific_interest]
		ldconst 18 --> [2]
		lcall 29 --> [ncurses.wwrite]
		ldvar 1 --> [perfil_win]
		ldconst 32 --> [ Localização: ]
		ldconst 18 --> [2]
		lcall 29 --> [ncurses.wwrite]
		ldvar 1 --> [perfil_win]
		ldcontexti 25 --> [location.symbolic]
		ldconst 18 --> [2]
		lcall 29 --> [ncurses.wwrite]
		ldvar 1 --> [perfil_win]
		lcall 6 --> [ncurses.wrefresh]
		lcall 5 --> [ncurses.refresh]
		lcall 33 --> [ncurses.getch]
		lcall 34 --> [ncurses.endwin]
		stop
	.end
.end
