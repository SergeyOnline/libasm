section .text

global _ft_strcmp       ; rdi = s1, rsi = s2

_ft_strcmp:
    xor rax, rax        ; resetting register rax
    xor rdx, rdx        ; resetting register rdx
.loop:
    mov al, byte [rdi]  ; write in the register al the value of the first character rdi
    mov dl, byte [rsi]  ; write in the register dl the value of the first character rsi
    sub rax, rdx        ; subtract the values of the registers
    jnz .end            ; if the result is not equal zero (characters are not equal) return the value rax
    test dl,dl          ; checking the dl register for zero
    jz .end             ; if the result is equal zero return the value rax
    inc rdi             ; increment rdi
    inc rsi             ; increment rsi
    jmp .loop

.end:
    ret