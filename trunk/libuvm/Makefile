#
# LibUVM Makefile for Linux
#

# Default installation locations
#DESTDIR = $(INSTROOT)/usr/local
#BINDIR = $(DESTDIR)/sbin
#MANDIR = $(DESTDIR)/share/man/man8
#INCDIR = $(DESTDIR)/include

TARGETS = libuvm

SRCS = AssemblyDefinition.cpp  InstructionDefinition.cpp  MethodDefinition.cpp  PropertyDefinition.cpp  SymbolTable.cpp \
       EntityDefinition.cpp    LocalVarDefinition.cpp     ParameterDefinition.cpp   ResultDefinition.cpp    Symbol.cpp \
	   UvmHeader.cpp BinString.cpp Log.cpp LibUvmCommon.cpp

OBJS = AssemblyDefinition.o  InstructionDefinition.o  MethodDefinition.o  PropertyDefinition.o  SymbolTable.o \
       EntityDefinition.o    LocalVarDefinition.o     ParameterDefinition.o   ResultDefinition.o    Symbol.o \
	   UvmHeader.o   BinString.o Log.o LibUvmCommon.o

#
# include dependencies if present
ifeq (.depend,$(wildcard .depend))
include .depend
endif

CC = g++
#

COPTS = -pipe -Wall -ggdb -pedantic
LIBS = -lcommon

INCLUDE_DIRS= -I. -I../libcommon/

#COMPILE_FLAGS= -DHAVE_PATHS_H -DHAVE_MMAP

CCFLAGS= $(COPTS) $(COMPILE_FLAGS) $(INCLUDE_DIRS)

LIB=libuvm.a

all: $(TARGETS)

%.o: %.cpp %.hpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIRS) $< -o $@

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIRS) $< -o $@

libuvm: $(OBJS)
	$(AR) r $(LIB) $(OBJS)

clean:
	rm -f $(OBJS) $(EXTRACLEAN) $(TARGETS) $(LIB) *~ core

depend:
	$(CPP) -M $(CFLAGS) $(SRCS) >.depend
