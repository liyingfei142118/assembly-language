
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

org 100h

; add your code here



          ;��ʾ����dp62.asm
        ;����ʹ������������EXE���͵Ŀ�ִ�г���
        segment   code              ;�����code
    ..start:                        ;�������
        MOV   AX, stack
        MOV   SS, AX                ;���ö�ջ�μĴ���
        MOV   SP, stacktop          ;���ö�ջ��
        ;
        MOV   AX, data
        MOV   DS, AX                ;�������ݶμĴ���
        ;
        MOV   DX, offset prompt
        CALL  PrintStr              ;��ʾ��ʾ��Ϣ
        ;
        MOV   AH, 1
        INT   21H                   ;�����û�����
        ;
        MOV   BL, AL                ;��ʱ����������
        ;
        MOV   DX,offset newline
        CALL  PrintStr              ;�γɻس�����
        ;
        MOV   AL, BL                ;�ָ�
        SHR   AL, 4
        CALL  ToASCII               ;�Ѹ�4λת��ӦASCII��
        MOV   [result], AL          ;����
        MOV   AL, BL
        CALL  ToASCII               ;�ѵ�4λת��ӦASCII��
        MOV   [result+1], AL        ;����
        ;
        MOV   DX,offset result
        CALL  PrintStr              ;��ʾ�����Ϣ
        ;
        MOV   AH, 4CH
        INT   21H                   ;���ز���ϵͳ
        ;
    ;��ʾ���ָ�����ַ���
    PrintStr:                       ;�ӳ������
        PUSH  BX                    ;�����Ĵ���BX
        MOV   BX, DX
    LAB1:
        MOV   DL, [BX]              ;ȡ������ʾ�ַ�
        INC   BX                    ;ָ����һ��
        CMP   DL, '$'               ;��������
        JZ    LAB2                  ;����������������
        MOV   AH, 2
        INT   21H                   ;��ʾ���ַ�
        JMP   LAB1                  ;����
    LAB2:
        POP   BX                    ;�ָ��Ĵ���BX
        RET
    ;
    ;�ѵ�4λת�ɶ�Ӧʮ��������ASCII��
    ToASCII:                        ;�ӳ������
        AND   AL, 0FH
        ADD   AL, '0'
        CMP   AL, '9'
        JBE   LAB3
        ADD   AL, 7
    LAB3:
        RET
    ;-------------------------------
    ;
        segment    data             ;�����data
    prompt    db   "Press a key: ",'$'
    newline   db   0DH,0AH,'$'
    result    db   0,0              ;���ʮ��������ASCII��
              db   'H',0DH,0AH,'$'  ;����ַ�����벿��
    ;-------------------------------
    ;
        segment    stack  stack     ;�����ջ��
       ; resb   1024                 ;����1024�ֽ���Ϊ��ջ
    stacktop:
    ;===============================
  ret

