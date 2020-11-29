  .globl main
  .type main, @function
main:
  pushq %rbp
  movq %rsp, %rbp
  subq $104, %rsp
  movq $1, %rbx
  movq %rbx, -72(%rbp)
  movq $2, %rcx
  movq %rcx, -80(%rbp)
  movq $3, %rdx
  movq %rdx, -88(%rbp)
  movq $4, %rsi
  movq %rsi, -96(%rbp)
  movq -72(%rbp), %rdi
  movq $1, %rbx
  cmp %rdi, %rbx
  jne L9
  je L6
L6:
  movq -80(%rbp), %rcx
  movq $3, %rdx
  cmp %rcx, %rdx
  jne L8
  je L9
L8:
  movq $10, %rsi
  movq %rsi, -48(%rbp)
L9:
  movq -72(%rbp), %rdi
  movq $1, %rbx
  cmp %rdi, %rbx
  jne L10
  je L13
L10:
  movq -80(%rbp), %rcx
  movq $2, %rdx
  cmp %rcx, %rdx
  jne L13
  je L12
L12:
  movq $11, %rsi
  movq %rsi, -48(%rbp)
L13:
  movq -72(%rbp), %rdi
  movq $1, %rbx
  cmp %rdi, %rbx
  jne L17
  je L14
L14:
  movq -80(%rbp), %rcx
  movq $2, %rdx
  cmp %rcx, %rdx
  jne L16
  je L17
L16:
  movq $11, %rsi
  movq %rsi, -48(%rbp)
L17:
  movq -72(%rbp), %rdi
  movq $1, %rbx
  cmp %rdi, %rbx
  jne L20
  je L18
L18:
  movq -80(%rbp), %rcx
  movq $2, %rdx
  cmp %rcx, %rdx
  jne L21
  je L20
L20:
  movq $20, %rsi
  movq %rsi, -56(%rbp)
L21:
  movq -88(%rbp), %rdi
  movq $2, %rbx
  cmp %rdi, %rbx
  jle L23
  jnle L24
L23:
  movq $30, %rcx
  movq %rcx, -64(%rbp)
L24:
  movq -72(%rbp), %rdx
  movq $1, %rsi
  cmp %rdx, %rsi
  jne L26
  je L27
L26:
  jmp L28
L27:
  movq $130, %rdi
  movq %rdi, -72(%rbp)
L28:
  movq -80(%rbp), %rbx
  movq $2, %rcx
  cmp %rbx, %rcx
  jne L31
  je L30
L30:
  movq $69, %rdx
  movq %rdx, -80(%rbp)
L31:
  movq -88(%rbp), %rsi
  movq $3, %rdi
  cmp %rsi, %rdi
  jne L33
  je L32
L32:
L33:
  movq -88(%rbp), %rbx
  movq $20, %rcx
  cmp %rcx, %rbx
  jl L34
  jmp L35
L34:
L35:
  movq -48(%rbp), %rdx
  movq -56(%rbp), %rsi
  addq %rdx, %rsi
  movq -64(%rbp), %rdi
  addq %rsi, %rdi
  movq -72(%rbp), %rbx
  addq %rdi, %rbx
  movq -80(%rbp), %rcx
  addq %rbx, %rcx
  movq -88(%rbp), %rdx
  addq %rcx, %rdx
  movq -96(%rbp), %rsi
  addq %rdx, %rsi
  movq %rsi, %rdi
  movq %rdi, -32(%rbp)
  movq -32(%rbp), %rax
  movq %rbp, %rsp
  popq %rbp
  ret
