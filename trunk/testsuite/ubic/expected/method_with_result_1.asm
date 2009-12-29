.constant_pool
	0   S start
	1   S constructor
	2   S result
	3   S x
	4   S result: 
	5   I 2
	6   S io.writeln
	7   S oi
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 string result
		ldself
		mcall 3 --> [x]
		stvar 0 --> [result]
		ldconst 4 --> [result: ]
		ldvar 0 --> [result]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		stop
	.end
	.method x
		.result 0 string
		ldconst 7 --> [oi]
		stresult 0
		ret
	.end
.end
