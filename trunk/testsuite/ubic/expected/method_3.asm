Entity start
	Constants
		0 S start
		1 S oi
		2 S x
		3 S msg
		4 S msg=
		5 I 2
		6 S writeln
	End
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [oi]
		ldself
		mcall 2 --> [x]
		stop
	End
	Def x
		Parameters
			0 string msg
		End
		No local variables
		No results
		ldconst 4 --> [msg=]
		ldpar 0 --> [msg]
		ldconst 5 --> [2]
		lcall 6 --> [writeln]
		ret
	End
End
