#
# LibCommon Makefile for Linux
#

# Default installation locations
#DESTDIR = $(INSTROOT)/usr/local
#BINDIR = $(DESTDIR)/sbin
#MANDIR = $(DESTDIR)/share/man/man8
#INCDIR = $(DESTDIR)/include

TARGETS = libcommon

SRCS = Tools.cpp TextFile.cpp

OBJS = Tools.o TextFile.o

#
# include dependencies if present
ifeq (.depend,$(wildcard .depend))
include .depend
endif

CC = g++
#

COPTS = -pipe -Wall -ggdb -pedantic
LIBS =

INCLUDE_DIRS= -I.

#COMPILE_FLAGS= -DHAVE_PATHS_H -DHAVE_MMAP

CCFLAGS= -rdynamic $(COPTS) $(COMPILE_FLAGS) $(INCLUDE_DIRS)

LIB=libcommon.a

all: $(TARGETS)

%.o: %.cpp %.hpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIRS) $< -o $@

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIRS) $< -o $@

libcommon: $(OBJS)
	$(AR) r $(LIB) $(OBJS)

clean:
	rm -f $(OBJS) $(EXTRACLEAN) $(TARGETS) $(LIB) *~ core

depend:
	$(CPP) -M $(CFLAGS) $(SRCS) >.depend
