.constant_pool
	0   S start
	1   S constructor
	2   S e
	3   S elemento
	4   S imprime
	5   S Oi !!!!
	6   I 1
	7   S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element e
		newelem 3 --> [elemento]
		stvar 0 --> [e]
		ldvar 0 --> [e]
		mcall 4 --> [imprime]
		stop
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method imprime
		ldconst 5 --> [Oi !!!!]
		ldconst 6 --> [1]
		lcall 7 --> [io.writeln]
		ret
	.end
.end
