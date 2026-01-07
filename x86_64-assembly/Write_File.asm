section .data
    filename db "HelloWorld.txt", 0
    text db "H4ckThePlanet!!!"

section .text
    global _start

_start:
    mov rax, 2
    mov rdi, filename
    mov rsi, 65
    mov rdx, 0644o
    syscall

    push rax
    mov rdi, rax
    mov rax, 1
    mov rsi, text
    mov rdx, 16
    syscall

    mov rax, 3
    pop rdi
    syscall

    mov rax, 60
    mov rdi, 0
    syscall
