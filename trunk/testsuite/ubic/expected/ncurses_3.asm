.constant_pool
	0   S start
	1   S constructor
	2   S ncurses.initscr
	3   I 1
	4   I 0
	5   S Nome: 
	6   I 3
	7   S ncurses.mvwrite
	8   S ncurses.read
	9   S identity.name
	10  I 2
	11  S Interesse geral: 
	12  S identity.general_interest
	13  S Interesse especifico: 
	14  S identity.specific_interest
	15  I 4
	16  S Localização: 
	17  S location.symbolic
	18  I 10
	19  S Dados lidos
	20  S ncurses.mvwriteln
	21  S ncurses.writeln
	22  S ncurses.refresh
	23  S ncurses.getch
	24  S ncurses.endwin
.end
.entity start
	.valid_context_when (always)
	.method constructor
		lcall 2 --> [ncurses.initscr]
		ldconst 3 --> [1]
		ldconst 4 --> [0]
		ldconst 5 --> [Nome: ]
		ldconst 6 --> [3]
		lcall 7 --> [ncurses.mvwrite]
		lcall 8 --> [ncurses.read]
		stcontexti 9 --> [identity.name]
		ldconst 10 --> [2]
		ldconst 4 --> [0]
		ldconst 11 --> [Interesse geral: ]
		ldconst 6 --> [3]
		lcall 7 --> [ncurses.mvwrite]
		lcall 8 --> [ncurses.read]
		stcontexti 12 --> [identity.general_interest]
		ldconst 6 --> [3]
		ldconst 4 --> [0]
		ldconst 13 --> [Interesse especifico: ]
		ldconst 6 --> [3]
		lcall 7 --> [ncurses.mvwrite]
		lcall 8 --> [ncurses.read]
		stcontexti 14 --> [identity.specific_interest]
		ldconst 15 --> [4]
		ldconst 4 --> [0]
		ldconst 16 --> [Localização: ]
		ldconst 6 --> [3]
		lcall 7 --> [ncurses.mvwrite]
		lcall 8 --> [ncurses.read]
		stcontexti 17 --> [location.symbolic]
		ldconst 18 --> [10]
		ldconst 4 --> [0]
		ldconst 19 --> [Dados lidos]
		ldconst 6 --> [3]
		lcall 20 --> [ncurses.mvwriteln]
		ldcontexti 9 --> [identity.name]
		ldconst 3 --> [1]
		lcall 21 --> [ncurses.writeln]
		ldcontexti 12 --> [identity.general_interest]
		ldconst 3 --> [1]
		lcall 21 --> [ncurses.writeln]
		ldcontexti 14 --> [identity.specific_interest]
		ldconst 3 --> [1]
		lcall 21 --> [ncurses.writeln]
		ldcontexti 17 --> [location.symbolic]
		ldconst 3 --> [1]
		lcall 21 --> [ncurses.writeln]
		lcall 22 --> [ncurses.refresh]
		lcall 23 --> [ncurses.getch]
		lcall 24 --> [ncurses.endwin]
		stop
	.end
.end
