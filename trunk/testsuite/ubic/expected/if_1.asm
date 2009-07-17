Entity start
	Constants
		0 S start
		1 S x
		2 I 1
		3 I 10
		4 S x>10
		5 S writeln
		6 S x not > 10
	End
	Def start
		Local variables
			0 int x
		End
		ldconst 2 --> [1]
		stvar 0 --> [x]
		ldvar 0 --> [x]
		ldconst 3 --> [10]
		gt
		ifnot 10 --> [10]
		ldconst 4 --> [x>10]
		ldconst 2 --> [1]
		lcall 5 --> [writeln]
		jmp 13 --> [13]
	10:	ldconst 6 --> [x not > 10]
		ldconst 2 --> [1]
		lcall 5 --> [writeln]
	13:	stop
	End
End
