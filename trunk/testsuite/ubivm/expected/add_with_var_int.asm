Entity start
	Constants
		0 S start
		1 S var1
		2 S var2
		3 I 10
		4 I 20
		5 I 1
		6 S io.writeln
	End
	Def start
		No parameters
		Local variables
			0 int var1
			1 int var2
		End
		No results
		ldconst 3 --> [10]
		stvar 0 --> [var1]
		ldvar 0 --> [var1]
		ldconst 4 --> [20]
		add
		stvar 1 --> [var2]
		ldvar 1 --> [var2]
		ldconst 5 --> [1]
		lcall 6 --> [io.writeln]
		stop
	End
End
