Entity elemento
	Constants
		0 S elemento
		1 S x
		2 S msg1
		3 S msg2
		4 S msg1=
		5 I 2
		6 S io.writeln
		7 S msg2=
	End
	Def x
		Parameters
			0 string msg1
			1 string msg2
		End
		No local variables
		No results
		ldconst 4 --> [msg1=]
		ldpar 0 --> [msg1]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ldconst 7 --> [msg2=]
		ldpar 1 --> [msg2]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ret
	End
End
Entity start
	Constants
		0 S start
		1 S e
		2 S elemento
		3 S oi
		4 S oi de novo !!!
		5 S x
	End
	Def start
		No parameters
		Local variables
			0 element e
		End
		No results
		newelem 2 --> [elemento]
		stvar 0 --> [e]
		ldconst 3 --> [oi]
		ldconst 4 --> [oi de novo !!!]
		ldvar 0 --> [e]
		mcall 5 --> [x]
		stop
	End
End
