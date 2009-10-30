Entity start
	No options
	Constants
		0 S start
		1 S (2.0 * (8.0 - 18.0 / 9.0 * (7.0 * 8.0 - 4.0 + 5.0 * 7.0) - 6.0) * (49.0 / 7.0 - 3.0))=
		2 R 2.000000
		3 R 8.000000
		4 R 18.000000
		5 R 9.000000
		6 R 7.000000
		7 R 4.000000
		8 R 5.000000
		9 R 6.000000
		10 R 49.000000
		11 R 3.000000
		12 I 2
		13 S io.writeln
	End
	No properties
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [(2.0 * (8.0 - 18.0 / 9.0 * (7.0 * 8.0 - 4.0 + 5.0 * 7.0) - 6.0) * (49.0 / 7.0 - 3.0))=]
		ldconst 2 --> [2.000000]
		ldconst 3 --> [8.000000]
		ldconst 4 --> [18.000000]
		ldconst 5 --> [9.000000]
		div
		ldconst 6 --> [7.000000]
		ldconst 3 --> [8.000000]
		mul
		ldconst 7 --> [4.000000]
		sub
		ldconst 8 --> [5.000000]
		ldconst 6 --> [7.000000]
		mul
		add
		mul
		sub
		ldconst 9 --> [6.000000]
		sub
		mul
		ldconst 10 --> [49.000000]
		ldconst 6 --> [7.000000]
		div
		ldconst 11 --> [3.000000]
		sub
		mul
		ldconst 12 --> [2]
		lcall 13 --> [io.writeln]
		stop
	End
End
