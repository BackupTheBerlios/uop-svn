.constant_pool
	0   S start
	1   S constructor
	2   S MeuContexto
	3   S prog1
	4   S Inserindo informacao
	5   I 1
	6   S io.writeln
	7   S Numero 1
	8   I 100
	9   S findnb em informacao inexistente: 
	10  S Numero X
	11  I 2
	12  S Informacao inserida: 
	13  S Removendo informacao inserida: 
	14  S Numero 1 nao existe mais: 
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [MeuContexto]
		ldconst 3 --> [prog1]
		joinc
		ldconst 4 --> [Inserindo informacao]
		ldconst 5 --> [1]
		lcall 6 --> [io.writeln]
		ldconst 2 --> [MeuContexto]
		ldconst 7 --> [Numero 1]
		ldconst 8 --> [100]
		ldconst 5 --> [1]
		ldconst 5 --> [1]
		publishd
		ldconst 9 --> [findnb em informacao inexistente: ]
		ldconst 2 --> [MeuContexto]
		ldconst 10 --> [Numero X]
		ldconst 5 --> [1]
		finddnb
		ldconst 11 --> [2]
		lcall 6 --> [io.writeln]
		ldconst 12 --> [Informacao inserida: ]
		ldconst 2 --> [MeuContexto]
		ldconst 7 --> [Numero 1]
		ldconst 5 --> [1]
		findd
		ldconst 11 --> [2]
		lcall 6 --> [io.writeln]
		ldconst 13 --> [Removendo informacao inserida: ]
		ldconst 2 --> [MeuContexto]
		ldconst 7 --> [Numero 1]
		ldconst 5 --> [1]
		getd
		ldconst 11 --> [2]
		lcall 6 --> [io.writeln]
		ldconst 14 --> [Numero 1 nao existe mais: ]
		ldconst 2 --> [MeuContexto]
		ldconst 7 --> [Numero 1]
		ldconst 5 --> [1]
		finddnb
		ldconst 11 --> [2]
		lcall 6 --> [io.writeln]
		ldconst 14 --> [Numero 1 nao existe mais: ]
		ldconst 2 --> [MeuContexto]
		ldconst 7 --> [Numero 1]
		ldconst 5 --> [1]
		getdnb
		ldconst 11 --> [2]
		lcall 6 --> [io.writeln]
		stop
	.end
.end