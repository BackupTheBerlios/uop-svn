.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [result]
	.const 3   string   [x]
	.const 4   string   [result: ]
	.const 5   int      [2]
	.const 6   string   [io.writeln]
	.const 7   string   [oi]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 string result
	        ldself      
	        mcall        3 --> [x]
	        stvar        0 --> [result]
	        ldconst      4 --> [result: ]
	        ldvar        0 --> [result]
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        exit        
	.end
	.method x
		.result 0 string
	        ldconst      7 --> [oi]
	        stresult     0
	        ret         
	.end
.end
