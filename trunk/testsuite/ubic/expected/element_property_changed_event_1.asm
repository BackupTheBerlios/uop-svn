.constant_pool
	0   S a
	1   S x
	2   S set_x
	3   S value
	4   S start
	5   S constructor
	6   S e
	7   S on_property_changed
	8   S alterado
	9   I 12
	10  S prop_name
	11  S old
	12  S new
	13  S A propriedade 
	14  S  foi alterada de 
	15  S  para 
	16  I 1
	17  S io.writeln
.end
.entity a
	.valid_context_when (always)
	.prop 0 public int x
	.method set_x
		.param 0 int value
		ldpar 0 --> [value]
		stprop 0 --> [x]
		ret
	.end
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element e
		newelem 0 --> [a]
		stvar 0 --> [e]
		ldconst 7 --> [on_property_changed]
		ldconst 8 --> [alterado]
		belementev 0 --> [e]
		ldconst 9 --> [12]
		ldvar 0 --> [e]
		mcall 2 --> [set_x]
		stop
	.end
	.method alterado
		.param 0 string prop_name
		.param 1 string old
		.param 2 string new
		ldconst 13 --> [A propriedade ]
		ldpar 0 --> [prop_name]
		add
		ldconst 14 --> [ foi alterada de ]
		add
		ldpar 1 --> [old]
		add
		ldconst 15 --> [ para ]
		add
		ldpar 2 --> [new]
		add
		ldconst 16 --> [1]
		lcall 17 --> [io.writeln]
		ret
	.end
.end
