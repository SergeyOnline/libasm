section .text

extern _ft_strlen
extern _malloc
extern _ft_strcpy
global _ft_strdup           ; rdi = str

_ft_strdup:
    push rdi				; store the rdi value onto the stack (save string)
	call _ft_strlen			; count the length of the string (rax = len)
	mov rdi, rax			; copy len to rdi
	inc rdi					; increment rdi (needed for malloc)
	call _malloc			; malloc(sizeof(rdi)) (rax = pointer)
	pop rsi					; the value of the stack is transferred to rsi
	test rax, rax			; check malloc return (check NULL)
	jz .err_malloc
	mov rdi, rax			; pointer from malloc transferring to the register rdi
	call _ft_strcpy			; rax = ft_strcpy(rdi, rsi)
	ret

.err_malloc:
    ret