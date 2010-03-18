.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [(2 * (8 - 18 / 9 * (7 * 8 - 4 + 5 * 7) - 6) * (49 / 7 - 3))=]
	.const 3   int      [2]
	.const 4   int      [8]
	.const 5   int      [18]
	.const 6   int      [9]
	.const 7   int      [7]
	.const 8   int      [4]
	.const 9   int      [5]
	.const 10  int      [6]
	.const 11  int      [49]
	.const 12  int      [3]
	.const 13  string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [(2 * (8 - 18 / 9 * (7 * 8 - 4 + 5 * 7) - 6) * (49 / 7 - 3))=]
	        ldconst      3 --> [2]
	        ldconst      4 --> [8]
	        ldconst      5 --> [18]
	        ldconst      6 --> [9]
	        div         
	        ldconst      7 --> [7]
	        ldconst      4 --> [8]
	        mul         
	        ldconst      8 --> [4]
	        sub         
	        ldconst      9 --> [5]
	        ldconst      7 --> [7]
	        mul         
	        add         
	        mul         
	        sub         
	        ldconst      10 --> [6]
	        sub         
	        mul         
	        ldconst      11 --> [49]
	        ldconst      7 --> [7]
	        div         
	        ldconst      12 --> [3]
	        sub         
	        mul         
	        ldconst      3 --> [2]
	        lcall        13 --> [io.writeln]
	        exit        
	.end
.end
