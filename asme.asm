section .data
    msg db 'The factorial of %d is %d', 0
section .bss
    num resd 1
section .text
    global _start

_start:
    ; read integer from user into num
    mov eax, 3
    mov ebx, num
    mov ecx, num
    mov edx, 4
    int 0x80

    ; calculate factorial and store result in eax
    mov eax, [num] ; eax = num
    mov ebx, 1 ; ebx = 1

calculate:
    cmp eax, 1 ; if eax == 1, skip to end
    je end
    mul ebx ; ebx *= eax
    dec eax ; decrement eax
    jmp calculate

end:
    ; print result
    mov eax, 4 ; system call for write
    mov ebx, 1 ; file descriptor for stdout
    mov ecx, msg ; message to be printed
    mov edx, 20 ; length of message
    int 0x80

    ; exit
    mov eax, 1 ; system call for exit
    xor ebx, ebx ; exit status
    int 0x80
