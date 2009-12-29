.constant_pool
	0   S start
	1   S adicao
	2   S x
	3   S y
	4   S subtracao
	5   S constructor
	6   S a
	7   S s
	8   I 10
	9   I 20
	10  S Adicao dos valores    : 
	11  I 2
	12  S io.writeln
	13  S Subtracao dos valores : 
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
	.method subtracao
		.param 0 int x
		.param 1 int y
		.result 0 int
		ldpar 0 --> [x]
		ldpar 1 --> [y]
		sub
		stresult 0
		ret
	.end
	.method constructor
		.var 0 int a
		.var 1 int s
		ldconst 8 --> [10]
		ldconst 9 --> [20]
		ldself
		mcall 1 --> [adicao]
		stvar 0 --> [a]
		ldconst 8 --> [10]
		ldconst 9 --> [20]
		ldself
		mcall 4 --> [subtracao]
		stvar 1 --> [s]
		ldconst 10 --> [Adicao dos valores    : ]
		ldvar 0 --> [a]
		ldconst 11 --> [2]
		lcall 12 --> [io.writeln]
		ldconst 13 --> [Subtracao dos valores : ]
		ldvar 1 --> [s]
		ldconst 11 --> [2]
		lcall 12 --> [io.writeln]
		stop
	.end
.end
