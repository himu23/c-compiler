.globl main
main:
  pushq %rbp
  movq %rsp, %rbp
  movq x, %rax
  popq %rbp
  ret
