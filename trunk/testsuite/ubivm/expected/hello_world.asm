Entity start
	Constants
		0 S start
		1 S Olá mundo !!!
		2 I 1
		3 S io.writeln
	End
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [Olá mundo !!!]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		stop
	End
End
