.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   real     [10.000000]
	.const 3   real     [20.000000]
	.const 4   int      [1]
	.const 5   string   [io.writeln]
	.const 6   real     [30.000000]
	.const 7   real     [5.000000]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [10.000000]
	        ldconst      3 --> [20.000000]
	        add         
	        ldconst      4 --> [1]
	        lcall        5 --> [io.writeln]
	        ldconst      2 --> [10.000000]
	        ldconst      3 --> [20.000000]
	        add         
	        ldconst      6 --> [30.000000]
	        add         
	        ldconst      4 --> [1]
	        lcall        5 --> [io.writeln]
	        ldconst      2 --> [10.000000]
	        ldconst      3 --> [20.000000]
	        add         
	        ldconst      7 --> [5.000000]
	        sub         
	        ldconst      4 --> [1]
	        lcall        5 --> [io.writeln]
	        exit        
	.end
.end
