Entity start
	Constants
		0 S start
		1 S Olá mundo !!!
		2 I 1
		3 S io.writeln
		4 S Mais um olá mundo !!!
	End
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [Olá mundo !!!]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		ldconst 4 --> [Mais um olá mundo !!!]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		stop
	End
End
