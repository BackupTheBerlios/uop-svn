Entity elemento
	Constants
		0 S elemento
		1 S y
		2 S oi
	End
	Def y
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
		1 S x
		2 S result
		3 S e
		4 S elemento
		5 S y
		6 S result: 
		7 I 2
		8 S writeln
	End
	Def start
		No parameters
		No local variables
		No results
		ldself
		mcall 1 --> [x]
		stop
	End
	Def x
		No parameters
		Local variables
			0 string result
			1 element e
		End
		No results
		newelem 4 --> [elemento]
		stvar 0 --> [result]
		ldvar 0 --> [result]
		mcall 5 --> [y]
		stvar 1 --> [e]
		ldconst 6 --> [result: ]
		ldvar 1 --> [e]
		ldconst 7 --> [2]
		lcall 8 --> [writeln]
		ret
	End
End
