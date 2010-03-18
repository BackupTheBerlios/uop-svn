.constant_pool
	.const 0   string   [start]
	.const 1   string   [p1]
	.const 2   string   [set_p1]
	.const 3   string   [value]
	.const 4   string   [constructor]
	.const 5   int      [10]
	.const 6   string   [Prop deve ser 10: ]
	.const 7   int      [2]
	.const 8   string   [io.writeln]
	.const 9   int      [20]
	.const 10  string   [Prop deve ser 20: ]
	.const 11  int      [30]
	.const 12  string   [Prop deve ser 30: ]
	.const 13  int      [40]
	.const 14  string   [Prop deve ser 40: ]
	.const 15  int      [50]
	.const 16  string   [Prop deve ser 50: ]
.end
.entity start
	.valid_context_when (always)
	.prop 0 public int p1
	.method set_p1
		.param 0 int value
	        ldparam      0 --> [value]
	        stprop       0 --> [p1]
	        ret         
	.end
	.method constructor
	        ldconst      5 --> [10]
	        stprop       0 --> [p1]
	        ldconst      6 --> [Prop deve ser 10: ]
	        ldprop       0 --> [p1]
	        ldconst      7 --> [2]
	        lcall        8 --> [io.writeln]
	        ldconst      9 --> [20]
	        stprop       0 --> [p1]
	        ldconst      10 --> [Prop deve ser 20: ]
	        ldprop       0 --> [p1]
	        ldconst      7 --> [2]
	        lcall        8 --> [io.writeln]
	        ldconst      11 --> [30]
	        ldself      
	        mcall        2 --> [set_p1]
	        ldconst      12 --> [Prop deve ser 30: ]
	        ldprop       0 --> [p1]
	        ldconst      7 --> [2]
	        lcall        8 --> [io.writeln]
	        ldconst      13 --> [40]
	        ldself      
	        mcall        2 --> [set_p1]
	        ldconst      14 --> [Prop deve ser 40: ]
	        ldprop       0 --> [p1]
	        ldconst      7 --> [2]
	        lcall        8 --> [io.writeln]
	        ldconst      15 --> [50]
	        stprop       0 --> [p1]
	        ldconst      16 --> [Prop deve ser 50: ]
	        ldprop       0 --> [p1]
	        ldconst      7 --> [2]
	        lcall        8 --> [io.writeln]
	        exit        
	.end
.end
