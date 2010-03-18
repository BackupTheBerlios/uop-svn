.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [x]
	.const 3   int      [1]
	.const 4   int      [10]
	.const 5   int      [5]
	.const 6   int      [7]
	.const 7   int      [9]
	.const 8   string   [x=]
	.const 9   int      [2]
	.const 10  string   [io.writeln]
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
	        ifnot        33 --> [33]
	        ldvar        0 --> [x]
	        ldconst      5 --> [5]
	        eq          
	        ldvar        0 --> [x]
	        ldconst      6 --> [7]
	        eq          
	        or          
	        ldvar        0 --> [x]
	        ldconst      7 --> [9]
	        eq          
	        or          
	        ifnot        24 --> [24]
	        ldvar        0 --> [x]
	        ldconst      3 --> [1]
	        add         
	        stvar        0 --> [x]
	        jmp          2 --> [2]
	        jmp          24 --> [24]
	:24     ldconst      8 --> [x=]
	        ldvar        0 --> [x]
	        ldconst      9 --> [2]
	        lcall        10 --> [io.writeln]
	        ldvar        0 --> [x]
	        ldconst      3 --> [1]
	        add         
	        stvar        0 --> [x]
	        jmp          2 --> [2]
	:33     exit        
	.end
.end
