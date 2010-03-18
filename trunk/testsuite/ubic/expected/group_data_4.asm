.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [insere]
	.const 3   string   [insert_data]
	.const 4   string   [Informacao inserida: ]
	.const 5   string   [MeuContexto]
	.const 6   string   [Numero 1]
	.const 7   int      [1]
	.const 8   int      [2]
	.const 9   string   [io.writeln]
	.const 10  int      [5]
	.const 11  string   [datetime.sleep]
	.const 12  string   [Inserindo informacao]
	.const 13  int      [100]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element insere
	        newelem      3 --> [insert_data]
	        stvar        0 --> [insere]
	        ldconst      4 --> [Informacao inserida: ]
	        ldconst      5 --> [MeuContexto]
	        ldconst      6 --> [Numero 1]
	        ldconst      7 --> [1]
	        cfind       
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        exit        
	.end
.end
.entity insert_data
	.option parallel
	.valid_context_when (always)
	.method constructor
	        ldconst      10 --> [5]
	        lcall        11 --> [datetime.sleep]
	        ldconst      12 --> [Inserindo informacao]
	        ldconst      7 --> [1]
	        lcall        9 --> [io.writeln]
	        ldconst      5 --> [MeuContexto]
	        ldconst      6 --> [Numero 1]
	        ldconst      13 --> [100]
	        ldconst      7 --> [1]
	        ldconst      7 --> [1]
	        cpublish    
	        ret         
	.end
.end
