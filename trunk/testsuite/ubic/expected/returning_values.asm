.constant_pool
	0   S start
	1   S multiplica
	2   S x
	3   S y
	4   S calcula
	5   S constructor
	6   S m
	7   S a
	8   S s
	9   I 10
	10  I 20
	11  S Multiplicacao dos valores: 
	12  I 2
	13  S io.writeln
	14  S Adicao dos valores       : 
	15  S Subtracao dos valores    : 
.end
.entity start
	.valid_context_when (always)
	.method multiplica
		.param 0 int x
		.param 1 int y
		.result 0 int
		ldpar 0 --> [x]
		ldpar 1 --> [y]
		mul
		stresult 0
		ret
	.end
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
		.var 0 int m
		.var 1 int a
		.var 2 int s
		ldconst 9 --> [10]
		ldconst 10 --> [20]
		ldself
		mcall 1 --> [multiplica]
		stvar 0 --> [m]
		ldconst 9 --> [10]
		ldconst 10 --> [20]
		ldself
		mcall 4 --> [calcula]
		stvar 1 --> [a]
		stvar 2 --> [s]
		ldconst 11 --> [Multiplicacao dos valores: ]
		ldvar 0 --> [m]
		ldconst 12 --> [2]
		lcall 13 --> [io.writeln]
		ldconst 14 --> [Adicao dos valores       : ]
		ldvar 1 --> [a]
		ldconst 12 --> [2]
		lcall 13 --> [io.writeln]
		ldconst 15 --> [Subtracao dos valores    : ]
		ldvar 2 --> [s]
		ldconst 12 --> [2]
		lcall 13 --> [io.writeln]
		stop
	.end
.end
