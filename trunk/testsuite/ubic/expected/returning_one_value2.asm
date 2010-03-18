.constant_pool
	.const 0   string   [start]
	.const 1   string   [adicao]
	.const 2   string   [x]
	.const 3   string   [y]
	.const 4   string   [constructor]
	.const 5   string   [a]
	.const 6   int      [10]
	.const 7   int      [20]
	.const 8   string   [Adicao dos valores    : ]
	.const 9   int      [2]
	.const 10  string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method adicao
		.param 0 int x
		.param 1 int y
		.result 0 int
	        ldparam      0 --> [x]
	        ldparam      1 --> [y]
	        add         
	        stresult     0
	        ret         
	.end
	.method constructor
		.var 0 int a
	        ldconst      6 --> [10]
	        ldconst      7 --> [20]
	        ldself      
	        mcall        1 --> [adicao]
	        stvar        0 --> [a]
	        ldconst      8 --> [Adicao dos valores    : ]
	        ldvar        0 --> [a]
	        ldconst      9 --> [2]
	        lcall        10 --> [io.writeln]
	        exit        
	.end
.end
