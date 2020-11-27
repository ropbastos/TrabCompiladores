  .globl main
  .type main, @function
main:
  pushq %rbp
  movq %rsp, %rbp
  mov $1, %ah
  mov %ah, -36(%rbp)
  mov $2, %al
  mov %al, -40(%rbp)
  mov $3, %bh
  mov %bh, -44(%rbp)
  mov $4, %bl
  mov %bl, -48(%rbp)
  mov -36(%rbp), %ch
  mov $1, %cl
  cmp %ch, %cl
  jne L9
  je L6
L6:
  mov -40(%rbp), %dh
  mov $3, %dl
  cmp %dh, %dl
  jne L8
  je L9
L8:
  mov $10, %ah
  mov %ah, -24(%rbp)
L9:
  mov -36(%rbp), %al
  mov $1, %bh
  cmp %al, %bh
  jne L10
  je L13
L10:
  mov -40(%rbp), %bl
  mov $2, %ch
  cmp %bl, %ch
  jne L13
  je L12
L12:
  mov $11, %cl
  mov %cl, -24(%rbp)
L13:
  mov -36(%rbp), %dh
  mov $1, %dl
  cmp %dh, %dl
  jne L17
  je L14
L14:
  mov -40(%rbp), %ah
  mov $2, %al
  cmp %ah, %al
  jne L16
  je L17
L16:
  mov $11, %bh
  mov %bh, -24(%rbp)
L17:
  mov -36(%rbp), %bl
  mov $1, %ch
  cmp %bl, %ch
  jne L20
  je L18
L18:
  mov -40(%rbp), %cl
  mov $2, %dh
  cmp %cl, %dh
  jne L21
  je L20
L20:
  mov $20, %dl
  mov %dl, -28(%rbp)
L21:
  mov -44(%rbp), %ah
  mov $2, %al
  cmp %ah, %al
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
  mov $69, %ah
  mov %ah, -40(%rbp)
L31:
  mov -44(%rbp), %al
  mov $3, %bh
  cmp %al, %bh
  jne L33
  je L32
L32:
L33:
  mov -44(%rbp), %bl
  mov $20, %ch
  cmp %ch, %bl
  jl L34
  jmp L35
L34:
L35:
  mov -24(%rbp), %cl
  mov -28(%rbp), %dh
  add %dh, %cl
  mov -32(%rbp), %dl
  add %dl, %cl
  mov -36(%rbp), %ah
  add %ah, %cl
  mov -40(%rbp), %al
  add %al, %cl
  mov -44(%rbp), %bh
  add %bh, %cl
  mov -48(%rbp), %bl
  add %bl, %cl
  mov %cl, %al
  popq %rbp
  ret
