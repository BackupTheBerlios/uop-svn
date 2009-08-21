Entity start
	Constants
		0 S start
		1 S x
		2 I 1
		3 I 10
		4 I 3
		5 I 5
		6 I 7
		7 I 9
		8 S x=
		9 S  eh impar !!!
		10 S writeln
		11 I 2
		12 I 4
		13 I 6
		14 I 8
		15 S  eh par !!!
		16 S  ???
	End
	Def start
		No parameters
		Local variables
			0 int x
		End
		No results
		ldconst 2 --> [1]
		stvar 0 --> [x]
	2:	ldvar 0 --> [x]
		ldconst 3 --> [10]
		le
		ifnot 70 --> [70]
		jmp 12 --> [12]
	7:	ldvar 0 --> [x]
		ldconst 2 --> [1]
		add
		stvar 0 --> [x]
		jmp 2 --> [2]
	12:	ldvar 0 --> [x]
		ldconst 2 --> [1]
		eq
		ldvar 0 --> [x]
		ldconst 4 --> [3]
		eq
		or
		ldvar 0 --> [x]
		ldconst 5 --> [5]
		eq
		or
		ldvar 0 --> [x]
		ldconst 6 --> [7]
		eq
		or
		ldvar 0 --> [x]
		ldconst 7 --> [9]
		eq
		or
		ifnot 38 --> [38]
		ldconst 8 --> [x=]
		ldvar 0 --> [x]
		ldconst 9 --> [ eh impar !!!]
		ldconst 4 --> [3]
		lcall 10 --> [writeln]
		jmp 69 --> [69]
	38:	ldvar 0 --> [x]
		ldconst 11 --> [2]
		eq
		ldvar 0 --> [x]
		ldconst 12 --> [4]
		eq
		or
		ldvar 0 --> [x]
		ldconst 13 --> [6]
		eq
		or
		ldvar 0 --> [x]
		ldconst 14 --> [8]
		eq
		or
		ldvar 0 --> [x]
		ldconst 3 --> [10]
		eq
		or
		ifnot 64 --> [64]
		ldconst 8 --> [x=]
		ldvar 0 --> [x]
		ldconst 15 --> [ eh par !!!]
		ldconst 4 --> [3]
		lcall 10 --> [writeln]
		jmp 69 --> [69]
	64:	ldconst 8 --> [x=]
		ldvar 0 --> [x]
		ldconst 16 --> [ ???]
		ldconst 4 --> [3]
		lcall 10 --> [writeln]
	69:	jmp 7 --> [7]
	70:	stop
	End
End
