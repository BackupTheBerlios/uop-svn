Entity start
	No options
	Constants
		0 S start
		1 S x
		2 I 1
		3 S x=
		4 I 2
		5 S io.writeln
		6 I 10
	End
	No properties
	Def start
		No parameters
		Local variables
			0 int x
		End
		No results
		ldconst 2 --> [1]
		stvar 0 --> [x]
	2:	ldconst 3 --> [x=]
		ldvar 0 --> [x]
		ldconst 4 --> [2]
		lcall 5 --> [io.writeln]
		ldvar 0 --> [x]
		ldconst 2 --> [1]
		add
		stvar 0 --> [x]
		ldvar 0 --> [x]
		ldconst 6 --> [10]
		gt
		ifnot 2 --> [2]
		stop
	End
End
