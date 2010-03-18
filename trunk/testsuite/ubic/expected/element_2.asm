.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [e]
	.const 3   string   [elemento]
	.const 4   string   [Antes de chamar imprime]
	.const 5   int      [1]
	.const 6   string   [io.writeln]
	.const 7   string   [imprime]
	.const 8   string   [Depois de chamar imprime]
	.const 9   string   [Metodo elemento.imprime()]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element e
	        newelem      3 --> [elemento]
	        stvar        0 --> [e]
	        ldconst      4 --> [Antes de chamar imprime]
	        ldconst      5 --> [1]
	        lcall        6 --> [io.writeln]
	        ldvar        0 --> [e]
	        mcall        7 --> [imprime]
	        ldconst      8 --> [Depois de chamar imprime]
	        ldconst      5 --> [1]
	        lcall        6 --> [io.writeln]
	        exit        
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method imprime
	        ldconst      9 --> [Metodo elemento.imprime()]
	        ldconst      5 --> [1]
	        lcall        6 --> [io.writeln]
	        ret         
	.end
.end
