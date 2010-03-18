.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [antes da chamada a x]
	.const 3   int      [1]
	.const 4   string   [io.writeln]
	.const 5   string   [x]
	.const 6   string   [depois da chamada a x]
	.const 7   string   [no metodo x]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [antes da chamada a x]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldself      
	        mcall        5 --> [x]
	        ldconst      6 --> [depois da chamada a x]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        exit        
	.end
	.method x
	        ldconst      7 --> [no metodo x]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ret         
	.end
.end
