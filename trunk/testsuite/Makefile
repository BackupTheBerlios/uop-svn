#LIBUVM=../libuvm/
LIBCOMMON=../libcommon/

#INCLUDE_DIR=-I/usr/local/include/ -I$(LIBUVM) -I$(LIBCOMMON)
INCLUDE_DIR=-I. -I$(LIBCOMMON)
CC=g++
CCFLAGS=-g -Wall -pedantic

objects = main.o Test.o Tests.o Tool.o Args.o Subtest.o

all: $(objects)
	g++ -o tests $(objects) -static -L$(LIBCOMMON) -lcommon

%.o: %.cpp %.hpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@


clean:
	rm -f *.o tests core
