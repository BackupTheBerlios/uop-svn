Entity servico
	No options
	Constants
		0 S servico
		1 S soma
		2 S x
		3 S y
		4 S group
		5 S Alex
	End
	No properties
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
		ldconst 5 --> [Alex]
		bindg
		ldconst 4 --> [group]
		publishs 1 --> [soma]
		ret
	End
End
Entity start
	No options
	Constants
		0 S start
		1 S s
		2 S servico
		3 S Soma: 
		4 S group
		5 I 10
		6 I 20
		7 I 2
		8 S soma
		9 S io.writeln
	End
	No properties
	Def start
		No parameters
		Local variables
			0 element s
		End
		No results
		newelem 2 --> [servico]
		stvar 0 --> [s]
		ldvar 0 --> [s]
		mcall 2 --> [servico]
		ldconst 3 --> [Soma: ]
		ldconst 5 --> [10]
		ldconst 6 --> [20]
		ldconst 7 --> [2]
		ldconst 4 --> [group]
		scall 8 --> [soma]
		ldconst 7 --> [2]
		lcall 9 --> [io.writeln]
		stop
	End
End
