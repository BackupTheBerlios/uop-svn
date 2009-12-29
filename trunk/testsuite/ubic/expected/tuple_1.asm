.constant_pool
	0   S start
	1   S constructor
	2   S number
	3   S MeuContexto
	4   S teste
	5   S Numero 1
	6   I 100
	7   I 1
	8   S Informacoes inseridas: key=
	9   S  value=
	10  I 4
	11  S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 tuple number
		ldconst 3 --> [MeuContexto]
		ldconst 4 --> [teste]
		joinc
		ldconst 3 --> [MeuContexto]
		ldconst 5 --> [Numero 1]
		ldconst 6 --> [100]
		ldconst 7 --> [1]
		ldconst 7 --> [1]
		publishd
		ldconst 3 --> [MeuContexto]
		ldconst 5 --> [Numero 1]
		ldconst 7 --> [1]
		findd
		stvar 0 --> [number]
		ldconst 8 --> [Informacoes inseridas: key=]
		ldconst 7 --> [1]
		ldtuplek 0 --> [number]
		ldconst 9 --> [ value=]
		ldconst 7 --> [1]
		ldtuplev 0 --> [number]
		ldconst 10 --> [4]
		lcall 11 --> [io.writeln]
		stop
	.end
.end
