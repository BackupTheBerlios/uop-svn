Entity elemento
	Constants
		0 S elemento
		1 S x
		2 S antes da chamada a elemento::y
		3 I 1
		4 S io.writeln
		5 S y
		6 S depois da chamada a elemento::y
		7 S no metodo elemento::y
	End
	Def x
		No parameters
		No local variables
		No results
		ldconst 2 --> [antes da chamada a elemento::y]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ldself
		mcall 5 --> [y]
		ldconst 6 --> [depois da chamada a elemento::y]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ret
	End
	Def y
		No parameters
		No local variables
		No results
		ldconst 7 --> [no metodo elemento::y]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ret
	End
End
Entity start
	Constants
		0 S start
		1 S antes da chamada a start::x
		2 I 1
		3 S io.writeln
		4 S x
		5 S depois da chamada a start::x
		6 S antes da chamada a start::y
		7 S y
		8 S depois da chamada a start::y
		9 S e
		10 S antes da chamada a elemento::x
		11 S elemento
		12 S depois da chamada a elemento::x
	End
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [antes da chamada a start::x]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		ldself
		mcall 4 --> [x]
		ldconst 5 --> [depois da chamada a start::x]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		stop
	End
	Def x
		No parameters
		No local variables
		No results
		ldconst 6 --> [antes da chamada a start::y]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		ldself
		mcall 7 --> [y]
		ldconst 8 --> [depois da chamada a start::y]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		ret
	End
	Def y
		No parameters
		Local variables
			0 element e
		End
		No results
		ldconst 10 --> [antes da chamada a elemento::x]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		newelem 11 --> [elemento]
		stvar 0 --> [e]
		ldvar 0 --> [e]
		mcall 4 --> [x]
		ldconst 12 --> [depois da chamada a elemento::x]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		ret
	End
End
