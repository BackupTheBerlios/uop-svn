.constant_pool
	.const 0   string   [servico]
	.const 1   string   [soma]
	.const 2   string   [x]
	.const 3   string   [y]
	.const 4   string   [constructor]
	.const 5   string   [context]
	.const 6   string   [start]
	.const 7   string   [s]
	.const 8   string   [on_insert_service]
	.const 9   string   [ev_servico_inserido]
	.const 10  int      [2]
	.const 11  string   [datetime.sleep]
	.const 12  string   [Terminando a execucao...]
	.const 13  int      [1]
	.const 14  string   [io.writeln]
	.const 15  string   [nome]
	.const 16  string   [Inserido servico ]
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
	        ldconst      5 --> [context]
	        ldconst      8 --> [on_insert_service]
	        ldconst      9 --> [ev_servico_inserido]
	        bcontextev  
	        newelem      0 --> [servico]
	        stvar        0 --> [s]
	        ldconst      10 --> [2]
	        lcall        11 --> [datetime.sleep]
	        ldconst      12 --> [Terminando a execucao...]
	        ldconst      13 --> [1]
	        lcall        14 --> [io.writeln]
	        exit        
	.end
	.method ev_servico_inserido
		.param 0 string nome
	        ldconst      16 --> [Inserido servico ]
	        ldparam      0 --> [nome]
	        ldconst      10 --> [2]
	        lcall        14 --> [io.writeln]
	        ret         
	.end
.end
