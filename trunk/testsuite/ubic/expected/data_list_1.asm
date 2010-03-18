.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [number_list]
	.const 3   string   [number]
	.const 4   string   [count]
	.const 5   string   [MeuContexto]
	.const 6   string   [Numero 1]
	.const 7   int      [100]
	.const 8   int      [1]
	.const 9   string   [Numero 2]
	.const 10  int      [200]
	.const 11  string   [Numero 3]
	.const 12  int      [300]
	.const 13  string   [Numero 4]
	.const 14  int      [400]
	.const 15  string   [key=]
	.const 16  string   [ value=]
	.const 17  int      [4]
	.const 18  string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 table number_list
		.var 1 tuple number
		.var 2 int count
	        ldconst      5 --> [MeuContexto]
	        ldconst      6 --> [Numero 1]
	        ldconst      7 --> [100]
	        ldconst      8 --> [1]
	        ldconst      8 --> [1]
	        cpublish    
	        ldconst      5 --> [MeuContexto]
	        ldconst      9 --> [Numero 2]
	        ldconst      10 --> [200]
	        ldconst      8 --> [1]
	        ldconst      8 --> [1]
	        cpublish    
	        ldconst      5 --> [MeuContexto]
	        ldconst      11 --> [Numero 3]
	        ldconst      12 --> [300]
	        ldconst      8 --> [1]
	        ldconst      8 --> [1]
	        cpublish    
	        ldconst      5 --> [MeuContexto]
	        ldconst      13 --> [Numero 4]
	        ldconst      14 --> [400]
	        ldconst      8 --> [1]
	        ldconst      8 --> [1]
	        cpublish    
	        ldconst      5 --> [MeuContexto]
	        clist       
	        stvar        0 --> [number_list]
	        ldconst      8 --> [1]
	        stvar        2 --> [count]
	:29     ldvar        2 --> [count]
	        ldvar        0 --> [number_list]
	        tabsize     
	        le          
	        ifnot        53 --> [53]
	        jmp          40 --> [40]
	:35     ldvar        2 --> [count]
	        ldconst      8 --> [1]
	        add         
	        stvar        2 --> [count]
	        jmp          29 --> [29]
	:40     ldvar        0 --> [number_list]
	        ldvar        2 --> [count]
	        ldtab       
	        stvar        1 --> [number]
	        ldconst      15 --> [key=]
	        ldconst      8 --> [1]
	        ldtuplek     1 --> [number]
	        ldconst      16 --> [ value=]
	        ldconst      8 --> [1]
	        ldtupler     1 --> [number]
	        ldconst      17 --> [4]
	        lcall        18 --> [io.writeln]
	        jmp          35 --> [35]
	:53     exit        
	.end
.end
