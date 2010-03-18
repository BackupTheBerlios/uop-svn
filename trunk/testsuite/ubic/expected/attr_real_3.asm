.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [var1]
	.const 3   string   [var2]
	.const 4   real     [10.990000]
	.const 5   int      [1]
	.const 6   string   [io.writeln]
	.const 7   real     [20.990000]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 real var1
		.var 1 real var2
	        ldconst      4 --> [10.990000]
	        stvar        0 --> [var1]
	        ldvar        0 --> [var1]
	        ldconst      5 --> [1]
	        lcall        6 --> [io.writeln]
	        ldconst      7 --> [20.990000]
	        stvar        1 --> [var2]
	        ldvar        1 --> [var2]
	        ldconst      5 --> [1]
	        lcall        6 --> [io.writeln]
	        exit        
	.end
.end
