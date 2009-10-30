Entity start
	No options
	Constants
		0 S start
		1 S var1
		2 S var2
		3 R 10.990000
		4 R 20.990000
		5 I 1
		6 S io.writeln
	End
	Valid context (always)
	No properties
	Def start
		No parameters
		Local variables
			0 real var1
			1 real var2
		End
		No results
		ldconst 3 --> [10.990000]
		stvar 0 --> [var1]
		ldvar 0 --> [var1]
		ldconst 4 --> [20.990000]
		add
		stvar 1 --> [var2]
		ldvar 1 --> [var2]
		ldconst 5 --> [1]
		lcall 6 --> [io.writeln]
		stop
	End
End
