.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [soma]
	.const 3   string   [subtracao]
	.const 4   int      [2]
	.const 5   int      [10]
	.const 6   string   [operations]
	.const 7   string   [soma     : ]
	.const 8   string   [io.writeln]
	.const 9   string   [subtracao: ]
	.const 10  string   [par1]
	.const 11  string   [par2]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int soma
		.var 1 int subtracao
	        ldconst      4 --> [2]
	        ldconst      5 --> [10]
	        ldself      
	        mcall        6 --> [operations]
	        stvar        0 --> [soma]
	        stvar        1 --> [subtracao]
	        ldconst      7 --> [soma     : ]
	        ldvar        0 --> [soma]
	        ldconst      4 --> [2]
	        lcall        8 --> [io.writeln]
	        ldconst      9 --> [subtracao: ]
	        ldvar        1 --> [subtracao]
	        ldconst      4 --> [2]
	        lcall        8 --> [io.writeln]
	        exit        
	.end
	.method operations
		.param 0 int par1
		.param 1 int par2
		.result 0 int
		.result 1 int
	        ldparam      0 --> [par1]
	        ldparam      1 --> [par2]
	        add         
	        stresult     0
	        ldparam      0 --> [par1]
	        ldparam      1 --> [par2]
	        sub         
	        stresult     1
	        ret         
	.end
.end
