.constant_pool
	0   S start
	1   S constructor
	2   S result1
	3   S result2
	4   S x
	5   S result1: 
	6   I 2
	7   S io.writeln
	8   S result2: 
	9   S oi 1
	10  S oi 2
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 string result1
		.var 1 string result2
		ldself
		mcall 4 --> [x]
		stvar 0 --> [result1]
		stvar 1 --> [result2]
		ldconst 5 --> [result1: ]
		ldvar 0 --> [result1]
		ldconst 6 --> [2]
		lcall 7 --> [io.writeln]
		ldconst 8 --> [result2: ]
		ldvar 1 --> [result2]
		ldconst 6 --> [2]
		lcall 7 --> [io.writeln]
		stop
	.end
	.method x
		.result 0 string
		.result 1 string
		ldconst 9 --> [oi 1]
		stresult 0
		ldconst 10 --> [oi 2]
		stresult 1
		ret
	.end
.end
