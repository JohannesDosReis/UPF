%include '../util.asm/util.asm'

section		.data
    vet: dq 100, 15, 4300, -1, 55

section		.text
global		_start

_start:
    xor     rbx, rbx
    .loop:
        mov     rdi, [vet + rbx * 8]
        call 	printint
        call 	endl
        inc     rbx
        cmp     rbx, 5
        jl      .loop

    call 	exit