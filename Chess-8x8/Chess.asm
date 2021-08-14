global _start

chess_size equ 72   	; 64 + 8 for '\n'
black_square equ 35		; '#'  - symbol
white_square equ 32 	; ' '  - empty symbol
new_str equ 10			; '\n' - new string
flag equ 66				; rw + create new file

section .data

string:	dq 1
column: dq 1
chess: times chess_size db 0
file_name: db "Output.txt", 0
size_file_name: dq $ - file_name
file_descr: dq 0

section .text

_start:

	mov rcx, chess_size

	chess_l:

		xor rdx, rdx
		mov rax, chess_size
		sub rax, rcx        ;push number of symbol in chess
		add rax, 1         ; vyravnivaem

		mov rbx, 9
		div rbx

		cmp rdx, 0
		je new_string

		xor rdx, rdx
		mov rax, chess_size
		sub rax, rcx        ;push number of symbol in chess
		add rax, 1         ; vyravnivaem

		xor rdx, rdx
		mov rbx, 2
		div rbx

		cmp rdx, 0
		je white
		
		xor rbx, rbx
		mov rdx, chess_size
		sub rdx, rcx
		mov bl, white_square
		mov [chess + rdx], bl
		loop chess_l

		white:
			xor rbx, rbx
			mov rdx, chess_size
			sub rdx, rcx
			mov bl, black_square
			mov [chess + rdx], bl
			loop chess_l

		new_string:
			xor rbx, rbx
			mov rdx, chess_size
			sub rdx, rcx
			mov bl, new_str
			mov [chess + rdx], bl
			loop chess_l

	call file_open
	mov [file_descr], rax
	call file_write
	call file_close
	call asm_exit

file_open:
	
	mov rax, 2				
	mov rdi, file_name		
	mov rsi, flag		
	syscall
	ret

file_write:	

	mov rax, 1					
	mov rdi, [file_descr]					
	mov rsi, chess				
	mov rdx, chess_size					
	syscall						
	ret

file_close:

	mov rax, 3		
	mov rdi, [file_descr]
	syscall
	ret 

asm_exit:

	mov rax, 60					
	xor rdi, rdi					
	syscall
	ret 
