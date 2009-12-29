.constant_pool
	0   S servico
	1   S soma
	2   S x
	3   S y
	4   S constructor
	5   S context
	6   S destructor
	7   S start
	8   S s
	9   S on_insert_service
	10  S ev_servico_inserido
	11  S on_remove_service
	12  S ev_servico_removido
	13  S Resultado do servico soma(10,20): 
	14  I 10
	15  I 20
	16  I 2
	17  S io.writeln
	18  S datetime.sleep
	19  S Terminando a execucao...
	20  I 1
	21  S nome
	22  S Inserido servico 
	23  S Removido servico 
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
	.method destructor
		ldconst 5 --> [context]
		removes 1 --> [soma]
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
		ldconst 9 --> [on_insert_service]
		ldconst 10 --> [ev_servico_inserido]
		bcontextev
		ldconst 5 --> [context]
		ldconst 11 --> [on_remove_service]
		ldconst 12 --> [ev_servico_removido]
		bcontextev
		newelem 0 --> [servico]
		stvar 0 --> [s]
		ldconst 13 --> [Resultado do servico soma(10,20): ]
		ldconst 14 --> [10]
		ldconst 15 --> [20]
		ldconst 16 --> [2]
		ldconst 5 --> [context]
		runs 1 --> [soma]
		ldconst 16 --> [2]
		lcall 17 --> [io.writeln]
		ldvar 0 --> [s]
		mcall 6 --> [destructor]
		ldconst 16 --> [2]
		lcall 18 --> [datetime.sleep]
		ldconst 19 --> [Terminando a execucao...]
		ldconst 20 --> [1]
		lcall 17 --> [io.writeln]
		stop
	.end
	.method ev_servico_inserido
		.param 0 string nome
		ldconst 22 --> [Inserido servico ]
		ldpar 0 --> [nome]
		ldconst 16 --> [2]
		lcall 17 --> [io.writeln]
		ret
	.end
	.method ev_servico_removido
		.param 0 string nome
		ldconst 23 --> [Removido servico ]
		ldpar 0 --> [nome]
		ldconst 16 --> [2]
		lcall 17 --> [io.writeln]
		ret
	.end
.end
