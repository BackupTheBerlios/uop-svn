Entity start
	Constants
		0 S start
		1 S Olá mundo !!!
		2 I 1
		3 S writeln
	End
	Def start
		No local variables
		ldconst 1 --> [Olá mundo !!!]
		ldconst 2 --> [1]
		lcall 3 --> [writeln]
		stop
	End
End
