Entity start
	Constants
		0 S start
		1 S var1
		2 S var2
		3 R 10.990000
		4 I 1
		5 S writeln
		6 R 20.990000
	End
	Def start
		Local variables
			0 real var1
			1 real var2
		End
			ldconst 3 --> [10.990000]
			stvar 0 --> [var1]
			ldvar 0 --> [var1]
			ldconst 4 --> [1]
			lcall 5 --> [writeln]
			ldconst 6 --> [20.990000]
			stvar 1 --> [var2]
			ldvar 1 --> [var2]
			ldconst 4 --> [1]
			lcall 5 --> [writeln]
			stop
	End
End
