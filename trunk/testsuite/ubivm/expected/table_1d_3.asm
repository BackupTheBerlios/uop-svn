Entity start
	No options
	Constants
		0 S start
		1 S tab
		2 S index
		3 I 1
		4 I 10
		5 S tab[
		6 S ]=
		7 I 4
		8 S io.writeln
	End
	Valid context (always)
	No properties
	Def start
		No parameters
		Local variables
			0 table tab
			1 int index
		End
		No results
		ldconst 3 --> [1]
		stvar 1 --> [index]
	2:	ldvar 1 --> [index]
		ldconst 4 --> [10]
		le
		ifnot 18 --> [18]
		jmp 12 --> [12]
	7:	ldvar 1 --> [index]
		ldconst 3 --> [1]
		add
		stvar 1 --> [index]
		jmp 2 --> [2]
	12:	ldvar 1 --> [index]
		ldvar 1 --> [index]
		ldconst 4 --> [10]
		mul
		sttab 0 --> [tab]
		jmp 7 --> [7]
	18:	ldconst 3 --> [1]
		stvar 1 --> [index]
	20:	ldvar 1 --> [index]
		ldconst 4 --> [10]
		le
		ifnot 38 --> [38]
		jmp 30 --> [30]
	25:	ldvar 1 --> [index]
		ldconst 3 --> [1]
		add
		stvar 1 --> [index]
		jmp 20 --> [20]
	30:	ldconst 5 --> [tab[]
		ldvar 1 --> [index]
		ldconst 6 --> []=]
		ldvar 1 --> [index]
		ldtab 0 --> [tab]
		ldconst 7 --> [4]
		lcall 8 --> [io.writeln]
		jmp 25 --> [25]
	38:	stop
	End
End
