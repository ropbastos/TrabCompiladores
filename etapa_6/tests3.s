  .globl main
  .type main, @function
main:
  pushq %rbp
  mov $2, %ah
  mov $3, %al
  mov %al, -24(%rbp)
  mov -24(%rbp), %bl
  
  movq %rsp, %rbp
  mov $13, %ax
  mov $5, %bl
  div %bl
  popq %rbp
  ret
