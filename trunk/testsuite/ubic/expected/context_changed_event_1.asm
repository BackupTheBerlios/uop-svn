.constant_pool
	0   S start
	1   S constructor
	2   S 1
	3   S location.symbolic
	4   S on_changed
	5   S alt_loc
	6   S 2
	7   S 3
	8   S old
	9   S new
	10  S Localizacao 
	11  S  mudou para 
	12  I 1
	13  S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [1]
		stcontexti 3 --> [location.symbolic]
		ldconst 4 --> [on_changed]
		ldconst 5 --> [alt_loc]
		bcontextiev 3 --> [location.symbolic]
		ldconst 6 --> [2]
		stcontexti 3 --> [location.symbolic]
		ldconst 7 --> [3]
		stcontexti 3 --> [location.symbolic]
		stop
	.end
	.method alt_loc
		.param 0 string old
		.param 1 string new
		ldconst 10 --> [Localizacao ]
		ldpar 0 --> [old]
		add
		ldconst 11 --> [ mudou para ]
		add
		ldpar 1 --> [new]
		add
		ldconst 12 --> [1]
		lcall 13 --> [io.writeln]
		ret
	.end
.end
