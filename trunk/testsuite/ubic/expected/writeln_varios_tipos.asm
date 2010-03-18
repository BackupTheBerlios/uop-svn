.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [ABCDEFGHIJKLMNOPQRSTUVWXYZ]
	.const 3   int      [1]
	.const 4   string   [io.writeln]
	.const 5   string   [12345 true false 10.0 20.9876]
	.const 6   int      [12345]
	.const 7   bool     [true]
	.const 8   bool     [false]
	.const 9   real     [10.000000]
	.const 10  real     [20.987600]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [ABCDEFGHIJKLMNOPQRSTUVWXYZ]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldconst      5 --> [12345 true false 10.0 20.9876]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldconst      6 --> [12345]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldconst      7 --> [true]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldconst      8 --> [false]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldconst      9 --> [10.000000]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldconst      10 --> [20.987600]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        exit        
	.end
.end
