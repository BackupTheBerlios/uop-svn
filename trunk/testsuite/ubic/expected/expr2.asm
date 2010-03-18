.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   int      [10]
	.const 3   int      [20]
	.const 4   int      [1]
	.const 5   string   [io.writeln]
	.const 6   int      [30]
	.const 7   int      [5]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [10]
	        ldconst      3 --> [20]
	        add         
	        ldconst      4 --> [1]
	        lcall        5 --> [io.writeln]
	        ldconst      2 --> [10]
	        ldconst      3 --> [20]
	        add         
	        ldconst      6 --> [30]
	        add         
	        ldconst      4 --> [1]
	        lcall        5 --> [io.writeln]
	        ldconst      2 --> [10]
	        ldconst      3 --> [20]
	        add         
	        ldconst      7 --> [5]
	        sub         
	        ldconst      4 --> [1]
	        lcall        5 --> [io.writeln]
	        exit        
	.end
.end
