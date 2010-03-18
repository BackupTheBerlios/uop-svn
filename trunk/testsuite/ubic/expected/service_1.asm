.constant_pool
	.const 0   string   [servico]
	.const 1   string   [soma]
	.const 2   string   [x]
	.const 3   string   [y]
	.const 4   string   [constructor]
	.const 5   string   [context]
	.const 6   string   [start]
	.const 7   string   [s]
	.const 8   string   [Soma: ]
	.const 9   int      [10]
	.const 10  int      [20]
	.const 11  int      [2]
	.const 12  string   [io.writeln]
.end
.entity servico
	.valid_context_when (always)
	.method soma
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
	        ldconst      5 --> [context]
	        ldconst      1 --> [soma]
	        spublish    
	        ret         
	.end
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element s
	        newelem      0 --> [servico]
	        stvar        0 --> [s]
	        ldconst      8 --> [Soma: ]
	        ldconst      5 --> [context]
	        ldconst      1 --> [soma]
	        ldconst      9 --> [10]
	        ldconst      10 --> [20]
	        ldconst      11 --> [2]
	        runs        
	        ldconst      11 --> [2]
	        lcall        12 --> [io.writeln]
	        exit        
	.end
.end
