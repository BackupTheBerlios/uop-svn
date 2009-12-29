.constant_pool
	0   S start
	1   S constructor
	2   S MeuContexto
	3   S Alex
	4   S Inserindo informacoes
	5   I 1
	6   S io.writeln
	7   S Numero 1
	8   I 54321
	9   S Informacoes inseridas: 
	10  I 2
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
		ldconst 8 --> [54321]
		ldconst 5 --> [1]
		ldconst 5 --> [1]
		publishd
		ldconst 9 --> [Informacoes inseridas: ]
		ldconst 2 --> [MeuContexto]
		ldconst 7 --> [Numero 1]
		ldconst 5 --> [1]
		getd
		ldconst 10 --> [2]
		lcall 6 --> [io.writeln]
		stop
	.end
.end
