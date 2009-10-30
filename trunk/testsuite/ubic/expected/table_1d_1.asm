Entity start
	No options
	Constants
		0 S start
		1 S tab
		2 I 1
		3 I 100
		4 I 2
		5 I 200
		6 S tab[1]=
		7 S io.writeln
		8 S tab[2]=
	End
	No properties
	Def start
		No parameters
		Local variables
			0 table tab
		End
		No results
		ldconst 2 --> [1]
		ldconst 3 --> [100]
		sttab 0 --> [tab]
		ldconst 4 --> [2]
		ldconst 5 --> [200]
		sttab 0 --> [tab]
		ldconst 6 --> [tab[1]=]
		ldconst 2 --> [1]
		ldtab 0 --> [tab]
		ldconst 4 --> [2]
		lcall 7 --> [io.writeln]
		ldconst 8 --> [tab[2]=]
		ldconst 4 --> [2]
		ldtab 0 --> [tab]
		ldconst 4 --> [2]
		lcall 7 --> [io.writeln]
		stop
	End
End
