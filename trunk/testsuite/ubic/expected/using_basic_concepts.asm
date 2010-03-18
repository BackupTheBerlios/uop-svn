.constant_pool
	.const 0   string   [soma]
	.const 1   string   [calcula]
	.const 2   int      [10]
	.const 3   int      [20]
	.const 4   string   [start]
	.const 5   string   [constructor]
	.const 6   string   [result]
	.const 7   string   [s]
	.const 8   string   [Resultado: ]
	.const 9   int      [2]
	.const 10  string   [io.writeln]
.end
.entity soma
	.valid_context_when (always)
	.method calcula
		.result 0 int
	        ldconst      2 --> [10]
	        ldconst      3 --> [20]
	        add         
	        stresult     0
	        ret         
	.end
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int result
		.var 1 element s
	        newelem      0 --> [soma]
	        stvar        1 --> [s]
	        ldvar        1 --> [s]
	        mcall        1 --> [calcula]
	        stvar        0 --> [result]
	        ldconst      8 --> [Resultado: ]
	        ldvar        0 --> [result]
	        ldconst      9 --> [2]
	        lcall        10 --> [io.writeln]
	        exit        
	.end
.end
