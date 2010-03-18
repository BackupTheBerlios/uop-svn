.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [x]
	.const 3   int      [0]
	.const 4   int      [10]
	.const 5   int      [1]
	.const 6   string   [x=]
	.const 7   int      [2]
	.const 8   string   [io.writeln]
	.const 9   int      [5]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int x
	        ldconst      3 --> [0]
	        stvar        0 --> [x]
	:2      ldvar        0 --> [x]
	        ldconst      4 --> [10]
	        le          
	        ifnot        21 --> [21]
	        ldvar        0 --> [x]
	        ldconst      5 --> [1]
	        add         
	        stvar        0 --> [x]
	        ldconst      6 --> [x=]
	        ldvar        0 --> [x]
	        ldconst      7 --> [2]
	        lcall        8 --> [io.writeln]
	        ldvar        0 --> [x]
	        ldconst      9 --> [5]
	        ge          
	        ifnot        20 --> [20]
	        jmp          21 --> [21]
	        jmp          20 --> [20]
	:20     jmp          2 --> [2]
	:21     exit        
	.end
.end
