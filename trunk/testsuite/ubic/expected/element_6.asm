.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [e]
	.const 3   string   [elemento]
	.const 4   string   [oi]
	.const 5   string   [oi de novo !!!]
	.const 6   string   [x]
	.const 7   string   [msg1]
	.const 8   string   [msg2]
	.const 9   string   [msg1=]
	.const 10  int      [2]
	.const 11  string   [io.writeln]
	.const 12  string   [msg2=]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element e
	        newelem      3 --> [elemento]
	        stvar        0 --> [e]
	        ldconst      4 --> [oi]
	        ldconst      5 --> [oi de novo !!!]
	        ldvar        0 --> [e]
	        mcall        6 --> [x]
	        exit        
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method x
		.param 0 string msg1
		.param 1 string msg2
	        ldconst      9 --> [msg1=]
	        ldparam      0 --> [msg1]
	        ldconst      10 --> [2]
	        lcall        11 --> [io.writeln]
	        ldconst      12 --> [msg2=]
	        ldparam      1 --> [msg2]
	        ldconst      10 --> [2]
	        lcall        11 --> [io.writeln]
	        ret         
	.end
.end
