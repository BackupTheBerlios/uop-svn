.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [context]
	.const 3   string   [on_insert_data]
	.const 4   string   [ev_dado_inserido]
	.const 5   string   [on_remove_data]
	.const 6   string   [ev_dado_removido]
	.const 7   string   [xxx]
	.const 8   string   [yyy]
	.const 9   string   [zzz]
	.const 10  int      [1]
	.const 11  int      [2]
	.const 12  string   [xxx2]
	.const 13  string   [yyy2]
	.const 14  string   [zzz2]
	.const 15  string   [datetime.sleep]
	.const 16  string   [Valor removido: ]
	.const 17  string   [io.writeln]
	.const 18  string   [Terminando a execucao...]
	.const 19  string   [chave]
	.const 20  string   [valor]
	.const 21  string   [Inserido chave ]
	.const 22  string   [ com valor ]
	.const 23  int      [4]
	.const 24  string   [Removido chave ]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [context]
	        ldconst      3 --> [on_insert_data]
	        ldconst      4 --> [ev_dado_inserido]
	        bcontextev  
	        ldconst      2 --> [context]
	        ldconst      5 --> [on_remove_data]
	        ldconst      6 --> [ev_dado_removido]
	        bcontextev  
	        ldconst      2 --> [context]
	        ldconst      7 --> [xxx]
	        ldconst      8 --> [yyy]
	        ldconst      9 --> [zzz]
	        ldconst      10 --> [1]
	        ldconst      11 --> [2]
	        cpublish    
	        ldconst      2 --> [context]
	        ldconst      12 --> [xxx2]
	        ldconst      13 --> [yyy2]
	        ldconst      14 --> [zzz2]
	        ldconst      10 --> [1]
	        ldconst      11 --> [2]
	        cpublish    
	        ldconst      11 --> [2]
	        lcall        15 --> [datetime.sleep]
	        ldconst      16 --> [Valor removido: ]
	        ldconst      2 --> [context]
	        ldconst      7 --> [xxx]
	        ldconst      10 --> [1]
	        cget        
	        ldconst      11 --> [2]
	        lcall        17 --> [io.writeln]
	        ldconst      16 --> [Valor removido: ]
	        ldconst      2 --> [context]
	        ldconst      12 --> [xxx2]
	        ldconst      10 --> [1]
	        cget        
	        ldconst      11 --> [2]
	        lcall        17 --> [io.writeln]
	        ldconst      18 --> [Terminando a execucao...]
	        ldconst      10 --> [1]
	        lcall        17 --> [io.writeln]
	        exit        
	.end
	.method ev_dado_inserido
		.param 0 string chave
		.param 1 string valor
	        ldconst      21 --> [Inserido chave ]
	        ldparam      0 --> [chave]
	        ldconst      22 --> [ com valor ]
	        ldparam      1 --> [valor]
	        ldconst      23 --> [4]
	        lcall        17 --> [io.writeln]
	        ret         
	.end
	.method ev_dado_removido
		.param 0 string chave
		.param 1 string valor
	        ldconst      24 --> [Removido chave ]
	        ldparam      0 --> [chave]
	        ldconst      22 --> [ com valor ]
	        ldparam      1 --> [valor]
	        ldconst      23 --> [4]
	        lcall        17 --> [io.writeln]
	        ret         
	.end
.end
