.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [(2.0 * (8.0 * 6.0) * (49.0 / 7.0 - 3.0))=]
	.const 3   real     [2.000000]
	.const 4   real     [8.000000]
	.const 5   real     [6.000000]
	.const 6   real     [49.000000]
	.const 7   real     [7.000000]
	.const 8   real     [3.000000]
	.const 9   int      [2]
	.const 10  string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [(2.0 * (8.0 * 6.0) * (49.0 / 7.0 - 3.0))=]
	        ldconst      3 --> [2.000000]
	        ldconst      4 --> [8.000000]
	        ldconst      5 --> [6.000000]
	        mul         
	        mul         
	        ldconst      6 --> [49.000000]
	        ldconst      7 --> [7.000000]
	        div         
	        ldconst      8 --> [3.000000]
	        sub         
	        mul         
	        ldconst      9 --> [2]
	        lcall        10 --> [io.writeln]
	        exit        
	.end
.end
