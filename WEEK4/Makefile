CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SRC = src/main.cpp src/lexer.cpp src/parser.cpp src/ast.cpp src/ir_instruction.cpp src/ir_generator.cpp
TARGET = irgen

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)
