.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [var1]
	.const 3   string   [aaa]
	.const 4   int      [1]
	.const 5   string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 string var1
	        ldconst      3 --> [aaa]
	        stvar        0 --> [var1]
	        ldvar        0 --> [var1]
	        ldconst      4 --> [1]
	        lcall        5 --> [io.writeln]
	        exit        
	.end
.end
