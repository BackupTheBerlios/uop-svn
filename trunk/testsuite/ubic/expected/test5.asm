.constant_pool
	0   S start
	1   S constructor
	2   S Hello world !!!
	3   I 1
	4   S io.writeln
	5   S metodo1
	6   S Depois de metodo1/0
	7   S metodo2
	8   S Depois de metodo2/0
	9   S metodo3
	10  S Depois de metodo3/0
	11  S Hello world in action1/0 !!!
	12  S Hello world in action2/0 !!!
	13  S Hello world in action3/0 !!!
	14  S Depois da acao2/0 na acao 3
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [Hello world !!!]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ldself
		mcall 5 --> [metodo1]
		ldconst 6 --> [Depois de metodo1/0]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ldself
		mcall 7 --> [metodo2]
		ldconst 8 --> [Depois de metodo2/0]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ldself
		mcall 9 --> [metodo3]
		ldconst 10 --> [Depois de metodo3/0]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		stop
	.end
	.method metodo1
		ldconst 11 --> [Hello world in action1/0 !!!]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ret
	.end
	.method metodo2
		ldconst 12 --> [Hello world in action2/0 !!!]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ret
	.end
	.method metodo3
		ldconst 13 --> [Hello world in action3/0 !!!]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ldself
		mcall 7 --> [metodo2]
		ldconst 14 --> [Depois da acao2/0 na acao 3]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ret
	.end
.end
