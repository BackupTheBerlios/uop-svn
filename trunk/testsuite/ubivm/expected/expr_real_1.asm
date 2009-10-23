Entity start
	No options
	Constants
		0 S start
		1 R 10.000000
		2 R 20.000000
		3 I 1
		4 S io.writeln
	End
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [10.000000]
		ldconst 2 --> [20.000000]
		add
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		stop
	End
End
