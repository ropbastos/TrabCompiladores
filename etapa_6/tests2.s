  .globl main
  .type main, @function
L1:
  movq %rsp, %rbp
  subq $40, %rsp
  movq -24(%rbp), %rbx
  movq %rbx, -40(%rbp)
  movq $0, %rbx
  movq %rbx, -48(%rbp)
  movq $1, %rbx
  movq %rbx, -56(%rbp)
  movq -40(%rbp), %rcx
  movq $0, %rdx
  cmp %rcx, %rdx
  jne L3
  je L2
L2:
  movq -48(%rbp), %rsi
  movq %rsi, %rdi
  movq %rdi, -32(%rbp)
  movq -0(%rbp), %rdi
  movq -8(%rbp), %rbx
  movq -16(%rbp), %rcx
  movq %rbx, %rsp
  movq %rcx, %rbp
  jmp *%rdi
L3:
  movq $2, %rdx
  movq %rdx, -72(%rbp)
L11:
  movq -72(%rbp), %rsi
  movq -40(%rbp), %rdi
  cmp %rsi, %rdi
  jge L9
  jnge L10
L9:
  movq -48(%rbp), %rdx
  movq -56(%rbp), %rsi
  addq %rdx, %rsi
  movq %rsi, -64(%rbp)
  movq -56(%rbp), %rdi
  movq %rdi, -48(%rbp)
  movq -64(%rbp), %rbx
  movq %rbx, -56(%rbp)
  movq -72(%rbp), %rbx
  movq $1, %rcx
  addq %rbx, %rcx
  movq %rcx, -72(%rbp)
  jmp L11
L10:
  movq -56(%rbp), %rcx
  movq -56(%rbp), %rdx
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
  subq $56, %rsp
  movq $9, %rcx
  movq %rcx, -48(%rbp)
  lea 0(%rip), %rdi
  addq $32, %rdi
  movq %rdi, -0(%rsp)
  movq %rsp, -8(%rsp)
  movq %rbp, -16(%rsp)
  movq -48(%rbp), %rdx
  movq %rdx, -24(%rsp)
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
