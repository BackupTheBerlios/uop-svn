.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [i]
	.const 3   int      [0]
	.const 4   int      [10]
	.const 5   int      [1]
	.const 6   string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int i
	        ldconst      3 --> [0]
	        stvar        0 --> [i]
	:2      ldvar        0 --> [i]
	        ldconst      4 --> [10]
	        le          
	        ifnot        16 --> [16]
	        jmp          12 --> [12]
	:7      ldvar        0 --> [i]
	        ldconst      5 --> [1]
	        add         
	        stvar        0 --> [i]
	        jmp          2 --> [2]
	:12     ldvar        0 --> [i]
	        ldconst      5 --> [1]
	        lcall        6 --> [io.writeln]
	        jmp          7 --> [7]
	:16     exit        
	.end
.end
