Entity elemento
	No options
	Constants
		0 S elemento
		1 S x
		2 S number1
		3 S msg1
		4 S number2
		5 S msg2
		6 S number1=
		7 S  msg1=
		8 I 4
		9 S io.writeln
		10 S number2=
		11 S  msg2=
	End
	No properties
	Def x
		Parameters
			0 int number1
			1 string msg1
			2 int number2
			3 string msg2
		End
		No local variables
		No results
		ldconst 6 --> [number1=]
		ldpar 0 --> [number1]
		ldconst 7 --> [ msg1=]
		ldpar 1 --> [msg1]
		ldconst 8 --> [4]
		lcall 9 --> [io.writeln]
		ldconst 10 --> [number2=]
		ldpar 2 --> [number2]
		ldconst 11 --> [ msg2=]
		ldpar 3 --> [msg2]
		ldconst 8 --> [4]
		lcall 9 --> [io.writeln]
		ret
	End
End
Entity start
	No options
	Constants
		0 S start
		1 S e
		2 S elemento
		3 I 1
		4 S um
		5 I 2
		6 S dois
		7 S x
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
		ldconst 3 --> [1]
		ldconst 4 --> [um]
		ldconst 5 --> [2]
		ldconst 6 --> [dois]
		ldvar 0 --> [e]
		mcall 7 --> [x]
		stop
	End
End
