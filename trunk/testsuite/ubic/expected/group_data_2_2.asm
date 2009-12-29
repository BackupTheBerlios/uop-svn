.constant_pool
	0   S start
	1   S constructor
	2   S MeuContexto
	3   S prog2
	4   S Informacoes inseridas pelo programa 1: 
	5   S Numero 1
	6   I 1
	7   I 2
	8   S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [MeuContexto]
		ldconst 3 --> [prog2]
		joinc
		ldconst 4 --> [Informacoes inseridas pelo programa 1: ]
		ldconst 2 --> [MeuContexto]
		ldconst 5 --> [Numero 1]
		ldconst 6 --> [1]
		findd
		ldconst 7 --> [2]
		lcall 8 --> [io.writeln]
		stop
	.end
.end
