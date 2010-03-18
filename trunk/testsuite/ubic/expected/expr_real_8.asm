.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [(2.0 * (8.0 - 18.0 / 9.0 * (7.0 * 8.0 - 4.0 + 5.0 * 7.0) - 6.0) * (49.0 / 7.0 - 3.0))=]
	.const 3   real     [2.000000]
	.const 4   real     [8.000000]
	.const 5   real     [18.000000]
	.const 6   real     [9.000000]
	.const 7   real     [7.000000]
	.const 8   real     [4.000000]
	.const 9   real     [5.000000]
	.const 10  real     [6.000000]
	.const 11  real     [49.000000]
	.const 12  real     [3.000000]
	.const 13  int      [2]
	.const 14  string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [(2.0 * (8.0 - 18.0 / 9.0 * (7.0 * 8.0 - 4.0 + 5.0 * 7.0) - 6.0) * (49.0 / 7.0 - 3.0))=]
	        ldconst      3 --> [2.000000]
	        ldconst      4 --> [8.000000]
	        ldconst      5 --> [18.000000]
	        ldconst      6 --> [9.000000]
	        div         
	        ldconst      7 --> [7.000000]
	        ldconst      4 --> [8.000000]
	        mul         
	        ldconst      8 --> [4.000000]
	        sub         
	        ldconst      9 --> [5.000000]
	        ldconst      7 --> [7.000000]
	        mul         
	        add         
	        mul         
	        sub         
	        ldconst      10 --> [6.000000]
	        sub         
	        mul         
	        ldconst      11 --> [49.000000]
	        ldconst      7 --> [7.000000]
	        div         
	        ldconst      12 --> [3.000000]
	        sub         
	        mul         
	        ldconst      13 --> [2]
	        lcall        14 --> [io.writeln]
	        exit        
	.end
.end
