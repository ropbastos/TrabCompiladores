  .globl main
  .type main, @function
main:
  pushq %rbp
  movq %rsp, %rbp
  mov $20, %ah
  mov %ah, -20(%rbp)
  mov $10, %al
  mov %al, -24(%rbp)
  mov -24(%rbp), %bh
  mov $2, %bl
  mov %bh, %al
  xor %ah, %ah
  div %bl
  mov %al, %bh
  mov -20(%rbp), %ch
  mov %bh, %al
  xor %ah, %ah
  mul %ch
  mov %al, %bh
  mov $50, %cl
  add %cl, %bh
  mov -20(%rbp), %dh
  sub %dh, %bh
  mov %bh, %al
  popq %rbp
  ret
