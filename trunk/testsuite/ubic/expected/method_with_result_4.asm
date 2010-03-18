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
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int result1
		.var 1 int result2
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
		.result 0 int
		.result 1 int
	        ret         
	.end
.end
