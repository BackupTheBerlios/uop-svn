.constant_pool
	0   S start
	1   S constructor
	2   S ABCDEFGHIJKLMNOPQRSTUVWXYZ
	3   I 1
	4   S io.writeln
	5   S 12345 true false 10.0 20.9876
	6   I 12345
	7   B true
	8   B false
	9   R 10.000000
	10  R 20.987600
.end
.entity start
	.valid_context_when (always)
	.method constructor
		ldconst 2 --> [ABCDEFGHIJKLMNOPQRSTUVWXYZ]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ldconst 5 --> [12345 true false 10.0 20.9876]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ldconst 6 --> [12345]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ldconst 7 --> [true]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ldconst 8 --> [false]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ldconst 9 --> [10.000000]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		ldconst 10 --> [20.987600]
		ldconst 3 --> [1]
		lcall 4 --> [io.writeln]
		stop
	.end
.end
