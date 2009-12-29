.constant_pool
	0   S start
	1   S constructor
	2   S x
	3   S result
	4   S e
	5   S elemento
	6   S y
	7   S result: 
	8   I 2
	9   S io.writeln
	10  S oi
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
		.var 1 element e
		newelem 5 --> [elemento]
		stvar 1 --> [e]
		ldvar 1 --> [e]
		mcall 6 --> [y]
		stvar 0 --> [result]
		ldconst 7 --> [result: ]
		ldvar 0 --> [result]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		ret
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method y
		.result 0 string
		ldconst 10 --> [oi]
		stresult 0
		ret
	.end
.end
