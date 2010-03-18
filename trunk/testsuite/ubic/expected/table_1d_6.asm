.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [tab]
	.const 3   string   [20]
	.const 4   int      [20]
	.const 5   string   [10]
	.const 6   int      [10]
	.const 7   string   [tab[1]=]
	.const 8   int      [1]
	.const 9   int      [2]
	.const 10  string   [io.writeln]
	.const 11  string   [tab[2]=]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 table tab
	        ldvar        0 --> [tab]
	        ldconst      3 --> [20]
	        ldconst      4 --> [20]
	        sttab       
	        ldvar        0 --> [tab]
	        ldconst      5 --> [10]
	        ldconst      6 --> [10]
	        sttab       
	        ldconst      7 --> [tab[1]=]
	        ldvar        0 --> [tab]
	        ldconst      8 --> [1]
	        ldtab       
	        ldconst      9 --> [2]
	        lcall        10 --> [io.writeln]
	        ldconst      11 --> [tab[2]=]
	        ldvar        0 --> [tab]
	        ldconst      9 --> [2]
	        ldtab       
	        ldconst      9 --> [2]
	        lcall        10 --> [io.writeln]
	        exit        
	.end
.end
