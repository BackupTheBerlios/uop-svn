.constant_pool
	0   S start
	1   S constructor
	2   S var1
	3   S var2
	4   S var3
	5   S var4
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int var1
		.var 1 string var2
		.var 2 real var3
		.var 3 bool var4
		stop
	.end
.end
