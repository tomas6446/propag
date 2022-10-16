	.file	"main.c"
	.text
	.def	printf;	.scl	3;	.type	32;	.endef
	.seh_proc	printf
printf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	32(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	time;	.scl	3;	.type	32;	.endef
	.seh_proc	time
time:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rcx
	movq	__imp__time64(%rip), %rax
	call	*%rax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	fillArray
	.def	fillArray;	.scl	2;	.type	32;	.endef
	.seh_proc	fillArray
fillArray:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movl	%ecx, 32(%rbp)
	movl	$0, %ecx
	call	time
	movl	%eax, %ecx
	call	srand
	movl	32(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rcx
	call	malloc
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	32(%rbp), %edx
	movl	%edx, (%rax)
	movl	$1, -4(%rbp)
	jmp	.L6
.L7:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-16(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	call	rand
	movl	%eax, (%rbx)
	addl	$1, -4(%rbp)
.L6:
	movl	-4(%rbp), %eax
	cmpl	32(%rbp), %eax
	jl	.L7
	movq	-16(%rbp), %rax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "%d \0"
.LC1:
	.ascii "\12\0"
	.text
	.globl	printArray
	.def	printArray;	.scl	2;	.type	32;	.endef
	.seh_proc	printArray
printArray:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -8(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L10
.L11:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	16(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	addl	$1, -4(%rbp)
.L10:
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	jl	.L11
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC2:
	.ascii "file.txt\0"
.LC3:
	.ascii "file2.txt\0"
.LC4:
	.ascii "all good\12\0"
.LC5:
	.ascii "something's wrong\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	call	__main
	movl	$10, %ecx
	call	fillArray
	movq	%rax, -8(%rbp)
	movl	$10, %ecx
	call	fillArray
	movq	%rax, -16(%rbp)
	movl	$10, %ecx
	call	fillArray
	movq	%rax, -24(%rbp)
	movq	-8(%rbp), %rax
	leaq	.LC2(%rip), %rdx
	movq	%rax, %rcx
	call	saveToFile
	movq	-24(%rbp), %rax
	leaq	.LC2(%rip), %rdx
	movq	%rax, %rcx
	call	saveToFile
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	loadFromFile
	movq	%rax, -8(%rbp)
	movq	-16(%rbp), %rax
	leaq	.LC3(%rip), %rdx
	movq	%rax, %rcx
	call	saveToFile
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	loadFromFile
	movq	%rax, -24(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	loadFromFile
	movq	%rax, -16(%rbp)
	movq	.refptr.saveCount(%rip), %rax
	movl	(%rax), %eax
	cmpl	$3, %eax
	jne	.L13
	movq	.refptr.loadCount(%rip), %rax
	movl	(%rax), %eax
	cmpl	$3, %eax
	jne	.L13
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L14
.L13:
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	printf
.L14:
	movq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	free
	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 11.2.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	srand;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	rand;	.scl	2;	.type	32;	.endef
	.def	saveToFile;	.scl	2;	.type	32;	.endef
	.def	loadFromFile;	.scl	2;	.type	32;	.endef
	.def	free;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr.loadCount, "dr"
	.globl	.refptr.loadCount
	.linkonce	discard
.refptr.loadCount:
	.quad	loadCount
	.section	.rdata$.refptr.saveCount, "dr"
	.globl	.refptr.saveCount
	.linkonce	discard
.refptr.saveCount:
	.quad	saveCount
