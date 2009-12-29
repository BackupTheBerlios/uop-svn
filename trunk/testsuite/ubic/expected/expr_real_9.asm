.constant_pool
	0   S start
	1   S constructor
	2   S 2.0 - 1.0=
	3   R 2.000000
	4   R 1.000000
	5   I 2
	6   S io.writeln
	7   S 2.0 * 7=
	8   I 7
	9   S 2.0 * 8.0 - 5.0=
	10  R 8.000000
	11  R 5.000000
	12  S 2.0 - 8.0 * 5.0=
	13  S (2.0 - 8.0) * 5.0=
	14  S (2.0 * (8.0 - 18.0 / 9.0 * (7.0 * 8.0 - 4.0 + 5.0 * 7.0) - 6.0) * (49.0 / 7.0 - 3.0))=
	15  R 18.000000
	16  R 9.000000
	17  R 7.000000
	18  R 4.000000
	19  R 6.000000
	20  R 49.000000
	21  R 3.000000
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [2.0 - 1.0=]
		ldconst 3 --> [2.000000]
		ldconst 4 --> [1.000000]
		sub
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ldconst 7 --> [2.0 * 7=]
		ldconst 5 --> [2]
		ldconst 8 --> [7]
		mul
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ldconst 9 --> [2.0 * 8.0 - 5.0=]
		ldconst 3 --> [2.000000]
		ldconst 10 --> [8.000000]
		mul
		ldconst 11 --> [5.000000]
		sub
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ldconst 12 --> [2.0 - 8.0 * 5.0=]
		ldconst 3 --> [2.000000]
		ldconst 10 --> [8.000000]
		ldconst 11 --> [5.000000]
		mul
		sub
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ldconst 13 --> [(2.0 - 8.0) * 5.0=]
		ldconst 3 --> [2.000000]
		ldconst 10 --> [8.000000]
		sub
		ldconst 11 --> [5.000000]
		mul
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ldconst 14 --> [(2.0 * (8.0 - 18.0 / 9.0 * (7.0 * 8.0 - 4.0 + 5.0 * 7.0) - 6.0) * (49.0 / 7.0 - 3.0))=]
		ldconst 3 --> [2.000000]
		ldconst 10 --> [8.000000]
		ldconst 15 --> [18.000000]
		ldconst 16 --> [9.000000]
		div
		ldconst 17 --> [7.000000]
		ldconst 10 --> [8.000000]
		mul
		ldconst 18 --> [4.000000]
		sub
		ldconst 11 --> [5.000000]
		ldconst 17 --> [7.000000]
		mul
		add
		mul
		sub
		ldconst 19 --> [6.000000]
		sub
		mul
		ldconst 20 --> [49.000000]
		ldconst 17 --> [7.000000]
		div
		ldconst 21 --> [3.000000]
		sub
		mul
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		stop
	.end
.end
