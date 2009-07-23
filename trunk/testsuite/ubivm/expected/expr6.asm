Entity start
	Constants
		0 S start
		1 S (2 * (8 * 6) * (49 / 7 - 3))=
		2 I 2
		3 I 8
		4 I 6
		5 I 49
		6 I 7
		7 I 3
		8 S writeln
	End
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [(2 * (8 * 6) * (49 / 7 - 3))=]
		ldconst 2 --> [2]
		ldconst 3 --> [8]
		ldconst 4 --> [6]
		mul
		mul
		ldconst 5 --> [49]
		ldconst 6 --> [7]
		div
		ldconst 7 --> [3]
		sub
		mul
		ldconst 2 --> [2]
		lcall 8 --> [writeln]
		stop
	End
End
