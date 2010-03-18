.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [2 * (49 / 7 - 3)=]
	.const 3   int      [2]
	.const 4   int      [49]
	.const 5   int      [7]
	.const 6   int      [3]
	.const 7   string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [2 * (49 / 7 - 3)=]
	        ldconst      3 --> [2]
	        ldconst      4 --> [49]
	        ldconst      5 --> [7]
	        div         
	        ldconst      6 --> [3]
	        sub         
	        mul         
	        ldconst      3 --> [2]
	        lcall        7 --> [io.writeln]
	        exit        
	.end
.end
