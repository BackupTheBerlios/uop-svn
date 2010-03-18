.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [var1]
	.const 3   string   [var2]
	.const 4   string   [var3]
	.const 5   string   [var4]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int var1
		.var 1 string var2
		.var 2 real var3
		.var 3 bool var4
	        exit        
	.end
.end
