Entity elemento
	Constants
		0 S elemento
		1 S x
	End
	Def x
		No parameters
		No local variables
		Result
			0 int
			1 int
		End
		ret
	End
End
Entity start
	Constants
		0 S start
		1 S result1
		2 S result2
		3 S e
		4 S elemento
		5 S x
		6 S result1: 
		7 I 2
		8 S writeln
		9 S result2: 
	End
	Def start
		No parameters
		Local variables
			0 int result1
			1 int result2
			2 element e
		End
		No results
		newelem 4 --> [elemento]
		stvar 2 --> [e]
		ldvar 2 --> [e]
		mcall 5 --> [x]
		stvar 0 --> [result1]
		stvar 1 --> [result2]
		ldconst 6 --> [result1: ]
		ldvar 0 --> [result1]
		ldconst 7 --> [2]
		lcall 8 --> [writeln]
		ldconst 9 --> [result2: ]
		ldvar 1 --> [result2]
		ldconst 7 --> [2]
		lcall 8 --> [writeln]
		stop
	End
End
