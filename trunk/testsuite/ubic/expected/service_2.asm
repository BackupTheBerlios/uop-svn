.constant_pool
	0   S servico
	1   S soma
	2   S x
	3   S y
	4   S diminui
	5   S imprime
	6   S msg
	7   S Mensagem: 
	8   I 2
	9   S io.writeln
	10  S constructor
	11  S context
	12  S Alex
	13  S start
	14  S s
	15  S Soma  : 
	16  I 10
	17  I 20
	18  S Diminui: 
	19  S Ola !!!
	20  I 1
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
	.method diminui
		.param 0 int x
		.param 1 int y
		.result 0 int
		ldpar 0 --> [x]
		ldpar 1 --> [y]
		sub
		stresult 0
		ret
	.end
	.method imprime
		.param 0 string msg
		ldconst 7 --> [Mensagem: ]
		ldpar 0 --> [msg]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		ret
	.end
	.method constructor
		ldconst 11 --> [context]
		ldconst 12 --> [Alex]
		joinc
		ldconst 11 --> [context]
		publishs 1 --> [soma]
		ldconst 11 --> [context]
		publishs 4 --> [diminui]
		ldconst 11 --> [context]
		publishs 5 --> [imprime]
		ret
	.end
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element s
		newelem 0 --> [servico]
		stvar 0 --> [s]
		ldconst 15 --> [Soma  : ]
		ldconst 16 --> [10]
		ldconst 17 --> [20]
		ldconst 8 --> [2]
		ldconst 11 --> [context]
		runs 1 --> [soma]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		ldconst 18 --> [Diminui: ]
		ldconst 16 --> [10]
		ldconst 17 --> [20]
		ldconst 8 --> [2]
		ldconst 11 --> [context]
		runs 4 --> [diminui]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		ldconst 19 --> [Ola !!!]
		ldconst 20 --> [1]
		ldconst 11 --> [context]
		runs 5 --> [imprime]
		stop
	.end
.end
