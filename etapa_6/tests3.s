  .globl main
  .type main, @function
L1:
  pushq %rbp
  movq %rsp, %rbp
  subq $24, %rsp
  movl -12(%rbp), %edi
  movl %edi, -20(%rbp)
  movl -16(%rbp), %edi
  movl %edi, -24(%rbp)
  movl $23, %ebx
  movl $23, %eax
  popq %rbp
  ret
main:
  pushq %rbp
  movq %rsp, %rbp
  subq $16, %rsp
  movl $2, %ebx
  movl %ebx, -24(%rbp)
  movl $3, %ecx
  movl %ecx, -28(%rbp)
#  subq $16, %rsp
  movl $0, %eax
  movq %rbp, %rsp # leave
  popq %rbp
  ret
