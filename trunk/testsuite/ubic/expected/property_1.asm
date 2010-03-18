.constant_pool
	.const 0   string   [start]
	.const 1   string   [txt]
	.const 2   string   [constructor]
	.const 3   string   [Mensagem]
	.const 4   int      [1]
	.const 5   string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.prop 0 public string txt
	.method constructor
	        ldconst      3 --> [Mensagem]
	        stprop       0 --> [txt]
	        ldprop       0 --> [txt]
	        ldconst      4 --> [1]
	        lcall        5 --> [io.writeln]
	        exit        
	.end
.end
