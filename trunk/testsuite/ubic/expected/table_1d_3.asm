.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [tab]
	.const 3   string   [index]
	.const 4   int      [1]
	.const 5   int      [10]
	.const 6   string   [tab[]
	.const 7   string   []=]
	.const 8   int      [4]
	.const 9   string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 table tab
		.var 1 int index
	        ldconst      4 --> [1]
	        stvar        1 --> [index]
	:2      ldvar        1 --> [index]
	        ldconst      5 --> [10]
	        le          
	        ifnot        19 --> [19]
	        jmp          12 --> [12]
	:7      ldvar        1 --> [index]
	        ldconst      4 --> [1]
	        add         
	        stvar        1 --> [index]
	        jmp          2 --> [2]
	:12     ldvar        0 --> [tab]
	        ldvar        1 --> [index]
	        ldvar        1 --> [index]
	        ldconst      5 --> [10]
	        mul         
	        sttab       
	        jmp          7 --> [7]
	:19     ldconst      4 --> [1]
	        stvar        1 --> [index]
	:21     ldvar        1 --> [index]
	        ldconst      5 --> [10]
	        le          
	        ifnot        40 --> [40]
	        jmp          31 --> [31]
	:26     ldvar        1 --> [index]
	        ldconst      4 --> [1]
	        add         
	        stvar        1 --> [index]
	        jmp          21 --> [21]
	:31     ldconst      6 --> [tab[]
	        ldvar        1 --> [index]
	        ldconst      7 --> []=]
	        ldvar        0 --> [tab]
	        ldvar        1 --> [index]
	        ldtab       
	        ldconst      8 --> [4]
	        lcall        9 --> [io.writeln]
	        jmp          26 --> [26]
	:40     exit        
	.end
.end
