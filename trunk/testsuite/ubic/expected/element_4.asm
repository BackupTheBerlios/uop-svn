.constant_pool
	0   S start
	1   S constructor
	2   S antes da chamada a start::x
	3   I 1
	4   S io.writeln
	5   S x
	6   S depois da chamada a start::x
	7   S antes da chamada a start::y
	8   S y
	9   S depois da chamada a start::y
	10  S e
	11  S antes da chamada a elemento::x
	12  S elemento
	13  S depois da chamada a elemento::x
	14  S antes da chamada a elemento::y
	15  S depois da chamada a elemento::y
	16  S no metodo elemento::y
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [antes da chamada a start::x]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ldself
		mcall 5 --> [x]
		ldconst 6 --> [depois da chamada a start::x]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		stop
	.end
	.method x
		ldconst 7 --> [antes da chamada a start::y]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ldself
		mcall 8 --> [y]
		ldconst 9 --> [depois da chamada a start::y]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ret
	.end
	.method y
		.var 0 element e
		ldconst 11 --> [antes da chamada a elemento::x]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		newelem 12 --> [elemento]
		stvar 0 --> [e]
		ldvar 0 --> [e]
		mcall 5 --> [x]
		ldconst 13 --> [depois da chamada a elemento::x]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ret
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method x
		ldconst 14 --> [antes da chamada a elemento::y]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ldself
		mcall 8 --> [y]
		ldconst 15 --> [depois da chamada a elemento::y]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ret
	.end
	.method y
		ldconst 16 --> [no metodo elemento::y]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ret
	.end
.end
