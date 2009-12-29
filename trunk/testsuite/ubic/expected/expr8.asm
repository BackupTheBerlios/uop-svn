.constant_pool
	0   S start
	1   S constructor
	2   S (2 * (8 - 18 / 9 * (7 * 8 - 4 + 5 * 7) - 6) * (49 / 7 - 3))=
	3   I 2
	4   I 8
	5   I 18
	6   I 9
	7   I 7
	8   I 4
	9   I 5
	10  I 6
	11  I 49
	12  I 3
	13  S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [(2 * (8 - 18 / 9 * (7 * 8 - 4 + 5 * 7) - 6) * (49 / 7 - 3))=]
		ldconst 3 --> [2]
		ldconst 4 --> [8]
		ldconst 5 --> [18]
		ldconst 6 --> [9]
		div
		ldconst 7 --> [7]
		ldconst 4 --> [8]
		mul
		ldconst 8 --> [4]
		sub
		ldconst 9 --> [5]
		ldconst 7 --> [7]
		mul
		add
		mul
		sub
		ldconst 10 --> [6]
		sub
		mul
		ldconst 11 --> [49]
		ldconst 7 --> [7]
		div
		ldconst 12 --> [3]
		sub
		mul
		ldconst 3 --> [2]
		lcall 13 --> [io.writeln]
		stop
	.end
.end
