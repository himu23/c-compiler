CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = src/main.cpp src/lexer.cpp src/parser.cpp
OUT = parser

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

run:
	./parser tests/sample_programs/test2.c--

clean:
	rm -f $(OUT)
