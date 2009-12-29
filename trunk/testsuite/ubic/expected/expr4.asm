.constant_pool
	0   S start
	1   S constructor
	2   S 2 * (49 / 7 - 3)=
	3   I 2
	4   I 49
	5   I 7
	6   I 3
	7   S io.writeln
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [2 * (49 / 7 - 3)=]
		ldconst 3 --> [2]
		ldconst 4 --> [49]
		ldconst 5 --> [7]
		div
		ldconst 6 --> [3]
		sub
		mul
		ldconst 3 --> [2]
		lcall 7 --> [io.writeln]
		stop
	.end
.end
