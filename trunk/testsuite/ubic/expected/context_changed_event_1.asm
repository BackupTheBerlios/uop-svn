.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [1]
	.const 3   string   [location.symbolic]
	.const 4   string   [on_changed]
	.const 5   string   [alt_loc]
	.const 6   string   [2]
	.const 7   string   [3]
	.const 8   string   [old]
	.const 9   string   [new]
	.const 10  string   [Localizacao ]
	.const 11  string   [ mudou para ]
	.const 12  int      [1]
	.const 13  string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [1]
	        stcontexti   3 --> [location.symbolic]
	        ldconst      4 --> [on_changed]
	        ldconst      5 --> [alt_loc]
	        bcontextiev  3 --> [location.symbolic]
	        ldconst      6 --> [2]
	        stcontexti   3 --> [location.symbolic]
	        ldconst      7 --> [3]
	        stcontexti   3 --> [location.symbolic]
	        exit        
	.end
	.method alt_loc
		.param 0 string old
		.param 1 string new
	        ldconst      10 --> [Localizacao ]
	        ldparam      0 --> [old]
	        add         
	        ldconst      11 --> [ mudou para ]
	        add         
	        ldparam      1 --> [new]
	        add         
	        ldconst      12 --> [1]
	        lcall        13 --> [io.writeln]
	        ret         
	.end
.end
