.constant_pool
	0   S start
	1   S constructor
	2   I 1
	3   S um
	4   I 2
	5   S dois
	6   S x
	7   S number1
	8   S msg1
	9   S number2
	10  S msg2
	11  S number1=
	12  S  msg1=
	13  I 4
	14  S io.writeln
	15  S number2=
	16  S  msg2=
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [1]
		ldconst 3 --> [um]
		ldconst 4 --> [2]
		ldconst 5 --> [dois]
		ldself
		mcall 6 --> [x]
		stop
	.end
	.method x
		.param 0 int number1
		.param 1 string msg1
		.param 2 int number2
		.param 3 string msg2
		ldconst 11 --> [number1=]
		ldpar 0 --> [number1]
		ldconst 12 --> [ msg1=]
		ldpar 1 --> [msg1]
		ldconst 13 --> [4]
		lcall 14 --> [io.writeln]
		ldconst 15 --> [number2=]
		ldpar 2 --> [number2]
		ldconst 16 --> [ msg2=]
		ldpar 3 --> [msg2]
		ldconst 13 --> [4]
		lcall 14 --> [io.writeln]
		ret
	.end
.end
