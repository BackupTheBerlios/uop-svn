.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [result1]
	.const 3   string   [result2]
	.const 4   string   [x]
	.const 5   string   [result1: ]
	.const 6   int      [2]
	.const 7   string   [io.writeln]
	.const 8   string   [result2: ]
	.const 9   string   [oi 1]
	.const 10  string   [oi 2]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 string result1
		.var 1 string result2
	        ldself      
	        mcall        4 --> [x]
	        stvar        0 --> [result1]
	        stvar        1 --> [result2]
	        ldconst      5 --> [result1: ]
	        ldvar        0 --> [result1]
	        ldconst      6 --> [2]
	        lcall        7 --> [io.writeln]
	        ldconst      8 --> [result2: ]
	        ldvar        1 --> [result2]
	        ldconst      6 --> [2]
	        lcall        7 --> [io.writeln]
	        exit        
	.end
	.method x
		.result 0 string
		.result 1 string
	        ldconst      9 --> [oi 1]
	        stresult     0
	        ldconst      10 --> [oi 2]
	        stresult     1
	        ret         
	.end
.end
