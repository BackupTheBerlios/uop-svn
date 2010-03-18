.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [x]
	.const 3   string   [elemento1]
	.const 4   int      [1]
	.const 5   string   [concorrente]
	.const 6   int      [5]
	.const 7   string   [Elemento start esta na iteracao ]
	.const 8   int      [2]
	.const 9   string   [io.writeln]
	.const 10  string   [datetime.sleep]
	.const 11  string   [wait]
	.const 12  string   [Elemento 1 terminou...]
	.const 13  string   [id]
	.const 14  string   [y]
	.const 15  int      [10]
	.const 16  string   [Elemento ]
	.const 17  string   [ esta na iteracao ]
	.const 18  int      [4]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int x
		.var 1 element elemento1
	        ldconst      4 --> [1]
	        newelem      5 --> [concorrente]
	        stvar        1 --> [elemento1]
	        ldconst      4 --> [1]
	        stvar        0 --> [x]
	:5      ldvar        0 --> [x]
	        ldconst      6 --> [5]
	        le          
	        ifnot        22 --> [22]
	        jmp          15 --> [15]
	:10     ldvar        0 --> [x]
	        ldconst      4 --> [1]
	        add         
	        stvar        0 --> [x]
	        jmp          5 --> [5]
	:15     ldconst      7 --> [Elemento start esta na iteracao ]
	        ldvar        0 --> [x]
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        ldconst      4 --> [1]
	        lcall        10 --> [datetime.sleep]
	        jmp          10 --> [10]
	:22     ldvar        1 --> [elemento1]
	        mcall        11 --> [wait]
	        ldconst      12 --> [Elemento 1 terminou...]
	        ldconst      4 --> [1]
	        lcall        9 --> [io.writeln]
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
	        ldconst      15 --> [10]
	        le          
	        ifnot        23 --> [23]
	        jmp          12 --> [12]
	:7      ldvar        0 --> [y]
	        ldconst      4 --> [1]
	        add         
	        stvar        0 --> [y]
	        jmp          2 --> [2]
	:12     ldconst      16 --> [Elemento ]
	        ldparam      0 --> [id]
	        ldconst      17 --> [ esta na iteracao ]
	        ldvar        0 --> [y]
	        ldconst      18 --> [4]
	        lcall        9 --> [io.writeln]
	        ldconst      4 --> [1]
	        ldparam      0 --> [id]
	        mul         
	        lcall        10 --> [datetime.sleep]
	        jmp          7 --> [7]
	:23     ret         
	.end
.end
