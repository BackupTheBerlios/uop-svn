Entity start
	Constants
		0 S start
		1 S Meu Host
		2 S identity.host
		3 S Mobilab - sala 1
		4 S location.symbolic
		5 I 101010
		6 S time.now
		7 S Host atual: 
		8 I 2
		9 S writeln
		10 S Onde estou: 
		11 S Horario   : 
	End
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [Meu Host]
		stcontext 2 --> [identity.host]
		ldconst 3 --> [Mobilab - sala 1]
		stcontext 4 --> [location.symbolic]
		ldconst 5 --> [101010]
		stcontext 6 --> [time.now]
		ldconst 7 --> [Host atual: ]
		ldcontext 2 --> [identity.host]
		ldconst 8 --> [2]
		lcall 9 --> [writeln]
		ldconst 10 --> [Onde estou: ]
		ldcontext 4 --> [location.symbolic]
		ldconst 8 --> [2]
		lcall 9 --> [writeln]
		ldconst 11 --> [Horario   : ]
		ldcontext 6 --> [time.now]
		ldconst 8 --> [2]
		lcall 9 --> [writeln]
		stop
	End
End
