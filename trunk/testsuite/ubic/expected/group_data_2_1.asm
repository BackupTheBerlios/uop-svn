.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [Programa 1 inserindo informacoes]
	.const 3   int      [1]
	.const 4   string   [io.writeln]
	.const 5   string   [MeuContexto]
	.const 6   string   [Numero 1]
	.const 7   int      [100]
	.const 8   bool     [true]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [Programa 1 inserindo informacoes]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldconst      5 --> [MeuContexto]
	        ldconst      6 --> [Numero 1]
	        ldconst      7 --> [100]
	        ldconst      3 --> [1]
	        ldconst      3 --> [1]
	        cpublish    
	:9      ldconst      8 --> [true]
	        ifnot        12 --> [12]
	        jmp          9 --> [9]
	:12     exit        
	.end
.end
