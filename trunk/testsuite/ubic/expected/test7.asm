.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [v1]
	.const 3   int      [0]
	.const 4   string   [v1 em start/0: ]
	.const 5   int      [2]
	.const 6   string   [io.writeln]
	.const 7   string   [Nome]
	.const 8   string   [metodo1]
	.const 9   string   [v1 em metodo1/1: ]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int v1
	        ldconst      3 --> [0]
	        stvar        0 --> [v1]
	        ldconst      4 --> [v1 em start/0: ]
	        ldvar        0 --> [v1]
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        ldconst      7 --> [Nome]
	        ldself      
	        mcall        8 --> [metodo1]
	        ldconst      4 --> [v1 em start/0: ]
	        ldvar        0 --> [v1]
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        exit        
	.end
	.method metodo1
		.param 0 string v1
	        ldconst      9 --> [v1 em metodo1/1: ]
	        ldparam      0 --> [v1]
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        ret         
	.end
.end
