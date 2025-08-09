.MODEL SMALL
.STACK 100h

.DATA
    msg db 'Enter characters (blank to stop): $'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    lea dx, msg
    mov ah, 9
    int 21h

    read_loop:
    mov ah, 1
    int 21h         
    cmp al, ' '
    je done
    jmp read_loop

    done:
    mov ah, 4ch
    int 21h

MAIN ENDP
END MAIN