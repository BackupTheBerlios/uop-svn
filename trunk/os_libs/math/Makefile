LIBUVM=../../libuvm/
UBIVM=../../ubivm
LIBCOMMON=../../libcommon/

# INCLUDE_DIR=-I/usr/local/include/ -I$(LIBUVM) -I$(LIBCOMMON)
INCLUDE_DIR=-I$(LIBUVM) -I$(UBIVM) -I$(LIBCOMMON) -I../ -I/usr/local/include/boost-1_39/
CC=g++
CCFLAGS=-g -Wall -pedantic -fpic

OBJECTS = uvm_os_math.o

LIBNAME = libuvm_os_math

all: $(OBJECTS)
	g++ -shared -o $(LIBNAME).so $(OBJECTS)
#	g++ -shared -o $(LIBNAME).so $(OBJECTS) ../../ubivm/DataStack.o ../../ubivm/Literal.o ../../libcommon/libcommon.a ../../ubivm/Tuple.o
#	g++ -shared -o $(LIBNAME).so $(OBJECTS) #-luvm_os_libs -L../

%.o: %.cpp %.hpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@

%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@


clean:
	rm -f *.o $(LIBNAME).so $(OBJECTS) core
