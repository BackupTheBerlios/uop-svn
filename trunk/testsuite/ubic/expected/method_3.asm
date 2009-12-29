.constant_pool
	0   S start
	1   S constructor
	2   S oi
	3   S x
	4   S msg
	5   S msg=
	6   I 2
	7   S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [oi]
		ldself
		mcall 3 --> [x]
		stop
	.end
	.method x
		.param 0 string msg
		ldconst 5 --> [msg=]
		ldpar 0 --> [msg]
		ldconst 6 --> [2]
		lcall 7 --> [io.writeln]
		ret
	.end
.end
