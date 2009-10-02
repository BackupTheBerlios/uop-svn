#LIBUVM=../libuvm/
LIBCOMMON=../libcommon/

INCLUDE_DIR=-I/usr/local/include/ -I$(LIBCOMMON)
CC=g++
CCFLAGS=-g -Wall -pedantic
CCFLAGS_ANTLR=-g -Wall

objects = ubibindLexer.o ubibindParser.o main.o BindSources.o

all: $(objects)
	g++ -o ubibind $(objects) -static -lantlr3c -L$(LIBCOMMON) -lcommon

ubibindLexer.o ubibindParser.o: ubibind.g
	java -jar ~/downloads/apps/antlr-3.1.3.jar ubibind.g
	$(CC) $(CCFLAGS_ANTLR) -c $(INCLUDE_DIR) ubibindLexer.c -o ubibindLexer.o
	$(CC) $(CCFLAGS_ANTLR) -c $(INCLUDE_DIR) ubibindParser.c -o ubibindParser.o

%.o: %.cpp %.hpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@


clean:
	rm -f *.o ubibind ubibindLexer.h ubibindLexer.c ubibindParser.h ubibindParser.c ubibind.tokens core
