.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [(2 * (8 - 18 / 9 * 6) * (49 / 7 - 3))=]
	.const 3   int      [2]
	.const 4   int      [8]
	.const 5   int      [18]
	.const 6   int      [9]
	.const 7   int      [6]
	.const 8   int      [49]
	.const 9   int      [7]
	.const 10  int      [3]
	.const 11  string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [(2 * (8 - 18 / 9 * 6) * (49 / 7 - 3))=]
	        ldconst      3 --> [2]
	        ldconst      4 --> [8]
	        ldconst      5 --> [18]
	        ldconst      6 --> [9]
	        div         
	        ldconst      7 --> [6]
	        mul         
	        sub         
	        mul         
	        ldconst      8 --> [49]
	        ldconst      9 --> [7]
	        div         
	        ldconst      10 --> [3]
	        sub         
	        mul         
	        ldconst      3 --> [2]
	        lcall        11 --> [io.writeln]
	        exit        
	.end
.end
