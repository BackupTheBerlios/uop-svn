.constant_pool
	0   S start
	1   S constructor
	2   S x
	3   S elemento1
	4   I 1
	5   S concorrente
	6   I 5
	7   S Elemento start esta na iteracao 
	8   I 2
	9   S io.writeln
	10  S datetime.sleep
	11  S wait
	12  S Elemento 1 terminou...
	13  S id
	14  S y
	15  I 10
	16  S Elemento 
	17  S  esta na iteracao 
	18  I 4
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int x
		.var 1 element elemento1
		ldconst 4 --> [1]
		newelem 5 --> [concorrente]
		stvar 1 --> [elemento1]
		ldconst 4 --> [1]
		stvar 0 --> [x]
	:5    	ldvar 0 --> [x]
		ldconst 6 --> [5]
		le
		ifnot 22 --> [22]
		jmp 15 --> [15]
	:10   	ldvar 0 --> [x]
		ldconst 4 --> [1]
		add
		stvar 0 --> [x]
		jmp 5 --> [5]
	:15   	ldconst 7 --> [Elemento start esta na iteracao ]
		ldvar 0 --> [x]
		ldconst 8 --> [2]
		lcall 9 --> [io.writeln]
		ldconst 4 --> [1]
		lcall 10 --> [datetime.sleep]
		jmp 10 --> [10]
	:22   	ldvar 1 --> [elemento1]
		mcall 11 --> [wait]
		ldconst 12 --> [Elemento 1 terminou...]
		ldconst 4 --> [1]
		lcall 9 --> [io.writeln]
		stop
	.end
.end
.entity concorrente
	.option parallel
	.valid_context_when (always)
	.method constructor
		.param 0 int id
		.var 0 int y
		ldconst 4 --> [1]
		stvar 0 --> [y]
	:2    	ldvar 0 --> [y]
		ldconst 15 --> [10]
		le
		ifnot 23 --> [23]
		jmp 12 --> [12]
	:7    	ldvar 0 --> [y]
		ldconst 4 --> [1]
		add
		stvar 0 --> [y]
		jmp 2 --> [2]
	:12   	ldconst 16 --> [Elemento ]
		ldpar 0 --> [id]
		ldconst 17 --> [ esta na iteracao ]
		ldvar 0 --> [y]
		ldconst 18 --> [4]
		lcall 9 --> [io.writeln]
		ldconst 4 --> [1]
		ldpar 0 --> [id]
		mul
		lcall 10 --> [datetime.sleep]
		jmp 7 --> [7]
	:23   	ret
	.end
.end
