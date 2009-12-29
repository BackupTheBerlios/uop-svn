.constant_pool
	0   S start
	1   S constructor
	2   S var1
	3   S var2
	4   R 10.990000
	5   I 1
	6   S io.writeln
	7   R 20.990000
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 real var1
		.var 1 real var2
		ldconst 4 --> [10.990000]
		stvar 0 --> [var1]
		ldvar 0 --> [var1]
		ldconst 5 --> [1]
		lcall 6 --> [io.writeln]
		ldconst 7 --> [20.990000]
		stvar 1 --> [var2]
		ldvar 1 --> [var2]
		ldconst 5 --> [1]
		lcall 6 --> [io.writeln]
		stop
	.end
.end
