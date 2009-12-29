.constant_pool
	0   S start
	1   S constructor
	2   S value
	3   I 10
	4   I 100
	5   I 1
	6   S value=
	7   I 2
	8   S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int value
		ldconst 3 --> [10]
		stvar 0 --> [value]
		ldvar 0 --> [value]
		ldconst 4 --> [100]
		lt
		ifnot 9 --> [9]
		ldconst 4 --> [100]
		stvar 0 --> [value]
		jmp 13 --> [13]
	:9    	ldvar 0 --> [value]
		ldconst 5 --> [1]
		sub
		stvar 0 --> [value]
	:13   	ldconst 6 --> [value=]
		ldvar 0 --> [value]
		ldconst 7 --> [2]
		lcall 8 --> [io.writeln]
		stop
	.end
.end
