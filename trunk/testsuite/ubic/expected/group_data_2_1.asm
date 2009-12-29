.constant_pool
	0   S start
	1   S constructor
	2   S MeuContexto
	3   S prog1
	4   S Programa 1 inserindo informacoes
	5   I 1
	6   S io.writeln
	7   S Numero 1
	8   I 100
	9   B true
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [MeuContexto]
		ldconst 3 --> [prog1]
		joinc
		ldconst 4 --> [Programa 1 inserindo informacoes]
		ldconst 5 --> [1]
		lcall 6 --> [io.writeln]
		ldconst 2 --> [MeuContexto]
		ldconst 7 --> [Numero 1]
		ldconst 8 --> [100]
		ldconst 5 --> [1]
		ldconst 5 --> [1]
		publishd
	:12   	ldconst 9 --> [true]
		ifnot 15 --> [15]
		jmp 12 --> [12]
	:15   	stop
	.end
.end
