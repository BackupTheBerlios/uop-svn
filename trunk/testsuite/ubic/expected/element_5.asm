Entity elemento
	No options
	Constants
		0 S elemento
		1 S x
		2 S msg
		3 S msg=
		4 I 2
		5 S io.writeln
	End
	No properties
	Def x
		Parameters
			0 string msg
		End
		No local variables
		No results
		ldconst 3 --> [msg=]
		ldpar 0 --> [msg]
		ldconst 4 --> [2]
		lcall 5 --> [io.writeln]
		ret
	End
End
Entity start
	No options
	Constants
		0 S start
		1 S e
		2 S elemento
		3 S oi
		4 S x
	End
	No properties
	Def start
		No parameters
		Local variables
			0 element e
		End
		No results
		newelem 2 --> [elemento]
		stvar 0 --> [e]
		ldconst 3 --> [oi]
		ldvar 0 --> [e]
		mcall 4 --> [x]
		stop
	End
End
