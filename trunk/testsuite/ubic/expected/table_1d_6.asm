Entity start
	Constants
		0 S start
		1 S tab
		2 S 20
		3 I 20
		4 S 10
		5 I 10
		6 S tab[1]=
		7 I 1
		8 I 2
		9 S io.writeln
		10 S tab[2]=
	End
	Def start
		No parameters
		Local variables
			0 table tab
		End
		No results
		ldconst 2 --> [20]
		ldconst 3 --> [20]
		sttab 0 --> [tab]
		ldconst 4 --> [10]
		ldconst 5 --> [10]
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
