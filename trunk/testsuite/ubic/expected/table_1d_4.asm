.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [tab]
	.const 3   string   [Nome]
	.const 4   string   [Alex]
	.const 5   string   [Sexo]
	.const 6   string   [M]
	.const 7   string   [Idade]
	.const 8   int      [34]
	.const 9   string   [Nome =]
	.const 10  int      [2]
	.const 11  string   [io.writeln]
	.const 12  string   [Sexo =]
	.const 13  string   [Idade=]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 table tab
	        ldvar        0 --> [tab]
	        ldconst      3 --> [Nome]
	        ldconst      4 --> [Alex]
	        sttab       
	        ldvar        0 --> [tab]
	        ldconst      5 --> [Sexo]
	        ldconst      6 --> [M]
	        sttab       
	        ldvar        0 --> [tab]
	        ldconst      7 --> [Idade]
	        ldconst      8 --> [34]
	        sttab       
	        ldconst      9 --> [Nome =]
	        ldvar        0 --> [tab]
	        ldconst      3 --> [Nome]
	        ldtab       
	        ldconst      10 --> [2]
	        lcall        11 --> [io.writeln]
	        ldconst      12 --> [Sexo =]
	        ldvar        0 --> [tab]
	        ldconst      5 --> [Sexo]
	        ldtab       
	        ldconst      10 --> [2]
	        lcall        11 --> [io.writeln]
	        ldconst      13 --> [Idade=]
	        ldvar        0 --> [tab]
	        ldconst      7 --> [Idade]
	        ldtab       
	        ldconst      10 --> [2]
	        lcall        11 --> [io.writeln]
	        exit        
	.end
.end
