.constant_pool
	0   S start
	1   S constructor
	2   S tab
	3   S 20
	4   I 20
	5   S 10
	6   I 10
	7   S tab[1]=
	8   I 1
	9   I 2
	10  S io.writeln
	11  S tab[2]=
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 table tab
		ldconst 3 --> [20]
		ldconst 4 --> [20]
		sttab 0 --> [tab]
		ldconst 5 --> [10]
		ldconst 6 --> [10]
		sttab 0 --> [tab]
		ldconst 7 --> [tab[1]=]
		ldconst 8 --> [1]
		ldtab 0 --> [tab]
		ldconst 9 --> [2]
		lcall 10 --> [io.writeln]
		ldconst 11 --> [tab[2]=]
		ldconst 9 --> [2]
		ldtab 0 --> [tab]
		ldconst 9 --> [2]
		lcall 10 --> [io.writeln]
		stop
	.end
.end
