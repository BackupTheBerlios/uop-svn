.constant_pool
	0   S start
	1   S constructor
	2   S antes da chamada a x
	3   I 1
	4   S io.writeln
	5   S x
	6   S depois da chamada a x
	7   S no metodo x
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [antes da chamada a x]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ldself
		mcall 5 --> [x]
		ldconst 6 --> [depois da chamada a x]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		stop
	.end
	.method x
		ldconst 7 --> [no metodo x]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ret
	.end
.end
