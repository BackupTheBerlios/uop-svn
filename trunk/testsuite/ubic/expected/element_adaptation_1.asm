.constant_pool
	.const 0   string   [test]
	.const 1   string   [__when]
	.const 2   string   [identity.name]
	.const 3   string   [alex]
	.const 4   string   [run]
	.const 5   string   [Eu sou o Alex !!!]
	.const 6   int      [1]
	.const 7   string   [io.writeln]
	.const 8   string   [Ops, nao sou o Alex :-/]
	.const 9   string   [start]
	.const 10  string   [constructor]
	.const 11  string   [t1]
	.const 12  string   [t2]
	.const 13  string   [gracy]
.end
.entity test
	.valid_context_when 	        ldcontexti   2 --> [identity.name]
	        ldconst      3 --> [alex]
	        eq          
	        ret         
	.method run
	        ldconst      5 --> [Eu sou o Alex !!!]
	        ldconst      6 --> [1]
	        lcall        7 --> [io.writeln]
	        ret         
	.end
.end
.entity test
	.valid_context_when 	        ldcontexti   2 --> [identity.name]
	        ldconst      3 --> [alex]
	        ne          
	        ret         
	.method run
	        ldconst      8 --> [Ops, nao sou o Alex :-/]
	        ldconst      6 --> [1]
	        lcall        7 --> [io.writeln]
	        ret         
	.end
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element t1
		.var 1 element t2
	        ldconst      3 --> [alex]
	        stcontexti   2 --> [identity.name]
	        newelem      0 --> [test]
	        stvar        0 --> [t1]
	        ldvar        0 --> [t1]
	        mcall        4 --> [run]
	        ldconst      13 --> [gracy]
	        stcontexti   2 --> [identity.name]
	        newelem      0 --> [test]
	        stvar        1 --> [t2]
	        ldvar        1 --> [t2]
	        mcall        4 --> [run]
	        exit        
	.end
.end
