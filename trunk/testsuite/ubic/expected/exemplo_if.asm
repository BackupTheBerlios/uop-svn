.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [value]
	.const 3   int      [10]
	.const 4   int      [100]
	.const 5   int      [1]
	.const 6   string   [value=]
	.const 7   int      [2]
	.const 8   string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int value
	        ldconst      3 --> [10]
	        stvar        0 --> [value]
	        ldvar        0 --> [value]
	        ldconst      4 --> [100]
	        lt          
	        ifnot        9 --> [9]
	        ldconst      4 --> [100]
	        stvar        0 --> [value]
	        jmp          13 --> [13]
	:9      ldvar        0 --> [value]
	        ldconst      5 --> [1]
	        sub         
	        stvar        0 --> [value]
	:13     ldconst      6 --> [value=]
	        ldvar        0 --> [value]
	        ldconst      7 --> [2]
	        lcall        8 --> [io.writeln]
	        exit        
	.end
.end
