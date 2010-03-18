.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   []
	.const 3   string   [Alex]
	.const 4   string   [on_new_context]
	.const 5   string   [ev_contexto_inserido]
	.const 6   string   [context]
	.const 7   string   [context.1]
	.const 8   string   [ev_contexto_inserido2]
	.const 9   string   [context.1.1]
	.const 10  int      [2]
	.const 11  string   [datetime.sleep]
	.const 12  string   [Terminando a execucao...]
	.const 13  int      [1]
	.const 14  string   [io.writeln]
	.const 15  string   [nome]
	.const 16  string   [Inserido contexto ]
	.const 17  string   [Inserido contexto em context.1: ]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> []
	        ldconst      3 --> [Alex]
	        mjoin       
	        ldconst      2 --> []
	        ldconst      4 --> [on_new_context]
	        ldconst      5 --> [ev_contexto_inserido]
	        bcontextev  
	        ldconst      6 --> [context]
	        ldconst      3 --> [Alex]
	        mjoin       
	        ldconst      7 --> [context.1]
	        ldconst      3 --> [Alex]
	        mjoin       
	        ldconst      7 --> [context.1]
	        ldconst      4 --> [on_new_context]
	        ldconst      8 --> [ev_contexto_inserido2]
	        bcontextev  
	        ldconst      9 --> [context.1.1]
	        ldconst      3 --> [Alex]
	        mjoin       
	        ldconst      10 --> [2]
	        lcall        11 --> [datetime.sleep]
	        ldconst      12 --> [Terminando a execucao...]
	        ldconst      13 --> [1]
	        lcall        14 --> [io.writeln]
	        exit        
	.end
	.method ev_contexto_inserido
		.param 0 string nome
	        ldconst      16 --> [Inserido contexto ]
	        ldparam      0 --> [nome]
	        ldconst      10 --> [2]
	        lcall        14 --> [io.writeln]
	        ret         
	.end
	.method ev_contexto_inserido2
		.param 0 string nome
	        ldconst      17 --> [Inserido contexto em context.1: ]
	        ldparam      0 --> [nome]
	        ldconst      10 --> [2]
	        lcall        14 --> [io.writeln]
	        ret         
	.end
.end
