.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [x]
	.const 3   int      [20]
	.const 4   int      [1]
	.const 5   int      [10]
	.const 6   string   [x entre 1 e 10]
	.const 7   string   [io.writeln]
	.const 8   int      [11]
	.const 9   string   [x entre 11 e 20]
	.const 10  string   [x > 20]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int x
	        ldconst      3 --> [20]
	        stvar        0 --> [x]
	        ldvar        0 --> [x]
	        ldconst      4 --> [1]
	        ge          
	        ldvar        0 --> [x]
	        ldconst      5 --> [10]
	        le          
	        and         
	        ifnot        14 --> [14]
	        ldconst      6 --> [x entre 1 e 10]
	        ldconst      4 --> [1]
	        lcall        7 --> [io.writeln]
	        jmp          29 --> [29]
	:14     ldvar        0 --> [x]
	        ldconst      8 --> [11]
	        ge          
	        ldvar        0 --> [x]
	        ldconst      3 --> [20]
	        le          
	        and         
	        ifnot        26 --> [26]
	        ldconst      9 --> [x entre 11 e 20]
	        ldconst      4 --> [1]
	        lcall        7 --> [io.writeln]
	        jmp          29 --> [29]
	:26     ldconst      10 --> [x > 20]
	        ldconst      4 --> [1]
	        lcall        7 --> [io.writeln]
	:29     exit        
	.end
.end
