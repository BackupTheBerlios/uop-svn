.constant_pool
	.const 0   string   [start]
	.const 1   string   [constructor]
	.const 2   string   [quantos]
	.const 3   int      [10]
	.const 4   string   [x]
	.const 5   int      [1]
	.const 6   string   [io.writeln]
.end
.entity start
	.valid_context_when (always)
	.method constructor
		.var 0 int quantos
		.var 1 int x
	        ldconst      3 --> [10]
	        stvar        0 --> [quantos]
	        ldconst      5 --> [1]
	        stvar        1 --> [x]
	:4      ldvar        1 --> [x]
	        ldvar        0 --> [quantos]
	        le          
	        ifnot        18 --> [18]
	        jmp          14 --> [14]
	:9      ldvar        1 --> [x]
	        ldconst      5 --> [1]
	        add         
	        stvar        1 --> [x]
	        jmp          4 --> [4]
	:14     ldvar        1 --> [x]
	        ldconst      5 --> [1]
	        lcall        6 --> [io.writeln]
	        jmp          9 --> [9]
	:18     exit        
	.end
.end
