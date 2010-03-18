.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [i]
	.const 3   int      [1]
	.const 4   int      [10]
	.const 5   string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int i
	        ldconst      3 --> [1]
	        stvar        0 --> [i]
	:2      ldvar        0 --> [i]
	        ldconst      4 --> [10]
	        le          
	        ifnot        14 --> [14]
	        ldvar        0 --> [i]
	        ldconst      3 --> [1]
	        lcall        5 --> [io.writeln]
	        ldvar        0 --> [i]
	        ldconst      3 --> [1]
	        add         
	        stvar        0 --> [i]
	        jmp          2 --> [2]
	:14     exit        
	.end
.end
