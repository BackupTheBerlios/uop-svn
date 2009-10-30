Entity start
	No options
	Constants
		0 S start
		1 S tab
		2 S 1
		3 I 10
		4 S 2
		5 I 20
		6 S tab[1]=
		7 I 1
		8 I 2
		9 S io.writeln
		10 S tab[2]=
	End
	Valid context (always)
	No properties
	Def start
		No parameters
		Local variables
			0 table tab
		End
		No results
		ldconst 2 --> [1]
		ldconst 3 --> [10]
		sttab 0 --> [tab]
		ldconst 4 --> [2]
		ldconst 5 --> [20]
		sttab 0 --> [tab]
		ldconst 6 --> [tab[1]=]
		ldconst 7 --> [1]
		ldtab 0 --> [tab]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		ldconst 10 --> [tab[2]=]
		ldconst 8 --> [2]
		ldtab 0 --> [tab]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		stop
	End
End
