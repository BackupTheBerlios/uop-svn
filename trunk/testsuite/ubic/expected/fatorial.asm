.constant_pool
	0   S start
	1   S constructor
	2   S Fatorial de 0: 
	3   I 0
	4   S fatorial
	5   I 2
	6   S io.writeln
	7   S Fatorial de 1: 
	8   I 1
	9   S Fatorial de 2: 
	10  S Fatorial de 3: 
	11  I 3
	12  S Fatorial de 4: 
	13  I 4
	14  S Fatorial de 5: 
	15  I 5
	16  S Fatorial de 6: 
	17  I 6
	18  S n
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [Fatorial de 0: ]
		ldconst 3 --> [0]
		ldself
		mcall 4 --> [fatorial]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ldconst 7 --> [Fatorial de 1: ]
		ldconst 8 --> [1]
		ldself
		mcall 4 --> [fatorial]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ldconst 9 --> [Fatorial de 2: ]
		ldconst 5 --> [2]
		ldself
		mcall 4 --> [fatorial]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ldconst 10 --> [Fatorial de 3: ]
		ldconst 11 --> [3]
		ldself
		mcall 4 --> [fatorial]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ldconst 12 --> [Fatorial de 4: ]
		ldconst 13 --> [4]
		ldself
		mcall 4 --> [fatorial]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ldconst 14 --> [Fatorial de 5: ]
		ldconst 15 --> [5]
		ldself
		mcall 4 --> [fatorial]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		ldconst 16 --> [Fatorial de 6: ]
		ldconst 17 --> [6]
		ldself
		mcall 4 --> [fatorial]
		ldconst 5 --> [2]
		lcall 6 --> [io.writeln]
		stop
	.end
	.method fatorial
		.param 0 int n
		.result 0 int
		ldpar 0 --> [n]
		ldconst 3 --> [0]
		eq
		ifnot 7 --> [7]
		ldconst 8 --> [1]
		stresult 0
		jmp 15 --> [15]
	:7    	ldpar 0 --> [n]
		ldpar 0 --> [n]
		ldconst 8 --> [1]
		sub
		ldself
		mcall 4 --> [fatorial]
		mul
		stresult 0
	:15   	ret
	.end
.end
