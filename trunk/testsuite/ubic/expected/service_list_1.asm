.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [service_list]
	.const 3   string   [servicet]
	.const 4   string   [service_number]
	.const 5   string   [users]
	.const 6   int      [1]
	.const 7   string   [Nome:      ]
	.const 8   int      [2]
	.const 9   string   [io.writeln]
	.const 10  string   [Descricao: ]
	.const 11  string   [TBF:       ]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 table service_list
		.var 1 tuple servicet
		.var 2 int service_number
	        ldconst      5 --> [users]
	        slist       
	        stvar        0 --> [service_list]
	        ldconst      6 --> [1]
	        stvar        2 --> [service_number]
	:5      ldvar        2 --> [service_number]
	        ldvar        0 --> [service_list]
	        tabsize     
	        le          
	        ifnot        36 --> [36]
	        jmp          16 --> [16]
	:11     ldvar        2 --> [service_number]
	        ldconst      6 --> [1]
	        add         
	        stvar        2 --> [service_number]
	        jmp          5 --> [5]
	:16     ldvar        0 --> [service_list]
	        ldvar        2 --> [service_number]
	        ldtab       
	        stvar        1 --> [servicet]
	        ldconst      7 --> [Nome:      ]
	        ldconst      6 --> [1]
	        ldtuplek     1 --> [servicet]
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        ldconst      10 --> [Descricao: ]
	        ldconst      6 --> [1]
	        ldtupler     1 --> [servicet]
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        ldconst      11 --> [TBF:       ]
	        ldconst      8 --> [2]
	        ldtupler     1 --> [servicet]
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        jmp          11 --> [11]
	:36     exit        
	.end
.end
