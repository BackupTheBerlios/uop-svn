.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [e]
	.const 3   string   [elemento]
	.const 4   int      [1]
	.const 5   string   [um]
	.const 6   int      [2]
	.const 7   string   [dois]
	.const 8   string   [x]
	.const 9   string   [number1]
	.const 10  string   [msg1]
	.const 11  string   [number2]
	.const 12  string   [msg2]
	.const 13  string   [number1=]
	.const 14  string   [ msg1=]
	.const 15  int      [4]
	.const 16  string   [io.writeln]
	.const 17  string   [number2=]
	.const 18  string   [ msg2=]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element e
	        newelem      3 --> [elemento]
	        stvar        0 --> [e]
	        ldconst      4 --> [1]
	        ldconst      5 --> [um]
	        ldconst      6 --> [2]
	        ldconst      7 --> [dois]
	        ldvar        0 --> [e]
	        mcall        8 --> [x]
	        exit        
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method x
		.param 0 int number1
		.param 1 string msg1
		.param 2 int number2
		.param 3 string msg2
	        ldconst      13 --> [number1=]
	        ldparam      0 --> [number1]
	        ldconst      14 --> [ msg1=]
	        ldparam      1 --> [msg1]
	        ldconst      15 --> [4]
	        lcall        16 --> [io.writeln]
	        ldconst      17 --> [number2=]
	        ldparam      2 --> [number2]
	        ldconst      18 --> [ msg2=]
	        ldparam      3 --> [msg2]
	        ldconst      15 --> [4]
	        lcall        16 --> [io.writeln]
	        ret         
	.end
.end
