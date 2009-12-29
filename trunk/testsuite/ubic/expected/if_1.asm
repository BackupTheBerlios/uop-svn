.constant_pool
	0   S start
	1   S constructor
	2   S x
	3   I 1
	4   I 10
	5   S x>10
	6   S io.writeln
	7   S x not > 10
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int x
		ldconst 3 --> [1]
		stvar 0 --> [x]
		ldvar 0 --> [x]
		ldconst 4 --> [10]
		gt
		ifnot 10 --> [10]
		ldconst 5 --> [x>10]
		ldconst 3 --> [1]
		lcall 6 --> [io.writeln]
		jmp 13 --> [13]
	:10   	ldconst 7 --> [x not > 10]
		ldconst 3 --> [1]
		lcall 6 --> [io.writeln]
	:13   	stop
	.end
.end
