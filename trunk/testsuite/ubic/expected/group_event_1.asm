.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [context]
	.const 3   string   [on_insert_data]
	.const 4   string   [ev_dado_inserido]
	.const 5   string   [xxx]
	.const 6   string   [yyy]
	.const 7   string   [zzz]
	.const 8   int      [1]
	.const 9   int      [2]
	.const 10  string   [xxx2]
	.const 11  string   [yyy2]
	.const 12  string   [zzz2]
	.const 13  string   [datetime.sleep]
	.const 14  string   [Terminando a execucao...]
	.const 15  string   [io.writeln]
	.const 16  string   [chave]
	.const 17  string   [valor]
	.const 18  string   [Inserido chave ]
	.const 19  string   [ com valor ]
	.const 20  int      [4]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [context]
	        ldconst      3 --> [on_insert_data]
	        ldconst      4 --> [ev_dado_inserido]
	        bcontextev  
	        ldconst      2 --> [context]
	        ldconst      5 --> [xxx]
	        ldconst      6 --> [yyy]
	        ldconst      7 --> [zzz]
	        ldconst      8 --> [1]
	        ldconst      9 --> [2]
	        cpublish    
	        ldconst      2 --> [context]
	        ldconst      10 --> [xxx2]
	        ldconst      11 --> [yyy2]
	        ldconst      12 --> [zzz2]
	        ldconst      8 --> [1]
	        ldconst      9 --> [2]
	        cpublish    
	        ldconst      9 --> [2]
	        lcall        13 --> [datetime.sleep]
	        ldconst      14 --> [Terminando a execucao...]
	        ldconst      8 --> [1]
	        lcall        15 --> [io.writeln]
	        exit        
	.end
	.method ev_dado_inserido
		.param 0 string chave
		.param 1 string valor
	        ldconst      18 --> [Inserido chave ]
	        ldparam      0 --> [chave]
	        ldconst      19 --> [ com valor ]
	        ldparam      1 --> [valor]
	        ldconst      20 --> [4]
	        lcall        15 --> [io.writeln]
	        ret         
	.end
.end
