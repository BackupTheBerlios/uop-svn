Entity start
	No options
	Constants
		0 S start
		1 S oi
		2 S oi de novo !!!
		3 S x
		4 S msg1
		5 S msg2
		6 S msg1=
		7 I 2
		8 S io.writeln
		9 S msg2=
	End
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [oi]
		ldconst 2 --> [oi de novo !!!]
		ldself
		mcall 3 --> [x]
		stop
	End
	Def x
		Parameters
			0 string msg1
			1 string msg2
		End
		No local variables
		No results
		ldconst 6 --> [msg1=]
		ldpar 0 --> [msg1]
		ldconst 7 --> [2]
		lcall 8 --> [io.writeln]
		ldconst 9 --> [msg2=]
		ldpar 1 --> [msg2]
		ldconst 7 --> [2]
		lcall 8 --> [io.writeln]
		ret
	End
End
