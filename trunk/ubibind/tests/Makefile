LIBUVM=../../libuvm/
UBIVM=../../ubivm
LIBCOMMON=../../libcommon/
INCLUDE_DIR=-I$(LIBUVM) -I$(UBIVM) -I$(LIBCOMMON) -I../ -I/usr/local/include/boost-1_39/
CC=g++
CCFLAGS=-g -Wall -pedantic
LIBS=

OBJECTS = uvm_os_math.o

LIBNAME = libuvm_os_math

all: $(OBJECTS)
	g++ -shared -o $(LIBNAME).so $(OBJECTS) $(LIBS)

%.cpp:
	../ubibind math.bind

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@

clean:
	rm -f *.o $(LIBNAME).so $(OBJECTS) core uvm_os_math.cpp
