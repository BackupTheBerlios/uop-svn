Entity start
	No options
	Constants
		0 S start
		1 I 10
		2 I 20
		3 I 1
		4 S io.writeln
	End
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [10]
		ldconst 2 --> [20]
		add
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		stop
	End
End
