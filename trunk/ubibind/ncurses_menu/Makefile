LIBUVM=../../libuvm/
UBIVM=../../ubivm
LIBCOMMON=../../libcommon/
INCLUDE_DIR=-I$(LIBUVM) -I$(UBIVM) -I$(LIBCOMMON) -I../ -I/usr/local/include/boost-1_39/
LIB_DIR=-L$(LIBCOMMON)
CC=g++
CCFLAGS=-g -Wall -pedantic -fPIC
LIBS=-lmenu 

OBJECTS = uvm_os_ncurses_menu.o

LIBDIR  = ../../lib/
LIBNAME = $(LIBDIR)libuvm_os_ncurses_menu

all: $(OBJECTS)
	g++ -shared -o $(LIBNAME).so $(OBJECTS) $(LIBS) $(LIB_DIR)

%.cpp:
	../ubibind ncurses_menu.bind

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@

clean:
	rm -f *.o $(LIBNAME).so $(OBJECTS) core uvm_os_ncurses_menu.cpp
