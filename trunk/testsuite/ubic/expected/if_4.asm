.constant_pool
	0   S start
	1   S constructor
	2   S x
	3   I 1
	4   I 10
	5   I 3
	6   I 5
	7   I 7
	8   I 9
	9   S x=
	10  S  eh impar !!!
	11  S io.writeln
	12  I 2
	13  I 4
	14  I 6
	15  I 8
	16  S  eh par !!!
	17  S  ???
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
		ifnot 70 --> [70]
		jmp 12 --> [12]
	:7    	ldvar 0 --> [x]
		ldconst 3 --> [1]
		add
		stvar 0 --> [x]
		jmp 2 --> [2]
	:12   	ldvar 0 --> [x]
		ldconst 3 --> [1]
		eq
		ldvar 0 --> [x]
		ldconst 5 --> [3]
		eq
		or
		ldvar 0 --> [x]
		ldconst 6 --> [5]
		eq
		or
		ldvar 0 --> [x]
		ldconst 7 --> [7]
		eq
		or
		ldvar 0 --> [x]
		ldconst 8 --> [9]
		eq
		or
		ifnot 38 --> [38]
		ldconst 9 --> [x=]
		ldvar 0 --> [x]
		ldconst 10 --> [ eh impar !!!]
		ldconst 5 --> [3]
		lcall 11 --> [io.writeln]
		jmp 69 --> [69]
	:38   	ldvar 0 --> [x]
		ldconst 12 --> [2]
		eq
		ldvar 0 --> [x]
		ldconst 13 --> [4]
		eq
		or
		ldvar 0 --> [x]
		ldconst 14 --> [6]
		eq
		or
		ldvar 0 --> [x]
		ldconst 15 --> [8]
		eq
		or
		ldvar 0 --> [x]
		ldconst 4 --> [10]
		eq
		or
		ifnot 64 --> [64]
		ldconst 9 --> [x=]
		ldvar 0 --> [x]
		ldconst 16 --> [ eh par !!!]
		ldconst 5 --> [3]
		lcall 11 --> [io.writeln]
		jmp 69 --> [69]
	:64   	ldconst 9 --> [x=]
		ldvar 0 --> [x]
		ldconst 17 --> [ ???]
		ldconst 5 --> [3]
		lcall 11 --> [io.writeln]
	:69   	jmp 7 --> [7]
	:70   	stop
	.end
.end
