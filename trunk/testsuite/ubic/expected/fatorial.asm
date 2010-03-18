.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [Fatorial de 0: ]
	.const 3   int      [0]
	.const 4   string   [fatorial]
	.const 5   int      [2]
	.const 6   string   [io.writeln]
	.const 7   string   [Fatorial de 1: ]
	.const 8   int      [1]
	.const 9   string   [Fatorial de 2: ]
	.const 10  string   [Fatorial de 3: ]
	.const 11  int      [3]
	.const 12  string   [Fatorial de 4: ]
	.const 13  int      [4]
	.const 14  string   [Fatorial de 5: ]
	.const 15  int      [5]
	.const 16  string   [Fatorial de 6: ]
	.const 17  int      [6]
	.const 18  string   [n]
.end
.entity start
	.valid_context_when (always)
	.method constructor
	        ldconst      2 --> [Fatorial de 0: ]
	        ldconst      3 --> [0]
	        ldself      
	        mcall        4 --> [fatorial]
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        ldconst      7 --> [Fatorial de 1: ]
	        ldconst      8 --> [1]
	        ldself      
	        mcall        4 --> [fatorial]
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        ldconst      9 --> [Fatorial de 2: ]
	        ldconst      5 --> [2]
	        ldself      
	        mcall        4 --> [fatorial]
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        ldconst      10 --> [Fatorial de 3: ]
	        ldconst      11 --> [3]
	        ldself      
	        mcall        4 --> [fatorial]
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        ldconst      12 --> [Fatorial de 4: ]
	        ldconst      13 --> [4]
	        ldself      
	        mcall        4 --> [fatorial]
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        ldconst      14 --> [Fatorial de 5: ]
	        ldconst      15 --> [5]
	        ldself      
	        mcall        4 --> [fatorial]
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        ldconst      16 --> [Fatorial de 6: ]
	        ldconst      17 --> [6]
	        ldself      
	        mcall        4 --> [fatorial]
	        ldconst      5 --> [2]
	        lcall        6 --> [io.writeln]
	        exit        
	.end
	.method fatorial
		.param 0 int n
		.result 0 int
	        ldparam      0 --> [n]
	        ldconst      3 --> [0]
	        eq          
	        ifnot        8 --> [8]
	        ldconst      8 --> [1]
	        stresult     0
	        ret         
	        jmp          17 --> [17]
	:8      ldparam      0 --> [n]
	        ldparam      0 --> [n]
	        ldconst      8 --> [1]
	        sub         
	        ldself      
	        mcall        4 --> [fatorial]
	        mul         
	        stresult     0
	        ret         
	:17     ret         
	.end
.end
