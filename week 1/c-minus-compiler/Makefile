CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = src/main.cpp src/lexer.cpp
OUT = lexer

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

run:
	./lexer tests/sample_programs/test1.c--

clean:
	rm -f $(OUT)
