Entity start
	No options
	Constants
		0 S start
		1 S result
		2 S x
		3 S result: 
		4 I 2
		5 S io.writeln
		6 S oi
	End
	Def start
		No parameters
		Local variables
			0 string result
		End
		No results
		ldself
		mcall 2 --> [x]
		stvar 0 --> [result]
		ldconst 3 --> [result: ]
		ldvar 0 --> [result]
		ldconst 4 --> [2]
		lcall 5 --> [io.writeln]
		stop
	End
	Def x
		No parameters
		No local variables
		Result
			0 string
		End
		ldconst 6 --> [oi]
		stresult 0
		ret
	End
End
