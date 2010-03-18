.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [Inserindo informacoes]
	.const 3   int      [1]
	.const 4   string   [io.writeln]
	.const 5   string   [MeuContexto]
	.const 6   string   [key 1]
	.const 7   string   [key 2]
	.const 8   string   [key 3]
	.const 9   string   [key 4]
	.const 10  string   [res1]
	.const 11  string   [res2]
	.const 12  string   [res3]
	.const 13  string   [res4]
	.const 14  int      [4]
	.const 15  string   [Informacoes inseridas: ]
	.const 16  int      [2]
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
	        ldconst      8 --> [key 3]
	        ldconst      9 --> [key 4]
	        ldconst      10 --> [res1]
	        ldconst      11 --> [res2]
	        ldconst      12 --> [res3]
	        ldconst      13 --> [res4]
	        ldconst      14 --> [4]
	        ldconst      14 --> [4]
	        cpublish    
	        ldconst      15 --> [Informacoes inseridas: ]
	        ldconst      5 --> [MeuContexto]
	        ldconst      6 --> [key 1]
	        ldconst      7 --> [key 2]
	        ldconst      8 --> [key 3]
	        ldconst      9 --> [key 4]
	        ldconst      14 --> [4]
	        cget        
	        ldconst      16 --> [2]
	        lcall        4 --> [io.writeln]
	        exit        
	.end
.end
