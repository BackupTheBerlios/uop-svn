.constant_pool
	0   S start
	1   S constructor
	2   S number_list
	3   S number
	4   S count
	5   S MeuContexto
	6   S teste
	7   S Numero 1
	8   I 100
	9   I 1
	10  S Numero 2
	11  I 200
	12  S Numero 3
	13  I 300
	14  S Numero 4
	15  I 400
	16  S key=
	17  S  value=
	18  I 4
	19  S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 table number_list
		.var 1 tuple number
		.var 2 int count
		ldconst 5 --> [MeuContexto]
		ldconst 6 --> [teste]
		joinc
		ldconst 5 --> [MeuContexto]
		ldconst 7 --> [Numero 1]
		ldconst 8 --> [100]
		ldconst 9 --> [1]
		ldconst 9 --> [1]
		publishd
		ldconst 5 --> [MeuContexto]
		ldconst 10 --> [Numero 2]
		ldconst 11 --> [200]
		ldconst 9 --> [1]
		ldconst 9 --> [1]
		publishd
		ldconst 5 --> [MeuContexto]
		ldconst 12 --> [Numero 3]
		ldconst 13 --> [300]
		ldconst 9 --> [1]
		ldconst 9 --> [1]
		publishd
		ldconst 5 --> [MeuContexto]
		ldconst 14 --> [Numero 4]
		ldconst 15 --> [400]
		ldconst 9 --> [1]
		ldconst 9 --> [1]
		publishd
		ldconst 5 --> [MeuContexto]
		listd
		stvar 0 --> [number_list]
		ldconst 9 --> [1]
		stvar 2 --> [count]
	:32   	ldvar 2 --> [count]
		tabsize 0 --> [number_list]
		le
		ifnot 54 --> [54]
		jmp 42 --> [42]
	:37   	ldvar 2 --> [count]
		ldconst 9 --> [1]
		add
		stvar 2 --> [count]
		jmp 32 --> [32]
	:42   	ldvar 2 --> [count]
		ldtab 0 --> [number_list]
		stvar 1 --> [number]
		ldconst 16 --> [key=]
		ldconst 9 --> [1]
		ldtuplek 1 --> [number]
		ldconst 17 --> [ value=]
		ldconst 9 --> [1]
		ldtuplev 1 --> [number]
		ldconst 18 --> [4]
		lcall 19 --> [io.writeln]
		jmp 37 --> [37]
	:54   	stop
	.end
.end
