.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [antes da chamada a x]
	.const 3   int      [1]
	.const 4   string   [io.writeln]
	.const 5   string   [x]
	.const 6   string   [depois da chamada a x]
	.const 7   string   [antes da chamada a y]
	.const 8   string   [y]
	.const 9   string   [depois da chamada a y]
	.const 10  string   [no metodo y]
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
	        ldconst      7 --> [antes da chamada a y]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldself      
	        mcall        8 --> [y]
	        ldconst      9 --> [depois da chamada a y]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ret         
	.end
	.method y
	        ldconst      10 --> [no metodo y]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ret         
	.end
.end
