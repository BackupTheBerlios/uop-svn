.constant_pool
	0   S start
	1   S constructor
	2   S data_list
	3   S datat
	4   S data_number
	5   S users
	6   I 1
	7   S Nome : 
	8   I 2
	9   S io.writeln
	10  S Valor: 
	11  S TTL  : 
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 table data_list
		.var 1 tuple datat
		.var 2 int data_number
		ldconst 5 --> [users]
		listd
		stvar 0 --> [data_list]
		ldconst 6 --> [1]
		stvar 2 --> [data_number]
	:5    	ldvar 2 --> [data_number]
		tabsize 0 --> [data_list]
		le
		ifnot 34 --> [34]
		jmp 15 --> [15]
	:10   	ldvar 2 --> [data_number]
		ldconst 6 --> [1]
		add
		stvar 2 --> [data_number]
		jmp 5 --> [5]
	:15   	ldvar 2 --> [data_number]
		ldtab 0 --> [data_list]
		stvar 1 --> [datat]
		ldconst 7 --> [Nome : ]
		ldconst 6 --> [1]
		ldtuplek 1 --> [datat]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		ldconst 10 --> [Valor: ]
		ldconst 6 --> [1]
		ldtuplev 1 --> [datat]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		ldconst 11 --> [TTL  : ]
		ldconst 8 --> [2]
		ldtuplev 1 --> [datat]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		jmp 10 --> [10]
	:34   	stop
	.end
.end
