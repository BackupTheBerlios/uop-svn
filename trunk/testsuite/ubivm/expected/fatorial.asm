Entity start
	Constants
		0 S start
		1 S Fatorial de 0: 
		2 I 0
		3 S fatorial
		4 I 2
		5 S io.writeln
		6 S Fatorial de 1: 
		7 I 1
		8 S Fatorial de 2: 
		9 S Fatorial de 3: 
		10 I 3
		11 S Fatorial de 4: 
		12 I 4
		13 S Fatorial de 5: 
		14 I 5
		15 S Fatorial de 6: 
		16 I 6
		17 S n
	End
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [Fatorial de 0: ]
		ldconst 2 --> [0]
		ldself
		mcall 3 --> [fatorial]
		ldconst 4 --> [2]
		lcall 5 --> [io.writeln]
		ldconst 6 --> [Fatorial de 1: ]
		ldconst 7 --> [1]
		ldself
		mcall 3 --> [fatorial]
		ldconst 4 --> [2]
		lcall 5 --> [io.writeln]
		ldconst 8 --> [Fatorial de 2: ]
		ldconst 4 --> [2]
		ldself
		mcall 3 --> [fatorial]
		ldconst 4 --> [2]
		lcall 5 --> [io.writeln]
		ldconst 9 --> [Fatorial de 3: ]
		ldconst 10 --> [3]
		ldself
		mcall 3 --> [fatorial]
		ldconst 4 --> [2]
		lcall 5 --> [io.writeln]
		ldconst 11 --> [Fatorial de 4: ]
		ldconst 12 --> [4]
		ldself
		mcall 3 --> [fatorial]
		ldconst 4 --> [2]
		lcall 5 --> [io.writeln]
		ldconst 13 --> [Fatorial de 5: ]
		ldconst 14 --> [5]
		ldself
		mcall 3 --> [fatorial]
		ldconst 4 --> [2]
		lcall 5 --> [io.writeln]
		ldconst 15 --> [Fatorial de 6: ]
		ldconst 16 --> [6]
		ldself
		mcall 3 --> [fatorial]
		ldconst 4 --> [2]
		lcall 5 --> [io.writeln]
		stop
	End
	Def fatorial
		Parameters
			0 int n
		End
		No local variables
		Result
			0 int
		End
		ldpar 0 --> [n]
		ldconst 2 --> [0]
		eq
		ifnot 7 --> [7]
		ldconst 7 --> [1]
		stresult 0
		jmp 15 --> [15]
	7:	ldpar 0 --> [n]
		ldpar 0 --> [n]
		ldconst 7 --> [1]
		sub
		ldself
		mcall 3 --> [fatorial]
		mul
		stresult 0
	15:	ret
	End
End
