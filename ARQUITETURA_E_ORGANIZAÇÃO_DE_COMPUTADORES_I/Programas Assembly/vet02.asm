%include '../util.asm/util.asm'

section		.data
    vet: dq 100, 15, 4300, -1, 55

section		.text
global		_start

_start:
    mov     rbx, 4
    .loop:
        mov     rdi, [vet + rbx * 8]
        call 	printint
        call 	endl
        dec     rbx
        ; cmp     rbx, -1
        jns      .loop

    call 	exit