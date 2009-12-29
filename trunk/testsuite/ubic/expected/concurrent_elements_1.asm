.constant_pool
	0   S start
	1   S constructor
	2   S x
	3   S elemento1
	4   I 1
	5   S concorrente
	6   S elemento2
	7   I 2
	8   I 5
	9   S Elemento start esta na iteracao 
	10  S io.writeln
	11  S datetime.sleep
	12  S wait
	13  S Elemento 1 terminou...
	14  S Elemento 2 terminou...
	15  S id
	16  S y
	17  I 10
	18  S Elemento 
	19  S  esta na iteracao 
	20  I 4
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int x
		.var 1 element elemento1
		.var 2 element elemento2
		ldconst 4 --> [1]
		newelem 5 --> [concorrente]
		stvar 1 --> [elemento1]
		ldconst 7 --> [2]
		newelem 5 --> [concorrente]
		stvar 2 --> [elemento2]
		ldconst 4 --> [1]
		stvar 0 --> [x]
	:8    	ldvar 0 --> [x]
		ldconst 8 --> [5]
		le
		ifnot 25 --> [25]
		jmp 18 --> [18]
	:13   	ldvar 0 --> [x]
		ldconst 4 --> [1]
		add
		stvar 0 --> [x]
		jmp 8 --> [8]
	:18   	ldconst 9 --> [Elemento start esta na iteracao ]
		ldvar 0 --> [x]
		ldconst 7 --> [2]
		lcall 10 --> [io.writeln]
		ldconst 4 --> [1]
		lcall 11 --> [datetime.sleep]
		jmp 13 --> [13]
	:25   	ldvar 1 --> [elemento1]
		mcall 12 --> [wait]
		ldconst 13 --> [Elemento 1 terminou...]
		ldconst 4 --> [1]
		lcall 10 --> [io.writeln]
		ldvar 2 --> [elemento2]
		mcall 12 --> [wait]
		ldconst 14 --> [Elemento 2 terminou...]
		ldconst 4 --> [1]
		lcall 10 --> [io.writeln]
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
		ldconst 17 --> [10]
		le
		ifnot 23 --> [23]
		jmp 12 --> [12]
	:7    	ldvar 0 --> [y]
		ldconst 4 --> [1]
		add
		stvar 0 --> [y]
		jmp 2 --> [2]
	:12   	ldconst 18 --> [Elemento ]
		ldpar 0 --> [id]
		ldconst 19 --> [ esta na iteracao ]
		ldvar 0 --> [y]
		ldconst 20 --> [4]
		lcall 10 --> [io.writeln]
		ldconst 4 --> [1]
		ldpar 0 --> [id]
		mul
		lcall 11 --> [datetime.sleep]
		jmp 7 --> [7]
	:23   	ret
	.end
.end
