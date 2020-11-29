  .text
  .globl main
  .type main, @function
L1:
  movq %rsp, %rbp
  subq $40, %rsp
  movq -24(%rbp), %rcx
  movq %rcx, -40(%rbp)
  movq -40(%rbp), %rbx
  movq $1, %rcx
  subq %rcx, %rbx
  movq %rbx, -40(%rbp)
  movq -40(%rbp), %rdx
  movq -40(%rbp), %rsi
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
  subq $48, %rsp
  movq $2, -40(%rbp)
L8:
  movq -40(%rbp), %rsi
  movq $6, %rdi
  movq $1, %rbx
  addq %rdi, %rbx
  neg %rbx
  cmp %rsi, %rbx
  jne L6
  je L7
L6:
  lea 0(%rip), %rdi
  addq $32, %rdi
  movq %rdi, -0(%rsp)
  movq %rsp, -8(%rsp)
  movq %rbp, -16(%rsp)
  movq -40(%rbp), %rdx
  movq %rdx, -24(%rsp)
  jmp L1
  movq -32(%rsp), %rsi
  movq %rsi, -40(%rbp)
  jmp L8
L7:
  movq -40(%rbp), %rbx
  movq -40(%rbp), %rcx
  movq %rcx, -32(%rbp)
  movq -32(%rbp), %rax
  movq %rbp, %rsp
  popq %rbp
  ret
