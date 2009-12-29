.constant_pool
	0   S start
	1   S txt
	2   S constructor
	3   S Mensagem
	4   I 1
	5   S io.writeln
.end
.entity start
	.valid_context_when (always)
	.prop 0 public string txt
	.method constructor
		ldconst 3 --> [Mensagem]
		stprop 0 --> [txt]
		ldprop 0 --> [txt]
		ldconst 4 --> [1]
		lcall 5 --> [io.writeln]
		stop
	.end
.end
