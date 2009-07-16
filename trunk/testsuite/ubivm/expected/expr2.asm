Entity start
	Constants
		3 I 1
		1 I 10
		2 I 20
		5 I 30
		6 I 5
		0 S start
		4 S writeln
	End
	Def start
		ldconst 1 --> [10]
		ldconst 2 --> [20]
		add
		ldconst 3 --> [1]
		lcall 4 --> [writeln]
		ldconst 1 --> [10]
		ldconst 2 --> [20]
		add
		ldconst 5 --> [30]
		add
		ldconst 3 --> [1]
		lcall 4 --> [writeln]
		ldconst 1 --> [10]
		ldconst 2 --> [20]
		add
		ldconst 6 --> [5]
		sub
		ldconst 3 --> [1]
		lcall 4 --> [writeln]
		stop
	End
End
