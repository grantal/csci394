
CXX=clang++-5.0   # Can switch to g++ if desired
CXXFLAGS=-g -std=c++17 -Wall -pedantic -Wextra -Werror
LDFLAGS=$(CXXFLAGS)
LIBS=

INC=ptrtree.hh vectree.hh tree.hh catch.hpp
SRC=vectree.cc test_ptrtree.cc ptrtree.cc
OBJ=$(SRC:.cc=.o)

all: test_tree

test_tree: $(OBJ)
	$(CXX) $(LDFLAGS) $(LIBS) -o $@ $(OBJ)

%.o.cc: %.cc %.hh
	$(CXX) $(CFLAGS) -c -o $@ $<

test: all
	./test_tree

clean:
	rm -f $(OBJ)
