.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [Inserindo informacoes]
	.const 3   int      [1]
	.const 4   string   [io.writeln]
	.const 5   string   [MeuContexto]
	.const 6   string   [Numero 1]
	.const 7   int      [100]
	.const 8   string   [findnb em informacao inexistente: ]
	.const 9   string   [Numero X]
	.const 10  int      [2]
	.const 11  string   [Informacoes inseridas: ]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [Inserindo informacoes]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldconst      5 --> [MeuContexto]
	        ldconst      6 --> [Numero 1]
	        ldconst      7 --> [100]
	        ldconst      3 --> [1]
	        ldconst      3 --> [1]
	        cpublish    
	        ldconst      8 --> [findnb em informacao inexistente: ]
	        ldconst      5 --> [MeuContexto]
	        ldconst      9 --> [Numero X]
	        ldconst      3 --> [1]
	        cfindnb     
	        ldconst      10 --> [2]
	        lcall        4 --> [io.writeln]
	        ldconst      11 --> [Informacoes inseridas: ]
	        ldconst      5 --> [MeuContexto]
	        ldconst      6 --> [Numero 1]
	        ldconst      3 --> [1]
	        cfind       
	        ldconst      10 --> [2]
	        lcall        4 --> [io.writeln]
	        exit        
	.end
.end
