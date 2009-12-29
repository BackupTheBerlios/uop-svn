.constant_pool
	0   S servico
	1   S soma
	2   S x
	3   S y
	4   S constructor
	5   S context
	6   S start
	7   S s
	8   S on_insert_service
	9   S ev_servico_inserido
	10  I 2
	11  S datetime.sleep
	12  S Terminando a execucao...
	13  I 1
	14  S io.writeln
	15  S nome
	16  S Inserido servico 
.end
.entity servico
	.valid_context_when (always)
	.method soma
		.param 0 int x
		.param 1 int y
		.result 0 int
		ldpar 0 --> [x]
		ldpar 1 --> [y]
		add
		stresult 0
		ret
	.end
	.method constructor
		ldconst 5 --> [context]
		ldconst 5 --> [context]
		joinc
		ldconst 5 --> [context]
		publishs 1 --> [soma]
		ret
	.end
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element s
		ldconst 5 --> [context]
		ldconst 5 --> [context]
		joinc
		ldconst 5 --> [context]
		ldconst 8 --> [on_insert_service]
		ldconst 9 --> [ev_servico_inserido]
		bcontextev
		newelem 0 --> [servico]
		stvar 0 --> [s]
		ldconst 10 --> [2]
		lcall 11 --> [datetime.sleep]
		ldconst 12 --> [Terminando a execucao...]
		ldconst 13 --> [1]
		lcall 14 --> [io.writeln]
		stop
	.end
	.method ev_servico_inserido
		.param 0 string nome
		ldconst 16 --> [Inserido servico ]
		ldpar 0 --> [nome]
		ldconst 10 --> [2]
		lcall 14 --> [io.writeln]
		ret
	.end
.end
