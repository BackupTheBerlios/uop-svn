.constant_pool
	0   S start
	1   S constructor
	2   S x
	3   S util
	4   S aaa
	5   S metodo1
	6   S Depois de invocar metodo1
	7   I 1
	8   S io.writeln
	9   I 111
	10  S metodo2
	11  S Depois de invocar metodo2
	12  S param
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element x
		newelem 3 --> [util]
		stvar 0 --> [x]
		ldconst 4 --> [aaa]
		ldvar 0 --> [x]
		mcall 5 --> [metodo1]
		ldconst 6 --> [Depois de invocar metodo1]
		ldconst 7 --> [1]
		lcall 8 --> [io.writeln]
		ldconst 9 --> [111]
		ldvar 0 --> [x]
		mcall 10 --> [metodo2]
		ldconst 11 --> [Depois de invocar metodo2]
		ldconst 7 --> [1]
		lcall 8 --> [io.writeln]
		stop
	.end
.end
.entity util
	.valid_context_when (always)
	.method metodo1
		.param 0 string param
		ldpar 0 --> [param]
		ldconst 7 --> [1]
		lcall 8 --> [io.writeln]
		ret
	.end
	.method metodo2
		.param 0 int param
		ldpar 0 --> [param]
		ldconst 7 --> [1]
		lcall 8 --> [io.writeln]
		ret
	.end
.end
