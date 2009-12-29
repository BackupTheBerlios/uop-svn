.constant_pool
	0   S start
	1   S constructor
	2   S e
	3   S elemento
	4   S oi
	5   S x
	6   S msg
	7   S msg=
	8   I 2
	9   S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element e
		newelem 3 --> [elemento]
		stvar 0 --> [e]
		ldconst 4 --> [oi]
		ldvar 0 --> [e]
		mcall 5 --> [x]
		stop
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method x
		.param 0 string msg
		ldconst 7 --> [msg=]
		ldpar 0 --> [msg]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		ret
	.end
.end
