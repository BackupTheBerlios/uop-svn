.constant_pool
	.const 0   string   [start]
	.const 1   string   [proptab]
	.const 2   string   [constructor]
	.const 3   string   [vartab]
	.const 4   string   [index]
	.const 5   int      [1]
	.const 6   int      [10]
	.const 7   string   [vartab[]
	.const 8   string   []=]
	.const 9   int      [4]
	.const 10  string   [io.writeln]
	.const 11  int      [100]
	.const 12  string   [proptab[]
	.const 13  string   [paramtab baseado em vartab]
	.const 14  string   [imptab]
	.const 15  string   [paramtab baseado em proptab]
	.const 16  string   [paramtab]
	.const 17  string   [paramtab[]
.end
.entity start
	.valid_context_when (always)
	.prop 0 public table proptab
	.method constructor
		.var 0 table vartab
		.var 1 int index
	        ldconst      5 --> [1]
	        stvar        1 --> [index]
	:2      ldvar        1 --> [index]
	        ldconst      6 --> [10]
	        le          
	        ifnot        19 --> [19]
	        jmp          12 --> [12]
	:7      ldvar        1 --> [index]
	        ldconst      5 --> [1]
	        add         
	        stvar        1 --> [index]
	        jmp          2 --> [2]
	:12     ldvar        0 --> [vartab]
	        ldvar        1 --> [index]
	        ldvar        1 --> [index]
	        ldconst      6 --> [10]
	        mul         
	        sttab       
	        jmp          7 --> [7]
	:19     ldconst      5 --> [1]
	        stvar        1 --> [index]
	:21     ldvar        1 --> [index]
	        ldvar        0 --> [vartab]
	        tabsize     
	        le          
	        ifnot        41 --> [41]
	        jmp          32 --> [32]
	:27     ldvar        1 --> [index]
	        ldconst      5 --> [1]
	        add         
	        stvar        1 --> [index]
	        jmp          21 --> [21]
	:32     ldconst      7 --> [vartab[]
	        ldvar        1 --> [index]
	        ldconst      8 --> []=]
	        ldvar        0 --> [vartab]
	        ldvar        1 --> [index]
	        ldtab       
	        ldconst      9 --> [4]
	        lcall        10 --> [io.writeln]
	        jmp          27 --> [27]
	:41     ldconst      5 --> [1]
	        stvar        1 --> [index]
	:43     ldvar        1 --> [index]
	        ldconst      6 --> [10]
	        le          
	        ifnot        62 --> [62]
	        jmp          53 --> [53]
	:48     ldvar        1 --> [index]
	        ldconst      5 --> [1]
	        add         
	        stvar        1 --> [index]
	        jmp          43 --> [43]
	:53     ldprop       0 --> [proptab]
	        ldvar        1 --> [index]
	        ldconst      11 --> [100]
	        ldvar        1 --> [index]
	        ldconst      6 --> [10]
	        mul         
	        add         
	        sttab       
	        jmp          48 --> [48]
	:62     ldconst      5 --> [1]
	        stvar        1 --> [index]
	:64     ldvar        1 --> [index]
	        ldprop       0 --> [proptab]
	        tabsize     
	        le          
	        ifnot        84 --> [84]
	        jmp          75 --> [75]
	:70     ldvar        1 --> [index]
	        ldconst      5 --> [1]
	        add         
	        stvar        1 --> [index]
	        jmp          64 --> [64]
	:75     ldconst      12 --> [proptab[]
	        ldvar        1 --> [index]
	        ldconst      8 --> []=]
	        ldprop       0 --> [proptab]
	        ldvar        1 --> [index]
	        ldtab       
	        ldconst      9 --> [4]
	        lcall        10 --> [io.writeln]
	        jmp          70 --> [70]
	:84     ldconst      13 --> [paramtab baseado em vartab]
	        ldconst      5 --> [1]
	        lcall        10 --> [io.writeln]
	        ldvar        0 --> [vartab]
	        ldself      
	        mcall        14 --> [imptab]
	        ldconst      15 --> [paramtab baseado em proptab]
	        ldconst      5 --> [1]
	        lcall        10 --> [io.writeln]
	        ldprop       0 --> [proptab]
	        ldself      
	        mcall        14 --> [imptab]
	        exit        
	.end
	.method imptab
		.param 0 table paramtab
		.var 0 int index
	        ldconst      5 --> [1]
	        stvar        0 --> [index]
	:2      ldvar        0 --> [index]
	        ldparam      0 --> [paramtab]
	        tabsize     
	        le          
	        ifnot        22 --> [22]
	        jmp          13 --> [13]
	:8      ldvar        0 --> [index]
	        ldconst      5 --> [1]
	        add         
	        stvar        0 --> [index]
	        jmp          2 --> [2]
	:13     ldconst      17 --> [paramtab[]
	        ldvar        0 --> [index]
	        ldconst      8 --> []=]
	        ldparam      0 --> [paramtab]
	        ldvar        0 --> [index]
	        ldtab       
	        ldconst      9 --> [4]
	        lcall        10 --> [io.writeln]
	        jmp          8 --> [8]
	:22     ret         
	.end
.end
