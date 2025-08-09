.MODEL SMALL
.STACK 100h
.CODE
MAIN PROC
    MOV CX, 80

PRINT_LOOP:
    MOV DL, '*'         
    MOV AH, 2            
    INT 21h
    LOOP PRINT_LOOP      
    
    MOV AH, 4CH
    INT 21h
MAIN ENDP
END