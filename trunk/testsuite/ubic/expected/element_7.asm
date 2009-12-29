.constant_pool
	0   S start
	1   S constructor
	2   S e
	3   S elemento
	4   I 1
	5   S um
	6   I 2
	7   S dois
	8   S x
	9   S number1
	10  S msg1
	11  S number2
	12  S msg2
	13  S number1=
	14  S  msg1=
	15  I 4
	16  S io.writeln
	17  S number2=
	18  S  msg2=
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element e
		newelem 3 --> [elemento]
		stvar 0 --> [e]
		ldconst 4 --> [1]
		ldconst 5 --> [um]
		ldconst 6 --> [2]
		ldconst 7 --> [dois]
		ldvar 0 --> [e]
		mcall 8 --> [x]
		stop
	.end
.end
.entity elemento
	.valid_context_when (always)
	.method x
		.param 0 int number1
		.param 1 string msg1
		.param 2 int number2
		.param 3 string msg2
		ldconst 13 --> [number1=]
		ldpar 0 --> [number1]
		ldconst 14 --> [ msg1=]
		ldpar 1 --> [msg1]
		ldconst 15 --> [4]
		lcall 16 --> [io.writeln]
		ldconst 17 --> [number2=]
		ldpar 2 --> [number2]
		ldconst 18 --> [ msg2=]
		ldpar 3 --> [msg2]
		ldconst 15 --> [4]
		lcall 16 --> [io.writeln]
		ret
	.end
.end
