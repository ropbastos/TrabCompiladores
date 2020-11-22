
  .globl	main
	.type	main, @function
a:
  .zero 4
b:
  .zero 4
main:
  pushq %rbp
  movq %rsp, %rbp
  movl $3, %eax
  popq %rbp
  ret