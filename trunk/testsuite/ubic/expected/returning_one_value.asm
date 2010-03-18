.constant_pool
	.const 0   string   [start]
	.const 1   string   [adicao]
	.const 2   string   [x]
	.const 3   string   [y]
	.const 4   string   [subtracao]
	.const 5   string   [constructor]
	.const 6   string   [a]
	.const 7   string   [s]
	.const 8   int      [10]
	.const 9   int      [20]
	.const 10  string   [Adicao dos valores    : ]
	.const 11  int      [2]
	.const 12  string   [io.writeln]
	.const 13  string   [Subtracao dos valores : ]
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
	.method subtracao
		.param 0 int x
		.param 1 int y
		.result 0 int
	        ldparam      0 --> [x]
	        ldparam      1 --> [y]
	        sub         
	        stresult     0
	        ret         
	.end
	.method constructor
		.var 0 int a
		.var 1 int s
	        ldconst      8 --> [10]
	        ldconst      9 --> [20]
	        ldself      
	        mcall        1 --> [adicao]
	        stvar        0 --> [a]
	        ldconst      8 --> [10]
	        ldconst      9 --> [20]
	        ldself      
	        mcall        4 --> [subtracao]
	        stvar        1 --> [s]
	        ldconst      10 --> [Adicao dos valores    : ]
	        ldvar        0 --> [a]
	        ldconst      11 --> [2]
	        lcall        12 --> [io.writeln]
	        ldconst      13 --> [Subtracao dos valores : ]
	        ldvar        1 --> [s]
	        ldconst      11 --> [2]
	        lcall        12 --> [io.writeln]
	        exit        
	.end
.end
