Entity start
	No options
	Constants
		0 S start
		1 S 2 - 1=
		2 I 2
		3 I 1
		4 S io.writeln
		5 S 2 * 7=
		6 I 7
		7 S 2 * 8 - 5=
		8 I 8
		9 I 5
		10 S 2 - 8 * 5=
		11 S (2 - 8) * 5=
		12 S (2 * (8 - 18 / 9 * (7 * 8 - 4 + 5 * 7) - 6) * (49 / 7 - 3))=
		13 I 18
		14 I 9
		15 I 4
		16 I 6
		17 I 49
		18 I 3
	End
	No properties
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [2 - 1=]
		ldconst 2 --> [2]
		ldconst 3 --> [1]
		sub
		ldconst 2 --> [2]
		lcall 4 --> [io.writeln]
		ldconst 5 --> [2 * 7=]
		ldconst 2 --> [2]
		ldconst 6 --> [7]
		mul
		ldconst 2 --> [2]
		lcall 4 --> [io.writeln]
		ldconst 7 --> [2 * 8 - 5=]
		ldconst 2 --> [2]
		ldconst 8 --> [8]
		mul
		ldconst 9 --> [5]
		sub
		ldconst 2 --> [2]
		lcall 4 --> [io.writeln]
		ldconst 10 --> [2 - 8 * 5=]
		ldconst 2 --> [2]
		ldconst 8 --> [8]
		ldconst 9 --> [5]
		mul
		sub
		ldconst 2 --> [2]
		lcall 4 --> [io.writeln]
		ldconst 11 --> [(2 - 8) * 5=]
		ldconst 2 --> [2]
		ldconst 8 --> [8]
		sub
		ldconst 9 --> [5]
		mul
		ldconst 2 --> [2]
		lcall 4 --> [io.writeln]
		ldconst 12 --> [(2 * (8 - 18 / 9 * (7 * 8 - 4 + 5 * 7) - 6) * (49 / 7 - 3))=]
		ldconst 2 --> [2]
		ldconst 8 --> [8]
		ldconst 13 --> [18]
		ldconst 14 --> [9]
		div
		ldconst 6 --> [7]
		ldconst 8 --> [8]
		mul
		ldconst 15 --> [4]
		sub
		ldconst 9 --> [5]
		ldconst 6 --> [7]
		mul
		add
		mul
		sub
		ldconst 16 --> [6]
		sub
		mul
		ldconst 17 --> [49]
		ldconst 6 --> [7]
		div
		ldconst 18 --> [3]
		sub
		mul
		ldconst 2 --> [2]
		lcall 4 --> [io.writeln]
		stop
	End
End
