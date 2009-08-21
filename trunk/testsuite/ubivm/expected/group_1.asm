Entity start
	Constants
		0 S start
		1 S MeuGrupo
		2 S Inserindo informacoes
		3 I 1
		4 S writeln
		5 S Numero 1
		6 I 54321
		7 S Informacoes inseridas: 
		8 I 2
	End
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [MeuGrupo]
		bindg
		ldconst 2 --> [Inserindo informacoes]
		ldconst 3 --> [1]
		lcall 4 --> [writeln]
		ldconst 1 --> [MeuGrupo]
		ldconst 5 --> [Numero 1]
		ldconst 6 --> [54321]
		ldconst 3 --> [1]
		ldconst 3 --> [1]
		dataaf
		ldconst 7 --> [Informacoes inseridas: ]
		ldconst 1 --> [MeuGrupo]
		ldconst 5 --> [Numero 1]
		ldconst 3 --> [1]
		datadqu
		ldconst 8 --> [2]
		lcall 4 --> [writeln]
		stop
	End
End
