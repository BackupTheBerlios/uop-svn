.constant_pool
	.const 0   string   [start]
	.const 1   string   [calcula]
	.const 2   string   [x]
	.const 3   string   [y]
	.const 4   string   [constructor]
	.const 5   string   [a]
	.const 6   string   [s]
	.const 7   int      [10]
	.const 8   int      [20]
	.const 9   string   [Adicao dos valores    : ]
	.const 10  int      [2]
	.const 11  string   [io.writeln]
	.const 12  string   [Subtracao dos valores : ]
.end
.entity start
	.valid_context_when (always)
	.method calcula
		.param 0 int x
		.param 1 int y
		.result 0 int
		.result 1 int
	        ldparam      0 --> [x]
	        ldparam      1 --> [y]
	        add         
	        stresult     0
	        ldparam      0 --> [x]
	        ldparam      1 --> [y]
	        sub         
	        stresult     1
	        ret         
	.end
	.method constructor
		.var 0 int a
		.var 1 int s
	        ldconst      7 --> [10]
	        ldconst      8 --> [20]
	        ldself      
	        mcall        1 --> [calcula]
	        stvar        0 --> [a]
	        stvar        1 --> [s]
	        ldconst      9 --> [Adicao dos valores    : ]
	        ldvar        0 --> [a]
	        ldconst      10 --> [2]
	        lcall        11 --> [io.writeln]
	        ldconst      12 --> [Subtracao dos valores : ]
	        ldvar        1 --> [s]
	        ldconst      10 --> [2]
	        lcall        11 --> [io.writeln]
	        exit        
	.end
.end
