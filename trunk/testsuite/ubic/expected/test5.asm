.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [Hello world !!!]
	.const 3   int      [1]
	.const 4   string   [io.writeln]
	.const 5   string   [metodo1]
	.const 6   string   [Depois de metodo1/0]
	.const 7   string   [metodo2]
	.const 8   string   [Depois de metodo2/0]
	.const 9   string   [metodo3]
	.const 10  string   [Depois de metodo3/0]
	.const 11  string   [Hello world in action1/0 !!!]
	.const 12  string   [Hello world in action2/0 !!!]
	.const 13  string   [Hello world in action3/0 !!!]
	.const 14  string   [Depois da acao2/0 na acao 3]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [Hello world !!!]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldself      
	        mcall        5 --> [metodo1]
	        ldconst      6 --> [Depois de metodo1/0]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldself      
	        mcall        7 --> [metodo2]
	        ldconst      8 --> [Depois de metodo2/0]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldself      
	        mcall        9 --> [metodo3]
	        ldconst      10 --> [Depois de metodo3/0]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        exit        
	.end
	.method metodo1
	        ldconst      11 --> [Hello world in action1/0 !!!]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ret         
	.end
	.method metodo2
	        ldconst      12 --> [Hello world in action2/0 !!!]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ret         
	.end
	.method metodo3
	        ldconst      13 --> [Hello world in action3/0 !!!]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldself      
	        mcall        7 --> [metodo2]
	        ldconst      14 --> [Depois da acao2/0 na acao 3]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ret         
	.end
.end
