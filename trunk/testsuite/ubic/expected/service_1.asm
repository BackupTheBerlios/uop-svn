.constant_pool
	0   S servico
	1   S soma
	2   S x
	3   S y
	4   S constructor
	5   S context
	6   S Alex
	7   S start
	8   S s
	9   S Soma: 
	10  I 10
	11  I 20
	12  I 2
	13  S io.writeln
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
		ldconst 6 --> [Alex]
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
		newelem 0 --> [servico]
		stvar 0 --> [s]
		ldconst 9 --> [Soma: ]
		ldconst 10 --> [10]
		ldconst 11 --> [20]
		ldconst 12 --> [2]
		ldconst 5 --> [context]
		runs 1 --> [soma]
		ldconst 12 --> [2]
		lcall 13 --> [io.writeln]
		stop
	.end
.end
