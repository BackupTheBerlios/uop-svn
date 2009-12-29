.constant_pool
	0   S start
	1   S constructor
	2   S MeuContexto
	3   S prog1
	4   S Programa 1 inserindo N1
	5   I 1
	6   S io.writeln
	7   S N1
	8   I 100
	9   S Informacoes inseridas pelo programa 2: 
	10  S N2
	11  I 2
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [MeuContexto]
		ldconst 3 --> [prog1]
		joinc
		ldconst 4 --> [Programa 1 inserindo N1]
		ldconst 5 --> [1]
		lcall 6 --> [io.writeln]
		ldconst 2 --> [MeuContexto]
		ldconst 7 --> [N1]
		ldconst 8 --> [100]
		ldconst 5 --> [1]
		ldconst 5 --> [1]
		publishd
		ldconst 9 --> [Informacoes inseridas pelo programa 2: ]
		ldconst 2 --> [MeuContexto]
		ldconst 10 --> [N2]
		ldconst 5 --> [1]
		findd
		ldconst 11 --> [2]
		lcall 6 --> [io.writeln]
		stop
	.end
.end
