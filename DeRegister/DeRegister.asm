global _start

N equ 100

section .data

processed:  times N db 0

err_messege: db "Isnt symbol", 10
err_len: equ $ - err_messege

section .text
_start:

	call asm_read
	call transformer
	call asm_write
	call asm_exit

asm_read:						

	mov rax, 0					
	mov rdi, 0									
	mov rsi, processed				
	mov rdx, N					
	syscall							
	ret	

transformer:

	xor rbx, rbx
	xor rcx, rcx
	xor rdx, rdx

	mov rcx, N

	by_symbol:

		xor rax, rax

		mov r9, N
		sub r9, rcx
		mov bl, [processed + r9]
		call compare
		;call asm_write		
		mov [processed + r9], bl
		loop by_symbol

	ret

asm_write:	

	mov rax, 1					
	mov rdi, 1					
	mov rsi, processed				
	mov rdx, N					
	syscall						
	ret

asm_exit:

	mov rax, 60					
	xor rdi, rdi					
	syscall
	ret

compare:

	cmp bl, 90
	jbe upper

	cmp bl, 122
	jbe lower

	;call asm_write_mess

	ret

	upper:
	cmp bl, 65
	jae change_up

	;call asm_write_mess

	ret

	change_up:

	add bl, 32

	ret

	lower:
	cmp bl, 97
	jae change_low

	;call asm_write_mess

	ret

	change_low:

	sub bl, 32

	ret

asm_write_mess:

	push rax
	push rdi
	push rsi
	push rdx

	mov rax, 1
	mov rdi, 1
	mov rsi, err_messege
	mov rdx, err_len
	syscall

	pop rax
	pop rdi
	pop rsi
	pop rdx

	ret