Entity start
	Constants
		0 S start
		1 S var1
		2 S aaa
	End
	Def start
		Local variables
			0 string var1
		End
		ldconst 2 --> [aaa]
		stvar 0 --> [var1]
		stop
	End
End
