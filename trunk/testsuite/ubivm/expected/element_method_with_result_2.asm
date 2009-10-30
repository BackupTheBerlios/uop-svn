Entity start
	No options
	Constants
		0 S start
		1 S x
		2 S result
		3 S e
		4 S elemento
		5 S y
		6 S result: 
		7 I 2
		8 S io.writeln
	End
	Valid context (always)
	No properties
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
		stvar 1 --> [e]
		ldvar 1 --> [e]
		mcall 5 --> [y]
		stvar 0 --> [result]
		ldconst 6 --> [result: ]
		ldvar 0 --> [result]
		ldconst 7 --> [2]
		lcall 8 --> [io.writeln]
		ret
	End
End
Entity elemento
	No options
	Constants
		0 S elemento
		1 S y
		2 S oi
	End
	Valid context (always)
	No properties
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
