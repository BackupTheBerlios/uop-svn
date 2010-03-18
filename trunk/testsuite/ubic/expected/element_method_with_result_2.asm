.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [x]
	.const 3   string   [result]
	.const 4   string   [e]
	.const 5   string   [elemento]
	.const 6   string   [y]
	.const 7   string   [result: ]
	.const 8   int      [2]
	.const 9   string   [io.writeln]
	.const 10  string   [oi]
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
		.var 1 element e
	        newelem      5 --> [elemento]
	        stvar        1 --> [e]
	        ldvar        1 --> [e]
	        mcall        6 --> [y]
	        stvar        0 --> [result]
	        ldconst      7 --> [result: ]
	        ldvar        0 --> [result]
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        ret         
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method y
		.result 0 string
	        ldconst      10 --> [oi]
	        stresult     0
	        ret         
	.end
.end
