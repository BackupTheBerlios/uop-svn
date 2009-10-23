Entity start
	No options
	Constants
		0 S start
		1 S var1
		2 S var2
		3 S aaa
		4 I 1
		5 S io.writeln
		6 S bbb
	End
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
		ldconst 4 --> [1]
		lcall 5 --> [io.writeln]
		ldconst 6 --> [bbb]
		stvar 1 --> [var2]
		ldvar 1 --> [var2]
		ldconst 4 --> [1]
		lcall 5 --> [io.writeln]
		stop
	End
End
