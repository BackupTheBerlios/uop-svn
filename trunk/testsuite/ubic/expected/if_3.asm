Entity start
	No options
	Constants
		0 S start
		1 S x
		2 I 1
		3 I 30
		4 S x=
		5 I 2
		6 S io.writeln
		7 I 10
		8 S x entre 1 e 10
		9 I 11
		10 I 20
		11 S x entre 11 e 20
		12 S x > 20
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
		ldconst 3 --> [30]
		le
		ifnot 44 --> [44]
		jmp 12 --> [12]
	7:	ldvar 0 --> [x]
		ldconst 2 --> [1]
		add
		stvar 0 --> [x]
		jmp 2 --> [2]
	12:	ldconst 4 --> [x=]
		ldvar 0 --> [x]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ldvar 0 --> [x]
		ldconst 2 --> [1]
		ge
		ldvar 0 --> [x]
		ldconst 7 --> [10]
		le
		and
		ifnot 28 --> [28]
		ldconst 8 --> [x entre 1 e 10]
		ldconst 2 --> [1]
		lcall 6 --> [io.writeln]
		jmp 43 --> [43]
	28:	ldvar 0 --> [x]
		ldconst 9 --> [11]
		ge
		ldvar 0 --> [x]
		ldconst 10 --> [20]
		le
		and
		ifnot 40 --> [40]
		ldconst 11 --> [x entre 11 e 20]
		ldconst 2 --> [1]
		lcall 6 --> [io.writeln]
		jmp 43 --> [43]
	40:	ldconst 12 --> [x > 20]
		ldconst 2 --> [1]
		lcall 6 --> [io.writeln]
	43:	jmp 7 --> [7]
	44:	stop
	End
End
