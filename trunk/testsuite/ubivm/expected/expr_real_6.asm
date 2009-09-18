Entity start
	Constants
		0 S start
		1 S (2.0 * (8.0 * 6.0) * (49.0 / 7.0 - 3.0))=
		2 R 2.000000
		3 R 8.000000
		4 R 6.000000
		5 R 49.000000
		6 R 7.000000
		7 R 3.000000
		8 I 2
		9 S io.writeln
	End
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [(2.0 * (8.0 * 6.0) * (49.0 / 7.0 - 3.0))=]
		ldconst 2 --> [2.000000]
		ldconst 3 --> [8.000000]
		ldconst 4 --> [6.000000]
		mul
		mul
		ldconst 5 --> [49.000000]
		ldconst 6 --> [7.000000]
		div
		ldconst 7 --> [3.000000]
		sub
		mul
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		stop
	End
End
