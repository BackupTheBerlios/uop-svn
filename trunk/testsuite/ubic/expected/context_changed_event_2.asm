.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [on_new_value]
	.const 3   string   [nova_info]
	.const 4   string   [location.symbolic]
	.const 5   string   [1]
	.const 6   string   [on_changed]
	.const 7   string   [alt_loc]
	.const 8   string   [2]
	.const 9   string   [3]
	.const 10  string   [old]
	.const 11  string   [new]
	.const 12  string   [Localizacao ]
	.const 13  string   [ mudou para ]
	.const 14  int      [1]
	.const 15  string   [io.writeln]
	.const 16  string   [info]
	.const 17  string   [value]
	.const 18  string   [Adicionada informacao ]
	.const 19  string   [ com valor ]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [on_new_value]
	        ldconst      3 --> [nova_info]
	        bcontextiev  4 --> [location.symbolic]
	        ldconst      5 --> [1]
	        stcontexti   4 --> [location.symbolic]
	        ldconst      6 --> [on_changed]
	        ldconst      7 --> [alt_loc]
	        bcontextiev  4 --> [location.symbolic]
	        ldconst      8 --> [2]
	        stcontexti   4 --> [location.symbolic]
	        ldconst      9 --> [3]
	        stcontexti   4 --> [location.symbolic]
	        exit        
	.end
	.method alt_loc
		.param 0 string old
		.param 1 string new
	        ldconst      12 --> [Localizacao ]
	        ldparam      0 --> [old]
	        add         
	        ldconst      13 --> [ mudou para ]
	        add         
	        ldparam      1 --> [new]
	        add         
	        ldconst      14 --> [1]
	        lcall        15 --> [io.writeln]
	        ret         
	.end
	.method nova_info
		.param 0 string info
		.param 1 string value
	        ldconst      18 --> [Adicionada informacao ]
	        ldparam      0 --> [info]
	        add         
	        ldconst      19 --> [ com valor ]
	        add         
	        ldparam      1 --> [value]
	        add         
	        ldconst      14 --> [1]
	        lcall        15 --> [io.writeln]
	        ret         
	.end
.end
