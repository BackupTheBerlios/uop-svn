.constant_pool
	.const 0   string   [servico]
	.const 1   string   [operations]
	.const 2   string   [par1]
	.const 3   string   [par2]
	.const 4   string   [par1=]
	.const 5   string   [ par2=]
	.const 6   int      [4]
	.const 7   string   [io.writeln]
	.const 8   string   [constructor]
	.const 9   string   [context]
	.const 10  string   [start]
	.const 11  string   [soma]
	.const 12  string   [subtracao]
	.const 13  string   [s]
	.const 14  int      [2]
	.const 15  int      [10]
	.const 16  string   [soma     : ]
	.const 17  string   [subtracao: ]
.end
.entity servico
	.valid_context_when (always)
	.method operations
		.param 0 int par1
		.param 1 int par2
		.result 0 int
		.result 1 int
	        ldconst      4 --> [par1=]
	        ldparam      0 --> [par1]
	        ldconst      5 --> [ par2=]
	        ldparam      1 --> [par2]
	        ldconst      6 --> [4]
	        lcall        7 --> [io.writeln]
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
	.method constructor
	        ldconst      9 --> [context]
	        ldconst      1 --> [operations]
	        spublish    
	        ret         
	.end
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int soma
		.var 1 int subtracao
		.var 2 element s
	        newelem      0 --> [servico]
	        stvar        2 --> [s]
	        ldconst      9 --> [context]
	        ldconst      1 --> [operations]
	        ldconst      14 --> [2]
	        ldconst      15 --> [10]
	        ldconst      14 --> [2]
	        runs        
	        stvar        0 --> [soma]
	        stvar        1 --> [subtracao]
	        ldconst      16 --> [soma     : ]
	        ldvar        0 --> [soma]
	        ldconst      14 --> [2]
	        lcall        7 --> [io.writeln]
	        ldconst      17 --> [subtracao: ]
	        ldvar        1 --> [subtracao]
	        ldconst      14 --> [2]
	        lcall        7 --> [io.writeln]
	        exit        
	.end
.end
