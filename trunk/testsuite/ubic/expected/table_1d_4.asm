Entity start
	Constants
		0 S start
		1 S tab
		2 S Nome
		3 S Alex
		4 S Sexo
		5 S M
		6 S Idade
		7 I 34
		8 S Nome =
		9 I 2
		10 S writeln
		11 S Sexo =
		12 S Idade=
	End
	Def start
		No parameters
		Local variables
			0 table tab
		End
		No results
		ldconst 2 --> [Nome]
		ldconst 3 --> [Alex]
		sttab 0 --> [tab]
		ldconst 4 --> [Sexo]
		ldconst 5 --> [M]
		sttab 0 --> [tab]
		ldconst 6 --> [Idade]
		ldconst 7 --> [34]
		sttab 0 --> [tab]
		ldconst 8 --> [Nome =]
		ldconst 2 --> [Nome]
		ldtab 0 --> [tab]
		ldconst 9 --> [2]
		lcall 10 --> [writeln]
		ldconst 11 --> [Sexo =]
		ldconst 4 --> [Sexo]
		ldtab 0 --> [tab]
		ldconst 9 --> [2]
		lcall 10 --> [writeln]
		ldconst 12 --> [Idade=]
		ldconst 6 --> [Idade]
		ldtab 0 --> [tab]
		ldconst 9 --> [2]
		lcall 10 --> [writeln]
		stop
	End
End
