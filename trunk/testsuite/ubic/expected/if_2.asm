.constant_pool
	0   S start
	1   S constructor
	2   S x
	3   I 20
	4   I 1
	5   I 10
	6   S x entre 1 e 10
	7   S io.writeln
	8   I 11
	9   S x entre 11 e 20
	10  S x > 20
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int x
		ldconst 3 --> [20]
		stvar 0 --> [x]
		ldvar 0 --> [x]
		ldconst 4 --> [1]
		ge
		ldvar 0 --> [x]
		ldconst 5 --> [10]
		le
		and
		ifnot 14 --> [14]
		ldconst 6 --> [x entre 1 e 10]
		ldconst 4 --> [1]
		lcall 7 --> [io.writeln]
		jmp 29 --> [29]
	:14   	ldvar 0 --> [x]
		ldconst 8 --> [11]
		ge
		ldvar 0 --> [x]
		ldconst 3 --> [20]
		le
		and
		ifnot 26 --> [26]
		ldconst 9 --> [x entre 11 e 20]
		ldconst 4 --> [1]
		lcall 7 --> [io.writeln]
		jmp 29 --> [29]
	:26   	ldconst 10 --> [x > 20]
		ldconst 4 --> [1]
		lcall 7 --> [io.writeln]
	:29   	stop
	.end
.end
