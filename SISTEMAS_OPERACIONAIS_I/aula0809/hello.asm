section .data
    msg: db "Hello World!", 10

section .text
    global _start
        _start:
            mov rax, 1; sys_write
            mov rdi, 1; std_out
            mov rsi, msg; endereço da mensagem
            lea rsi, [msg]; endereço da mensagem
            mov rdx, 13;tamanho da mensagem
            syscall

            mov rax, 60
            mov rdi, 0
            syscall

