  .globl main
  .type main, @function
main:
  pushq %rbp
  movq %rsp, %rbp
  mov $1, %bh
  mov %bh, -36(%rbp)
  mov $2, %bl
  mov %bl, -40(%rbp)
  mov $3, %ch
  mov %ch, -44(%rbp)
  mov $4, %cl
  mov %cl, -48(%rbp)
  mov -36(%rbp), %dh
  mov $1, %dl
  cmp %dh, %dl
  jne L9
  je L6
L6:
  mov -40(%rbp), %bh
  mov $3, %bl
  cmp %bh, %bl
  jne L8
  je L9
L8:
  mov $10, %ch
  mov %ch, -24(%rbp)
L9:
  mov -36(%rbp), %cl
  mov $1, %dh
  cmp %cl, %dh
  jne L10
  je L13
L10:
  mov -40(%rbp), %dh
  mov $2, %dl
  cmp %dh, %dl
  jne L13
  je L12
L12:
  mov $11, %bh
  mov %bh, -24(%rbp)
L13:
  mov -36(%rbp), %bl
  mov $1, %ch
  cmp %bl, %ch
  jne L17
  je L14
L14:
  mov -40(%rbp), %cl
  mov $2, %dh
  cmp %cl, %dh
  jne L16
  je L17
L16:
  mov $11, %dl
  mov %dl, -24(%rbp)
L17:
  mov -36(%rbp), %bh
  mov $1, %bl
  cmp %bh, %bl
  jne L20
  je L18
L18:
  mov -40(%rbp), %bl
  mov $2, %ch
  cmp %bl, %ch
  jne L21
  je L20
L20:
  mov $20, %cl
  mov %cl, -28(%rbp)
L21:
  mov -44(%rbp), %dh
  mov $2, %dl
  cmp %dh, %dl
  jle L23
  jnle L24
L23:
  mov $30, %bh
  mov %bh, -32(%rbp)
L24:
  mov -36(%rbp), %bl
  mov $1, %ch
  cmp %bl, %ch
  jne L26
  je L27
L26:
  jmp L28
L27:
  mov $130, %cl
  mov %cl, -36(%rbp)
L28:
  mov -40(%rbp), %dh
  mov $2, %dl
  cmp %dh, %dl
  jne L31
  je L30
L30:
  mov $69, %bh
  mov %bh, -40(%rbp)
L31:
  mov -44(%rbp), %bh
  mov $3, %bl
  cmp %bh, %bl
  jne L33
  je L32
L32:
L33:
  mov -44(%rbp), %ch
  mov $20, %cl
  cmp %cl, %ch
  jl L34
  jmp L35
L34:
L35:
  mov -24(%rbp), %dh
  mov -28(%rbp), %dl
  add %dl, %dh
  mov -32(%rbp), %dl
  add %dl, %dh
  mov -36(%rbp), %bh
  add %bh, %dh
  mov -40(%rbp), %bl
  add %bl, %dh
  mov -44(%rbp), %ch
  add %ch, %dh
  mov -48(%rbp), %ch
  add %ch, %dh
  mov %dh, %al
  popq %rbp
  ret
