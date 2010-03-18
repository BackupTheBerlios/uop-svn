.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [data_list]
	.const 3   string   [datat]
	.const 4   string   [data_number]
	.const 5   string   [users]
	.const 6   int      [1]
	.const 7   string   [Nome : ]
	.const 8   int      [2]
	.const 9   string   [io.writeln]
	.const 10  string   [Valor: ]
	.const 11  string   [TTL  : ]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 table data_list
		.var 1 tuple datat
		.var 2 int data_number
	        ldconst      5 --> [users]
	        clist       
	        stvar        0 --> [data_list]
	        ldconst      6 --> [1]
	        stvar        2 --> [data_number]
	:5      ldvar        2 --> [data_number]
	        ldvar        0 --> [data_list]
	        tabsize     
	        le          
	        ifnot        36 --> [36]
	        jmp          16 --> [16]
	:11     ldvar        2 --> [data_number]
	        ldconst      6 --> [1]
	        add         
	        stvar        2 --> [data_number]
	        jmp          5 --> [5]
	:16     ldvar        0 --> [data_list]
	        ldvar        2 --> [data_number]
	        ldtab       
	        stvar        1 --> [datat]
	        ldconst      7 --> [Nome : ]
	        ldconst      6 --> [1]
	        ldtuplek     1 --> [datat]
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        ldconst      10 --> [Valor: ]
	        ldconst      6 --> [1]
	        ldtupler     1 --> [datat]
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        ldconst      11 --> [TTL  : ]
	        ldconst      8 --> [2]
	        ldtupler     1 --> [datat]
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        jmp          11 --> [11]
	:36     exit        
	.end
.end
