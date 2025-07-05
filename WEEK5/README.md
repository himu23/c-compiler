ler/WEEK4$ ./irgen tests/sample_programs/ret.c--
Generated IR:
func main {
return x
}

piler/WEEK5$ make clean && make 
./codegen tests/sample_programs/ret.c--
rm -f codegen output.s
g++ -std=c++17 -Wall -Iinclude -o codegen src/main.cpp src/lexer.cpp src/parser.cpp src/ast.cpp src/ir_instruction.cpp src/ir_generator.cpp src/assembly_generator.cpp
Assembly code generated to output.s
himu23@ideapad3:~/Desktop/projects/c-compiler/WEEK5$ cat output.s
.globl main
main:
  pushq %rbp
  movq %rsp, %rbp
  movq x, %rax
  popq %rbp
  ret
himu23@ideapad3:~/Desktop/projects/c-compiler/WEEK5$ 


Built an IR-to-x86-64 code generator

Implemented:

Function prologue/epilogue

return x; to movq x, %rax

Output is valid x86-64 assembly (output.s)

Project builds cleanly with make