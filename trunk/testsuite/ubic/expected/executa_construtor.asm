.constant_pool
	.const 0   string   [minha_entidade]
	.const 1   string   [constructor]
	.const 2   string   [Executando o construtor...]
	.const 3   int      [1]
	.const 4   string   [io.writeln]
	.const 5   string   [start]
	.const 6   string   [e]
.end
.entity minha_entidade
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [Executando o construtor...]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ret         
	.end
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element e
	        newelem      0 --> [minha_entidade]
	        stvar        0 --> [e]
	        exit        
	.end
.end
