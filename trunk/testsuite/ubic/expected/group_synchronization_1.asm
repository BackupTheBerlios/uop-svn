.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [p]
	.const 3   string   [process]
	.const 4   string   [Resultado: ]
	.const 5   string   [context]
	.const 6   string   [Resultado]
	.const 7   int      [1]
	.const 8   int      [2]
	.const 9   string   [io.writeln]
	.const 10  int      [10]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element p
	        newelem      3 --> [process]
	        stvar        0 --> [p]
	        ldconst      4 --> [Resultado: ]
	        ldconst      5 --> [context]
	        ldconst      6 --> [Resultado]
	        ldconst      7 --> [1]
	        cget        
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        exit        
	.end
.end
.entity process
	.option parallel
	.valid_context_when (always)
	.method constructor
	        ldconst      5 --> [context]
	        ldconst      6 --> [Resultado]
	        ldconst      10 --> [10]
	        ldconst      8 --> [2]
	        mul         
	        ldconst      7 --> [1]
	        ldconst      7 --> [1]
	        cpublish    
	        ret         
	.end
.end
