Entity start
	Constants
		0 S start
		1 S 2 * (49 / 7 - 3)=
		2 I 2
		3 I 49
		4 I 7
		5 I 3
		6 S writeln
	End
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [2 * (49 / 7 - 3)=]
		ldconst 2 --> [2]
		ldconst 3 --> [49]
		ldconst 4 --> [7]
		div
		ldconst 5 --> [3]
		sub
		mul
		ldconst 2 --> [2]
		lcall 6 --> [writeln]
		stop
	End
End
