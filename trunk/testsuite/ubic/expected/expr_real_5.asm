.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [(2.0 * (49.0 / 7.0 - 3.0))=]
	.const 3   real     [2.000000]
	.const 4   real     [49.000000]
	.const 5   real     [7.000000]
	.const 6   real     [3.000000]
	.const 7   int      [2]
	.const 8   string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [(2.0 * (49.0 / 7.0 - 3.0))=]
	        ldconst      3 --> [2.000000]
	        ldconst      4 --> [49.000000]
	        ldconst      5 --> [7.000000]
	        div         
	        ldconst      6 --> [3.000000]
	        sub         
	        mul         
	        ldconst      7 --> [2]
	        lcall        8 --> [io.writeln]
	        exit        
	.end
.end
