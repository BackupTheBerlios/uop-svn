.constant_pool
	.const 0   string   [start]
	.const 1   string   [multiplica]
	.const 2   string   [x]
	.const 3   string   [y]
	.const 4   string   [calcula]
	.const 5   string   [constructor]
	.const 6   string   [m]
	.const 7   string   [a]
	.const 8   string   [s]
	.const 9   int      [10]
	.const 10  int      [20]
	.const 11  string   [Multiplicacao dos valores: ]
	.const 12  int      [2]
	.const 13  string   [io.writeln]
	.const 14  string   [Adicao dos valores       : ]
	.const 15  string   [Subtracao dos valores    : ]
.end
.entity start
	.valid_context_when (always)
	.method multiplica
		.param 0 int x
		.param 1 int y
		.result 0 int
	        ldparam      0 --> [x]
	        ldparam      1 --> [y]
	        mul         
	        stresult     0
	        ret         
	.end
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
		.var 0 int m
		.var 1 int a
		.var 2 int s
	        ldconst      9 --> [10]
	        ldconst      10 --> [20]
	        ldself      
	        mcall        1 --> [multiplica]
	        stvar        0 --> [m]
	        ldconst      9 --> [10]
	        ldconst      10 --> [20]
	        ldself      
	        mcall        4 --> [calcula]
	        stvar        1 --> [a]
	        stvar        2 --> [s]
	        ldconst      11 --> [Multiplicacao dos valores: ]
	        ldvar        0 --> [m]
	        ldconst      12 --> [2]
	        lcall        13 --> [io.writeln]
	        ldconst      14 --> [Adicao dos valores       : ]
	        ldvar        1 --> [a]
	        ldconst      12 --> [2]
	        lcall        13 --> [io.writeln]
	        ldconst      15 --> [Subtracao dos valores    : ]
	        ldvar        2 --> [s]
	        ldconst      12 --> [2]
	        lcall        13 --> [io.writeln]
	        exit        
	.end
.end
