.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [result]
	.const 3   string   [e]
	.const 4   string   [elemento]
	.const 5   string   [x]
	.const 6   string   [result: ]
	.const 7   int      [2]
	.const 8   string   [io.writeln]
	.const 9   string   [oi]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 string result
		.var 1 element e
	        newelem      4 --> [elemento]
	        stvar        1 --> [e]
	        ldvar        1 --> [e]
	        mcall        5 --> [x]
	        stvar        0 --> [result]
	        ldconst      6 --> [result: ]
	        ldvar        0 --> [result]
	        ldconst      7 --> [2]
	        lcall        8 --> [io.writeln]
	        exit        
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method x
		.result 0 string
	        ldconst      9 --> [oi]
	        stresult     0
	        ret         
	.end
.end
