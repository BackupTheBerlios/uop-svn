.constant_pool
	0   S start
	1   S constructor
	2   S tab
	3   S Nome
	4   S Alex
	5   S Sexo
	6   S M
	7   S Idade
	8   I 34
	9   S Nome =
	10  I 2
	11  S io.writeln
	12  S Sexo =
	13  S Idade=
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 table tab
		ldconst 3 --> [Nome]
		ldconst 4 --> [Alex]
		sttab 0 --> [tab]
		ldconst 5 --> [Sexo]
		ldconst 6 --> [M]
		sttab 0 --> [tab]
		ldconst 7 --> [Idade]
		ldconst 8 --> [34]
		sttab 0 --> [tab]
		ldconst 9 --> [Nome =]
		ldconst 3 --> [Nome]
		ldtab 0 --> [tab]
		ldconst 10 --> [2]
		lcall 11 --> [io.writeln]
		ldconst 12 --> [Sexo =]
		ldconst 5 --> [Sexo]
		ldtab 0 --> [tab]
		ldconst 10 --> [2]
		lcall 11 --> [io.writeln]
		ldconst 13 --> [Idade=]
		ldconst 7 --> [Idade]
		ldtab 0 --> [tab]
		ldconst 10 --> [2]
		lcall 11 --> [io.writeln]
		stop
	.end
.end
