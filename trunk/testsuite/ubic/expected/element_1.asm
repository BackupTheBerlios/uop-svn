.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [e]
	.const 3   string   [elemento]
	.const 4   string   [imprime]
	.const 5   string   [Oi !!!!]
	.const 6   int      [1]
	.const 7   string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element e
	        newelem      3 --> [elemento]
	        stvar        0 --> [e]
	        ldvar        0 --> [e]
	        mcall        4 --> [imprime]
	        exit        
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method imprime
	        ldconst      5 --> [Oi !!!!]
	        ldconst      6 --> [1]
	        lcall        7 --> [io.writeln]
	        ret         
	.end
.end
