Entity start
	Constants
		0 S start
		1 S (2 * (8 - 18 / 9 * (7 * 8 - 4 + 5 * 7) - 6) * (49 / 7 - 3))=
		2 I 2
		3 I 8
		4 I 18
		5 I 9
		6 I 7
		7 I 4
		8 I 5
		9 I 6
		10 I 49
		11 I 3
		12 S writeln
	End
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [(2 * (8 - 18 / 9 * (7 * 8 - 4 + 5 * 7) - 6) * (49 / 7 - 3))=]
		ldconst 2 --> [2]
		ldconst 3 --> [8]
		ldconst 4 --> [18]
		ldconst 5 --> [9]
		div
		ldconst 6 --> [7]
		ldconst 3 --> [8]
		mul
		ldconst 7 --> [4]
		sub
		ldconst 8 --> [5]
		ldconst 6 --> [7]
		mul
		add
		mul
		sub
		ldconst 9 --> [6]
		sub
		mul
		ldconst 10 --> [49]
		ldconst 6 --> [7]
		div
		ldconst 11 --> [3]
		sub
		mul
		ldconst 2 --> [2]
		lcall 12 --> [writeln]
		stop
	End
End
