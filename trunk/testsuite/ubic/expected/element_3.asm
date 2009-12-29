.constant_pool
	0   S start
	1   S constructor
	2   S e
	3   S antes da chamada a elemento::x
	4   I 1
	5   S io.writeln
	6   S elemento
	7   S x
	8   S depois da chamada a elemento::x
	9   S antes da chamada a elemento::y
	10  S y
	11  S depois da chamada a elemento::y
	12  S no metodo elemento::y
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element e
		ldconst 3 --> [antes da chamada a elemento::x]
		ldconst 4 --> [1]
		lcall 5 --> [io.writeln]
		newelem 6 --> [elemento]
		stvar 0 --> [e]
		ldvar 0 --> [e]
		mcall 7 --> [x]
		ldconst 8 --> [depois da chamada a elemento::x]
		ldconst 4 --> [1]
		lcall 5 --> [io.writeln]
		stop
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method x
		ldconst 9 --> [antes da chamada a elemento::y]
		ldconst 4 --> [1]
		lcall 5 --> [io.writeln]
		ldself
		mcall 10 --> [y]
		ldconst 11 --> [depois da chamada a elemento::y]
		ldconst 4 --> [1]
		lcall 5 --> [io.writeln]
		ret
	.end
	.method y
		ldconst 12 --> [no metodo elemento::y]
		ldconst 4 --> [1]
		lcall 5 --> [io.writeln]
		ret
	.end
.end
