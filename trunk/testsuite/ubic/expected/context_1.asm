.constant_pool
	0   S start
	1   S constructor
	2   S Meu Host
	3   S identity.host
	4   S Mobilab - sala 1
	5   S location.symbolic
	6   I 101010
	7   S time.now
	8   S Host atual: 
	9   I 2
	10  S io.writeln
	11  S Onde estou: 
	12  S Horario   : 
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [Meu Host]
		stcontexti 3 --> [identity.host]
		ldconst 4 --> [Mobilab - sala 1]
		stcontexti 5 --> [location.symbolic]
		ldconst 6 --> [101010]
		stcontexti 7 --> [time.now]
		ldconst 8 --> [Host atual: ]
		ldcontexti 3 --> [identity.host]
		ldconst 9 --> [2]
		lcall 10 --> [io.writeln]
		ldconst 11 --> [Onde estou: ]
		ldcontexti 5 --> [location.symbolic]
		ldconst 9 --> [2]
		lcall 10 --> [io.writeln]
		ldconst 12 --> [Horario   : ]
		ldcontexti 7 --> [time.now]
		ldconst 9 --> [2]
		lcall 10 --> [io.writeln]
		stop
	.end
.end
