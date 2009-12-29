.constant_pool
	0   S start
	1   S constructor
	2   S (2.0 * (8.0 * 6.0) * (49.0 / 7.0 - 3.0))=
	3   R 2.000000
	4   R 8.000000
	5   R 6.000000
	6   R 49.000000
	7   R 7.000000
	8   R 3.000000
	9   I 2
	10  S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [(2.0 * (8.0 * 6.0) * (49.0 / 7.0 - 3.0))=]
		ldconst 3 --> [2.000000]
		ldconst 4 --> [8.000000]
		ldconst 5 --> [6.000000]
		mul
		mul
		ldconst 6 --> [49.000000]
		ldconst 7 --> [7.000000]
		div
		ldconst 8 --> [3.000000]
		sub
		mul
		ldconst 9 --> [2]
		lcall 10 --> [io.writeln]
		stop
	.end
.end
