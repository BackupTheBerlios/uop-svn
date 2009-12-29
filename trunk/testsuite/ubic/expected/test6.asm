.constant_pool
	0   S start
	1   S constructor
	2   S v1
	3   I 0
	4   S v1 no metodo start/0: 
	5   I 2
	6   S io.writeln
	7   S metodo1
	8   I 1
	9   S V1 no metodo metodo1/0: 
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int v1
		ldconst 3 --> [0]
		stvar 0 --> [v1]
		ldconst 4 --> [v1 no metodo start/0: ]
		ldvar 0 --> [v1]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ldself
		mcall 7 --> [metodo1]
		ldconst 4 --> [v1 no metodo start/0: ]
		ldvar 0 --> [v1]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		stop
	.end
	.method metodo1
		.var 0 int v1
		ldconst 8 --> [1]
		stvar 0 --> [v1]
		ldconst 9 --> [V1 no metodo metodo1/0: ]
		ldvar 0 --> [v1]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ret
	.end
.end
