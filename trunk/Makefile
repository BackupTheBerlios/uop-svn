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
	make -C libcommon
	make -C libuvm
	make -C ubic
	make -C ubivm
	make -C testsuite
	make -C os_libs
	make -C ubibind
	make -C ubiprovider

clean:
	make -C libcommon clean
	make -C libuvm clean
	make -C ubic clean
	make -C ubivm clean
	make -C testsuite clean
	make -C os_libs clean
	make -C ubibind clean
	make -C ubiprovider clean
