.constant_pool
	0   S start
	1   S constructor
	2   S insere
	3   S insert_data
	4   S MeuContexto
	5   S Informacao inserida: 
	6   S Numero 1
	7   I 1
	8   I 2
	9   S io.writeln
	10  S insert
	11  I 5
	12  S datetime.sleep
	13  S Inserindo informacao
	14  I 100
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element insere
		newelem 3 --> [insert_data]
		stvar 0 --> [insere]
		ldconst 4 --> [MeuContexto]
		ldconst 0 --> [start]
		joinc
		ldconst 5 --> [Informacao inserida: ]
		ldconst 4 --> [MeuContexto]
		ldconst 6 --> [Numero 1]
		ldconst 7 --> [1]
		findd
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		stop
	.end
.end
.entity insert_data
	.option parallel
	.valid_context_when (always)
	.method constructor
		ldconst 4 --> [MeuContexto]
		ldconst 10 --> [insert]
		joinc
		ldconst 11 --> [5]
		lcall 12 --> [datetime.sleep]
		ldconst 13 --> [Inserindo informacao]
		ldconst 7 --> [1]
		lcall 9 --> [io.writeln]
		ldconst 4 --> [MeuContexto]
		ldconst 6 --> [Numero 1]
		ldconst 14 --> [100]
		ldconst 7 --> [1]
		ldconst 7 --> [1]
		publishd
		ret
	.end
.end
