.constant_pool
	0   S start
	1   S constructor
	2   S tab
	3   S index
	4   I 1
	5   I 10
	6   S tab[
	7   S ]=
	8   I 4
	9   S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 table tab
		.var 1 int index
		ldconst 4 --> [1]
		stvar 1 --> [index]
	:2    	ldvar 1 --> [index]
		ldconst 5 --> [10]
		le
		ifnot 18 --> [18]
		jmp 12 --> [12]
	:7    	ldvar 1 --> [index]
		ldconst 4 --> [1]
		add
		stvar 1 --> [index]
		jmp 2 --> [2]
	:12   	ldvar 1 --> [index]
		ldvar 1 --> [index]
		ldconst 5 --> [10]
		mul
		sttab 0 --> [tab]
		jmp 7 --> [7]
	:18   	ldconst 4 --> [1]
		stvar 1 --> [index]
	:20   	ldvar 1 --> [index]
		ldconst 5 --> [10]
		le
		ifnot 38 --> [38]
		jmp 30 --> [30]
	:25   	ldvar 1 --> [index]
		ldconst 4 --> [1]
		add
		stvar 1 --> [index]
		jmp 20 --> [20]
	:30   	ldconst 6 --> [tab[]
		ldvar 1 --> [index]
		ldconst 7 --> []=]
		ldvar 1 --> [index]
		ldtab 0 --> [tab]
		ldconst 8 --> [4]
		lcall 9 --> [io.writeln]
		jmp 25 --> [25]
	:38   	stop
	.end
.end
