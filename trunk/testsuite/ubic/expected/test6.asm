.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [v1]
	.const 3   int      [0]
	.const 4   string   [v1 no metodo start/0: ]
	.const 5   int      [2]
	.const 6   string   [io.writeln]
	.const 7   string   [metodo1]
	.const 8   int      [1]
	.const 9   string   [V1 no metodo metodo1/0: ]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int v1
	        ldconst      3 --> [0]
	        stvar        0 --> [v1]
	        ldconst      4 --> [v1 no metodo start/0: ]
	        ldvar        0 --> [v1]
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        ldself      
	        mcall        7 --> [metodo1]
	        ldconst      4 --> [v1 no metodo start/0: ]
	        ldvar        0 --> [v1]
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        exit        
	.end
	.method metodo1
		.var 0 int v1
	        ldconst      8 --> [1]
	        stvar        0 --> [v1]
	        ldconst      9 --> [V1 no metodo metodo1/0: ]
	        ldvar        0 --> [v1]
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        ret         
	.end
.end
