  .globl main
  .type main, @function
main:
  pushq %rbp
  movq %rsp, %rbp
  movl $3, %eax
  popq %rbp
  ret