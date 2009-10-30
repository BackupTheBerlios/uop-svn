Entity start
	No options
	Constants
		0 S start
		1 S result1
		2 S result2
		3 S x
		4 S result1: 
		5 I 2
		6 S io.writeln
		7 S result2: 
		8 S oi 1
		9 S oi 2
	End
	Valid context (always)
	No properties
	Def start
		No parameters
		Local variables
			0 string result1
			1 string result2
		End
		No results
		ldself
		mcall 3 --> [x]
		stvar 0 --> [result1]
		stvar 1 --> [result2]
		ldconst 4 --> [result1: ]
		ldvar 0 --> [result1]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ldconst 7 --> [result2: ]
		ldvar 1 --> [result2]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		stop
	End
	Def x
		No parameters
		No local variables
		Result
			0 string
			1 string
		End
		ldconst 8 --> [oi 1]
		stresult 0
		ldconst 9 --> [oi 2]
		stresult 1
		ret
	End
End
