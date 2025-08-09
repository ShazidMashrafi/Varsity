.model small
.stack 100h

.data
    msg_mul db 'Product: $'
    msg_div db 13,10,'Quotient: $'
    num1    dw 456
    num2    dw 123
.code
main proc
    mov ax, @data
    mov ds, ax
    
    lea dx, msg_mul
    mov ah, 9
    int 21h

    mov ax, num1
    mov bx, num2
    mul bx
    call printnum

    lea dx, msg_div
    mov ah, 9
    int 21h

    mov ax, num1
    xor dx, dx
    mov bx, num2
    div bx
    call printnum

    mov ah, 4ch
    int 21h
main endp

printnum proc
    push ax
    push bx
    push cx
    push dx

    xor cx, cx
    mov bx, 10

print_loop:
    xor dx, dx
    div bx
    push dx
    inc cx

    test ax, ax
    jnz print_loop

print_digits:
    pop dx
    add dl, '0'
    mov ah, 2
    int 21h
    loop print_digits

    pop dx
    pop cx
    pop bx
    pop ax
    ret
printnum endp
end main