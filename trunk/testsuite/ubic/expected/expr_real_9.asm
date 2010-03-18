.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [2.0 - 1.0=]
	.const 3   real     [2.000000]
	.const 4   real     [1.000000]
	.const 5   int      [2]
	.const 6   string   [io.writeln]
	.const 7   string   [2.0 * 7=]
	.const 8   int      [7]
	.const 9   string   [2.0 * 8.0 - 5.0=]
	.const 10  real     [8.000000]
	.const 11  real     [5.000000]
	.const 12  string   [2.0 - 8.0 * 5.0=]
	.const 13  string   [(2.0 - 8.0) * 5.0=]
	.const 14  string   [(2.0 * (8.0 - 18.0 / 9.0 * (7.0 * 8.0 - 4.0 + 5.0 * 7.0) - 6.0) * (49.0 / 7.0 - 3.0))=]
	.const 15  real     [18.000000]
	.const 16  real     [9.000000]
	.const 17  real     [7.000000]
	.const 18  real     [4.000000]
	.const 19  real     [6.000000]
	.const 20  real     [49.000000]
	.const 21  real     [3.000000]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [2.0 - 1.0=]
	        ldconst      3 --> [2.000000]
	        ldconst      4 --> [1.000000]
	        sub         
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        ldconst      7 --> [2.0 * 7=]
	        ldconst      5 --> [2]
	        ldconst      8 --> [7]
	        mul         
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        ldconst      9 --> [2.0 * 8.0 - 5.0=]
	        ldconst      3 --> [2.000000]
	        ldconst      10 --> [8.000000]
	        mul         
	        ldconst      11 --> [5.000000]
	        sub         
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        ldconst      12 --> [2.0 - 8.0 * 5.0=]
	        ldconst      3 --> [2.000000]
	        ldconst      10 --> [8.000000]
	        ldconst      11 --> [5.000000]
	        mul         
	        sub         
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        ldconst      13 --> [(2.0 - 8.0) * 5.0=]
	        ldconst      3 --> [2.000000]
	        ldconst      10 --> [8.000000]
	        sub         
	        ldconst      11 --> [5.000000]
	        mul         
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        ldconst      14 --> [(2.0 * (8.0 - 18.0 / 9.0 * (7.0 * 8.0 - 4.0 + 5.0 * 7.0) - 6.0) * (49.0 / 7.0 - 3.0))=]
	        ldconst      3 --> [2.000000]
	        ldconst      10 --> [8.000000]
	        ldconst      15 --> [18.000000]
	        ldconst      16 --> [9.000000]
	        div         
	        ldconst      17 --> [7.000000]
	        ldconst      10 --> [8.000000]
	        mul         
	        ldconst      18 --> [4.000000]
	        sub         
	        ldconst      11 --> [5.000000]
	        ldconst      17 --> [7.000000]
	        mul         
	        add         
	        mul         
	        sub         
	        ldconst      19 --> [6.000000]
	        sub         
	        mul         
	        ldconst      20 --> [49.000000]
	        ldconst      17 --> [7.000000]
	        div         
	        ldconst      21 --> [3.000000]
	        sub         
	        mul         
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        exit        
	.end
.end
