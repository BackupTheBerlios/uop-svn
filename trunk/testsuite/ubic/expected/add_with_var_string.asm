Entity start
	No options
	Constants
		0 S start
		1 S var1
		2 S var2
		3 S aaa
		4 S bbb
		5 I 1
		6 S io.writeln
	End
	No properties
	Def start
		No parameters
		Local variables
			0 string var1
			1 string var2
		End
		No results
		ldconst 3 --> [aaa]
		stvar 0 --> [var1]
		ldvar 0 --> [var1]
		ldconst 4 --> [bbb]
		add
		stvar 1 --> [var2]
		ldvar 1 --> [var2]
		ldconst 5 --> [1]
		lcall 6 --> [io.writeln]
		stop
	End
End
