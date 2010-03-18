.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [var1]
	.const 3   string   [aaa]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 string var1
	        ldconst      3 --> [aaa]
	        stvar        0 --> [var1]
	        exit        
	.end
.end
