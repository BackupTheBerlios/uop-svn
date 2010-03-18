.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [Inserindo informacoes]
	.const 3   int      [1]
	.const 4   string   [io.writeln]
	.const 5   string   [MeuContexto]
	.const 6   string   [key 1]
	.const 7   string   [key 2]
	.const 8   string   [key1+key2]
	.const 9   int      [2]
	.const 10  string   [Informacoes inseridas: ]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [Inserindo informacoes]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldconst      5 --> [MeuContexto]
	        ldconst      6 --> [key 1]
	        ldconst      7 --> [key 2]
	        ldconst      8 --> [key1+key2]
	        ldconst      9 --> [2]
	        ldconst      3 --> [1]
	        cpublish    
	        ldconst      10 --> [Informacoes inseridas: ]
	        ldconst      5 --> [MeuContexto]
	        ldconst      6 --> [key 1]
	        ldconst      7 --> [key 2]
	        ldconst      9 --> [2]
	        cget        
	        ldconst      9 --> [2]
	        lcall        4 --> [io.writeln]
	        exit        
	.end
.end
