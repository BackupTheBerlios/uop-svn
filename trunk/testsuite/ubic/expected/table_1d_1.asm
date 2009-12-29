.constant_pool
	0   S start
	1   S constructor
	2   S tab
	3   I 1
	4   I 100
	5   I 2
	6   I 200
	7   S tab[1]=
	8   S io.writeln
	9   S tab[2]=
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 table tab
		ldconst 3 --> [1]
		ldconst 4 --> [100]
		sttab 0 --> [tab]
		ldconst 5 --> [2]
		ldconst 6 --> [200]
		sttab 0 --> [tab]
		ldconst 7 --> [tab[1]=]
		ldconst 3 --> [1]
		ldtab 0 --> [tab]
		ldconst 5 --> [2]
		lcall 8 --> [io.writeln]
		ldconst 9 --> [tab[2]=]
		ldconst 5 --> [2]
		ldtab 0 --> [tab]
		ldconst 5 --> [2]
		lcall 8 --> [io.writeln]
		stop
	.end
.end
