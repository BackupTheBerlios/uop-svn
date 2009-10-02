#LIBUVM=../libuvm/
#LIBCOMMON=../libcommon/
#
#INCLUDE_DIR=-I/usr/local/include/ -I$(LIBUVM) -I$(LIBCOMMON)
#CC=g++
#CCFLAGS=-g -Wall
#
#objects = ubilLexer.o ubilParser.o UbiC.o main.o 
#
#all: $(objects)
#	g++ -o ubic $(objects) -static -lantlr3c -L$(LIBUVM) -luvm -L$(LIBCOMMON) -lcommon
all:
	make -C math
	make -C ncurses

clean:
	make -C math clean
	make -C ncurses clean
