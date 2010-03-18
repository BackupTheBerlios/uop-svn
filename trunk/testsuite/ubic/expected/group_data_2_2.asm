.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [Informacoes inseridas pelo programa 1: ]
	.const 3   string   [MeuContexto]
	.const 4   string   [Numero 1]
	.const 5   int      [1]
	.const 6   int      [2]
	.const 7   string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [Informacoes inseridas pelo programa 1: ]
	        ldconst      3 --> [MeuContexto]
	        ldconst      4 --> [Numero 1]
	        ldconst      5 --> [1]
	        cfind       
	        ldconst      6 --> [2]
	        lcall        7 --> [io.writeln]
	        exit        
	.end
.end
