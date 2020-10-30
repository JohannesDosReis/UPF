section     .text

global maior, fatorial

maior:
    cmp rdi, rsi
    mov rax, rdi
    cmovng rax, rsi
    ret


; Recursive
fatorial:
   cmp   rdi, 1
   jg    .multiplica
   mov   rax, 1
   ret
	
.multiplica:
   dec   rdi
   call  fatorial
   inc   rdi
   imul  rax, rdi
   ret

; Sequecial
    ; fatorial:
    ;     mov     rax, 1
    ;     cmp     rdi, 1
    ;     jle     .fim
    ; .laco:
    ;     imul    rax, rdi
    ;     dec     rdi
    ;     cmp     rdi, 2
    ;     jge     .laco
    ; .fim:
    ;     ret