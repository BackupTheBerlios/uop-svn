.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [x]
	.const 3   int      [1]
	.const 4   int      [30]
	.const 5   string   [x=]
	.const 6   int      [2]
	.const 7   string   [io.writeln]
	.const 8   int      [10]
	.const 9   string   [x entre 1 e 10]
	.const 10  int      [11]
	.const 11  int      [20]
	.const 12  string   [x entre 11 e 20]
	.const 13  string   [x > 20]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int x
	        ldconst      3 --> [1]
	        stvar        0 --> [x]
	:2      ldvar        0 --> [x]
	        ldconst      4 --> [30]
	        le          
	        ifnot        44 --> [44]
	        jmp          12 --> [12]
	:7      ldvar        0 --> [x]
	        ldconst      3 --> [1]
	        add         
	        stvar        0 --> [x]
	        jmp          2 --> [2]
	:12     ldconst      5 --> [x=]
	        ldvar        0 --> [x]
	        ldconst      6 --> [2]
	        lcall        7 --> [io.writeln]
	        ldvar        0 --> [x]
	        ldconst      3 --> [1]
	        ge          
	        ldvar        0 --> [x]
	        ldconst      8 --> [10]
	        le          
	        and         
	        ifnot        28 --> [28]
	        ldconst      9 --> [x entre 1 e 10]
	        ldconst      3 --> [1]
	        lcall        7 --> [io.writeln]
	        jmp          43 --> [43]
	:28     ldvar        0 --> [x]
	        ldconst      10 --> [11]
	        ge          
	        ldvar        0 --> [x]
	        ldconst      11 --> [20]
	        le          
	        and         
	        ifnot        40 --> [40]
	        ldconst      12 --> [x entre 11 e 20]
	        ldconst      3 --> [1]
	        lcall        7 --> [io.writeln]
	        jmp          43 --> [43]
	:40     ldconst      13 --> [x > 20]
	        ldconst      3 --> [1]
	        lcall        7 --> [io.writeln]
	:43     jmp          7 --> [7]
	:44     exit        
	.end
.end
