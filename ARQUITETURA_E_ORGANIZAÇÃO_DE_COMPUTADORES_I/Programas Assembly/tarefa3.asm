%include '../util.asm/util.asm'
extern fatorial

section		.data
    prompt1	db 'Digite de qual numero deseja o fatorial: ', 0
    msg	db 'Fatorial: ', 0

section		.text
global		_start

_start: mov		rdi, prompt1
	    call	printstr
	    call	readint
        
        mov rdi, rax
        call fatorial
        
        mov r12, rax

        mov		rdi, msg
	    call	printstr

	    mov		rdi, r12
	    call 	printint
	    call 	endl
	
	    call 	exit