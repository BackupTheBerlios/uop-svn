LIBUVM=../../libuvm/
UBIVM=../../ubivm
LIBCOMMON=../../libcommon/
INCLUDE_DIR=-I$(LIBUVM) -I$(UBIVM) -I$(LIBCOMMON) -I../
CC=g++
CCFLAGS=-g -Wall -pedantic
LIBS=-lncurses 

OBJECTS = uvm_os_ncurses.o

LIBNAME = libuvm_os_ncurses

all: $(OBJECTS)
	g++ -shared -o $(LIBNAME).so $(OBJECTS) $(LIBS)

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@

clean:
	rm -f *.o $(LIBNAME).so $(OBJECTS) core
