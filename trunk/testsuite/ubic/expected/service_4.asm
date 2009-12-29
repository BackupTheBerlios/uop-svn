.constant_pool
	0   S servico
	1   S operations
	2   S par1
	3   S par2
	4   S par1=
	5   S  par2=
	6   I 4
	7   S io.writeln
	8   S constructor
	9   S context
	10  S Alex
	11  S start
	12  S soma
	13  S subtracao
	14  S s
	15  I 2
	16  I 10
	17  S soma     : 
	18  S subtracao: 
.end
.entity servico
	.valid_context_when (always)
	.method operations
		.param 0 int par1
		.param 1 int par2
		.result 0 int
		.result 1 int
		ldconst 4 --> [par1=]
		ldpar 0 --> [par1]
		ldconst 5 --> [ par2=]
		ldpar 1 --> [par2]
		ldconst 6 --> [4]
		lcall 7 --> [io.writeln]
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
	.method constructor
		ldconst 9 --> [context]
		ldconst 10 --> [Alex]
		joinc
		ldconst 9 --> [context]
		publishs 1 --> [operations]
		ret
	.end
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int soma
		.var 1 int subtracao
		.var 2 element s
		newelem 0 --> [servico]
		stvar 2 --> [s]
		ldconst 15 --> [2]
		ldconst 16 --> [10]
		ldconst 15 --> [2]
		ldconst 9 --> [context]
		runs 1 --> [operations]
		stvar 0 --> [soma]
		stvar 1 --> [subtracao]
		ldconst 17 --> [soma     : ]
		ldvar 0 --> [soma]
		ldconst 15 --> [2]
		lcall 7 --> [io.writeln]
		ldconst 18 --> [subtracao: ]
		ldvar 1 --> [subtracao]
		ldconst 15 --> [2]
		lcall 7 --> [io.writeln]
		stop
	.end
.end
