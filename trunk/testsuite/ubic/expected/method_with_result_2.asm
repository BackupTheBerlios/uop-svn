Entity start
	Constants
		0 S start
		1 S x
		2 S result
		3 S y
		4 S result: 
		5 I 2
		6 S writeln
		7 S oi
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
		End
		No results
		ldself
		mcall 3 --> [y]
		stvar 0 --> [result]
		ldconst 4 --> [result: ]
		ldvar 0 --> [result]
		ldconst 5 --> [2]
		lcall 6 --> [writeln]
		ret
	End
	Def y
		No parameters
		No local variables
		Result
			0 string
		End
		ldconst 7 --> [oi]
		stresult 0
		ret
	End
End