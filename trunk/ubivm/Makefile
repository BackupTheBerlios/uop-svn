LIBUVM=../libuvm/
LIBCOMMON=../libcommon/
LIB_UVM_OS_LIBS=../os_libs/

INCLUDE_DIR=-I/usr/local/include/ -I$(LIBUVM) -I$(LIBCOMMON) -I/usr/local/include/boost-1_39/
CC=g++
CCFLAGS=-rdynamic -g -Wall #-pedantic

objects = UbiVM.o main.o RunBytecode.o DataStack.o Literal.o ActivationRecord.o Element.o Context.o Tuple.o CommunicationProvider.o ContextProvider.o

all: $(objects)
	g++ -rdynamic -o ubivm $(objects) -L$(LIBUVM) -L$(LIBCOMMON) -luvm -lcommon -ldl -lboost_thread-mt -lpthread -lboost_system-mt
# 	g++ -o ubivm $(objects) -static -L$(LIBUVM) -L$(LIBCOMMON) -L$(LIB_UVM_OS_LIBS) -luvm -lcommon -luvm_os_libs -ldl -lboost_thread-gcc42-mt -lpthread -lboost_system-gcc42-mt

%.o: %.cpp %.hpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@


clean:
	rm -f *.o ubivm core
