TARGET = cminusc
SRC = src/main.cpp src/lexer.cpp src/parser.cpp src/ast.cpp \
      src/semantic_analyzer.cpp src/ir_instruction.cpp \
      src/ir_generator.cpp src/ir_optimizer.cpp src/assembly_generator.cpp \
      src/compiler_driver.cpp

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) output.s
