  .globl main
  .type main, @function
main:
  pushq %rbp
  movq %rsp, %rbp
  movl $1, %ebx
  movl %ebx, -36(%rbp)
  movl $2, %ecx
  movl %ecx, -40(%rbp)
  movl $3, %edx
  movl %edx, -44(%rbp)
  movl $4, %esi
  movl %esi, -48(%rbp)
  movl -36(%rbp), %edi
  movl $1, %ebx
  cmp %edi, %ebx
  jne L9
  je L6
L6:
  movl -40(%rbp), %ecx
  movl $3, %edx
  cmp %ecx, %edx
  jne L8
  je L9
L8:
  movl $10, %esi
  movl %esi, -24(%rbp)
L9:
  movl -36(%rbp), %edi
  movl $1, %ebx
  cmp %edi, %ebx
  jne L10
  je L13
L10:
  movl -40(%rbp), %ecx
  movl $2, %edx
  cmp %ecx, %edx
  jne L13
  je L12
L12:
  movl $11, %esi
  movl %esi, -24(%rbp)
L13:
  movl -36(%rbp), %edi
  movl $1, %ebx
  cmp %edi, %ebx
  jne L17
  je L14
L14:
  movl -40(%rbp), %ecx
  movl $2, %edx
  cmp %ecx, %edx
  jne L16
  je L17
L16:
  movl $11, %esi
  movl %esi, -24(%rbp)
L17:
  movl -36(%rbp), %edi
  movl $1, %ebx
  cmp %edi, %ebx
  jne L20
  je L18
L18:
  movl -40(%rbp), %ecx
  movl $2, %edx
  cmp %ecx, %edx
  jne L21
  je L20
L20:
  movl $20, %esi
  movl %esi, -28(%rbp)
L21:
  movl -44(%rbp), %edi
  movl $2, %ebx
  cmp %edi, %ebx
  jle L23
  jnle L24
L23:
  movl $30, %ecx
  movl %ecx, -32(%rbp)
L24:
  movl -36(%rbp), %edx
  movl $1, %esi
  cmp %edx, %esi
  jne L26
  je L27
L26:
  jmp L28
L27:
  movl $130, %edi
  movl %edi, -36(%rbp)
L28:
  movl -40(%rbp), %ebx
  movl $2, %ecx
  cmp %ebx, %ecx
  jne L31
  je L30
L30:
  movl $69, %edx
  movl %edx, -40(%rbp)
L31:
  movl -44(%rbp), %esi
  movl $3, %edi
  cmp %esi, %edi
  jne L33
  je L32
L32:
L33:
  movl -44(%rbp), %ebx
  movl $20, %ecx
  cmp %ecx, %ebx
  jl L34
  jmp L35
L34:
L35:
  movl -24(%rbp), %edx
  movl -28(%rbp), %esi
  addl %edx, %esi
  movl -32(%rbp), %edi
  addl %esi, %edi
  movl -36(%rbp), %ebx
  addl %edi, %ebx
  movl -40(%rbp), %ecx
  addl %ebx, %ecx
  movl -44(%rbp), %edx
  addl %ecx, %edx
  movl -48(%rbp), %esi
  addl %edx, %esi
  movl %esi, %eax
  popq %rbp
  ret
