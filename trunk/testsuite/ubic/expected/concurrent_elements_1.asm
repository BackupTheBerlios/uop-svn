.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [x]
	.const 3   string   [elemento1]
	.const 4   int      [1]
	.const 5   string   [concorrente]
	.const 6   string   [elemento2]
	.const 7   int      [2]
	.const 8   int      [5]
	.const 9   string   [Elemento start esta na iteracao ]
	.const 10  string   [io.writeln]
	.const 11  string   [datetime.sleep]
	.const 12  string   [wait]
	.const 13  string   [Elemento 1 terminou...]
	.const 14  string   [Elemento 2 terminou...]
	.const 15  string   [id]
	.const 16  string   [y]
	.const 17  int      [10]
	.const 18  string   [Elemento ]
	.const 19  string   [ esta na iteracao ]
	.const 20  int      [4]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int x
		.var 1 element elemento1
		.var 2 element elemento2
	        ldconst      4 --> [1]
	        newelem      5 --> [concorrente]
	        stvar        1 --> [elemento1]
	        ldconst      7 --> [2]
	        newelem      5 --> [concorrente]
	        stvar        2 --> [elemento2]
	        ldconst      4 --> [1]
	        stvar        0 --> [x]
	:8      ldvar        0 --> [x]
	        ldconst      8 --> [5]
	        le          
	        ifnot        25 --> [25]
	        jmp          18 --> [18]
	:13     ldvar        0 --> [x]
	        ldconst      4 --> [1]
	        add         
	        stvar        0 --> [x]
	        jmp          8 --> [8]
	:18     ldconst      9 --> [Elemento start esta na iteracao ]
	        ldvar        0 --> [x]
	        ldconst      7 --> [2]
	        lcall        10 --> [io.writeln]
	        ldconst      4 --> [1]
	        lcall        11 --> [datetime.sleep]
	        jmp          13 --> [13]
	:25     ldvar        1 --> [elemento1]
	        mcall        12 --> [wait]
	        ldconst      13 --> [Elemento 1 terminou...]
	        ldconst      4 --> [1]
	        lcall        10 --> [io.writeln]
	        ldvar        2 --> [elemento2]
	        mcall        12 --> [wait]
	        ldconst      14 --> [Elemento 2 terminou...]
	        ldconst      4 --> [1]
	        lcall        10 --> [io.writeln]
	        exit        
	.end
.end
.entity concorrente
	.option parallel
	.valid_context_when (always)
	.method constructor
		.param 0 int id
		.var 0 int y
	        ldconst      4 --> [1]
	        stvar        0 --> [y]
	:2      ldvar        0 --> [y]
	        ldconst      17 --> [10]
	        le          
	        ifnot        23 --> [23]
	        jmp          12 --> [12]
	:7      ldvar        0 --> [y]
	        ldconst      4 --> [1]
	        add         
	        stvar        0 --> [y]
	        jmp          2 --> [2]
	:12     ldconst      18 --> [Elemento ]
	        ldparam      0 --> [id]
	        ldconst      19 --> [ esta na iteracao ]
	        ldvar        0 --> [y]
	        ldconst      20 --> [4]
	        lcall        10 --> [io.writeln]
	        ldconst      4 --> [1]
	        ldparam      0 --> [id]
	        mul         
	        lcall        11 --> [datetime.sleep]
	        jmp          7 --> [7]
	:23     ret         
	.end
.end
