.constant_pool
	0   S start
	1   S constructor
	2   S Olá mundo !!!
	3   I 1
	4   S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [Olá mundo !!!]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		stop
	.end
.end
