.constant_pool
	0   S start
	1   S constructor
	2   S x
	3   I 1
	4   I 30
	5   S x=
	6   I 2
	7   S io.writeln
	8   I 10
	9   S x entre 1 e 10
	10  I 11
	11  I 20
	12  S x entre 11 e 20
	13  S x > 20
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int x
		ldconst 3 --> [1]
		stvar 0 --> [x]
	:2    	ldvar 0 --> [x]
		ldconst 4 --> [30]
		le
		ifnot 44 --> [44]
		jmp 12 --> [12]
	:7    	ldvar 0 --> [x]
		ldconst 3 --> [1]
		add
		stvar 0 --> [x]
		jmp 2 --> [2]
	:12   	ldconst 5 --> [x=]
		ldvar 0 --> [x]
		ldconst 6 --> [2]
		lcall 7 --> [io.writeln]
		ldvar 0 --> [x]
		ldconst 3 --> [1]
		ge
		ldvar 0 --> [x]
		ldconst 8 --> [10]
		le
		and
		ifnot 28 --> [28]
		ldconst 9 --> [x entre 1 e 10]
		ldconst 3 --> [1]
		lcall 7 --> [io.writeln]
		jmp 43 --> [43]
	:28   	ldvar 0 --> [x]
		ldconst 10 --> [11]
		ge
		ldvar 0 --> [x]
		ldconst 11 --> [20]
		le
		and
		ifnot 40 --> [40]
		ldconst 12 --> [x entre 11 e 20]
		ldconst 3 --> [1]
		lcall 7 --> [io.writeln]
		jmp 43 --> [43]
	:40   	ldconst 13 --> [x > 20]
		ldconst 3 --> [1]
		lcall 7 --> [io.writeln]
	:43   	jmp 7 --> [7]
	:44   	stop
	.end
.end
