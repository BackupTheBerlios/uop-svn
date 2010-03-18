.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [x]
	.const 3   string   [util]
	.const 4   string   [aaa]
	.const 5   string   [metodo1]
	.const 6   string   [Depois de invocar metodo1]
	.const 7   int      [1]
	.const 8   string   [io.writeln]
	.const 9   int      [111]
	.const 10  string   [metodo2]
	.const 11  string   [Depois de invocar metodo2]
	.const 12  string   [param]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element x
	        newelem      3 --> [util]
	        stvar        0 --> [x]
	        ldconst      4 --> [aaa]
	        ldvar        0 --> [x]
	        mcall        5 --> [metodo1]
	        ldconst      6 --> [Depois de invocar metodo1]
	        ldconst      7 --> [1]
	        lcall        8 --> [io.writeln]
	        ldconst      9 --> [111]
	        ldvar        0 --> [x]
	        mcall        10 --> [metodo2]
	        ldconst      11 --> [Depois de invocar metodo2]
	        ldconst      7 --> [1]
	        lcall        8 --> [io.writeln]
	        exit        
	.end
.end
.entity util
	.valid_context_when (always)
	.method metodo1
		.param 0 string param
	        ldparam      0 --> [param]
	        ldconst      7 --> [1]
	        lcall        8 --> [io.writeln]
	        ret         
	.end
	.method metodo2
		.param 0 int param
	        ldparam      0 --> [param]
	        ldconst      7 --> [1]
	        lcall        8 --> [io.writeln]
	        ret         
	.end
.end
