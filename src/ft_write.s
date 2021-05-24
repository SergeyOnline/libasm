section .text

global _ft_write

extern ___error

_ft_write:
    xor     rax, rax            ; resetting register rax
    mov     rax, 0x2000004      ; save code syscall
    syscall                     ; rax = code error, error set carry flag
    jc .err
    ret

.err:
    push rax                    ; store the rax value into the stack (code error)
    call ___error               ; rax = pointer error in errno
    pop rdx                     ; put code error in rdx
    mov [rax], rdx              ; put error in errno
    mov rax, -1
    ret