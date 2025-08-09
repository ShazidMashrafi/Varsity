.MODEL SMALL
.STACK 100h

.DATA
    even_msg db 'Number is EVEN.$'
    odd_msg  db 'Number is ODD.$'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    mov ah, 1
    int 21h
    sub al, '0'

    test al, 1
    jz print_even

    print_odd:
    lea dx, odd_msg
    mov ah, 9
    int 21h
    jmp done

    print_even:
    lea dx, even_msg
    mov ah, 9
    int 21h

    done:
    mov ah, 4ch
    int 21h
    
MAIN ENDP
END MAIN