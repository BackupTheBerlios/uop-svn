.constant_pool
	0   S start
	1   S constructor
	2   S v1
	3   S Hello world !!!
	4   S v2
	5   I 1
	6   S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 string v1
		.var 1 string v2
		ldconst 3 --> [Hello world !!!]
		stvar 0 --> [v1]
		ldvar 0 --> [v1]
		ldconst 5 --> [1]
		lcall 6 --> [io.writeln]
		ldvar 0 --> [v1]
		stvar 1 --> [v2]
		ldvar 1 --> [v2]
		ldconst 5 --> [1]
		lcall 6 --> [io.writeln]
		stop
	.end
.end
