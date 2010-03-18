.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [Meu Host]
	.const 3   string   [identity.host]
	.const 4   string   [Mobilab - sala 1]
	.const 5   string   [location.symbolic]
	.const 6   int      [101010]
	.const 7   string   [time.now]
	.const 8   string   [Host atual: ]
	.const 9   int      [2]
	.const 10  string   [io.writeln]
	.const 11  string   [Onde estou: ]
	.const 12  string   [Horario   : ]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [Meu Host]
	        stcontexti   3 --> [identity.host]
	        ldconst      4 --> [Mobilab - sala 1]
	        stcontexti   5 --> [location.symbolic]
	        ldconst      6 --> [101010]
	        stcontexti   7 --> [time.now]
	        ldconst      8 --> [Host atual: ]
	        ldcontexti   3 --> [identity.host]
	        ldconst      9 --> [2]
	        lcall        10 --> [io.writeln]
	        ldconst      11 --> [Onde estou: ]
	        ldcontexti   5 --> [location.symbolic]
	        ldconst      9 --> [2]
	        lcall        10 --> [io.writeln]
	        ldconst      12 --> [Horario   : ]
	        ldcontexti   7 --> [time.now]
	        ldconst      9 --> [2]
	        lcall        10 --> [io.writeln]
	        exit        
	.end
.end
