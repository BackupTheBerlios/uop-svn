.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [Programa 1 inserindo N1]
	.const 3   int      [1]
	.const 4   string   [io.writeln]
	.const 5   string   [MeuContexto]
	.const 6   string   [N1]
	.const 7   int      [100]
	.const 8   string   [Informacoes inseridas pelo programa 2: ]
	.const 9   string   [N2]
	.const 10  int      [2]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [Programa 1 inserindo N1]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldconst      5 --> [MeuContexto]
	        ldconst      6 --> [N1]
	        ldconst      7 --> [100]
	        ldconst      3 --> [1]
	        ldconst      3 --> [1]
	        cpublish    
	        ldconst      8 --> [Informacoes inseridas pelo programa 2: ]
	        ldconst      5 --> [MeuContexto]
	        ldconst      9 --> [N2]
	        ldconst      3 --> [1]
	        cfind       
	        ldconst      10 --> [2]
	        lcall        4 --> [io.writeln]
	        exit        
	.end
.end
