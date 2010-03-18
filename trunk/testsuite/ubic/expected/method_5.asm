.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   int      [1]
	.const 3   string   [um]
	.const 4   int      [2]
	.const 5   string   [dois]
	.const 6   string   [x]
	.const 7   string   [number1]
	.const 8   string   [msg1]
	.const 9   string   [number2]
	.const 10  string   [msg2]
	.const 11  string   [number1=]
	.const 12  string   [ msg1=]
	.const 13  int      [4]
	.const 14  string   [io.writeln]
	.const 15  string   [number2=]
	.const 16  string   [ msg2=]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [1]
	        ldconst      3 --> [um]
	        ldconst      4 --> [2]
	        ldconst      5 --> [dois]
	        ldself      
	        mcall        6 --> [x]
	        exit        
	.end
	.method x
		.param 0 int number1
		.param 1 string msg1
		.param 2 int number2
		.param 3 string msg2
	        ldconst      11 --> [number1=]
	        ldparam      0 --> [number1]
	        ldconst      12 --> [ msg1=]
	        ldparam      1 --> [msg1]
	        ldconst      13 --> [4]
	        lcall        14 --> [io.writeln]
	        ldconst      15 --> [number2=]
	        ldparam      2 --> [number2]
	        ldconst      16 --> [ msg2=]
	        ldparam      3 --> [msg2]
	        ldconst      13 --> [4]
	        lcall        14 --> [io.writeln]
	        ret         
	.end
.end
