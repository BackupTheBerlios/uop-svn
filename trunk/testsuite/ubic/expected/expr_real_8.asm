.constant_pool
	0   S start
	1   S constructor
	2   S (2.0 * (8.0 - 18.0 / 9.0 * (7.0 * 8.0 - 4.0 + 5.0 * 7.0) - 6.0) * (49.0 / 7.0 - 3.0))=
	3   R 2.000000
	4   R 8.000000
	5   R 18.000000
	6   R 9.000000
	7   R 7.000000
	8   R 4.000000
	9   R 5.000000
	10  R 6.000000
	11  R 49.000000
	12  R 3.000000
	13  I 2
	14  S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [(2.0 * (8.0 - 18.0 / 9.0 * (7.0 * 8.0 - 4.0 + 5.0 * 7.0) - 6.0) * (49.0 / 7.0 - 3.0))=]
		ldconst 3 --> [2.000000]
		ldconst 4 --> [8.000000]
		ldconst 5 --> [18.000000]
		ldconst 6 --> [9.000000]
		div
		ldconst 7 --> [7.000000]
		ldconst 4 --> [8.000000]
		mul
		ldconst 8 --> [4.000000]
		sub
		ldconst 9 --> [5.000000]
		ldconst 7 --> [7.000000]
		mul
		add
		mul
		sub
		ldconst 10 --> [6.000000]
		sub
		mul
		ldconst 11 --> [49.000000]
		ldconst 7 --> [7.000000]
		div
		ldconst 12 --> [3.000000]
		sub
		mul
		ldconst 13 --> [2]
		lcall 14 --> [io.writeln]
		stop
	.end
.end
