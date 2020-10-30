%include	'../util.asm'

section		.text
global		_start

_start:
	mov		rdi, prompt
	call	printstr
	
	call	readint
	
	; imul 	r14, rax, 2
	shl		rax, 1
	mov		rbx, rax
	
	mov		rdi, msg2
	call	printstr
	
	; mov		rdi, r14
	mov		rdi, rbx
	call 	printint
	call 	endl
	
	call 	exit   
	
            
section		.data
     prompt	db 'Input a number: ', 0
     msg2	db 'Twice: ', 0
