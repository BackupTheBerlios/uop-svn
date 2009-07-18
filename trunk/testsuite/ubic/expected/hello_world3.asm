Entity start
	Constants
		0 S start
		1 S Olá mundo !!!
		2 I 1
		3 S writeln
		4 S Mais teste !!!
		5 I 2
	End
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [Olá mundo !!!]
		ldconst 2 --> [1]
		lcall 3 --> [writeln]
		ldconst 1 --> [Olá mundo !!!]
		ldconst 4 --> [Mais teste !!!]
		ldconst 5 --> [2]
		lcall 3 --> [writeln]
		stop
	End
End
