Entity start
	No options
	Constants
		0 S start
		1 S ABCDEFGHIJKLMNOPQRSTUVWXYZ
		2 I 1
		3 S io.writeln
		4 S 12345 true false 10.0 20.9876
		5 I 12345
		6 B true
		7 B false
		8 R 10.000000
		9 R 20.987600
	End
	No properties
	Def start
		No parameters
		No local variables
		No results
		ldconst 1 --> [ABCDEFGHIJKLMNOPQRSTUVWXYZ]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		ldconst 4 --> [12345 true false 10.0 20.9876]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		ldconst 5 --> [12345]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		ldconst 6 --> [true]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		ldconst 7 --> [false]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		ldconst 8 --> [10.000000]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		ldconst 9 --> [20.987600]
		ldconst 2 --> [1]
		lcall 3 --> [io.writeln]
		stop
	End
End
