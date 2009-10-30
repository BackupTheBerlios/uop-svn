Entity start
	No options
	Constants
		0 S start
		1 I 1
		2 S um
		3 I 2
		4 S dois
		5 S x
		6 S number1
		7 S msg1
		8 S number2
		9 S msg2
		10 S number1=
		11 S  msg1=
		12 I 4
		13 S io.writeln
		14 S number2=
		15 S  msg2=
	End
	No properties
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [1]
		ldconst 2 --> [um]
		ldconst 3 --> [2]
		ldconst 4 --> [dois]
		ldself
		mcall 5 --> [x]
		stop
	End
	Def x
		Parameters
			0 int number1
			1 string msg1
			2 int number2
			3 string msg2
		End
		No local variables
		No results
		ldconst 10 --> [number1=]
		ldpar 0 --> [number1]
		ldconst 11 --> [ msg1=]
		ldpar 1 --> [msg1]
		ldconst 12 --> [4]
		lcall 13 --> [io.writeln]
		ldconst 14 --> [number2=]
		ldpar 2 --> [number2]
		ldconst 15 --> [ msg2=]
		ldpar 3 --> [msg2]
		ldconst 12 --> [4]
		lcall 13 --> [io.writeln]
		ret
	End
End
