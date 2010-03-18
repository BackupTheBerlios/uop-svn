.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [oi]
	.const 3   string   [oi de novo !!!]
	.const 4   string   [x]
	.const 5   string   [msg1]
	.const 6   string   [msg2]
	.const 7   string   [msg1=]
	.const 8   int      [2]
	.const 9   string   [io.writeln]
	.const 10  string   [msg2=]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [oi]
	        ldconst      3 --> [oi de novo !!!]
	        ldself      
	        mcall        4 --> [x]
	        exit        
	.end
	.method x
		.param 0 string msg1
		.param 1 string msg2
	        ldconst      7 --> [msg1=]
	        ldparam      0 --> [msg1]
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        ldconst      10 --> [msg2=]
	        ldparam      1 --> [msg2]
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        ret         
	.end
.end
