.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [element_list]
	.const 3   string   [elementt]
	.const 4   string   [element_number]
	.const 5   string   [users]
	.const 6   int      [1]
	.const 7   string   [Nome:      ]
	.const 8   int      [2]
	.const 9   string   [io.writeln]
	.const 10  string   [Descricao: ]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 table element_list
		.var 1 tuple elementt
		.var 2 int element_number
	        ldconst      5 --> [users]
	        mlist       
	        stvar        0 --> [element_list]
	        ldconst      6 --> [1]
	        stvar        2 --> [element_number]
	:5      ldvar        2 --> [element_number]
	        ldvar        0 --> [element_list]
	        tabsize     
	        le          
	        ifnot        31 --> [31]
	        jmp          16 --> [16]
	:11     ldvar        2 --> [element_number]
	        ldconst      6 --> [1]
	        add         
	        stvar        2 --> [element_number]
	        jmp          5 --> [5]
	:16     ldvar        0 --> [element_list]
	        ldvar        2 --> [element_number]
	        ldtab       
	        stvar        1 --> [elementt]
	        ldconst      7 --> [Nome:      ]
	        ldconst      6 --> [1]
	        ldtuplek     1 --> [elementt]
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        ldconst      10 --> [Descricao: ]
	        ldconst      6 --> [1]
	        ldtupler     1 --> [elementt]
	        ldconst      8 --> [2]
	        lcall        9 --> [io.writeln]
	        jmp          11 --> [11]
	:31     exit        
	.end
.end
