.constant_pool
	0   S start
	1   S constructor
	2   S 2 - 1=
	3   I 2
	4   I 1
	5   S io.writeln
	6   S 2 * 7=
	7   I 7
	8   S 2 * 8 - 5=
	9   I 8
	10  I 5
	11  S 2 - 8 * 5=
	12  S (2 - 8) * 5=
	13  S (2 * (8 - 18 / 9 * (7 * 8 - 4 + 5 * 7) - 6) * (49 / 7 - 3))=
	14  I 18
	15  I 9
	16  I 4
	17  I 6
	18  I 49
	19  I 3
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [2 - 1=]
		ldconst 3 --> [2]
		ldconst 4 --> [1]
		sub
		ldconst 3 --> [2]
		lcall 5 --> [io.writeln]
		ldconst 6 --> [2 * 7=]
		ldconst 3 --> [2]
		ldconst 7 --> [7]
		mul
		ldconst 3 --> [2]
		lcall 5 --> [io.writeln]
		ldconst 8 --> [2 * 8 - 5=]
		ldconst 3 --> [2]
		ldconst 9 --> [8]
		mul
		ldconst 10 --> [5]
		sub
		ldconst 3 --> [2]
		lcall 5 --> [io.writeln]
		ldconst 11 --> [2 - 8 * 5=]
		ldconst 3 --> [2]
		ldconst 9 --> [8]
		ldconst 10 --> [5]
		mul
		sub
		ldconst 3 --> [2]
		lcall 5 --> [io.writeln]
		ldconst 12 --> [(2 - 8) * 5=]
		ldconst 3 --> [2]
		ldconst 9 --> [8]
		sub
		ldconst 10 --> [5]
		mul
		ldconst 3 --> [2]
		lcall 5 --> [io.writeln]
		ldconst 13 --> [(2 * (8 - 18 / 9 * (7 * 8 - 4 + 5 * 7) - 6) * (49 / 7 - 3))=]
		ldconst 3 --> [2]
		ldconst 9 --> [8]
		ldconst 14 --> [18]
		ldconst 15 --> [9]
		div
		ldconst 7 --> [7]
		ldconst 9 --> [8]
		mul
		ldconst 16 --> [4]
		sub
		ldconst 10 --> [5]
		ldconst 7 --> [7]
		mul
		add
		mul
		sub
		ldconst 17 --> [6]
		sub
		mul
		ldconst 18 --> [49]
		ldconst 7 --> [7]
		div
		ldconst 19 --> [3]
		sub
		mul
		ldconst 3 --> [2]
		lcall 5 --> [io.writeln]
		stop
	.end
.end
