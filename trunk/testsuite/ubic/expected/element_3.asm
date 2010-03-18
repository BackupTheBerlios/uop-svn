.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [e]
	.const 3   string   [antes da chamada a elemento::x]
	.const 4   int      [1]
	.const 5   string   [io.writeln]
	.const 6   string   [elemento]
	.const 7   string   [x]
	.const 8   string   [depois da chamada a elemento::x]
	.const 9   string   [antes da chamada a elemento::y]
	.const 10  string   [y]
	.const 11  string   [depois da chamada a elemento::y]
	.const 12  string   [no metodo elemento::y]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element e
	        ldconst      3 --> [antes da chamada a elemento::x]
	        ldconst      4 --> [1]
	        lcall        5 --> [io.writeln]
	        newelem      6 --> [elemento]
	        stvar        0 --> [e]
	        ldvar        0 --> [e]
	        mcall        7 --> [x]
	        ldconst      8 --> [depois da chamada a elemento::x]
	        ldconst      4 --> [1]
	        lcall        5 --> [io.writeln]
	        exit        
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method x
	        ldconst      9 --> [antes da chamada a elemento::y]
	        ldconst      4 --> [1]
	        lcall        5 --> [io.writeln]
	        ldself      
	        mcall        10 --> [y]
	        ldconst      11 --> [depois da chamada a elemento::y]
	        ldconst      4 --> [1]
	        lcall        5 --> [io.writeln]
	        ret         
	.end
	.method y
	        ldconst      12 --> [no metodo elemento::y]
	        ldconst      4 --> [1]
	        lcall        5 --> [io.writeln]
	        ret         
	.end
.end
