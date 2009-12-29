.constant_pool
	0   S start
	1   S constructor
	2   S var1
	3   S var2
	4   I 10
	5   I 20
	6   I 1
	7   S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int var1
		.var 1 int var2
		ldconst 4 --> [10]
		stvar 0 --> [var1]
		ldvar 0 --> [var1]
		ldconst 5 --> [20]
		add
		stvar 1 --> [var2]
		ldvar 1 --> [var2]
		ldconst 6 --> [1]
		lcall 7 --> [io.writeln]
		stop
	.end
.end
