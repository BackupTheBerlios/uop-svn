.constant_pool
	0   S start
	1   S constructor
	2   S var1
	3   S aaa
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 string var1
		ldconst 3 --> [aaa]
		stvar 0 --> [var1]
		stop
	.end
.end
