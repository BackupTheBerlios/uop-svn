.constant_pool
	0   S start
	1   S constructor
	2   S x
	3   S result
	4   S y
	5   S result: 
	6   I 2
	7   S io.writeln
	8   S oi
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldself
		mcall 2 --> [x]
		stop
	.end
	.method x
		.var 0 string result
		ldself
		mcall 4 --> [y]
		stvar 0 --> [result]
		ldconst 5 --> [result: ]
		ldvar 0 --> [result]
		ldconst 6 --> [2]
		lcall 7 --> [io.writeln]
		ret
	.end
	.method y
		.result 0 string
		ldconst 8 --> [oi]
		stresult 0
		ret
	.end
.end
