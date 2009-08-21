Entity servico
	Constants
		0 S servico
		1 S soma
		2 S x
		3 S y
		4 S group
	End
	Def soma
		Parameters
			0 int x
			1 int y
		End
		No local variables
		Result
			0 int
		End
		ldpar 0 --> [x]
		ldpar 1 --> [y]
		add
		stresult 0
		ret
	End
	Def servico
		No parameters
		No local variables
		No results
		ldconst 4 --> [group]
		ldconst 1 --> [soma]
		publishs
		ret
	End
End
Entity start
	Constants
		0 S start
		1 S Soma: 
		2 S group
		3 S soma
		4 I 10
		5 I 20
		6 I 2
		7 S writeln
	End
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [Soma: ]
		ldconst 2 --> [group]
		ldconst 3 --> [soma]
		finds
		binds
		ldconst 4 --> [10]
		ldconst 5 --> [20]
		scall
		ldconst 6 --> [2]
		lcall 7 --> [writeln]
		stop
	End
End
