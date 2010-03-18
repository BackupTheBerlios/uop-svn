.constant_pool
	.const 0   string   [a]
	.const 1   string   [x]
	.const 2   string   [set_x]
	.const 3   string   [value]
	.const 4   string   [start]
	.const 5   string   [constructor]
	.const 6   string   [e]
	.const 7   string   [on_property_changed]
	.const 8   string   [alterado]
	.const 9   int      [12]
	.const 10  string   [prop_name]
	.const 11  string   [old]
	.const 12  string   [new]
	.const 13  string   [A propriedade ]
	.const 14  string   [ foi alterada de ]
	.const 15  string   [ para ]
	.const 16  int      [1]
	.const 17  string   [io.writeln]
.end
.entity a
	.valid_context_when (always)
	.prop 0 public int x
	.method set_x
		.param 0 int value
	        ldparam      0 --> [value]
	        stprop       0 --> [x]
	        ret         
	.end
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 element e
	        newelem      0 --> [a]
	        stvar        0 --> [e]
	        ldconst      7 --> [on_property_changed]
	        ldconst      8 --> [alterado]
	        belementev   0 --> [e]
	        ldconst      9 --> [12]
	        ldvar        0 --> [e]
	        mcall        2 --> [set_x]
	        exit        
	.end
	.method alterado
		.param 0 string prop_name
		.param 1 string old
		.param 2 string new
	        ldconst      13 --> [A propriedade ]
	        ldparam      0 --> [prop_name]
	        add         
	        ldconst      14 --> [ foi alterada de ]
	        add         
	        ldparam      1 --> [old]
	        add         
	        ldconst      15 --> [ para ]
	        add         
	        ldparam      2 --> [new]
	        add         
	        ldconst      16 --> [1]
	        lcall        17 --> [io.writeln]
	        ret         
	.end
.end
