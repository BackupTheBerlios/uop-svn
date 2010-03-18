.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [x]
	.const 3   int      [1]
	.const 4   int      [5]
	.const 5   int      [7]
	.const 6   int      [9]
	.const 7   string   [x=]
	.const 8   int      [2]
	.const 9   string   [io.writeln]
	.const 10  int      [10]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int x
	        ldconst      3 --> [1]
	        stvar        0 --> [x]
	:2      ldvar        0 --> [x]
	        ldconst      4 --> [5]
	        eq          
	        ldvar        0 --> [x]
	        ldconst      5 --> [7]
	        eq          
	        or          
	        ldvar        0 --> [x]
	        ldconst      6 --> [9]
	        eq          
	        or          
	        ifnot        20 --> [20]
	        ldvar        0 --> [x]
	        ldconst      3 --> [1]
	        add         
	        stvar        0 --> [x]
	        jmp          2 --> [2]
	        jmp          20 --> [20]
	:20     ldconst      7 --> [x=]
	        ldvar        0 --> [x]
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        ldvar        0 --> [x]
	        ldconst      3 --> [1]
	        add         
	        stvar        0 --> [x]
	        ldvar        0 --> [x]
	        ldconst      10 --> [10]
	        gt          
	        ifnot        2 --> [2]
	        exit        
	.end
.end
