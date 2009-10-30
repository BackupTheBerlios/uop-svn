Entity start
	No options
	Constants
		0 S start
		1 S x
		2 I 20
		3 I 1
		4 I 10
		5 S x entre 1 e 10
		6 S io.writeln
		7 I 11
		8 S x entre 11 e 20
		9 S x > 20
	End
	Valid context (always)
	No properties
	Def start
		No parameters
		Local variables
			0 int x
		End
		No results
		ldconst 2 --> [20]
		stvar 0 --> [x]
		ldvar 0 --> [x]
		ldconst 3 --> [1]
		ge
		ldvar 0 --> [x]
		ldconst 4 --> [10]
		le
		and
		ifnot 14 --> [14]
		ldconst 5 --> [x entre 1 e 10]
		ldconst 3 --> [1]
		lcall 6 --> [io.writeln]
		jmp 29 --> [29]
	14:	ldvar 0 --> [x]
		ldconst 7 --> [11]
		ge
		ldvar 0 --> [x]
		ldconst 2 --> [20]
		le
		and
		ifnot 26 --> [26]
		ldconst 8 --> [x entre 11 e 20]
		ldconst 3 --> [1]
		lcall 6 --> [io.writeln]
		jmp 29 --> [29]
	26:	ldconst 9 --> [x > 20]
		ldconst 3 --> [1]
		lcall 6 --> [io.writeln]
	29:	stop
	End
End
