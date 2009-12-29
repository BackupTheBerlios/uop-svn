.constant_pool
	0   S start
	1   S constructor
	2   S service_list
	3   S servicet
	4   S service_number
	5   S users
	6   I 1
	7   S Nome:      
	8   I 2
	9   S io.writeln
	10  S Descricao: 
	11  S TBF:       
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 table service_list
		.var 1 tuple servicet
		.var 2 int service_number
		ldconst 5 --> [users]
		servicelist
		stvar 0 --> [service_list]
		ldconst 6 --> [1]
		stvar 2 --> [service_number]
	:5    	ldvar 2 --> [service_number]
		tabsize 0 --> [service_list]
		le
		ifnot 34 --> [34]
		jmp 15 --> [15]
	:10   	ldvar 2 --> [service_number]
		ldconst 6 --> [1]
		add
		stvar 2 --> [service_number]
		jmp 5 --> [5]
	:15   	ldvar 2 --> [service_number]
		ldtab 0 --> [service_list]
		stvar 1 --> [servicet]
		ldconst 7 --> [Nome:      ]
		ldconst 6 --> [1]
		ldtuplek 1 --> [servicet]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		ldconst 10 --> [Descricao: ]
		ldconst 6 --> [1]
		ldtuplev 1 --> [servicet]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		ldconst 11 --> [TBF:       ]
		ldconst 8 --> [2]
		ldtuplev 1 --> [servicet]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		jmp 10 --> [10]
	:34   	stop
	.end
.end
