.constant_pool
	0   S start
	1   S constructor
	2   S 
	3   S Alex
	4   S on_new_context
	5   S ev_contexto_inserido
	6   S context
	7   S context.1
	8   S ev_contexto_inserido2
	9   S context.1.1
	10  I 2
	11  S datetime.sleep
	12  S Terminando a execucao...
	13  I 1
	14  S io.writeln
	15  S nome
	16  S Inserido contexto 
	17  S Inserido contexto em context.1: 
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> []
		ldconst 3 --> [Alex]
		joinc
		ldconst 2 --> []
		ldconst 4 --> [on_new_context]
		ldconst 5 --> [ev_contexto_inserido]
		bcontextev
		ldconst 6 --> [context]
		ldconst 3 --> [Alex]
		joinc
		ldconst 7 --> [context.1]
		ldconst 3 --> [Alex]
		joinc
		ldconst 7 --> [context.1]
		ldconst 4 --> [on_new_context]
		ldconst 8 --> [ev_contexto_inserido2]
		bcontextev
		ldconst 9 --> [context.1.1]
		ldconst 3 --> [Alex]
		joinc
		ldconst 10 --> [2]
		lcall 11 --> [datetime.sleep]
		ldconst 12 --> [Terminando a execucao...]
		ldconst 13 --> [1]
		lcall 14 --> [io.writeln]
		stop
	.end
	.method ev_contexto_inserido
		.param 0 string nome
		ldconst 16 --> [Inserido contexto ]
		ldpar 0 --> [nome]
		ldconst 10 --> [2]
		lcall 14 --> [io.writeln]
		ret
	.end
	.method ev_contexto_inserido2
		.param 0 string nome
		ldconst 17 --> [Inserido contexto em context.1: ]
		ldpar 0 --> [nome]
		ldconst 10 --> [2]
		lcall 14 --> [io.writeln]
		ret
	.end
.end
