.constant_pool
	0   S start
	1   S constructor
	2   S x
	3   I 1
	4   I 10
	5   S x=
	6   I 2
	7   S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int x
		ldconst 3 --> [1]
		stvar 0 --> [x]
	:2    	ldvar 0 --> [x]
		ldconst 4 --> [10]
		le
		ifnot 15 --> [15]
		ldconst 5 --> [x=]
		ldvar 0 --> [x]
		ldconst 6 --> [2]
		lcall 7 --> [io.writeln]
		ldvar 0 --> [x]
		ldconst 3 --> [1]
		add
		stvar 0 --> [x]
		jmp 2 --> [2]
	:15   	stop
	.end
.end
