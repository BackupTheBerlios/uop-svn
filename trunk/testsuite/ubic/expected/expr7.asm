.constant_pool
	0   S start
	1   S constructor
	2   S (2 * (8 - 18 / 9 * 6) * (49 / 7 - 3))=
	3   I 2
	4   I 8
	5   I 18
	6   I 9
	7   I 6
	8   I 49
	9   I 7
	10  I 3
	11  S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [(2 * (8 - 18 / 9 * 6) * (49 / 7 - 3))=]
		ldconst 3 --> [2]
		ldconst 4 --> [8]
		ldconst 5 --> [18]
		ldconst 6 --> [9]
		div
		ldconst 7 --> [6]
		mul
		sub
		mul
		ldconst 8 --> [49]
		ldconst 9 --> [7]
		div
		ldconst 10 --> [3]
		sub
		mul
		ldconst 3 --> [2]
		lcall 11 --> [io.writeln]
		stop
	.end
.end
