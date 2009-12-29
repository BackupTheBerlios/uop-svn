.constant_pool
	0   S start
	1   S constructor
	2   I 10
	3   I 20
	4   I 1
	5   S io.writeln
	6   I 30
	7   I 5
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [10]
		ldconst 3 --> [20]
		mul
		ldconst 4 --> [1]
		lcall 5 --> [io.writeln]
		ldconst 2 --> [10]
		ldconst 3 --> [20]
		mul
		ldconst 6 --> [30]
		div
		ldconst 4 --> [1]
		lcall 5 --> [io.writeln]
		ldconst 2 --> [10]
		ldconst 3 --> [20]
		mul
		ldconst 7 --> [5]
		div
		ldconst 4 --> [1]
		lcall 5 --> [io.writeln]
		stop
	.end
.end
