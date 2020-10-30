%include '../util.asm/util.asm'
extern maior

section		.data
    prompt1	db 'Informe um numero ou zero para sair: ', 0
    msg	db 'Maior: ', 0

section		.text
global		_start

_start:
    mov r12, 0x8000000000000000
    mov r13, 0x8000000000000000

inicio:	mov rdi, r12
        mov rsi, r13
	    call maior
        mov		r12, rax
        
        mov		rdi, prompt1
	    call	printstr
	    call	readint
        mov r13, rax

        cmp rax, 0
        jne inicio

        mov		rdi, msg
	    call	printstr

	    mov		rdi, r12
	    call 	printint
	    call 	endl
	
	    call 	exit