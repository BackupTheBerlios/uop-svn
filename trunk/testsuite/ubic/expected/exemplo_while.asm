.constant_pool
	0   S start
	1   S constructor
	2   S i
	3   I 1
	4   I 10
	5   S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int i
		ldconst 3 --> [1]
		stvar 0 --> [i]
	:2    	ldvar 0 --> [i]
		ldconst 4 --> [10]
		le
		ifnot 14 --> [14]
		ldvar 0 --> [i]
		ldconst 3 --> [1]
		lcall 5 --> [io.writeln]
		ldvar 0 --> [i]
		ldconst 3 --> [1]
		add
		stvar 0 --> [i]
		jmp 2 --> [2]
	:14   	stop
	.end
.end
