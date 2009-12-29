.constant_pool
	0   S start
	1   S constructor
	2   S x
	3   I 1
	4   S x=
	5   I 2
	6   S io.writeln
	7   I 10
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int x
		ldconst 3 --> [1]
		stvar 0 --> [x]
	:2    	ldconst 4 --> [x=]
		ldvar 0 --> [x]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ldvar 0 --> [x]
		ldconst 3 --> [1]
		add
		stvar 0 --> [x]
		ldvar 0 --> [x]
		ldconst 7 --> [10]
		gt
		ifnot 2 --> [2]
		stop
	.end
.end
