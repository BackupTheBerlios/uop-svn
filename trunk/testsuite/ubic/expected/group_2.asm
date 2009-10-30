Entity start
	No options
	Constants
		0 S start
		1 S MeuGrupo
		2 S Alex
		3 S Inserindo informacoes
		4 I 1
		5 S io.writeln
		6 S Numero 1
		7 S 1
		8 S 2
		9 I 2
		10 S Informacoes inseridas: 
	End
	No properties
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [MeuGrupo]
		ldconst 2 --> [Alex]
		bindg
		ldconst 3 --> [Inserindo informacoes]
		ldconst 4 --> [1]
		lcall 5 --> [io.writeln]
		ldconst 1 --> [MeuGrupo]
		ldconst 6 --> [Numero 1]
		ldconst 7 --> [1]
		ldconst 8 --> [2]
		ldconst 4 --> [1]
		ldconst 9 --> [2]
		dataaf
		ldconst 10 --> [Informacoes inseridas: ]
		ldconst 1 --> [MeuGrupo]
		ldconst 6 --> [Numero 1]
		ldconst 4 --> [1]
		datadqu
		ldconst 9 --> [2]
		lcall 5 --> [io.writeln]
		stop
	End
End
