  .globl main
  .type main, @function
L1:
  movq %rsp, %rbp
  subq $48, %rsp
  movq -24(%rbp), %rbx
  movq %rbx, -40(%rbp)
  movq -32(%rbp), %rbx
  movq %rbx, -48(%rbp)
  movq -40(%rbp), %rbx
  movq -48(%rbp), %rcx
  addq %rbx, %rcx
  movq %rcx, %rdx
  movq %rdx, -32(%rbp)
  movq -0(%rbp), %rdx
  movq -8(%rbp), %rsi
  movq -16(%rbp), %rdi
  movq %rsi, %rsp
  movq %rdi, %rbp
  jmp *%rdx
main:
  pushq %rbp
  movq %rsp, %rbp
  subq $72, %rsp
  movq $2, %rcx
  movq %rcx, -48(%rbp)
  movq $10, %rdx
  movq %rdx, -56(%rbp)
  movq $8, %rsi
  movq %rsi, -64(%rbp)
  lea 0(%rip), %rdx
  addq $44, %rdx
  movq %rdx, -0(%rsp)
  movq %rsp, -8(%rsp)
  movq %rbp, -16(%rsp)
  movq $8, %rdi
  movq %rdi, -24(%rsp)
  movq -56(%rbp), %rbx
  movq %rbx, -32(%rsp)
  jmp L1
  movq -32(%rsp), %rcx
  movq $2, %rsi
  addq %rcx, %rsi
  movq %rsi, -40(%rbp)
  movq -40(%rbp), %rdi
  movq -40(%rbp), %rbx
  movq %rbx, -32(%rbp)
  movq -32(%rbp), %rax
  movq %rbp, %rsp
  popq %rbp
  ret
