.constant_pool
	0   S start
	1   S constructor
	2   S MeuContexto
	3   S Alex
	4   S Inserindo informacoes
	5   I 1
	6   S io.writeln
	7   S Numero 1
	8   S 1
	9   S 2
	10  I 2
	11  S Informacoes inseridas: 
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [MeuContexto]
		ldconst 3 --> [Alex]
		joinc
		ldconst 4 --> [Inserindo informacoes]
		ldconst 5 --> [1]
		lcall 6 --> [io.writeln]
		ldconst 2 --> [MeuContexto]
		ldconst 7 --> [Numero 1]
		ldconst 8 --> [1]
		ldconst 9 --> [2]
		ldconst 5 --> [1]
		ldconst 10 --> [2]
		publishd
		ldconst 11 --> [Informacoes inseridas: ]
		ldconst 2 --> [MeuContexto]
		ldconst 7 --> [Numero 1]
		ldconst 5 --> [1]
		getd
		ldconst 10 --> [2]
		lcall 6 --> [io.writeln]
		stop
	.end
.end
