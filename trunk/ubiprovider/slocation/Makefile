LIBUVM=../../libuvm/
UBIVM=../../ubivm
LIBCOMMON=../../libcommon/

INCLUDE_DIR=-I$(LIBUVM) -I$(UBIVM) -I$(LIBCOMMON) -I../ -I/usr/local/include/boost-1_39/
CC=g++
CCFLAGS=-g -Wall -pedantic -fpic

LIBBASENAME = slocation

OBJECTS = ubip_slocation.o

LIBNAME = libuop_p_$(LIBBASENAME)

all: $(OBJECTS)
	g++ -shared -o $(LIBNAME).so $(OBJECTS)

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
