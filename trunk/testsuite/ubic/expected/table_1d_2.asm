.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [tab]
	.const 3   string   [Alex]
	.const 4   int      [34]
	.const 5   string   [Gracy]
	.const 6   int      [32]
	.const 7   string   [Gabriel]
	.const 8   int      [1]
	.const 9   string   [Alex   =]
	.const 10  int      [2]
	.const 11  string   [io.writeln]
	.const 12  string   [Gracy  =]
	.const 13  string   [Gabriel=]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 table tab
	        ldvar        0 --> [tab]
	        ldconst      3 --> [Alex]
	        ldconst      4 --> [34]
	        sttab       
	        ldvar        0 --> [tab]
	        ldconst      5 --> [Gracy]
	        ldconst      6 --> [32]
	        sttab       
	        ldvar        0 --> [tab]
	        ldconst      7 --> [Gabriel]
	        ldconst      8 --> [1]
	        sttab       
	        ldconst      9 --> [Alex   =]
	        ldvar        0 --> [tab]
	        ldconst      3 --> [Alex]
	        ldtab       
	        ldconst      10 --> [2]
	        lcall        11 --> [io.writeln]
	        ldconst      12 --> [Gracy  =]
	        ldvar        0 --> [tab]
	        ldconst      5 --> [Gracy]
	        ldtab       
	        ldconst      10 --> [2]
	        lcall        11 --> [io.writeln]
	        ldconst      13 --> [Gabriel=]
	        ldvar        0 --> [tab]
	        ldconst      7 --> [Gabriel]
	        ldtab       
	        ldconst      10 --> [2]
	        lcall        11 --> [io.writeln]
	        exit        
	.end
.end
