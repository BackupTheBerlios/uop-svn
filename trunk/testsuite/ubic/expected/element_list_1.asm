.constant_pool
	0   S start
	1   S constructor
	2   S element_list
	3   S elementt
	4   S element_number
	5   S users
	6   I 1
	7   S Nome:      
	8   I 2
	9   S io.writeln
	10  S Descricao: 
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 table element_list
		.var 1 tuple elementt
		.var 2 int element_number
		ldconst 5 --> [users]
		elementlist
		stvar 0 --> [element_list]
		ldconst 6 --> [1]
		stvar 2 --> [element_number]
	:5    	ldvar 2 --> [element_number]
		tabsize 0 --> [element_list]
		le
		ifnot 29 --> [29]
		jmp 15 --> [15]
	:10   	ldvar 2 --> [element_number]
		ldconst 6 --> [1]
		add
		stvar 2 --> [element_number]
		jmp 5 --> [5]
	:15   	ldvar 2 --> [element_number]
		ldtab 0 --> [element_list]
		stvar 1 --> [elementt]
		ldconst 7 --> [Nome:      ]
		ldconst 6 --> [1]
		ldtuplek 1 --> [elementt]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		ldconst 10 --> [Descricao: ]
		ldconst 6 --> [1]
		ldtuplev 1 --> [elementt]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		jmp 10 --> [10]
	:29   	stop
	.end
.end
