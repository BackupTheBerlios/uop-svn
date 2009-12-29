.constant_pool
	0   S start
	1   S constructor
	2   R 10.000000
	3   R 20.000000
	4   I 1
	5   S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [10.000000]
		ldconst 3 --> [20.000000]
		add
		ldconst 4 --> [1]
		lcall 5 --> [io.writeln]
		stop
	.end
.end
