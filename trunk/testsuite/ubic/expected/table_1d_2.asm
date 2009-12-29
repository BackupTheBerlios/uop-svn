.constant_pool
	0   S start
	1   S constructor
	2   S tab
	3   S Alex
	4   I 34
	5   S Gracy
	6   I 32
	7   S Gabriel
	8   I 1
	9   S Alex   =
	10  I 2
	11  S io.writeln
	12  S Gracy  =
	13  S Gabriel=
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 table tab
		ldconst 3 --> [Alex]
		ldconst 4 --> [34]
		sttab 0 --> [tab]
		ldconst 5 --> [Gracy]
		ldconst 6 --> [32]
		sttab 0 --> [tab]
		ldconst 7 --> [Gabriel]
		ldconst 8 --> [1]
		sttab 0 --> [tab]
		ldconst 9 --> [Alex   =]
		ldconst 3 --> [Alex]
		ldtab 0 --> [tab]
		ldconst 10 --> [2]
		lcall 11 --> [io.writeln]
		ldconst 12 --> [Gracy  =]
		ldconst 5 --> [Gracy]
		ldtab 0 --> [tab]
		ldconst 10 --> [2]
		lcall 11 --> [io.writeln]
		ldconst 13 --> [Gabriel=]
		ldconst 7 --> [Gabriel]
		ldtab 0 --> [tab]
		ldconst 10 --> [2]
		lcall 11 --> [io.writeln]
		stop
	.end
.end
