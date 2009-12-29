.constant_pool
	0   S start
	1   S constructor
	2   S context
	3   S xxx
	4   S on_insert_data
	5   S ev_dado_inserido
	6   S yyy
	7   S zzz
	8   I 1
	9   I 2
	10  S xxx2
	11  S yyy2
	12  S zzz2
	13  S datetime.sleep
	14  S Terminando a execucao...
	15  S io.writeln
	16  S chave
	17  S valor
	18  S Inserido chave 
	19  S  com valor 
	20  I 4
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [context]
		ldconst 3 --> [xxx]
		joinc
		ldconst 2 --> [context]
		ldconst 4 --> [on_insert_data]
		ldconst 5 --> [ev_dado_inserido]
		bcontextev
		ldconst 2 --> [context]
		ldconst 3 --> [xxx]
		ldconst 6 --> [yyy]
		ldconst 7 --> [zzz]
		ldconst 8 --> [1]
		ldconst 9 --> [2]
		publishd
		ldconst 2 --> [context]
		ldconst 10 --> [xxx2]
		ldconst 11 --> [yyy2]
		ldconst 12 --> [zzz2]
		ldconst 8 --> [1]
		ldconst 9 --> [2]
		publishd
		ldconst 9 --> [2]
		lcall 13 --> [datetime.sleep]
		ldconst 14 --> [Terminando a execucao...]
		ldconst 8 --> [1]
		lcall 15 --> [io.writeln]
		stop
	.end
	.method ev_dado_inserido
		.param 0 string chave
		.param 1 string valor
		ldconst 18 --> [Inserido chave ]
		ldpar 0 --> [chave]
		ldconst 19 --> [ com valor ]
		ldpar 1 --> [valor]
		ldconst 20 --> [4]
		lcall 15 --> [io.writeln]
		ret
	.end
.end
