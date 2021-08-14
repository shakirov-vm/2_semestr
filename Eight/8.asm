
global _start

func:
	 
	push   rbp
	mov    rbp,rsp
	
	mov    rax, 0x5
	mov    rdx, 0x8
	mov    [rbp-0xc], rax	 
	mov    [rbp-0x8], rdx

	; There can be anyone that damaged rax and rdx

	mov    rdx, [rbp-0xc]
	mov    rax, [rbp-0x8]
	add    rax, rdx
	mov    [rbp-0x4], rax
	mov    rax, [rbp-0x4]      ; Argument in rax
	pop    rbp
	ret    

_start:

	xor    rax, rax
	
	call   func
	
	mov rax, 60					
	xor rdi, rdi					
	syscall
	ret 
