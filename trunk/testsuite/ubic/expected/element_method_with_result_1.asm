Entity elemento
	Constants
		0 S elemento
		1 S x
		2 S oi
	End
	Def x
		No parameters
		No local variables
		Result
			0 string
		End
		ldconst 2 --> [oi]
		stresult 0
		ret
	End
End
Entity start
	Constants
		0 S start
		1 S result
		2 S e
		3 S elemento
		4 S x
		5 S result: 
		6 I 2
		7 S writeln
	End
	Def start
		No parameters
		Local variables
			0 string result
			1 element e
		End
		No results
		newelem 3 --> [elemento]
		stvar 0 --> [result]
		ldvar 0 --> [result]
		mcall 4 --> [x]
		stvar 1 --> [e]
		ldconst 5 --> [result: ]
		ldvar 1 --> [e]
		ldconst 6 --> [2]
		lcall 7 --> [writeln]
		stop
	End
End