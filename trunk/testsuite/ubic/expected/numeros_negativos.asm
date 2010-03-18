.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   int      [-10]
	.const 3   int      [1]
	.const 4   string   [io.writeln]
	.const 5   int      [-20]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [-10]
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        ldconst      2 --> [-10]
	        ldconst      5 --> [-20]
	        add         
	        ldconst      3 --> [1]
	        lcall        4 --> [io.writeln]
	        exit        
	.end
.end
