.constant_pool
	0   S start
	1   S constructor
	2   S var1
	3   R 10.990000
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 real var1
		ldconst 3 --> [10.990000]
		stvar 0 --> [var1]
		stop
	.end
.end
