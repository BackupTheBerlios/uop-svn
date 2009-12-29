.constant_pool
	0   S start
	1   S constructor
	2   S e
	3   S elemento
	4   S Antes de chamar imprime
	5   I 1
	6   S io.writeln
	7   S imprime
	8   S Depois de chamar imprime
	9   S Metodo elemento.imprime()
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element e
		newelem 3 --> [elemento]
		stvar 0 --> [e]
		ldconst 4 --> [Antes de chamar imprime]
		ldconst 5 --> [1]
		lcall 6 --> [io.writeln]
		ldvar 0 --> [e]
		mcall 7 --> [imprime]
		ldconst 8 --> [Depois de chamar imprime]
		ldconst 5 --> [1]
		lcall 6 --> [io.writeln]
		stop
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method imprime
		ldconst 9 --> [Metodo elemento.imprime()]
		ldconst 5 --> [1]
		lcall 6 --> [io.writeln]
		ret
	.end
.end
