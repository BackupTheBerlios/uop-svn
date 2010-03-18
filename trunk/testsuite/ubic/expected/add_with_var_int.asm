.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [var1]
	.const 3   string   [var2]
	.const 4   int      [10]
	.const 5   int      [20]
	.const 6   int      [1]
	.const 7   string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int var1
		.var 1 int var2
	        ldconst      4 --> [10]
	        stvar        0 --> [var1]
	        ldvar        0 --> [var1]
	        ldconst      5 --> [20]
	        add         
	        stvar        1 --> [var2]
	        ldvar        1 --> [var2]
	        ldconst      6 --> [1]
	        lcall        7 --> [io.writeln]
	        exit        
	.end
.end
