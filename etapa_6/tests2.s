  .globl main
  .type main, @function
L1:
  movq %rsp, %rbp
  subq $56, %rsp
  movq -24(%rbp), %rcx
  movq %rcx, -40(%rbp)
  movq -32(%rbp), %rcx
  movq %rcx, -48(%rbp)
  movq -40(%rbp), %rcx
  movq %rcx, -56(%rbp)
  movq -40(%rbp), %rbx
  movq -48(%rbp), %rcx
  addq %rbx, %rcx
  movq -56(%rbp), %rdx
  addq %rcx, %rdx
  movq %rdx, %rsi
  movq %rsi, -32(%rbp)
  movq -0(%rbp), %rsi
  movq -8(%rbp), %rdi
  movq -16(%rbp), %rbx
  movq %rdi, %rsp
  movq %rbx, %rbp
  jmp *%rsi
main:
  pushq %rbp
  movq %rsp, %rbp
  subq $72, %rsp
  movq $2, %rdx
  movq %rdx, -48(%rbp)
  movq $10, %rsi
  movq %rsi, -56(%rbp)
  movq $8, %rdi
  movq %rdi, -64(%rbp)
  lea 0(%rip), %rdi
  addq $50, %rdi
  movq %rdi, -0(%rsp)
  movq %rsp, -8(%rsp)
  movq %rbp, -16(%rsp)
  movq -56(%rbp), %rbx
  movq %rbx, -24(%rsp)
  movq -64(%rbp), %rcx
  movq %rcx, -32(%rsp)
  movq -48(%rbp), %rdx
  movq %rdx, -40(%rsp)
  jmp L1
  movq -32(%rsp), %rsi
  movq %rsi, -40(%rbp)
  movq -40(%rbp), %rbx
  movq -40(%rbp), %rcx
  movq %rcx, -32(%rbp)
  movq -32(%rbp), %rax
  movq %rbp, %rsp
  popq %rbp
  ret
