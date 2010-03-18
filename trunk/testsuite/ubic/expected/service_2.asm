.constant_pool
	.const 0   string   [servico]
	.const 1   string   [soma]
	.const 2   string   [x]
	.const 3   string   [y]
	.const 4   string   [diminui]
	.const 5   string   [imprime]
	.const 6   string   [msg]
	.const 7   string   [Mensagem: ]
	.const 8   int      [2]
	.const 9   string   [io.writeln]
	.const 10  string   [constructor]
	.const 11  string   [context]
	.const 12  string   [start]
	.const 13  string   [s]
	.const 14  string   [Soma  : ]
	.const 15  int      [10]
	.const 16  int      [20]
	.const 17  string   [Diminui: ]
	.const 18  string   [Ola !!!]
	.const 19  int      [1]
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
	.method diminui
		.param 0 int x
		.param 1 int y
		.result 0 int
	        ldparam      0 --> [x]
	        ldparam      1 --> [y]
	        sub         
	        stresult     0
	        ret         
	.end
	.method imprime
		.param 0 string msg
	        ldconst      7 --> [Mensagem: ]
	        ldparam      0 --> [msg]
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        ret         
	.end
	.method constructor
	        ldconst      11 --> [context]
	        ldconst      1 --> [soma]
	        spublish    
	        ldconst      11 --> [context]
	        ldconst      4 --> [diminui]
	        spublish    
	        ldconst      11 --> [context]
	        ldconst      5 --> [imprime]
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
	        ldconst      14 --> [Soma  : ]
	        ldconst      11 --> [context]
	        ldconst      1 --> [soma]
	        ldconst      15 --> [10]
	        ldconst      16 --> [20]
	        ldconst      8 --> [2]
	        runs        
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        ldconst      17 --> [Diminui: ]
	        ldconst      11 --> [context]
	        ldconst      4 --> [diminui]
	        ldconst      15 --> [10]
	        ldconst      16 --> [20]
	        ldconst      8 --> [2]
	        runs        
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        ldconst      11 --> [context]
	        ldconst      5 --> [imprime]
	        ldconst      18 --> [Ola !!!]
	        ldconst      19 --> [1]
	        runs        
	        exit        
	.end
.end
