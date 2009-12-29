.constant_pool
	0   S start
	1   S constructor
	2   S e
	3   S elemento
	4   S oi
	5   S oi de novo !!!
	6   S x
	7   S msg1
	8   S msg2
	9   S msg1=
	10  I 2
	11  S io.writeln
	12  S msg2=
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element e
		newelem 3 --> [elemento]
		stvar 0 --> [e]
		ldconst 4 --> [oi]
		ldconst 5 --> [oi de novo !!!]
		ldvar 0 --> [e]
		mcall 6 --> [x]
		stop
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method x
		.param 0 string msg1
		.param 1 string msg2
		ldconst 9 --> [msg1=]
		ldpar 0 --> [msg1]
		ldconst 10 --> [2]
		lcall 11 --> [io.writeln]
		ldconst 12 --> [msg2=]
		ldpar 1 --> [msg2]
		ldconst 10 --> [2]
		lcall 11 --> [io.writeln]
		ret
	.end
.end
