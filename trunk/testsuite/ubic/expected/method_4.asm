.constant_pool
	0   S start
	1   S constructor
	2   S oi
	3   S oi de novo !!!
	4   S x
	5   S msg1
	6   S msg2
	7   S msg1=
	8   I 2
	9   S io.writeln
	10  S msg2=
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [oi]
		ldconst 3 --> [oi de novo !!!]
		ldself
		mcall 4 --> [x]
		stop
	.end
	.method x
		.param 0 string msg1
		.param 1 string msg2
		ldconst 7 --> [msg1=]
		ldpar 0 --> [msg1]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		ldconst 10 --> [msg2=]
		ldpar 1 --> [msg2]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		ret
	.end
.end
