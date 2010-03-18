.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [Olá mundo !!!]
	.const 3   int      [1]
	.const 4   string   [io.writeln]
	.const 5   string   [Mais um olá mundo !!!]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [Olá mundo !!!]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldconst      5 --> [Mais um olá mundo !!!]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        exit        
	.end
.end
