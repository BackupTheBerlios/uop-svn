.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [x]
	.const 3   int      [1]
	.const 4   int      [10]
	.const 5   string   [x=]
	.const 6   int      [2]
	.const 7   string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int x
	        ldconst      3 --> [1]
	        stvar        0 --> [x]
	:2      ldvar        0 --> [x]
	        ldconst      4 --> [10]
	        le          
	        ifnot        15 --> [15]
	        ldconst      5 --> [x=]
	        ldvar        0 --> [x]
	        ldconst      6 --> [2]
	        lcall        7 --> [io.writeln]
	        ldvar        0 --> [x]
	        ldconst      3 --> [1]
	        add         
	        stvar        0 --> [x]
	        jmp          2 --> [2]
	:15     exit        
	.end
.end
