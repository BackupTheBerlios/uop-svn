.constant_pool
	0   S start
	1   S constructor
	2   S on_new_value
	3   S nova_info
	4   S location.symbolic
	5   S 1
	6   S on_changed
	7   S alt_loc
	8   S 2
	9   S 3
	10  S old
	11  S new
	12  S Localizacao 
	13  S  mudou para 
	14  I 1
	15  S io.writeln
	16  S info
	17  S value
	18  S Adicionada informacao 
	19  S  com valor 
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [on_new_value]
		ldconst 3 --> [nova_info]
		bcontextiev 4 --> [location.symbolic]
		ldconst 5 --> [1]
		stcontexti 4 --> [location.symbolic]
		ldconst 6 --> [on_changed]
		ldconst 7 --> [alt_loc]
		bcontextiev 4 --> [location.symbolic]
		ldconst 8 --> [2]
		stcontexti 4 --> [location.symbolic]
		ldconst 9 --> [3]
		stcontexti 4 --> [location.symbolic]
		stop
	.end
	.method alt_loc
		.param 0 string old
		.param 1 string new
		ldconst 12 --> [Localizacao ]
		ldpar 0 --> [old]
		add
		ldconst 13 --> [ mudou para ]
		add
		ldpar 1 --> [new]
		add
		ldconst 14 --> [1]
		lcall 15 --> [io.writeln]
		ret
	.end
	.method nova_info
		.param 0 string info
		.param 1 string value
		ldconst 18 --> [Adicionada informacao ]
		ldpar 0 --> [info]
		add
		ldconst 19 --> [ com valor ]
		add
		ldpar 1 --> [value]
		add
		ldconst 14 --> [1]
		lcall 15 --> [io.writeln]
		ret
	.end
.end
