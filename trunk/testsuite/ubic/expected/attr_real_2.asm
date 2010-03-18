.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [var1]
	.const 3   real     [10.990000]
	.const 4   int      [1]
	.const 5   string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 real var1
	        ldconst      3 --> [10.990000]
	        stvar        0 --> [var1]
	        ldvar        0 --> [var1]
	        ldconst      4 --> [1]
	        lcall        5 --> [io.writeln]
	        exit        
	.end
.end
