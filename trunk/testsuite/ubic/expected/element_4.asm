.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [antes da chamada a start::x]
	.const 3   int      [1]
	.const 4   string   [io.writeln]
	.const 5   string   [x]
	.const 6   string   [depois da chamada a start::x]
	.const 7   string   [antes da chamada a start::y]
	.const 8   string   [y]
	.const 9   string   [depois da chamada a start::y]
	.const 10  string   [e]
	.const 11  string   [antes da chamada a elemento::x]
	.const 12  string   [elemento]
	.const 13  string   [depois da chamada a elemento::x]
	.const 14  string   [antes da chamada a elemento::y]
	.const 15  string   [depois da chamada a elemento::y]
	.const 16  string   [no metodo elemento::y]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [antes da chamada a start::x]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldself      
	        mcall        5 --> [x]
	        ldconst      6 --> [depois da chamada a start::x]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        exit        
	.end
	.method x
	        ldconst      7 --> [antes da chamada a start::y]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldself      
	        mcall        8 --> [y]
	        ldconst      9 --> [depois da chamada a start::y]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ret         
	.end
	.method y
		.var 0 element e
	        ldconst      11 --> [antes da chamada a elemento::x]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        newelem      12 --> [elemento]
	        stvar        0 --> [e]
	        ldvar        0 --> [e]
	        mcall        5 --> [x]
	        ldconst      13 --> [depois da chamada a elemento::x]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ret         
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method x
	        ldconst      14 --> [antes da chamada a elemento::y]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldself      
	        mcall        8 --> [y]
	        ldconst      15 --> [depois da chamada a elemento::y]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ret         
	.end
	.method y
	        ldconst      16 --> [no metodo elemento::y]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ret         
	.end
.end
