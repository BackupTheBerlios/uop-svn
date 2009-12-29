.constant_pool
	0   S start
	1   S constructor
	2   S MeuContexto
	3   S prog2
	4   S Programa 2 inserindo N2
	5   I 1
	6   S io.writeln
	7   S N2
	8   I 200
	9   S Informacoes inseridas pelo programa 1: 
	10  S N1
	11  I 2
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [MeuContexto]
		ldconst 3 --> [prog2]
		joinc
		ldconst 4 --> [Programa 2 inserindo N2]
		ldconst 5 --> [1]
		lcall 6 --> [io.writeln]
		ldconst 2 --> [MeuContexto]
		ldconst 7 --> [N2]
		ldconst 8 --> [200]
		ldconst 5 --> [1]
		ldconst 5 --> [1]
		publishd
		ldconst 9 --> [Informacoes inseridas pelo programa 1: ]
		ldconst 2 --> [MeuContexto]
		ldconst 10 --> [N1]
		ldconst 5 --> [1]
		findd
		ldconst 11 --> [2]
		lcall 6 --> [io.writeln]
		stop
	.end
.end
