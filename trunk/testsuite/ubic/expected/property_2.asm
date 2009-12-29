.constant_pool
	0   S start
	1   S p1
	2   S set_p1
	3   S value
	4   S constructor
	5   I 10
	6   S Prop deve ser 10: 
	7   I 2
	8   S io.writeln
	9   I 20
	10  S Prop deve ser 20: 
	11  I 30
	12  S Prop deve ser 30: 
	13  I 40
	14  S Prop deve ser 40: 
	15  I 50
	16  S Prop deve ser 50: 
.end
.entity start
	.valid_context_when (always)
	.prop 0 public int p1
	.method set_p1
		.param 0 int value
		ldpar 0 --> [value]
		stprop 0 --> [p1]
		ret
	.end
	.method constructor
		ldconst 5 --> [10]
		stprop 0 --> [p1]
		ldconst 6 --> [Prop deve ser 10: ]
		ldprop 0 --> [p1]
		ldconst 7 --> [2]
		lcall 8 --> [io.writeln]
		ldconst 9 --> [20]
		stprop 0 --> [p1]
		ldconst 10 --> [Prop deve ser 20: ]
		ldprop 0 --> [p1]
		ldconst 7 --> [2]
		lcall 8 --> [io.writeln]
		ldconst 11 --> [30]
		ldself
		mcall 2 --> [set_p1]
		ldconst 12 --> [Prop deve ser 30: ]
		ldprop 0 --> [p1]
		ldconst 7 --> [2]
		lcall 8 --> [io.writeln]
		ldconst 13 --> [40]
		ldself
		mcall 2 --> [set_p1]
		ldconst 14 --> [Prop deve ser 40: ]
		ldprop 0 --> [p1]
		ldconst 7 --> [2]
		lcall 8 --> [io.writeln]
		ldconst 15 --> [50]
		stprop 0 --> [p1]
		ldconst 16 --> [Prop deve ser 50: ]
		ldprop 0 --> [p1]
		ldconst 7 --> [2]
		lcall 8 --> [io.writeln]
		stop
	.end
.end
