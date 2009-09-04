LIBUVM=../libuvm/
LIBCOMMON=../libcommon/

INCLUDE_DIR=-I/usr/local/include/ -I$(LIBUVM) -I$(LIBCOMMON) -I/usr/local/include/boost-1_39/
CC=g++
CCFLAGS=-g -Wall -pedantic

objects = UbiVM.o main.o RunBytecode.o DataStack.o Literal.o ActivationRecord.o Element.o Group.o Tuple.o CommunicationProvider.o

all: $(objects)
	g++ -o ubivm $(objects) -static -L$(LIBUVM) -L$(LIBCOMMON) -luvm -lcommon -ldl -lboost_thread-gcc42-mt -lpthread -lboost_system-gcc42-mt

%.o: %.cpp %.hpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@


clean:
	rm -f *.o ubivm core
