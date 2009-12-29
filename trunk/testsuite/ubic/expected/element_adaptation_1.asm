.constant_pool
	0   S test
	1   S __when
	2   S identity.name
	3   S alex
	4   S run
	5   S Eu sou o Alex !!!
	6   I 1
	7   S io.writeln
	8   S Ops, nao sou o Alex :-/
	9   S start
	10  S constructor
	11  S t1
	12  S t2
	13  S gracy
.end
.entity test
	.valid_context_when 		ldcontexti 2 --> [identity.name]
		ldconst 3 --> [alex]
		eq
		ret
	.method run
		ldconst 5 --> [Eu sou o Alex !!!]
		ldconst 6 --> [1]
		lcall 7 --> [io.writeln]
		ret
	.end
.end
.entity test
	.valid_context_when 		ldcontexti 2 --> [identity.name]
		ldconst 3 --> [alex]
		ne
		ret
	.method run
		ldconst 8 --> [Ops, nao sou o Alex :-/]
		ldconst 6 --> [1]
		lcall 7 --> [io.writeln]
		ret
	.end
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element t1
		.var 1 element t2
		ldconst 3 --> [alex]
		stcontexti 2 --> [identity.name]
		newelem 0 --> [test]
		stvar 0 --> [t1]
		ldvar 0 --> [t1]
		mcall 4 --> [run]
		ldconst 13 --> [gracy]
		stcontexti 2 --> [identity.name]
		newelem 0 --> [test]
		stvar 1 --> [t2]
		ldvar 1 --> [t2]
		mcall 4 --> [run]
		stop
	.end
.end
