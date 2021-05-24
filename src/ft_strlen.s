section .text

global _ft_strlen           ;   rdi = str

_ft_strlen:
    xor rax, rax            ; resetting register rax

.loop:
    cmp byte [rdi], 0       ; checking the rdi register for zero
    jz .end                 ; if the result is equal zero return the value rax
    inc rdi                 ; increment rdi
    inc rax                 ; increment rax
    jmp .loop

.end:
    ret


