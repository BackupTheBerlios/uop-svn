Entity start
	Constants
		0 S start
		1 I 10
		2 I 20
		3 I 1
		4 S writeln
		5 I 30
		6 I 5
	End
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [10]
		ldconst 2 --> [20]
		mul
		ldconst 3 --> [1]
		lcall 4 --> [writeln]
		ldconst 1 --> [10]
		ldconst 2 --> [20]
		mul
		ldconst 5 --> [30]
		div
		ldconst 3 --> [1]
		lcall 4 --> [writeln]
		ldconst 1 --> [10]
		ldconst 2 --> [20]
		mul
		ldconst 6 --> [5]
		div
		ldconst 3 --> [1]
		lcall 4 --> [writeln]
		stop
	End
End