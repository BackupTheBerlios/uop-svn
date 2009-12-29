.constant_pool
	0   S soma
	1   S calcula
	2   I 10
	3   I 20
	4   S start
	5   S constructor
	6   S result
	7   S s
	8   S Resultado: 
	9   I 2
	10  S io.writeln
.end
.entity soma
	.valid_context_when (always)
	.method calcula
		.result 0 int
		ldconst 2 --> [10]
		ldconst 3 --> [20]
		add
		stresult 0
		ret
	.end
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int result
		.var 1 element s
		newelem 0 --> [soma]
		stvar 1 --> [s]
		ldvar 1 --> [s]
		mcall 1 --> [calcula]
		stvar 0 --> [result]
		ldconst 8 --> [Resultado: ]
		ldvar 0 --> [result]
		ldconst 9 --> [2]
		lcall 10 --> [io.writeln]
		stop
	.end
.end
