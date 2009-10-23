Entity elemento
	No options
	Constants
		0 S elemento
		1 S imprime
		2 S Oi !!!!
		3 I 1
		4 S io.writeln
	End
	Def imprime
		No parameters
		No local variables
		No results
		ldconst 2 --> [Oi !!!!]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ret
	End
End
Entity start
	No options
	Constants
		0 S start
		1 S e
		2 S elemento
		3 S imprime
	End
	Def start
		No parameters
		Local variables
			0 element e
		End
		No results
		newelem 2 --> [elemento]
		stvar 0 --> [e]
		ldvar 0 --> [e]
		mcall 3 --> [imprime]
		stop
	End
End
