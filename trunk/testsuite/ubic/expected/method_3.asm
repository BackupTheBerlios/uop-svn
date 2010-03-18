.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [oi]
	.const 3   string   [x]
	.const 4   string   [msg]
	.const 5   string   [msg=]
	.const 6   int      [2]
	.const 7   string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [oi]
	        ldself      
	        mcall        3 --> [x]
	        exit        
	.end
	.method x
		.param 0 string msg
	        ldconst      5 --> [msg=]
	        ldparam      0 --> [msg]
	        ldconst      6 --> [2]
	        lcall        7 --> [io.writeln]
	        ret         
	.end
.end
