EEK6$ ./cminusc tests/sample_programs/ret.c-- output.s
cat output.s
Assembly code generated to output.s
.globl main
main:
  pushq %rbp
  movq %rsp, %rbp
  movq x, %rax
  popq %rbp
  ret
himu23@ideapad3:~/Desktop/projects/c-compiler/WEEK6$ 