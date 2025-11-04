CXX ?= g++-13
CXXFLAGS ?= -O2 -std=gnu++17 -pipe
LDFLAGS ?=

all: code

code: main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f code
