Entity elemento
	Constants
		0 S elemento
		1 S x
		2 S oi 1
		3 S oi 2
	End
	Def x
		No parameters
		No local variables
		Result
			0 string
			1 string
		End
		ldconst 2 --> [oi 1]
		stresult 0
		ldconst 3 --> [oi 2]
		stresult 1
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
		8 S io.writeln
		9 S result2: 
	End
	Def start
		No parameters
		Local variables
			0 string result1
			1 string result2
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
		lcall 8 --> [io.writeln]
		ldconst 9 --> [result2: ]
		ldvar 1 --> [result2]
		ldconst 7 --> [2]
		lcall 8 --> [io.writeln]
		stop
	End
End
