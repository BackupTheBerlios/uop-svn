.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [x]
	.const 3   int      [1]
	.const 4   int      [10]
	.const 5   string   [x>10]
	.const 6   string   [io.writeln]
	.const 7   string   [x not > 10]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int x
	        ldconst      3 --> [1]
	        stvar        0 --> [x]
	        ldvar        0 --> [x]
	        ldconst      4 --> [10]
	        gt          
	        ifnot        10 --> [10]
	        ldconst      5 --> [x>10]
	        ldconst      3 --> [1]
	        lcall        6 --> [io.writeln]
	        jmp          13 --> [13]
	:10     ldconst      7 --> [x not > 10]
	        ldconst      3 --> [1]
	        lcall        6 --> [io.writeln]
	:13     exit        
	.end
.end
