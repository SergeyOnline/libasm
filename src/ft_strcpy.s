section .text

global _ft_strcpy				; rdi = dest, rsi = src

_ft_strcpy:
	mov rax, rdi				; copy addres dest
.loop:
    mov dl, byte [rsi]			; copying the character to dl
	mov byte [rdi], dl			; copying the dl addres to rdi
	test dl, dl					; checking the dl register for zero
	jz .end
	inc rdi						; increment rdi
	inc rsi						; increment rsi
	jmp .loop

.end:
	ret
