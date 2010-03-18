.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [x]
	.const 3   int      [1]
	.const 4   string   [x=]
	.const 5   int      [2]
	.const 6   string   [io.writeln]
	.const 7   int      [10]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int x
	        ldconst      3 --> [1]
	        stvar        0 --> [x]
	:2      ldconst      4 --> [x=]
	        ldvar        0 --> [x]
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        ldvar        0 --> [x]
	        ldconst      3 --> [1]
	        add         
	        stvar        0 --> [x]
	        ldvar        0 --> [x]
	        ldconst      7 --> [10]
	        gt          
	        ifnot        2 --> [2]
	        exit        
	.end
.end
