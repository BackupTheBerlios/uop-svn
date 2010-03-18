.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [number]
	.const 3   string   [MeuContexto]
	.const 4   string   [Numero 1]
	.const 5   int      [100]
	.const 6   int      [1]
	.const 7   string   [Informacoes inseridas: key=]
	.const 8   string   [ value=]
	.const 9   int      [4]
	.const 10  string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 tuple number
	        ldconst      3 --> [MeuContexto]
	        ldconst      4 --> [Numero 1]
	        ldconst      5 --> [100]
	        ldconst      6 --> [1]
	        ldconst      6 --> [1]
	        cpublish    
	        ldconst      3 --> [MeuContexto]
	        ldconst      4 --> [Numero 1]
	        ldconst      6 --> [1]
	        cfind       
	        stvar        0 --> [number]
	        ldconst      7 --> [Informacoes inseridas: key=]
	        ldconst      6 --> [1]
	        ldtuplek     0 --> [number]
	        ldconst      8 --> [ value=]
	        ldconst      6 --> [1]
	        ldtupler     0 --> [number]
	        ldconst      9 --> [4]
	        lcall        10 --> [io.writeln]
	        exit        
	.end
.end
