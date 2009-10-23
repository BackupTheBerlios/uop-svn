Entity start
	No options
	Constants
		0 S start
		1 S antes da chamada a x
		2 I 1
		3 S io.writeln
		4 S x
		5 S depois da chamada a x
		6 S antes da chamada a y
		7 S y
		8 S depois da chamada a y
		9 S no metodo y
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
		ldconst 6 --> [antes da chamada a y]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		ldself
		mcall 7 --> [y]
		ldconst 8 --> [depois da chamada a y]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		ret
	End
	Def y
		No parameters
		No local variables
		No results
		ldconst 9 --> [no metodo y]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		ret
	End
End
