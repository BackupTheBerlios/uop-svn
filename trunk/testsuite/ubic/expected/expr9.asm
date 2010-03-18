.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [2 - 1=]
	.const 3   int      [2]
	.const 4   int      [1]
	.const 5   string   [io.writeln]
	.const 6   string   [2 * 7=]
	.const 7   int      [7]
	.const 8   string   [2 * 8 - 5=]
	.const 9   int      [8]
	.const 10  int      [5]
	.const 11  string   [2 - 8 * 5=]
	.const 12  string   [(2 - 8) * 5=]
	.const 13  string   [(2 * (8 - 18 / 9 * (7 * 8 - 4 + 5 * 7) - 6) * (49 / 7 - 3))=]
	.const 14  int      [18]
	.const 15  int      [9]
	.const 16  int      [4]
	.const 17  int      [6]
	.const 18  int      [49]
	.const 19  int      [3]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [2 - 1=]
	        ldconst      3 --> [2]
	        ldconst      4 --> [1]
	        sub         
	        ldconst      3 --> [2]
	        lcall        5 --> [io.writeln]
	        ldconst      6 --> [2 * 7=]
	        ldconst      3 --> [2]
	        ldconst      7 --> [7]
	        mul         
	        ldconst      3 --> [2]
	        lcall        5 --> [io.writeln]
	        ldconst      8 --> [2 * 8 - 5=]
	        ldconst      3 --> [2]
	        ldconst      9 --> [8]
	        mul         
	        ldconst      10 --> [5]
	        sub         
	        ldconst      3 --> [2]
	        lcall        5 --> [io.writeln]
	        ldconst      11 --> [2 - 8 * 5=]
	        ldconst      3 --> [2]
	        ldconst      9 --> [8]
	        ldconst      10 --> [5]
	        mul         
	        sub         
	        ldconst      3 --> [2]
	        lcall        5 --> [io.writeln]
	        ldconst      12 --> [(2 - 8) * 5=]
	        ldconst      3 --> [2]
	        ldconst      9 --> [8]
	        sub         
	        ldconst      10 --> [5]
	        mul         
	        ldconst      3 --> [2]
	        lcall        5 --> [io.writeln]
	        ldconst      13 --> [(2 * (8 - 18 / 9 * (7 * 8 - 4 + 5 * 7) - 6) * (49 / 7 - 3))=]
	        ldconst      3 --> [2]
	        ldconst      9 --> [8]
	        ldconst      14 --> [18]
	        ldconst      15 --> [9]
	        div         
	        ldconst      7 --> [7]
	        ldconst      9 --> [8]
	        mul         
	        ldconst      16 --> [4]
	        sub         
	        ldconst      10 --> [5]
	        ldconst      7 --> [7]
	        mul         
	        add         
	        mul         
	        sub         
	        ldconst      17 --> [6]
	        sub         
	        mul         
	        ldconst      18 --> [49]
	        ldconst      7 --> [7]
	        div         
	        ldconst      19 --> [3]
	        sub         
	        mul         
	        ldconst      3 --> [2]
	        lcall        5 --> [io.writeln]
	        exit        
	.end
.end
