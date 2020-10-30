; // programa C++ equivalente:

; int maior(int a , int b)
; {
;     return (a>b) ? a : b;
; }

; int main()
; {
;     int n1, n2, m;
;     cin >> n1 >> n2;
;     m = maior(n1, n2);
;     cout << m << endl;
; }


%include '../util.asm/util.asm'


section     .data
    prompt1  db 'Digite um numero: ', 0
    prompt2  db 'Digite outro numero: ', 0
    prompt3  db 'Maior: ', 0

    


section		.text
global 		_start

maior:
    cmp rdi, rsi
    jl .segundo
    mov rax, rdi
    ret
.segundo:
    mov rax, rsi
    ret

_start:
    mov rdi, prompt1
    call printstr
    call readint
    mov r12, rax

    mov rdi, prompt2
    call printstr
    call readint
    mov rsi, rax
    mov rdi, r12
    call maior

    mov r12, rax
    mov rdi, prompt3
    call printstr

    mov rdi, r12
    call printint

    

    call endl
    call exit 