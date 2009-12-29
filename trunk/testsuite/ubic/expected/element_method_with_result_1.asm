.constant_pool
	0   S start
	1   S constructor
	2   S result
	3   S e
	4   S elemento
	5   S x
	6   S result: 
	7   I 2
	8   S io.writeln
	9   S oi
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 string result
		.var 1 element e
		newelem 4 --> [elemento]
		stvar 1 --> [e]
		ldvar 1 --> [e]
		mcall 5 --> [x]
		stvar 0 --> [result]
		ldconst 6 --> [result: ]
		ldvar 0 --> [result]
		ldconst 7 --> [2]
		lcall 8 --> [io.writeln]
		stop
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method x
		.result 0 string
		ldconst 9 --> [oi]
		stresult 0
		ret
	.end
.end
