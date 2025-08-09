.model small
.stack 100h

.data
    msg1 db 'Sum: $'
    msg2 db 10, 13, 'Sub: $'
    num1 dw 456
    num2 dw 123
.code
main proc
    mov ax, @data
    mov ds, ax

    lea dx, msg1
    mov ah, 9
    int 21h

    mov ax, num1
    add ax, num2
    call printnum

    lea dx, msg2
    mov ah, 9
    int 21h

    mov ax, num1
    sub ax, num2
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