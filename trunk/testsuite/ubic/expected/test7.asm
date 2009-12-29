.constant_pool
	0   S start
	1   S constructor
	2   S v1
	3   I 0
	4   S v1 em start/0: 
	5   I 2
	6   S io.writeln
	7   S Nome
	8   S metodo1
	9   S v1 em metodo1/1: 
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int v1
		ldconst 3 --> [0]
		stvar 0 --> [v1]
		ldconst 4 --> [v1 em start/0: ]
		ldvar 0 --> [v1]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ldconst 7 --> [Nome]
		ldself
		mcall 8 --> [metodo1]
		ldconst 4 --> [v1 em start/0: ]
		ldvar 0 --> [v1]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		stop
	.end
	.method metodo1
		.param 0 string v1
		ldconst 9 --> [v1 em metodo1/1: ]
		ldpar 0 --> [v1]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ret
	.end
.end
