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
		7 S 54321
		8 S Informacoes inseridas: 
		9 I 2
	End
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
		ldconst 7 --> [54321]
		ldconst 4 --> [1]
		ldconst 4 --> [1]
		dataaf
		ldconst 8 --> [Informacoes inseridas: ]
		ldconst 1 --> [MeuGrupo]
		ldconst 6 --> [Numero 1]
		ldconst 4 --> [1]
		datadqu
		ldconst 9 --> [2]
		lcall 5 --> [io.writeln]
		stop
	End
End
