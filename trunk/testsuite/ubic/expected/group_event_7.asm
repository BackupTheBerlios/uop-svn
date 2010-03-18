.constant_pool
	.const 0   string   [servico]
	.const 1   string   [soma]
	.const 2   string   [x]
	.const 3   string   [y]
	.const 4   string   [constructor]
	.const 5   string   [context]
	.const 6   string   [destructor]
	.const 7   string   [start]
	.const 8   string   [s]
	.const 9   string   [on_insert_service]
	.const 10  string   [ev_servico_inserido]
	.const 11  string   [on_remove_service]
	.const 12  string   [ev_servico_removido]
	.const 13  string   [Resultado do servico soma(10,20): ]
	.const 14  int      [10]
	.const 15  int      [20]
	.const 16  int      [2]
	.const 17  string   [io.writeln]
	.const 18  string   [datetime.sleep]
	.const 19  string   [Terminando a execucao...]
	.const 20  int      [1]
	.const 21  string   [nome]
	.const 22  string   [Inserido servico ]
	.const 23  string   [Removido servico ]
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
	.method destructor
	        ldconst      5 --> [context]
	        ldconst      1 --> [soma]
	        srem        
	        ret         
	.end
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element s
	        ldconst      5 --> [context]
	        ldconst      9 --> [on_insert_service]
	        ldconst      10 --> [ev_servico_inserido]
	        bcontextev  
	        ldconst      5 --> [context]
	        ldconst      11 --> [on_remove_service]
	        ldconst      12 --> [ev_servico_removido]
	        bcontextev  
	        newelem      0 --> [servico]
	        stvar        0 --> [s]
	        ldconst      13 --> [Resultado do servico soma(10,20): ]
	        ldconst      5 --> [context]
	        ldconst      1 --> [soma]
	        ldconst      14 --> [10]
	        ldconst      15 --> [20]
	        ldconst      16 --> [2]
	        runs        
	        ldconst      16 --> [2]
	        lcall        17 --> [io.writeln]
	        ldvar        0 --> [s]
	        mcall        6 --> [destructor]
	        ldconst      16 --> [2]
	        lcall        18 --> [datetime.sleep]
	        ldconst      19 --> [Terminando a execucao...]
	        ldconst      20 --> [1]
	        lcall        17 --> [io.writeln]
	        exit        
	.end
	.method ev_servico_inserido
		.param 0 string nome
	        ldconst      22 --> [Inserido servico ]
	        ldparam      0 --> [nome]
	        ldconst      16 --> [2]
	        lcall        17 --> [io.writeln]
	        ret         
	.end
	.method ev_servico_removido
		.param 0 string nome
	        ldconst      23 --> [Removido servico ]
	        ldparam      0 --> [nome]
	        ldconst      16 --> [2]
	        lcall        17 --> [io.writeln]
	        ret         
	.end
.end
