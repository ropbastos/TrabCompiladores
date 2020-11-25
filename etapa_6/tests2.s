  .globl main
  .type main, @function
main:
  pushq %rbp
  movq %rsp, %rbp
  movl $3, %eax
  movl %eax, -20(%rbp)
  movl $5, %ebx
  movl %ebx, -24(%rbp)
  movl $7, %eax
  popq %rbp
  ret
