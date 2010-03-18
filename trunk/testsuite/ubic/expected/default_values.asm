.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [var_int]
	.const 3   string   [var_real]
	.const 4   string   [var_string]
	.const 5   string   [Default de int   =]
	.const 6   int      [2]
	.const 7   string   [io.writeln]
	.const 8   string   [Default de real  =]
	.const 9   string   [Default de string=]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int var_int
		.var 1 real var_real
		.var 2 string var_string
	        ldconst      5 --> [Default de int   =]
	        ldvar        0 --> [var_int]
	        ldconst      6 --> [2]
	        lcall        7 --> [io.writeln]
	        ldconst      8 --> [Default de real  =]
	        ldvar        1 --> [var_real]
	        ldconst      6 --> [2]
	        lcall        7 --> [io.writeln]
	        ldconst      9 --> [Default de string=]
	        ldvar        2 --> [var_string]
	        ldconst      6 --> [2]
	        lcall        7 --> [io.writeln]
	        exit        
	.end
.end
