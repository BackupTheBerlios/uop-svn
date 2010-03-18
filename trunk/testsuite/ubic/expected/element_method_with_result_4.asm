.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [result1]
	.const 3   string   [result2]
	.const 4   string   [e]
	.const 5   string   [elemento]
	.const 6   string   [x]
	.const 7   string   [result1: ]
	.const 8   int      [2]
	.const 9   string   [io.writeln]
	.const 10  string   [result2: ]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int result1
		.var 1 int result2
		.var 2 element e
	        newelem      5 --> [elemento]
	        stvar        2 --> [e]
	        ldvar        2 --> [e]
	        mcall        6 --> [x]
	        stvar        0 --> [result1]
	        stvar        1 --> [result2]
	        ldconst      7 --> [result1: ]
	        ldvar        0 --> [result1]
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        ldconst      10 --> [result2: ]
	        ldvar        1 --> [result2]
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        exit        
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method x
		.result 0 int
		.result 1 int
	        ret         
	.end
.end
