Entity start
	No options
	Constants
		0 S start
		1 S 2.0 - 1.0=
		2 R 2.000000
		3 R 1.000000
		4 I 2
		5 S io.writeln
		6 S 2.0 * 7=
		7 I 7
		8 S 2.0 * 8.0 - 5.0=
		9 R 8.000000
		10 R 5.000000
		11 S 2.0 - 8.0 * 5.0=
		12 S (2.0 - 8.0) * 5.0=
		13 S (2.0 * (8.0 - 18.0 / 9.0 * (7.0 * 8.0 - 4.0 + 5.0 * 7.0) - 6.0) * (49.0 / 7.0 - 3.0))=
		14 R 18.000000
		15 R 9.000000
		16 R 7.000000
		17 R 4.000000
		18 R 6.000000
		19 R 49.000000
		20 R 3.000000
	End
	No properties
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [2.0 - 1.0=]
		ldconst 2 --> [2.000000]
		ldconst 3 --> [1.000000]
		sub
		ldconst 4 --> [2]
		lcall 5 --> [io.writeln]
		ldconst 6 --> [2.0 * 7=]
		ldconst 4 --> [2]
		ldconst 7 --> [7]
		mul
		ldconst 4 --> [2]
		lcall 5 --> [io.writeln]
		ldconst 8 --> [2.0 * 8.0 - 5.0=]
		ldconst 2 --> [2.000000]
		ldconst 9 --> [8.000000]
		mul
		ldconst 10 --> [5.000000]
		sub
		ldconst 4 --> [2]
		lcall 5 --> [io.writeln]
		ldconst 11 --> [2.0 - 8.0 * 5.0=]
		ldconst 2 --> [2.000000]
		ldconst 9 --> [8.000000]
		ldconst 10 --> [5.000000]
		mul
		sub
		ldconst 4 --> [2]
		lcall 5 --> [io.writeln]
		ldconst 12 --> [(2.0 - 8.0) * 5.0=]
		ldconst 2 --> [2.000000]
		ldconst 9 --> [8.000000]
		sub
		ldconst 10 --> [5.000000]
		mul
		ldconst 4 --> [2]
		lcall 5 --> [io.writeln]
		ldconst 13 --> [(2.0 * (8.0 - 18.0 / 9.0 * (7.0 * 8.0 - 4.0 + 5.0 * 7.0) - 6.0) * (49.0 / 7.0 - 3.0))=]
		ldconst 2 --> [2.000000]
		ldconst 9 --> [8.000000]
		ldconst 14 --> [18.000000]
		ldconst 15 --> [9.000000]
		div
		ldconst 16 --> [7.000000]
		ldconst 9 --> [8.000000]
		mul
		ldconst 17 --> [4.000000]
		sub
		ldconst 10 --> [5.000000]
		ldconst 16 --> [7.000000]
		mul
		add
		mul
		sub
		ldconst 18 --> [6.000000]
		sub
		mul
		ldconst 19 --> [49.000000]
		ldconst 16 --> [7.000000]
		div
		ldconst 20 --> [3.000000]
		sub
		mul
		ldconst 4 --> [2]
		lcall 5 --> [io.writeln]
		stop
	End
End
