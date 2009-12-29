.constant_pool
	0   S start
	1   S constructor
	2   S i
	3   I 0
	4   I 10
	5   I 1
	6   S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int i
		ldconst 3 --> [0]
		stvar 0 --> [i]
	:2    	ldvar 0 --> [i]
		ldconst 4 --> [10]
		le
		ifnot 16 --> [16]
		jmp 12 --> [12]
	:7    	ldvar 0 --> [i]
		ldconst 5 --> [1]
		add
		stvar 0 --> [i]
		jmp 2 --> [2]
	:12   	ldvar 0 --> [i]
		ldconst 5 --> [1]
		lcall 6 --> [io.writeln]
		jmp 7 --> [7]
	:16   	stop
	.end
.end
