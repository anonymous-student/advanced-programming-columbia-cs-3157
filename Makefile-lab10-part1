CC  = clang++
CXX = clang++

INCLUDES = -I../../lab3/solutions/part1

CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES) -std=c++11

LDFLAGS = -g -L../../lab3/solutions/part1
LDLIBS  = -lmylist

executables = strlist-test
objects = strlist-test.o strlist.o mystring.o

.PHONY: default
default: $(executables)

$(executables): strlist.o mystring.o

$(objects): strlist.h mystring.h

.PHONY: clean
clean:
	rm -f *~ a.out core $(objects) $(executables)

.PHONY: all
all: clean default
