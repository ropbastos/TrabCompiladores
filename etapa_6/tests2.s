  .globl main
  .type main, @function
main:
  pushq %rbp
  movq %rsp, %rbp
  subq $56, %rsp
  movq $0, %rbx
  movq %rbx, -48(%rbp)
  movq $0, %rcx
  movq %rcx, -40(%rbp)
L6:
  movq -40(%rbp), %rdx
  movq $100, %rsi
  cmp %rsi, %rdx
  jl L4
  jmp L5
L4:
  movq -40(%rbp), %rdi
  movq $1, %rbx
  addq %rdi, %rbx
  movq %rbx, -40(%rbp)
  jmp L6
L5:
  movq -40(%rbp), %rcx
  movq -40(%rbp), %rdx
  movq %rdx, -32(%rbp)
  movq -32(%rbp), %rax
  movq %rbp, %rsp
  popq %rbp
  ret
