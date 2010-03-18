.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [(2 * (8 * 6) * (49 / 7 - 3))=]
	.const 3   int      [2]
	.const 4   int      [8]
	.const 5   int      [6]
	.const 6   int      [49]
	.const 7   int      [7]
	.const 8   int      [3]
	.const 9   string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [(2 * (8 * 6) * (49 / 7 - 3))=]
	        ldconst      3 --> [2]
	        ldconst      4 --> [8]
	        ldconst      5 --> [6]
	        mul         
	        mul         
	        ldconst      6 --> [49]
	        ldconst      7 --> [7]
	        div         
	        ldconst      8 --> [3]
	        sub         
	        mul         
	        ldconst      3 --> [2]
	        lcall        9 --> [io.writeln]
	        exit        
	.end
.end
