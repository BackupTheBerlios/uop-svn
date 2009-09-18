Entity start
	Constants
		0 S start
		1 S antes da chamada a x
		2 I 1
		3 S io.writeln
		4 S x
		5 S depois da chamada a x
		6 S no metodo x
	End
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [antes da chamada a x]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		ldself
		mcall 4 --> [x]
		ldconst 5 --> [depois da chamada a x]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		stop
	End
	Def x
		No parameters
		No local variables
		No results
		ldconst 6 --> [no metodo x]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		ret
	End
End
