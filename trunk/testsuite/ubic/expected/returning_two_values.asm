.constant_pool
	0   S start
	1   S calcula
	2   S x
	3   S y
	4   S constructor
	5   S a
	6   S s
	7   I 10
	8   I 20
	9   S Adicao dos valores    : 
	10  I 2
	11  S io.writeln
	12  S Subtracao dos valores : 
.end
.entity start
	.valid_context_when (always)
	.method calcula
		.param 0 int x
		.param 1 int y
		.result 0 int
		.result 1 int
		ldpar 0 --> [x]
		ldpar 1 --> [y]
		add
		stresult 0
		ldpar 0 --> [x]
		ldpar 1 --> [y]
		sub
		stresult 1
		ret
	.end
	.method constructor
		.var 0 int a
		.var 1 int s
		ldconst 7 --> [10]
		ldconst 8 --> [20]
		ldself
		mcall 1 --> [calcula]
		stvar 0 --> [a]
		stvar 1 --> [s]
		ldconst 9 --> [Adicao dos valores    : ]
		ldvar 0 --> [a]
		ldconst 10 --> [2]
		lcall 11 --> [io.writeln]
		ldconst 12 --> [Subtracao dos valores : ]
		ldvar 1 --> [s]
		ldconst 10 --> [2]
		lcall 11 --> [io.writeln]
		stop
	.end
.end
