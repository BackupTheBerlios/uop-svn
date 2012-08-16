LIBUVM=../libuvm/
LIBCOMMON=../libcommon/

INCLUDE_DIR=-I/usr/local/include/ -I$(LIBUVM) -I$(LIBCOMMON)
CC=g++
CCFLAGS=-g -Wall -pedantic
CCFLAGS_ANTLR=-g -Wall

objects = ubilLexer.o ubilParser.o UbiC.o main.o

all: $(objects)
	g++ -o ubic $(objects) -static -lantlr3c -L$(LIBUVM) -luvm -L$(LIBCOMMON) -lcommon

#GptBindLexer.hpp GptBindLexer.cpp: lexer.g
#	antlr lexer.g

#GptBindParser.hpp GptBindParser.cpp: parser.g
#	antlr parser.g

ubilLexer.o ubilParser.o: ubil.g
#	java -jar ../../antlr-3.4-complete.jar ubil.g
	java -jar ../../antlr-3.1.3.jar ubil.g
	$(CC) $(CCFLAGS_ANTLR) -c $(INCLUDE_DIR) ubilLexer.c -o ubilLexer.o
	$(CC) $(CCFLAGS_ANTLR) -c $(INCLUDE_DIR) ubilParser.c -o ubilParser.o

%.o: %.cpp %.hpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@


clean:
	rm -f *.o ubic ubilLexer.h ubilLexer.c ubilParser.h ubilParser.c ubil.tokens core
