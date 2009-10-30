Entity start
	No options
	Constants
		0 S start
		1 S (2 * (8 - 18 / 9 * 6) * (49 / 7 - 3))=
		2 I 2
		3 I 8
		4 I 18
		5 I 9
		6 I 6
		7 I 49
		8 I 7
		9 I 3
		10 S io.writeln
	End
	No properties
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [(2 * (8 - 18 / 9 * 6) * (49 / 7 - 3))=]
		ldconst 2 --> [2]
		ldconst 3 --> [8]
		ldconst 4 --> [18]
		ldconst 5 --> [9]
		div
		ldconst 6 --> [6]
		mul
		sub
		mul
		ldconst 7 --> [49]
		ldconst 8 --> [7]
		div
		ldconst 9 --> [3]
		sub
		mul
		ldconst 2 --> [2]
		lcall 10 --> [io.writeln]
		stop
	End
End
