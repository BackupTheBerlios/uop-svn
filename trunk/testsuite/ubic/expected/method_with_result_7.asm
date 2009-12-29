.constant_pool
	0   S start
	1   S constructor
	2   S soma
	3   S subtracao
	4   I 2
	5   I 10
	6   S operations
	7   S soma     : 
	8   S io.writeln
	9   S subtracao: 
	10  S par1
	11  S par2
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int soma
		.var 1 int subtracao
		ldconst 4 --> [2]
		ldconst 5 --> [10]
		ldself
		mcall 6 --> [operations]
		stvar 0 --> [soma]
		stvar 1 --> [subtracao]
		ldconst 7 --> [soma     : ]
		ldvar 0 --> [soma]
		ldconst 4 --> [2]
		lcall 8 --> [io.writeln]
		ldconst 9 --> [subtracao: ]
		ldvar 1 --> [subtracao]
		ldconst 4 --> [2]
		lcall 8 --> [io.writeln]
		stop
	.end
	.method operations
		.param 0 int par1
		.param 1 int par2
		.result 0 int
		.result 1 int
		ldpar 0 --> [par1]
		ldpar 1 --> [par2]
		add
		stresult 0
		ldpar 0 --> [par1]
		ldpar 1 --> [par2]
		sub
		stresult 1
		ret
	.end
.end
