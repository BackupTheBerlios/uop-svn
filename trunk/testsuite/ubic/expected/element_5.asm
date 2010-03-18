.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [e]
	.const 3   string   [elemento]
	.const 4   string   [oi]
	.const 5   string   [x]
	.const 6   string   [msg]
	.const 7   string   [msg=]
	.const 8   int      [2]
	.const 9   string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element e
	        newelem      3 --> [elemento]
	        stvar        0 --> [e]
	        ldconst      4 --> [oi]
	        ldvar        0 --> [e]
	        mcall        5 --> [x]
	        exit        
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method x
		.param 0 string msg
	        ldconst      7 --> [msg=]
	        ldparam      0 --> [msg]
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        ret         
	.end
.end
