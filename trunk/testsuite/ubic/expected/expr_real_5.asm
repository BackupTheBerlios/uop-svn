Entity start
	Constants
		0 S start
		1 S (2.0 * (49.0 / 7.0 - 3.0))=
		2 R 2.000000
		3 R 49.000000
		4 R 7.000000
		5 R 3.000000
		6 I 2
		7 S io.writeln
	End
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [(2.0 * (49.0 / 7.0 - 3.0))=]
		ldconst 2 --> [2.000000]
		ldconst 3 --> [49.000000]
		ldconst 4 --> [7.000000]
		div
		ldconst 5 --> [3.000000]
		sub
		mul
		ldconst 6 --> [2]
		lcall 7 --> [io.writeln]
		stop
	End
End
