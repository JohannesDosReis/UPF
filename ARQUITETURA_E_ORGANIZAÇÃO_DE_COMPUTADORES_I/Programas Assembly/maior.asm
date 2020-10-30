%include	'../util.asm/util.asm'

extern maior

section		.data
    prompt1	db 'Informe um numero: ', 0
    prompt2	db 'Informe outro numero: ', 0
    msg	db 'Maior: ', 0


section		.text
global		_start

_start:
	mov		rdi, prompt1
	call	printstr
	call	readint
    mov r12, rax

    mov		rdi, prompt2
	call	printstr
	call	readint
    mov r13, rax

	mov		rdi, msg
	call	printstr
	
    mov rdi, r12
    mov rsi, r13
	call maior
	mov		rdi, rax
	call 	printint
	call 	endl
	
	call 	exit