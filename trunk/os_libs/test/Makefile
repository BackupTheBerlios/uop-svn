# LIBUVM=../libuvm/
# LIBCOMMON=../libcommon/

# INCLUDE_DIR=-I/usr/local/include/ -I$(LIBUVM) -I$(LIBCOMMON)
CC=g++
CCFLAGS=-g -Wall -pedantic
# CCFLAGS_ANTLR=-g -Wall

objects = test.o

all: $(objects)
	g++ -shared -o libtest.so $(objects)

%.o: %.cpp %.hpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@

%.o: %.c %.h
	$(CC) $(CCFLAGS) -c $(INCLUDE_DIR) $< -o $@


clean:
	rm -f *.o libtest.so $(objects) core
