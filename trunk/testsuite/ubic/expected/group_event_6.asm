.constant_pool
	0   S start
	1   S constructor
	2   S context
	3   S xxx
	4   S on_insert_data
	5   S ev_dado_inserido
	6   S on_remove_data
	7   S ev_dado_removido
	8   S yyy
	9   S zzz
	10  I 1
	11  I 2
	12  S xxx2
	13  S yyy2
	14  S zzz2
	15  S datetime.sleep
	16  S Valor removido: 
	17  S io.writeln
	18  S Terminando a execucao...
	19  S chave
	20  S valor
	21  S Inserido chave 
	22  S  com valor 
	23  I 4
	24  S Removido chave 
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
		ldconst 6 --> [on_remove_data]
		ldconst 7 --> [ev_dado_removido]
		bcontextev
		ldconst 2 --> [context]
		ldconst 3 --> [xxx]
		ldconst 8 --> [yyy]
		ldconst 9 --> [zzz]
		ldconst 10 --> [1]
		ldconst 11 --> [2]
		publishd
		ldconst 2 --> [context]
		ldconst 12 --> [xxx2]
		ldconst 13 --> [yyy2]
		ldconst 14 --> [zzz2]
		ldconst 10 --> [1]
		ldconst 11 --> [2]
		publishd
		ldconst 11 --> [2]
		lcall 15 --> [datetime.sleep]
		ldconst 16 --> [Valor removido: ]
		ldconst 2 --> [context]
		ldconst 3 --> [xxx]
		ldconst 10 --> [1]
		getd
		ldconst 11 --> [2]
		lcall 17 --> [io.writeln]
		ldconst 16 --> [Valor removido: ]
		ldconst 2 --> [context]
		ldconst 12 --> [xxx2]
		ldconst 10 --> [1]
		getd
		ldconst 11 --> [2]
		lcall 17 --> [io.writeln]
		ldconst 18 --> [Terminando a execucao...]
		ldconst 10 --> [1]
		lcall 17 --> [io.writeln]
		stop
	.end
	.method ev_dado_inserido
		.param 0 string chave
		.param 1 string valor
		ldconst 21 --> [Inserido chave ]
		ldpar 0 --> [chave]
		ldconst 22 --> [ com valor ]
		ldpar 1 --> [valor]
		ldconst 23 --> [4]
		lcall 17 --> [io.writeln]
		ret
	.end
	.method ev_dado_removido
		.param 0 string chave
		.param 1 string valor
		ldconst 24 --> [Removido chave ]
		ldpar 0 --> [chave]
		ldconst 22 --> [ com valor ]
		ldpar 1 --> [valor]
		ldconst 23 --> [4]
		lcall 17 --> [io.writeln]
		ret
	.end
.end
