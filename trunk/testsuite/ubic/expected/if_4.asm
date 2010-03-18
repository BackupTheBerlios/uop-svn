.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [x]
	.const 3   int      [1]
	.const 4   int      [10]
	.const 5   int      [3]
	.const 6   int      [5]
	.const 7   int      [7]
	.const 8   int      [9]
	.const 9   string   [x=]
	.const 10  string   [ eh impar !!!]
	.const 11  string   [io.writeln]
	.const 12  int      [2]
	.const 13  int      [4]
	.const 14  int      [6]
	.const 15  int      [8]
	.const 16  string   [ eh par !!!]
	.const 17  string   [ ???]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int x
	        ldconst      3 --> [1]
	        stvar        0 --> [x]
	:2      ldvar        0 --> [x]
	        ldconst      4 --> [10]
	        le          
	        ifnot        70 --> [70]
	        jmp          12 --> [12]
	:7      ldvar        0 --> [x]
	        ldconst      3 --> [1]
	        add         
	        stvar        0 --> [x]
	        jmp          2 --> [2]
	:12     ldvar        0 --> [x]
	        ldconst      3 --> [1]
	        eq          
	        ldvar        0 --> [x]
	        ldconst      5 --> [3]
	        eq          
	        or          
	        ldvar        0 --> [x]
	        ldconst      6 --> [5]
	        eq          
	        or          
	        ldvar        0 --> [x]
	        ldconst      7 --> [7]
	        eq          
	        or          
	        ldvar        0 --> [x]
	        ldconst      8 --> [9]
	        eq          
	        or          
	        ifnot        38 --> [38]
	        ldconst      9 --> [x=]
	        ldvar        0 --> [x]
	        ldconst      10 --> [ eh impar !!!]
	        ldconst      5 --> [3]
	        lcall        11 --> [io.writeln]
	        jmp          69 --> [69]
	:38     ldvar        0 --> [x]
	        ldconst      12 --> [2]
	        eq          
	        ldvar        0 --> [x]
	        ldconst      13 --> [4]
	        eq          
	        or          
	        ldvar        0 --> [x]
	        ldconst      14 --> [6]
	        eq          
	        or          
	        ldvar        0 --> [x]
	        ldconst      15 --> [8]
	        eq          
	        or          
	        ldvar        0 --> [x]
	        ldconst      4 --> [10]
	        eq          
	        or          
	        ifnot        64 --> [64]
	        ldconst      9 --> [x=]
	        ldvar        0 --> [x]
	        ldconst      16 --> [ eh par !!!]
	        ldconst      5 --> [3]
	        lcall        11 --> [io.writeln]
	        jmp          69 --> [69]
	:64     ldconst      9 --> [x=]
	        ldvar        0 --> [x]
	        ldconst      17 --> [ ???]
	        ldconst      5 --> [3]
	        lcall        11 --> [io.writeln]
	:69     jmp          7 --> [7]
	:70     exit        
	.end
.end
