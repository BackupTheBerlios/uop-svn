LIBUVM=../../libuvm/
UBIVM=../../ubivm
LIBCOMMON=../../libcommon/

INCLUDE_DIR=-I$(LIBUVM) -I$(UBIVM) -I$(LIBCOMMON) -I../ -I/usr/local/include/boost-1_39/
CC=g++
CCFLAGS=-g -Wall -pedantic

LIBBASENAME = ncurses

OBJECTS = uvm_os_$(LIBBASENAME).o

LIBNAME = libuvm_os_$(LIBBASENAME)

all: $(OBJECTS)
	g++ -shared -o $(LIBNAME).so $(OBJECTS) -lncurses

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
