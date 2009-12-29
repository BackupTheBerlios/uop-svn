.constant_pool
	0   S start
	1   S adicao
	2   S x
	3   S y
	4   S constructor
	5   S a
	6   I 10
	7   I 20
	8   S Adicao dos valores    : 
	9   I 2
	10  S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method adicao
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
		.var 0 int a
		ldconst 6 --> [10]
		ldconst 7 --> [20]
		ldself
		mcall 1 --> [adicao]
		stvar 0 --> [a]
		ldconst 8 --> [Adicao dos valores    : ]
		ldvar 0 --> [a]
		ldconst 9 --> [2]
		lcall 10 --> [io.writeln]
		stop
	.end
.end
