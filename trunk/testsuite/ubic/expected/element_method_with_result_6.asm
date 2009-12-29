.constant_pool
	0   S start
	1   S constructor
	2   S result1
	3   S result2
	4   S e
	5   S elemento
	6   S x
	7   S result1: 
	8   I 2
	9   S io.writeln
	10  S result2: 
	11  S So um resultado...
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 string result1
		.var 1 string result2
		.var 2 element e
		newelem 5 --> [elemento]
		stvar 2 --> [e]
		ldvar 2 --> [e]
		mcall 6 --> [x]
		stvar 0 --> [result1]
		stvar 1 --> [result2]
		ldconst 7 --> [result1: ]
		ldvar 0 --> [result1]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		ldconst 10 --> [result2: ]
		ldvar 1 --> [result2]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		stop
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method x
		.result 0 string
		.result 1 string
		ldconst 11 --> [So um resultado...]
		stresult 0
		ret
	.end
.end
