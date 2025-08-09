.MODEL SMALL
.STACK 100h

.DATA
    msg db 'IBM Characters:',13,10,'$'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    lea dx, msg
    mov ah, 9
    int 21h

    mov cx, 32         
    mov bl, 0 

    display_loop:
    mov ah, 2
    mov dl, bl
    int 21h            

    inc bl
    loop display_loop

    mov ah, 4ch
    int 21h
    
MAIN ENDP
END MAIN