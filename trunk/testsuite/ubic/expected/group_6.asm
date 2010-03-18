.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [Inserindo informacoes]
	.const 3   int      [1]
	.const 4   string   [io.writeln]
	.const 5   string   [MeuContexto]
	.const 6   string   [key 1]
	.const 7   string   [key 2]
	.const 8   string   [res1]
	.const 9   string   [res2]
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
	        ldconst      6 --> [key 1]
	        ldconst      7 --> [key 2]
	        ldconst      8 --> [res1]
	        ldconst      9 --> [res2]
	        ldconst      10 --> [2]
	        ldconst      10 --> [2]
	        cpublish    
	        ldconst      11 --> [Informacoes inseridas: ]
	        ldconst      5 --> [MeuContexto]
	        ldconst      6 --> [key 1]
	        ldconst      7 --> [key 2]
	        ldconst      10 --> [2]
	        cget        
	        ldconst      10 --> [2]
	        lcall        4 --> [io.writeln]
	        exit        
	.end
.end
