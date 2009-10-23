Entity start
	No options
	Constants
		0 S start
		1 S x
		2 I 1
		3 I 10
		4 S x=
		5 I 2
		6 S io.writeln
	End
	Def start
		No parameters
		Local variables
			0 int x
		End
		No results
		ldconst 2 --> [1]
		stvar 0 --> [x]
	2:	ldvar 0 --> [x]
		ldconst 3 --> [10]
		le
		ifnot 15 --> [15]
		ldconst 4 --> [x=]
		ldvar 0 --> [x]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ldvar 0 --> [x]
		ldconst 2 --> [1]
		add
		stvar 0 --> [x]
		jmp 2 --> [2]
	15:	stop
	End
End
