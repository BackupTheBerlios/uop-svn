.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [v1]
	.const 3   string   [Hello world !!!]
	.const 4   string   [v2]
	.const 5   int      [1]
	.const 6   string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 string v1
		.var 1 string v2
	        ldconst      3 --> [Hello world !!!]
	        stvar        0 --> [v1]
	        ldvar        0 --> [v1]
	        ldconst      5 --> [1]
	        lcall        6 --> [io.writeln]
	        ldvar        0 --> [v1]
	        stvar        1 --> [v2]
	        ldvar        1 --> [v2]
	        ldconst      5 --> [1]
	        lcall        6 --> [io.writeln]
	        exit        
	.end
.end
