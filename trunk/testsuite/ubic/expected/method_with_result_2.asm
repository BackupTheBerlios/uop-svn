.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [x]
	.const 3   string   [result]
	.const 4   string   [y]
	.const 5   string   [result: ]
	.const 6   int      [2]
	.const 7   string   [io.writeln]
	.const 8   string   [oi]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldself      
	        mcall        2 --> [x]
	        exit        
	.end
	.method x
		.var 0 string result
	        ldself      
	        mcall        4 --> [y]
	        stvar        0 --> [result]
	        ldconst      5 --> [result: ]
	        ldvar        0 --> [result]
	        ldconst      6 --> [2]
	        lcall        7 --> [io.writeln]
	        ret         
	.end
	.method y
		.result 0 string
	        ldconst      8 --> [oi]
	        stresult     0
	        ret         
	.end
.end
