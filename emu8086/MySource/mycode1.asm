
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

DATA SEGMENT
    SUM DW DUP(0) ;�ۼӺ�
   HELLO DB 'COUNT:',0DH,0AH,'$';�ۼӺ���ʾ
   HELLO1 DB 0DH,0AH,'$';����
   HELLO2 DB '+:',0DH,0AH,'$';����
   HELLO3 DB '-:',0DH,0AH,'$';����
   HELLO4 DB '0:',0DH,0AH,'$' ;��
 DATA ENDS 

DATA1 SEGMENT
ASSUME CS:DATA1 

START: 
;6.43��ʮ���������������ascll
 NE:    
    MOV AH,1 ;�����ַ����ַ�����AL��
    INT 21H
    MOV DL,AL 
    CMP AL,'$';�ж��Ƿ����
    JE NET
    CALL print_al ;���10����
    ASSUME DS:DATA��
    MOV AX,DATA
    MOV DS,AX
    
    MOV DX,OFFSET HELLO1 ������
    MOV AH,9
    INT 21H 
    JMP NE
    
;��F000��0000��ֵ   
 NET:   
    MOV AX,0F000H
    MOV DS,AX
    
    MOV CX,100 ;100���ֽ�
    MOV DL,1
    MOV SI,0
  NEXT:
    MOV [SI],DL
    INC DL
    INC SI
    LOOP NEXT 
 ;6.48 �ҳ����� ���� ��ĸ���
    CALL BTO1
    
  

 
     
 ;6.46��100���ֽ��ۼӺ�   

    MOV AX,0F000H
    MOV DS,AX
    
    MOV CX,100
    MOV DX,0 ;DL����
    XOR AX,AX
    MOV SI,0  ;ָ��
  NEXT1: 
    MOV AL,[DI]
    ADD DX,AX
    INC SI
    LOOP NEXT1 
    
     ASSUME DS:DATA
     MOV AX,DATA
     MOV DS,AX
     MOV SUM,DX
     MOV CX, SUM ;�������
     MOV AX,CX
     SHL AX,4;�����4λ
    MOV DX,OFFSET HELLO  ;�������
    MOV AH,9
    INT 21H
    CALL print_al
   
     MOV AL,CL ;�����4λ
    CALL print_al
    
    
    ;6.44��F000��16���ֽڸ��Ƶ�B800�� 
    ;ASSUME DS:DATA
   ;MOV AX,DATA
    ;MOV DS,AX
    
    ;MOV DX,OFFSET HELLO1 
    ;MOV AH,9
    ;INT 21H
    ;CALL BTO   
    
     

     MOV AH,4CH
     INT 21H   

print_al proc ;��2����ת����10���Ʋ����
cmp al, 0
jne print_al_r
    push ax
    mov al, '0'
    mov ah, 0eh
    int 10h
    pop ax
    ret 
print_al_r:    
    pusha
    mov ah, 0
    cmp ax, 0
    je pn_done
    mov dl, 10
    div dl    
    call print_al_r
    mov al, ah
    add al, 30h
    mov ah, 0eh
    int 10h    
    jmp pn_done
pn_done:
    popa  
    ret  
endp


BTO PROC
      MOV CX,16    
  NEXT2:
    MOV SI,16
    MOV AX,0F000H
    MOV DS,AX  
    
    SUB  SI,CX     
    MOV DL,[SI]

    MOV AX,0B800H
    MOV DS,AX
    MOV [SI],DL
    LOOP NEXT2 
     RET  
ENDP

BTO1 PROC
    MOV AX,0F000H
    MOV DS,AX
    
    MOV CX,128
    MOV DX,0
    MOV SI,0 
    XOR DI,DI ; �渺��
    XOR BX,BX  ; ������
  NEXT4:
    ADD DX,[SI]
    CMP DX,0
    JL LABE
    JG LABE1 
    JMP LABE3
    LABE:
       INC DI
       JMP LABE3
    LABE1:
        INC BX  
    LABE3:
    ADD SI,2
    LOOP NEXT4 
    
    ASSUME DS:DATA
    MOV AX,DATA
    MOV DS,AX
    
    MOV DX,OFFSET HELLO1 ;����
    MOV AH,9
    INT 21H  
    
    MOV DX,OFFSET HELLO3 ;�������
    MOV AH,9
    INT 21H     
    MOV AX,DI
    CALL print_al
      

       
    MOV DX,OFFSET HELLO1 ;�������
    MOV AH,9
    INT 21H
    
    MOV DX,OFFSET HELLO2 
    MOV AH,9
    INT 21H
   MOV AL,BL
   CALL print_al   
     
    MOV DX,OFFSET HELLO1 ;���0
    MOV AH,9
    INT 21H 
    
    MOV DX,OFFSET HELLO4 
    MOV AH,9
    INT 21H
    MOV CX,DI
    ADD CX,BX
    SUB CX,128
    NEG CX
    MOV AL,CL
    CALL print_al
    
    MOV DX,OFFSET HELLO1 
    MOV AH,9
    INT 21H
    RET 
ENDP    
    
    
   DATA1 ENDS
END START
  



