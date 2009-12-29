.constant_pool
	0   S start
	1   S constructor
	2   S (2.0 * (49.0 / 7.0 - 3.0))=
	3   R 2.000000
	4   R 49.000000
	5   R 7.000000
	6   R 3.000000
	7   I 2
	8   S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [(2.0 * (49.0 / 7.0 - 3.0))=]
		ldconst 3 --> [2.000000]
		ldconst 4 --> [49.000000]
		ldconst 5 --> [7.000000]
		div
		ldconst 6 --> [3.000000]
		sub
		mul
		ldconst 7 --> [2]
		lcall 8 --> [io.writeln]
		stop
	.end
.end
