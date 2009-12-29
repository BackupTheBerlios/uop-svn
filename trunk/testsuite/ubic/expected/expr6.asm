.constant_pool
	0   S start
	1   S constructor
	2   S (2 * (8 * 6) * (49 / 7 - 3))=
	3   I 2
	4   I 8
	5   I 6
	6   I 49
	7   I 7
	8   I 3
	9   S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [(2 * (8 * 6) * (49 / 7 - 3))=]
		ldconst 3 --> [2]
		ldconst 4 --> [8]
		ldconst 5 --> [6]
		mul
		mul
		ldconst 6 --> [49]
		ldconst 7 --> [7]
		div
		ldconst 8 --> [3]
		sub
		mul
		ldconst 3 --> [2]
		lcall 9 --> [io.writeln]
		stop
	.end
.end
