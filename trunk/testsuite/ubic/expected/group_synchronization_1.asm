.constant_pool
	0   S start
	1   S constructor
	2   S p
	3   S process
	4   S context
	5   S Eu
	6   S Resultado: 
	7   S Resultado
	8   I 1
	9   I 2
	10  S io.writeln
	11  I 10
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element p
		newelem 3 --> [process]
		stvar 0 --> [p]
		ldconst 4 --> [context]
		ldconst 5 --> [Eu]
		joinc
		ldconst 6 --> [Resultado: ]
		ldconst 4 --> [context]
		ldconst 7 --> [Resultado]
		ldconst 8 --> [1]
		getd
		ldconst 9 --> [2]
		lcall 10 --> [io.writeln]
		stop
	.end
.end
.entity process
	.option parallel
	.valid_context_when (always)
	.method constructor
		ldconst 4 --> [context]
		ldconst 5 --> [Eu]
		joinc
		ldconst 4 --> [context]
		ldconst 7 --> [Resultado]
		ldconst 11 --> [10]
		ldconst 9 --> [2]
		mul
		ldconst 8 --> [1]
		ldconst 8 --> [1]
		publishd
		ret
	.end
.end
