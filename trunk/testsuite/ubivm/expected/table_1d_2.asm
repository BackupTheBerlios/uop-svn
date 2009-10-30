Entity start
	No options
	Constants
		0 S start
		1 S tab
		2 S Alex
		3 I 34
		4 S Gracy
		5 I 32
		6 S Gabriel
		7 I 1
		8 S Alex   =
		9 I 2
		10 S io.writeln
		11 S Gracy  =
		12 S Gabriel=
	End
	No properties
	Def start
		No parameters
		Local variables
			0 table tab
		End
		No results
		ldconst 2 --> [Alex]
		ldconst 3 --> [34]
		sttab 0 --> [tab]
		ldconst 4 --> [Gracy]
		ldconst 5 --> [32]
		sttab 0 --> [tab]
		ldconst 6 --> [Gabriel]
		ldconst 7 --> [1]
		sttab 0 --> [tab]
		ldconst 8 --> [Alex   =]
		ldconst 2 --> [Alex]
		ldtab 0 --> [tab]
		ldconst 9 --> [2]
		lcall 10 --> [io.writeln]
		ldconst 11 --> [Gracy  =]
		ldconst 4 --> [Gracy]
		ldtab 0 --> [tab]
		ldconst 9 --> [2]
		lcall 10 --> [io.writeln]
		ldconst 12 --> [Gabriel=]
		ldconst 6 --> [Gabriel]
		ldtab 0 --> [tab]
		ldconst 9 --> [2]
		lcall 10 --> [io.writeln]
		stop
	End
End
