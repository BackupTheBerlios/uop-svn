.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [tab]
	.const 3   int      [1]
	.const 4   int      [100]
	.const 5   int      [2]
	.const 6   int      [200]
	.const 7   string   [tab[1]=]
	.const 8   string   [io.writeln]
	.const 9   string   [tab[2]=]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 table tab
	        ldvar        0 --> [tab]
	        ldconst      3 --> [1]
	        ldconst      4 --> [100]
	        sttab       
	        ldvar        0 --> [tab]
	        ldconst      5 --> [2]
	        ldconst      6 --> [200]
	        sttab       
	        ldconst      7 --> [tab[1]=]
	        ldvar        0 --> [tab]
	        ldconst      3 --> [1]
	        ldtab       
	        ldconst      5 --> [2]
	        lcall        8 --> [io.writeln]
	        ldconst      9 --> [tab[2]=]
	        ldvar        0 --> [tab]
	        ldconst      5 --> [2]
	        ldtab       
	        ldconst      5 --> [2]
	        lcall        8 --> [io.writeln]
	        exit        
	.end
.end
